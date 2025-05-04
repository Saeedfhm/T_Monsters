#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "second.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);




    ui->go_btn->setFixedSize(150, 50); // عرض: 100 پیکسل، ارتفاع: 50 پیکسل


    ui->go_btn->setStyleSheet(
        "QPushButton {"
        "   border-radius: 15px;"
        "   background-color: #4CAF50;"
        "   padding: 8px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #45a049;" /* تغییر رنگ هنگام هاور */
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
