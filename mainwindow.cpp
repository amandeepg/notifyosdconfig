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

using namespace std;

string clean (string s);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->bblBackColour->setStandardColors();
    ui->bblBackColour->insertColor(QColor(19, 19, 19),"Dark Grey",0);
    ui->bblBackColour->setCurrentColor(QColor(19, 19, 19));

    ui->titleColour->setStandardColors();
    ui->titleColour->setCurrentColor(QColor(255, 255, 255));

    ui->bodyColour->setStandardColors();
    ui->bodyColour->insertColor(QColor(234, 234, 234),"Light Grey",0);
    ui->bodyColour->setCurrentColor(QColor(234, 234, 234));

    ifstream nf;
    string s1 = getenv ("HOME");
    string s2 = "/testqt.txt";
    string s;

    nf.open ((s1+s2).c_str());

    if (!nf)return;

    getline(nf,s);
    if (s=="")return;
    s = clean(s);
    if (s=="dynamic") {
        ui->positionCombo->setCurrentIndex(1);
    } else {
        ui->positionCombo->setCurrentIndex(0);
    }

    getline(nf,s);
    if (s=="")return;
    s = clean(s);
    ui->timeoutSpin->setValue(atoi(s.c_str()));

    getline(nf,s);
    if (s=="")return;
    s = clean(s);
    ui->bblVerticalGap->setValue(atoi(s.c_str()));

    getline(nf,s);
    if (s=="")return;
    s = clean(s);
    ui->bblHorizontalGap->setValue(atoi(s.c_str()));

    getline(nf,s);
    if (s=="")return;
    s = clean(s);
    ui->bblCornerRadius->setValue(atoi(s.c_str()));

    getline(nf,s);
    if (s=="")return;
    s = clean(s);
    ui->bblIconSize->setValue(atoi(s.c_str()));

    getline(nf,s);
    if (s=="")return;
    s = clean(s);
    ui->bblGaugeSize->setValue(atoi(s.c_str()));

    getline(nf,s);
    if (s=="")return;
    s = clean(s);
    ui->bblWidth->setValue(atoi(s.c_str()));

    getline(nf,s);
    if (s=="")return;
    s = clean(s);
    QColor qc = QColor(("#"+s).c_str());
    ui->bblBackColour->setCurrentColor(qc);

    getline(nf,s);
    if (s=="")return;
    s = clean(s);
    ui->bblOpacity->setValue(atoi(s.c_str()));

    getline(nf,s);
    if (s=="")return;
    s = clean(s);
    ui->marginSize->setValue(atoi(s.c_str()));

    getline(nf,s);
    if (s=="")return;
    s = clean(s);
    ui->titleSize->setValue(atoi(s.c_str()));

    getline(nf,s);
    if (s=="")return;
    s = clean(s);
    if (s=="normal"){
        ui->titleWeight->setCurrentIndex(1);
    } else if (s=="light"){
        ui->titleWeight->setCurrentIndex(2);
    } else {
        ui->titleWeight->setCurrentIndex(0);
    }

    getline(nf,s);
    if (s=="")return;
    s = clean(s);
    QColor qc2 = QColor(("#"+s).c_str());
    ui->titleColour->setCurrentColor(qc2);

    getline(nf,s);
    if (s=="")return;
    s = clean(s);
    ui->titleOpacity->setValue(atoi(s.c_str()));

    getline(nf,s);
    if (s=="")return;
    s = clean(s);
    ui->bodySize->setValue(atoi(s.c_str()));

    getline(nf,s);
    if (s=="")return;
    s = clean(s);
    if (s=="normal"){
        ui->bodyWeight->setCurrentIndex(1);
    } else if (s=="light"){
        ui->bodyWeight->setCurrentIndex(2);
    } else {
        ui->bodyWeight->setCurrentIndex(0);
    }

    getline(nf,s);
    if (s=="")return;
    s = clean(s);
    QColor qc3 = QColor(("#"+s).c_str());
    ui->bodyColour->setCurrentColor(qc3);

    getline(nf,s);
    if (s=="")return;
    s = clean(s);
    ui->titleOpacity->setValue(atoi(s.c_str()));

    getline(nf,s);
    if (s=="")return;
    s = clean(s);
    ui->bodySize->setValue(atoi(s.c_str()));

}

string clean (string s)
{
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

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::closeEvent(QCloseEvent *event)
{
  exit(0);
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
void MainWindow::on_applyBut_clicked()
{
      ofstream nf;
      string s1 = getenv ("HOME");
      string s2 = "/testqt.txt";

      nf.open ((s1+s2).c_str());

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

      system ("killall notify-osd");
      system ("notify-send -u critical \"Notify OSD Configuration\" \"This is how the notifications now look.\"");
}

void MainWindow::on_actionQuit_triggered()
{
    exit(0);
}

void MainWindow::on_actionAbout_triggered()
{
    AboutW *window = new AboutW();
    window->show();
    int scrn = 0;
    QWidget *w = topLevelWidget();

    if(w)
         scrn = QApplication::desktop()->screenNumber(w);
    else if(QApplication::desktop()->isVirtualDesktop())
         scrn = QApplication::desktop()->screenNumber(QCursor::pos());
    else
         scrn = QApplication::desktop()->screenNumber(this);

    QRect desk(QApplication::desktop()->availableGeometry(scrn));

    window->move((desk.width() - window->frameGeometry().width()) / 2,
          (desk.height() - window->frameGeometry().height()) / 2);

}

