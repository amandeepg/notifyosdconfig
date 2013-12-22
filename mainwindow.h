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
void readThemes();
void loadTheme (std::string s);
void saveTheme(std::string s);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;

private slots:
       void on_applyBut_clicked();
       void clickLoad();
       void clickSave();
       void on_actionQuit_triggered();
       void on_actionReset_triggered();
       void on_actionAbout_triggered();
       void on_actionAbout_Qt_triggered();
       void dragEnterEvent(QDragEnterEvent *event);
       void dropEvent(QDropEvent *event);
       void saveNewTheme();
};




#endif // MAINWINDOW_H
