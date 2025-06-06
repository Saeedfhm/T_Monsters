#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "second.h"

// project done

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    setFixedSize(1200,800);

    ui->go_btn->setFixedSize(150, 50); // عرض: 100 پیکسل، ارتفاع: 50 پیکسل


    ui->go_btn->setStyleSheet(
        "QPushButton {"
        "   border-radius: 15px;"
        "   background: transparent; "
        "   background-color: #aaa516;"
        "   padding: 8px;"
        "   color: white"
        "}"
        "QPushButton:hover {"
        "   background-color: #aaa510;" /* تغییر رنگ هنگام هاور */
        "}"
    );




}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_go_btn_clicked()
{
    hide();
    second *s = new second ();
    s->show();

}
