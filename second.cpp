#include "second.h"
#include "ui_second.h"
#include "gallerypage.h"
#include "login.h"

second::second(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::second)
{
    ui->setupUi(this);


    ui->gallery_btn->setFixedSize(150, 50); // عرض: 100 پیکسل، ارتفاع: 50 پیکسل
    ui->start_btn->setFixedSize(150, 50); // عرض: 100 پیکسل، ارتفاع: 50 پیکسل


    ui->gallery_btn->setStyleSheet(
        "QPushButton {"
        "   border-radius: 15px;"
        "   background-color: #4CAF50;"
        "   padding: 8px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #40a049;" /* تغییر رنگ هنگام هاور */
        "}"
    );

    ui->start_btn->setStyleSheet(
        "QPushButton {"
        "   border-radius: 15px;"
        "   background-color: #4CAF50;"
        "   padding: 8px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #40a049;" /* تغییر رنگ هنگام هاور */
        "}"
    );


}

second::~second()
{
    delete ui;
}

void second::on_gallery_btn_clicked()
{
    hide();
    gallerypage *g = new gallerypage ();
    g->show();
}

void second::on_start_btn_clicked()
{
    hide();
    login *log = new login ();
    log->show();

}
