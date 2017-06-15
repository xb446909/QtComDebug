#ifndef DIALOG_CONNECT_UI_H
#define DIALOG_CONNECT_UI_H

#include <QMainWindow>


namespace Ui {
class dialog_connect_ui;
}

class dialog_connect_ui: public QMainWindow
{
     Q_OBJECT
public:
    explicit dialog_connect_ui(QWidget *parent = 0);
    ~dialog_connect_ui();
private:
   // Ui::dialog_connect_ui *ui;

};

#endif // DIALOG_CONNECT_UI_H
