#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gui.h"
#include "gui2.h"

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void closeEvent(QCloseEvent *e);

private slots:
    void on_actionQuit_triggered();
    void on_actionCamera_Controls_triggered();

    void on_actionEditor_triggered();

    void on_actionOpen_triggered();

    void on_actionOpen_JSON_triggered();

    void on_actionEditor2_triggered();

private:
    void connectSignalSlot();
    Ui::MainWindow *ui;
    gui* g;
    gui2* g2;
};


#endif // MAINWINDOW_H
