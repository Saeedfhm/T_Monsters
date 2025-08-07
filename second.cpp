#include "second.h"
#include "ui_second.h"
#include "gallerypage.h"
#include "login.h"

// project done

second::second(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::second)
{
    ui->setupUi(this);


    ui->gallery_btn->setFixedSize(150, 50); // عرض: 100 پیکسل، ارتفاع: 50 پیکسل
    ui->start_btn->setFixedSize(150, 50); // عرض: 100 پیکسل، ارتفاع: 50 پیکسل


    ui->gallery_btn->setStyleSheet(
        "QPushButton {"
        "   background : transparent;"
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
        "   background : transparent;"
        "   border-radius: 15px;"
        "   background-color: #4CAF50;"
        "   padding: 8px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #40a049;" /* تغییر رنگ هنگام هاور */
        "}"
    );

//    ui->gallery_btn->installEventFilter(this);
//    ui->start_btn->installEventFilter(this);


}

second::~second()
{
    delete ui;
}

void second::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
        QWidget *focused = focusWidget();

        if (focused == ui->gallery_btn) {
            on_gallery_btn_clicked();
        }
        else if (focused == ui->start_btn) {
            on_start_btn_clicked();
        }
    }
    QMainWindow::keyPressEvent(event);
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
