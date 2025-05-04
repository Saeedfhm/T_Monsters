#include "gallerypage.h"
#include "ui_gallerypage.h"
#include "second.h"

gallerypage::gallerypage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gallerypage)
{
    ui->setupUi(this);\
    ui->back_btn->setFixedSize(150, 50); // عرض: 100 پیکسل، ارتفاع: 50 پیکسل


    ui->back_btn->setStyleSheet(
        "QPushButton {"
        "   border-radius: 15px;"
        "   background-color: #470505;"
        "   color: white;"
        "   padding: 8px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #983737;" /* تغییر رنگ هنگام هاور */
        "}"
    );
}

gallerypage::~gallerypage()
{
    delete ui;
}

void gallerypage::on_back_btn_clicked()
{
    hide();
    second *s = new second();
    s->show();

}
