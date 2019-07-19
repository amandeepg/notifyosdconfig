#include "aboutw.h"
#include "ui_aboutw.h"
#include <QtWidgets>

AboutW::AboutW(QWidget *parent) : QMainWindow(parent), ui(new Ui::AboutW) {
  ui->setupUi(this);
  ui->closeBut->setIcon(QMessageBox(0).addButton(QMessageBox::Ok)->icon());
}

AboutW::~AboutW() {
  delete ui;
}

void AboutW::changeEvent(QEvent *e) {
  QMainWindow::changeEvent(e);
  switch (e->type()) {
  case QEvent::LanguageChange:
    ui->retranslateUi(this);
    break;
  default:
    break;
  }
}

void AboutW::on_closeBut_clicked() {
 this->close();
}
