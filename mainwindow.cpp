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

string clean (string s);
Ui::MainWindow* ui;

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow) {
    this->ui=ui;
    ui->setupUi(this);
    ui->bblBackColour->setStandardColors();
    ui->bblBackColour->insertColor(QColor(19, 19, 19),"Dark Grey",0);
    ui->bblBackColour->setCurrentColor(QColor(19, 19, 19));

    ui->titleColour->setStandardColors();
    ui->titleColour->setCurrentColor(QColor(255, 255, 255));

    ui->bodyColour->setStandardColors();
    ui->bodyColour->insertColor(QColor(234, 234, 234),"Light Grey",0);
    ui->bodyColour->setCurrentColor(QColor(234, 234, 234));

    readThemes();

    string s1 = getenv ("HOME");
    string s2 = "/.notify-osd";
    loadTheme(s1+s2);


}

void MainWindow::loadTheme (string s) {

    ifstream nf;

    nf.open (s.c_str());

    ui->statusBar->showMessage("Loading configuration file",3000);

    if (!nf) {
        ui->statusBar->showMessage("No configuration file to load",3000);
        return;
    }
    ui->statusBar->showMessage("",3000);

    getline(nf,s);
    if (s=="") {
        ui->statusBar->showMessage("Configuration file incomplete",3000);
        return;
    }
    s = clean(s);
    if (s=="dynamic") {
        ui->positionCombo->setCurrentIndex(1);
    } else {
        ui->positionCombo->setCurrentIndex(0);
    }

    getline(nf,s);
    if (s=="") {
        ui->statusBar->showMessage("Configuration file incomplete",3000);
        return;
    }
    s = clean(s);
    ui->timeoutSpin->setValue(atoi(s.c_str()));

    getline(nf,s);
    if (s=="") {
        ui->statusBar->showMessage("Configuration file incomplete",3000);
        return;
    }
    s = clean(s);
    ui->bblVerticalGap->setValue(atoi(s.c_str()));

    getline(nf,s);
    if (s=="") {
        ui->statusBar->showMessage("Configuration file incomplete",3000);
        return;
    }
    s = clean(s);
    ui->bblHorizontalGap->setValue(atoi(s.c_str()));

    getline(nf,s);
    if (s=="") {
        ui->statusBar->showMessage("Configuration file incomplete",3000);
        return;
    }
    s = clean(s);
    ui->bblCornerRadius->setValue(atoi(s.c_str()));

    getline(nf,s);
    if (s=="") {
        ui->statusBar->showMessage("Configuration file incomplete",3000);
        return;
    }
    s = clean(s);
    ui->bblIconSize->setValue(atoi(s.c_str()));

    getline(nf,s);
    if (s=="") {
        ui->statusBar->showMessage("Configuration file incomplete",3000);
        return;
    }
    s = clean(s);
    ui->bblGaugeSize->setValue(atoi(s.c_str()));

    getline(nf,s);
    if (s=="") {
        ui->statusBar->showMessage("Configuration file incomplete",3000);
        return;
    }
    s = clean(s);
    ui->bblWidth->setValue(atoi(s.c_str()));

    getline(nf,s);
    if (s=="") {
        ui->statusBar->showMessage("Configuration file incomplete",3000);
        return;
    }
    s = clean(s);
    QColor qc = QColor(("#"+s).c_str());
    ui->bblBackColour->setCurrentColor(qc);

    getline(nf,s);
    if (s=="") {
        ui->statusBar->showMessage("Configuration file incomplete",3000);
        return;
    }
    s = clean(s);
    ui->bblOpacity->setValue(atoi(s.c_str()));

    getline(nf,s);
    if (s=="") {
        ui->statusBar->showMessage("Configuration file incomplete",3000);
        return;
    }
    s = clean(s);
    ui->marginSize->setValue(atoi(s.c_str()));

    getline(nf,s);
    if (s=="") {
        ui->statusBar->showMessage("Configuration file incomplete",3000);
        return;
    }
    s = clean(s);
    ui->titleSize->setValue(atoi(s.c_str()));

    getline(nf,s);
    if (s=="") {
        ui->statusBar->showMessage("Configuration file incomplete",3000);
        return;
    }
    s = clean(s);
    if (s=="normal") {
        ui->titleWeight->setCurrentIndex(1);
    } else if (s=="light") {
        ui->titleWeight->setCurrentIndex(2);
    } else {
        ui->titleWeight->setCurrentIndex(0);
    }

    getline(nf,s);
    if (s=="") {
        ui->statusBar->showMessage("Configuration file incomplete",3000);
        return;
    }
    s = clean(s);
    QColor qc2 = QColor(("#"+s).c_str());
    ui->titleColour->setCurrentColor(qc2);

    getline(nf,s);
    if (s=="") {
        ui->statusBar->showMessage("Configuration file incomplete",3000);
        return;
    }
    s = clean(s);
    ui->titleOpacity->setValue(atoi(s.c_str()));

    getline(nf,s);
    if (s=="") {
        ui->statusBar->showMessage("Configuration file incomplete",3000);
        return;
    }
    s = clean(s);
    ui->bodySize->setValue(atoi(s.c_str()));

    getline(nf,s);
    if (s=="") {
        ui->statusBar->showMessage("Configuration file incomplete",3000);
        return;
    }
    s = clean(s);
    if (s=="normal") {
        ui->bodyWeight->setCurrentIndex(1);
    } else if (s=="light") {
        ui->bodyWeight->setCurrentIndex(2);
    } else {
        ui->bodyWeight->setCurrentIndex(0);
    }

    getline(nf,s);
    if (s=="") {
        ui->statusBar->showMessage("Configuration file incomplete",3000);
        return;
    }
    s = clean(s);
    QColor qc3 = QColor(("#"+s).c_str());
    ui->bodyColour->setCurrentColor(qc3);

    getline(nf,s);
    if (s=="") {
        ui->statusBar->showMessage("Configuration file incomplete",3000);
        return;
    }
    s = clean(s);
    ui->bodyOpacity->setValue(atoi(s.c_str()));

    getline(nf,s);
    if (s=="") {
        ui->statusBar->showMessage("Configuration file incomplete",3000);
        return;
    }
    s = clean(s);
    ui->shadowOpacity->setValue(atoi(s.c_str()));

    ui->statusBar->showMessage("Loaded configuration file",3000);

}

void MainWindow::doS() {
    QAction *qa = (QAction *)sender();
    string s1 = getenv ("HOME");
    s1 = s1 +"/.notifyosdconf/";
    string s2 = qa->text().toStdString() + ".osdtheme";
    string s3 =s1+s2;
    loadTheme(s3);
    ui->statusBar->showMessage("Loaded theme",3000);
}

void MainWindow::saveT() {
    QAction *qa = (QAction *)sender();
    string s1 = getenv ("HOME");
    s1 = s1 +"/.notifyosdconf/";
    string s2 = qa->text().toStdString() + ".osdtheme";
    string s3 =s1+s2;
    saveTheme(s3);

    ui->statusBar->showMessage("Saved theme",3000);
}



void MainWindow::readThemes() {
    string s1 = getenv ("HOME");
    s1 = s1 +"/.notifyosdconf/";
    cout << system (("mkdir "+s1).c_str()) << endl;
    QDir directory = QDir(s1.c_str());
    QStringList files;

    files = directory.entryList(QStringList("*.osdtheme"),
                                QDir::Files | QDir::NoSymLinks);

    ui->menuLoad_Theme->clear();
    ui->menuSave_Theme->clear();

    QAction* qa = new QAction("New theme ...",this);
    connect(qa, SIGNAL(triggered()), this, SLOT(saveNewTheme()));
    ui->menuSave_Theme->addAction(qa);


    for (int x=0; x<files.length(); x++) {
        cout << ((QString)files.at(x)).toStdString() << endl;

        QAction* qa = new QAction(((QString)files.at(x)).replace(".osdtheme",""),this);
        connect(qa, SIGNAL(triggered()), this, SLOT(doS()));

        QAction* qa2 = new QAction(((QString)files.at(x)).replace(".osdtheme",""),this);
        connect(qa2, SIGNAL(triggered()), this, SLOT(saveT()));

        ui->menuLoad_Theme->addAction(qa);
        ui->menuSave_Theme->addAction(qa2);
    }

    if (files.length()==0) {
        ui->menuLoad_Theme->addAction("No themes available.");
    }
}


string clean (string s) {
    QString qs = QString(s.c_str());
    qs = qs.toLower();

    qs = qs.replace(" ","");
    qs = qs.replace("=","");
    qs = qs.replace("px","");
    qs = qs.replace("sec","");
    qs = qs.replace("%","");
    qs = qs.replace(",5%","");
    qs = qs.replace("slot-allocation","");
    qs = qs.replace("bubble-expire-timeout","");
    qs = qs.replace("bubble-vertical-gap","");
    qs = qs.replace("bubble-horizontal-gap","");
    qs = qs.replace("bubble-corner-radius","");
    qs = qs.replace("bubble-icon-size","");
    qs = qs.replace("bubble-gauge-size","");
    qs = qs.replace("bubble-width","");
    qs = qs.replace("bubble-background-color","");
    qs = qs.replace("bubble-background-opacity","");
    qs = qs.replace("text-margin-size","");
    qs = qs.replace("text-title-size","");
    qs = qs.replace("text-title-weight","");
    qs = qs.replace("text-title-color","");
    qs = qs.replace("text-title-opacity","");
    qs = qs.replace("text-body-size","");
    qs = qs.replace("text-body-weight","");
    qs = qs.replace("text-body-color","");
    qs = qs.replace("text-body-opacity","");
    qs = qs.replace("text-shadow-opacity","");

    string s2 = qs.toStdString();

    return s2;
}

MainWindow::~MainWindow() {
    delete ui;
}
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
    srand ( time(NULL) );
    int sec = rand() % 100 + 1;
    string temm = "OSD-Theme-"+itos(sec);


    QString text = QInputDialog::getText(this, tr("New Theme .."),
                                         tr("Name of new theme:"), QLineEdit::Normal,
                                         QString(temm.c_str()), &ok);

    if ( ok && !text.isEmpty() ) {
        string s1 = getenv ("HOME");
        string s2 = "/.notifyosdconf/";
        string s3 = text.toStdString()+".osdtheme";
        saveTheme(s1+s2+s3);

        readThemes();

        ui->statusBar->showMessage("New theme file saved" ,3000);
    } else {
        ui->statusBar->showMessage("No new theme file saved" ,3000);
    }

}

void MainWindow::saveTheme(string s) {

    ofstream nf;

    nf.open (s.c_str());

    string pos = ui->positionCombo->currentText().toLower().toStdString();
    string timeout = ui->timeoutSpin->text().toLower().replace(" ","").toStdString();
    string bblVerticalGap = ui->bblVerticalGap->text().toLower().replace(" ","").toStdString();
    string bblHorizontalGap = ui->bblHorizontalGap->text().toLower().replace(" ","").toStdString();
    string bblCornerRadius = ui->bblCornerRadius->text().toLower().replace(" ","").replace("px","").toStdString();
    string bblIconSize = ui->bblIconSize->text().toLower().replace(" ","").toStdString();
    string bblGaugeSize = ui->bblGaugeSize->text().toLower().replace(" ","").toStdString();
    string bblWidth = ui->bblWidth->text().toLower().replace(" ","").toStdString();
    string bblBackColour =ui->bblBackColour->currentColor().name().toLower().replace("#","").toStdString();
    string bblOpacity = ui->bblOpacity->text().toLower().replace(" ","").toStdString();
    string marginSize = ui->marginSize->text().toLower().replace(" ","").toStdString();
    string titleSize = ui->titleSize->text().toLower().replace(" ","").toStdString();
    string titleWeight = ui->titleWeight->currentText().toLower().replace(" ","").replace("light","thin").toStdString();
    string titleColour =ui->titleColour->currentColor().name().toLower().replace("#","").toStdString();
    string titleOpacity = ui->titleOpacity->text().toLower().replace(" ","").toStdString();
    string bodySize = ui->bodySize->text().toLower().replace(" ","").toStdString();
    string bodyWeight = ui->bodyWeight->currentText().toLower().replace(" ","").replace("light","thin").toStdString();
    string bodyColour =ui->bodyColour->currentColor().name().toLower().replace("#","").toStdString();
    string bodyOpacity = ui->bodyOpacity->text().toLower().replace(" ","").toStdString();
    string shadowOpacity = ui->shadowOpacity->text().toLower().replace(" ","").toStdString();

    nf << "slot-allocation = " << pos << endl;
    nf << "bubble-expire-timeout = " << timeout << endl;
    nf << "bubble-vertical-gap = " << bblVerticalGap << endl;
    nf << "bubble-horizontal-gap = " << bblHorizontalGap << endl;
    nf << "bubble-corner-radius = " << bblCornerRadius << ",5%" << endl;
    nf << "bubble-icon-size = " << bblIconSize << endl;
    nf << "bubble-gauge-size = " << bblGaugeSize << endl;
    nf << "bubble-width = " << bblWidth << endl;
    nf << "bubble-background-color = " << bblBackColour << endl;
    nf << "bubble-background-opacity = " << bblOpacity << endl;
    nf << "text-margin-size = " << marginSize << endl;
    nf << "text-title-size = " << titleSize << endl;
    nf << "text-title-weight = " << titleWeight << endl;
    nf << "text-title-color = " << titleColour << endl;
    nf << "text-title-opacity = " << titleOpacity << endl;
    nf << "text-body-size = " << bodySize << endl;
    nf << "text-body-weight = " << bodyWeight << endl;
    nf << "text-body-color = " << bodyColour << endl;
    nf << "text-body-opacity = " << bodyOpacity << endl;
    nf << "text-shadow-opacity = " << shadowOpacity << endl;

    nf.close();

}

void MainWindow::on_applyBut_clicked() {
    string s1 = getenv ("HOME");
    string s2 = "/.notify-osd";

    saveTheme(s1+s2);

    cout << system ("killall notify-osd") << endl;
    cout << system ("notify-send -u critical -i /usr/share/notifyosdconf/not.png \"Notify OSD Configuration\" \"This is how the notifications now look.\"") << endl;
}

void MainWindow::on_actionQuit_triggered() {
    exit(0);
}

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
    string s3 = "/usr/share/notifyosdconf/default.def";
    loadTheme(s3);
    ui->statusBar->showMessage("Reset to default theme",3000);
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event) {
    if (event->mimeData()->urls().size()==1) {
        if (event->mimeData()->urls()[0].toLocalFile().endsWith(".osdtheme")) {
            event->acceptProposedAction();
        }
    }

}

void MainWindow::dropEvent(QDropEvent *event) {
    string se =event->mimeData()->urls()[0].toLocalFile().toStdString();
    cout << se << endl;
    string s1 = getenv ("HOME");
    s1 = s1 +"/.notifyosdconf/";
    string se2 = s1+se.substr(se.find_last_of('/'),se.length()-1);
    QFile::copy(QString(se.c_str()),QString(se2.c_str()));

    event->acceptProposedAction();

    string tem = "Added ";
    string tem2 = QString(se.substr(se.find_last_of('/')+1,se.length()-1).c_str()).replace(".osdtheme","").toStdString();
    tem+=tem2;
    tem+=" to theme list";

    ui->statusBar->showMessage(QString(tem.c_str()) ,3000);
    readThemes();
}


