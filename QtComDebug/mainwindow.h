#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qtcomlibrary.h"

#define COM_ID        1
#define INI_PATH        "..//QtComDebugger.ini"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pBtn_connect_clicked();
    void on_pBtn_send_clicked();

signals:
    void ComSendMsg(QString msg);
    void ComRecvMsg(QString msg);
    void ComInfoMsg(QString msg);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
