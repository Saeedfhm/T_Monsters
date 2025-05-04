#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "game_page.h"

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    ui->game_btn->setFixedSize(80, 30); // عرض: 100 پیکسل، ارتفاع: 50 پیکسل


    ui->game_btn->setStyleSheet(
        "QPushButton {"

        " background:none;"
        " background-color:transparent;"
        "   border-radius: 7px;"
        "   color: white;"
        "   background-color: #030614;"
        "   padding: 8px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #252529;" /* تغییر رنگ هنگام هاور */
        "}"
    );
    ui->P1_name->setStyleSheet(
        "QLineEdit {"
        " background:none;"
        " background-color:transparent;"
        "   border-radius: 7px;"
        "   color: white;"
        "   background-color: #030614;"

        "}"
    );
    ui->P2_name->setStyleSheet(
        "QLineEdit {"
        " background:none;"
        " background-color:transparent;"
        "   border-radius: 7px;"
        "   color: white;"
        "   background-color: #030614;"

        "}"
    );

    gp = new game_page (this);

}

login::~login()
{
    delete ui;
}

//void login::on_game_btn_clicked()
//{
//    hide();
//    MainWindow *m = new MainWindow ();
//    m->show();
//}

//font: 75 italic 31pt "Z003";
//color: rgb(165, 29, 45);

void login::on_game_btn_clicked()
{
    hide();
    QString p1 = ui->P1_name->text();
    QString p2 = ui->P2_name->text();
    gp->set_name(p1,p2);
    gp->show();


}
