#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "game_page.h"

namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);

    ~login();

private slots:




    void on_game_btn_clicked();

private:
    Ui::login *ui;
    game_page *gp;



};

#endif // LOGIN_H
