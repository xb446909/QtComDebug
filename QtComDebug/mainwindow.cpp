#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextCodec>
int RecvCallbackPro(int nSize, const char* szRecv);
extern MainWindow* pWnd;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this, SIGNAL(ComSendMsg(QString)), ui->textEdit_send, SLOT(append(QString)));
    connect(this, SIGNAL(ComRecvMsg(QString)), ui->textEdit_recv, SLOT(append(QString)));
    connect(this, SIGNAL(ComInfoMsg(QString)), ui->textEdit_info, SLOT(append(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pBtn_connect_clicked()
{
    if (OpenCOM(COM_ID, INI_PATH, RecvCallbackPro) != 0)
    {
        emit ComInfoMsg(QString().sprintf("OpenCOM error"));
    }
}

int RecvCallbackPro(int nSize, const char* szRecv)
{
    QTextCodec* codec = QTextCodec::codecForName("GB18030");
    QString recvStr = codec->toUnicode(szRecv, nSize);
    emit pWnd->ComRecvMsg(QString().sprintf("[Received]: %s", recvStr.toStdString().c_str()));
    return 0;
}

void MainWindow::on_pBtn_send_clicked()
{
    QString strSend = ui->textEdit_send->toPlainText();
    //const char * tempd = strSend.toStdString().c_str();
    //QString转char *
    QByteArray baTemp = strSend.toLatin1();
    char *szTemp = baTemp.data();
    WriteCOM(COM_ID, szTemp, strSend.size());
    emit ComSendMsg(QString().sprintf("[Send]: %s", strSend.toStdString().c_str()));
}
