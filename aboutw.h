#ifndef ABOUTW_H
#define ABOUTW_H

#include <QMainWindow>

namespace Ui {
    class AboutW;
}

class AboutW : public QMainWindow {
    Q_OBJECT
public:
    AboutW(QWidget *parent = 0);
    ~AboutW();

protected:
    void changeEvent(QEvent *e);

private slots:
       void on_closeBut_clicked();

private:
    Ui::AboutW *ui;
};

#endif // ABOUTW_H
