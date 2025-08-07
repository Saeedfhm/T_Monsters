#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "second.h"
#include <QKeyEvent>
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
        "   background-color: #515100;"
        "}"
    );




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    // Check for Enter key (ASCII 10 is actually Qt::Key_Return)
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
        on_go_btn_clicked();  // Directly call your button click handler
    }
    QMainWindow::keyPressEvent(event);  // Pass other keys to parent
}

void MainWindow::on_go_btn_clicked()
{
    hide();
    second *s = new second ();
    s->show();

}
