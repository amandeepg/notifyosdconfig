#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_dialog.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include "aboutw.h"
#include "ui_aboutw.h"
#include <QDesktopWidget>
#include <QtGui>
#include <sstream>

using namespace std;

#define TIMEOUT 3000
#define HOME (string(getenv("HOME")) + "/")
#define DEFAULT_DEF "/usr/share/notifyosdconf/default.def"

Ui::MainWindow *ui;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->bblBackColour->setStandardColors();
  ui->bblBackColour->insertColor(QColor(19, 19, 19), "Dark Grey", 0);
  ui->bblBackColour->setCurrentColor(QColor(19, 19, 19));

  ui->titleColour->setStandardColors();
  ui->titleColour->setCurrentColor(QColor(255, 255, 255));

  ui->bodyColour->setStandardColors();
  ui->bodyColour->insertColor(QColor(234, 234, 234), "Light Grey", 0);
  ui->bodyColour->setCurrentColor(QColor(234, 234, 234));

  ui->actionQuit->setIcon(QIcon::fromTheme("application-exit"));
  ui->menuLoad_Theme->setIcon(QIcon::fromTheme("document-open"));
  ui->menuSave_Theme->setIcon(QIcon::fromTheme("document-save"));
  ui->actionReset->setIcon(QIcon::fromTheme("document-revert"));
  ui->actionAbout->setIcon(QIcon::fromTheme("help-about"));
  ui->applyBut->setIcon(QMessageBox(0).addButton(QMessageBox::Ok)->icon());

  readThemes();
  loadTheme(HOME + ".notify-osd");
}

int stringToInt(string s) {
  return atoi(s.c_str());
}

int weightToIndex(string s) {
  if (s == "normal") {
    return 1;
  } else if (s == "light") {
    return 2;
  } else {
    return 0;
  }
}

QColor stringToHex(string s) {
  return QColor(("#" + s).c_str());
}

map<string, string> loadConfigFromFile(string filename) {
  ifstream infile;
  infile.open(filename.c_str());

  if (!infile) {
    return map<string, string>();
  }

  map<string, string> config_params;

  string k, eq, v;
  while (infile >> k >> eq >> v) {
    config_params[k] = QString(v.c_str()).remove("px").remove("sec").toStdString();
  }

  return config_params;
}

string orMap(map<string, string> map1, map<string, string> map2, string key) {
  if (map1.find(key) != map1.end()) {
    return map1[key];
  } else {
    return map2[key];
  }
}

void MainWindow::loadTheme(string filename) {
  ui->statusBar->showMessage("Loading configuration file ...", TIMEOUT);

  map<string, string> config_params_def;
  if (filename != DEFAULT_DEF) {
    config_params_def = loadConfigFromFile(DEFAULT_DEF);
  }

  map<string, string> config_params = loadConfigFromFile(filename);
  if (config_params.empty()) {
    return;
  }

  ui->positionCombo->setCurrentIndex(orMap(config_params, config_params_def, "slot-allocation") == "dynamic" ? 1 : 0);
  ui->timeoutSpin->setValue(stringToInt(orMap(config_params, config_params_def, "bubble-expire-timeout")));
  ui->bblVerticalGap->setValue(stringToInt(orMap(config_params, config_params_def, "bubble-vertical-gap")));
  ui->bblHorizontalGap->setValue(stringToInt(orMap(config_params, config_params_def, "bubble-horizontal-gap")));
  ui->bblCornerRadius->setValue(stringToInt(orMap(config_params, config_params_def, "bubble-corner-radius")));
  ui->bblIconSize->setValue(stringToInt(orMap(config_params, config_params_def, "bubble-icon-size")));
  ui->bblGaugeSize->setValue(stringToInt(orMap(config_params, config_params_def, "bubble-gauge-size")));
  ui->bblWidth->setValue(stringToInt(orMap(config_params, config_params_def, "bubble-width")));
  ui->bblBackColour->setCurrentColor(stringToHex(orMap(config_params, config_params_def, "bubble-background-color")));
  ui->bblOpacity->setValue(stringToInt(orMap(config_params, config_params_def, "bubble-background-opacity")));
  ui->marginSize->setValue(stringToInt(orMap(config_params, config_params_def, "text-margin-size")));
  ui->titleSize->setValue(stringToInt(orMap(config_params, config_params_def, "text-title-size")));
  ui->titleWeight->setCurrentIndex(weightToIndex(orMap(config_params, config_params_def, "text-title-weight")));
  ui->titleColour->setCurrentColor(stringToHex(orMap(config_params, config_params_def, "text-title-color")));
  ui->bodySize->setValue(stringToInt(orMap(config_params, config_params_def, "text-body-size")));
  ui->bodyWeight->setCurrentIndex(weightToIndex(orMap(config_params, config_params_def, "text-body-weight")));
  ui->titleColour->setCurrentColor(stringToHex(orMap(config_params, config_params_def, "text-body-color")));
  ui->bodyOpacity->setValue(stringToInt(orMap(config_params, config_params_def, "text-body-opacity")));
  ui->shadowOpacity->setValue(stringToInt(orMap(config_params, config_params_def, "text-shadow-opacity")));
  ui->locationCombo->setCurrentIndex(stringToInt(orMap(config_params, config_params_def, "location")) - 1);
  ui->fadeOnHoverCb->setChecked(stringToInt(orMap(config_params, config_params_def, "bubble-prevent-fade")) == 1);
  ui->closeOnClickCb->setChecked(stringToInt(orMap(config_params, config_params_def, "bubble-close-on-click")) == 1);
  ui->bblBackDashCb->setChecked(stringToInt(orMap(config_params, config_params_def, "bubble-as-desktop-bg")) == 1);

  ui->statusBar->showMessage("Loaded configuration file", TIMEOUT);
}

void MainWindow::clickLoad() {
  QAction *qa = (QAction *) sender();
  loadTheme(HOME + ".notifyosdconf/" + qa->text().toStdString() + ".osdtheme");
  ui->statusBar->showMessage("Loaded theme", TIMEOUT);
}

void MainWindow::clickSave() {
  QAction *qa = (QAction *) sender();
  saveTheme(HOME + ".notifyosdconf/" + qa->text().toStdString() + ".osdtheme");
  ui->statusBar->showMessage("Saved theme", TIMEOUT);
}

void MainWindow::readThemes() {
  string thmes_dir_str = HOME + ".notifyosdconf/";
  QDir directory = QDir(thmes_dir_str.c_str());
  directory.mkpath(".");

  QStringList files = directory.entryList(QStringList("*.osdtheme"), QDir::Files | QDir::NoSymLinks);

  ui->menuLoad_Theme->clear();
  ui->menuSave_Theme->clear();

  QAction *qa;
  for (int x = 0; x < files.length(); x++) {
    qa = new QAction(files.value(x).remove(".osdtheme"), this);
    connect(qa, SIGNAL(triggered()), this, SLOT(clickLoad()));
    ui->menuLoad_Theme->addAction(qa);

    qa = new QAction(files.value(x).remove(".osdtheme"), this);
    connect(qa, SIGNAL(triggered()), this, SLOT(clickSave()));
    ui->menuSave_Theme->addAction(qa);
  }

  if (files.length() == 0) {
    ui->menuLoad_Theme->addAction("No themes available.");
  }

  qa = new QAction("New theme ...", this);
  connect(qa, SIGNAL(triggered()), this, SLOT(saveNewTheme()));
  ui->menuSave_Theme->addAction(qa);
}

MainWindow::~MainWindow() { delete ui; }
void MainWindow::closeEvent(QCloseEvent *event) {
  exit(0);
  event->accept();
}

void MainWindow::changeEvent(QEvent *e) {
  QMainWindow::changeEvent(e);
  switch (e->type()) {
  case QEvent::LanguageChange:
    ui->retranslateUi(this);
    break;
  default:
    break;
  }
}

string itos(int i) { // convert int to string
  stringstream s;
  s << i;
  return s.str();
}

void MainWindow::saveNewTheme() {
  bool ok;
  srand(time(NULL));
  string temm = "OSD-Theme-" + itos(rand() % 100 + 1);

  QString text = QInputDialog::getText(this, tr("New Theme .."), tr("Name of new theme:"),
      QLineEdit::Normal, QString(temm.c_str()), &ok);

  if (ok && !text.isEmpty()) {
    saveTheme(HOME + ".notifyosdconf/" + text.toStdString() + ".osdtheme");
    readThemes();

    ui->statusBar->showMessage("New theme file saved", TIMEOUT);
  } else {
    ui->statusBar->showMessage("No new theme file saved", TIMEOUT);
  }
}

string normalizeString(QString s) {
  return s.toLower().remove("#").remove(" ").toStdString();
}

void MainWindow::saveTheme(string s) {
  ofstream outfile;
  outfile.open(s.c_str());

  outfile << "slot-allocation = "           << normalizeString(ui->positionCombo->currentText())         << endl;
  outfile << "bubble-expire-timeout = "     << normalizeString(ui->timeoutSpin->text())                  << endl;
  outfile << "bubble-vertical-gap = "       << normalizeString(ui->bblVerticalGap->text())               << endl;
  outfile << "bubble-horizontal-gap = "     << normalizeString(ui->bblHorizontalGap->text())             << endl;
  outfile << "bubble-corner-radius = "      << normalizeString(ui->bblCornerRadius->text())              << endl;
  outfile << "bubble-icon-size = "          << normalizeString(ui->bblIconSize->text())                  << endl;
  outfile << "bubble-gauge-size = "         << normalizeString(ui->bblGaugeSize->text())                 << endl;
  outfile << "bubble-width = "              << normalizeString(ui->bblWidth->text())                     << endl;
  outfile << "bubble-background-color = "   << normalizeString(ui->bblBackColour->currentColor().name()) << endl;
  outfile << "bubble-background-opacity = " << normalizeString(ui->bblOpacity->text())                   << endl;
  outfile << "text-margin-size = "          << normalizeString(ui->marginSize->text())                   << endl;
  outfile << "text-title-size = "           << normalizeString(ui->titleSize->text())                    << endl;
  outfile << "text-title-weight = "         << normalizeString(ui->titleWeight->currentText())           << endl;
  outfile << "text-title-color = "          << normalizeString(ui->titleColour->currentColor().name())   << endl;
  outfile << "text-title-opacity = "        << normalizeString(ui->titleOpacity->text())                 << endl;
  outfile << "text-body-size = "            << normalizeString(ui->bodySize->text())                     << endl;
  outfile << "text-body-weight = "          << normalizeString(ui->bodyWeight->currentText())            << endl;
  outfile << "text-body-color = "           << normalizeString(ui->bodyColour->currentColor().name())    << endl;
  outfile << "text-body-opacity = "         << normalizeString(ui->bodyOpacity->text())                  << endl;
  outfile << "text-shadow-opacity = "       << normalizeString(ui->shadowOpacity->text())                << endl;
  outfile << "location = "                  << (ui->locationCombo->currentIndex() + 1)                   << endl;
  outfile << "bubble-prevent-fade = "       << (ui->fadeOnHoverCb->isChecked() ? "1" : "0")              << endl;
  outfile << "bubble-close-on-click = "     << (ui->closeOnClickCb->isChecked() ? "1" : "0")             << endl;
  outfile << "bubble-as-desktop-bg = "      << (ui->bblBackDashCb->isChecked() ? "1" : "0")              << endl;

  system(("gsettings set com.canonical.notify-osd gravity " + itos(ui->locationCombo->currentIndex() + 1)).c_str());

  outfile.close();
}

void MainWindow::on_applyBut_clicked() {
  saveTheme(HOME + ".notify-osd");

  system("killall notify-osd");
  system("notify-send -u critical -i /usr/share/notifyosdconf/not.png "
                 "\"Notify OSD Configuration\" \"This is how the notifications now look.\"");
}

void MainWindow::on_actionQuit_triggered() { exit(0); }

void MainWindow::on_actionAbout_triggered() {
  AboutW *window = new AboutW();
  window->show();
  int scrn = 0;
  QWidget *w = topLevelWidget();

  if (w)
    scrn = QApplication::desktop()->screenNumber(w);
  else if (QApplication::desktop()->isVirtualDesktop())
    scrn = QApplication::desktop()->screenNumber(QCursor::pos());
  else
    scrn = QApplication::desktop()->screenNumber(this);

  QRect desk(QApplication::desktop()->availableGeometry(scrn));

  window->move((desk.width() - window->frameGeometry().width()) / 2,
               (desk.height() - window->frameGeometry().height()) / 2);
}

void MainWindow::on_actionAbout_Qt_triggered() {
  QMessageBox::aboutQt(0, "About QT");
}

void MainWindow::on_actionReset_triggered() {
  loadTheme(DEFAULT_DEF);
  ui->statusBar->showMessage("Reset to default theme", TIMEOUT);
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event) {
  if (event->mimeData()->urls().size() == 1) {
    if (event->mimeData()->urls()[0].toLocalFile().endsWith(".osdtheme")) {
      event->acceptProposedAction();
    }
  }
}

void MainWindow::dropEvent(QDropEvent *event) {
  string se = event->mimeData()->urls()[0].toLocalFile().toStdString();
  string se2 = HOME + ".notifyosdconf/" + se.substr(se.find_last_of('/'), se.length() - 1);
  QFile::copy(QString(se.c_str()), QString(se2.c_str()));

  event->acceptProposedAction();

  string tem = "Added ";
  tem += QString(se.substr(se.find_last_of('/') + 1, se.length() - 1).c_str()).remove(".osdtheme").toStdString();
  tem += " to theme list";

  ui->statusBar->showMessage(QString(tem.c_str()), TIMEOUT);
  readThemes();
}
