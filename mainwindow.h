#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
void closeEvent(QCloseEvent *event);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;

private slots:
       void on_applyBut_clicked();

private slots:
          void on_actionQuit_triggered();

private slots:
          void on_actionAbout_triggered();

private slots:
          void on_actionAbout_Qt_triggered();
};




#endif // MAINWINDOW_H
