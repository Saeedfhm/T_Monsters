#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "second.h"
#include <QKeyEvent>
#include <QGraphicsDropShadowEffect>
#include <QPropertyAnimation>
// project done

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    setFixedSize(1200,800);

    ui->go_btn->setFixedSize(180, 60); // Slightly larger for better presence
    ui->go_btn->setStyleSheet(
        "QPushButton {"
        "   border-radius: 18px;"
        "   background: qradialgradient("
        "       cx:0.5, cy:0.5, radius: 0.8,"
        "       fx:0.4, fy:0.4,"
        "       stop:0 #FFD700, stop:0.8 #D4AF37, stop:1 #AA8516);"
        "   color: #FFFFFF;"
        "   font: bold 16pt 'Comic Sans MS';" // Playful yet readable font
        "   padding: 12px 24px;"
        "   border: 3px solid #FFEE99;"
        "   text-shadow: 1px 1px 2px rgba(0,0,0,0.3);"
        "   box-shadow: "
        "       0 4px 8px rgba(170, 133, 22, 0.3),"
        "       inset 0 2px 4px rgba(255, 255, 255, 0.4);"
        "   transition: all 0.3s cubic-bezier(0.25, 0.8, 0.25, 1);"
        "}"
        "QPushButton:hover {"
        "   background: qradialgradient("
        "       cx:0.5, cy:0.5, radius: 0.9,"
        "       fx:0.4, fy:0.4,"
        "       stop:0 #FFE44D, stop:0.8 #E6C035, stop:1 #C9A116);"
        "   border: 3px solid #FFFFCC;"
        "   box-shadow: "
        "       0 6px 12px rgba(201, 161, 22, 0.4),"
        "       inset 0 3px 6px rgba(255, 255, 255, 0.5);"
        "   transform: translateY(-2px);"
        "}"
        "QPushButton:pressed {"
        "   background: qradialgradient("
        "       cx:0.5, cy:0.5, radius: 0.7,"
        "       fx:0.4, fy:0.4,"
        "       stop:0 #D4AF37, stop:0.8 #AA8516, stop:1 #8A6D0B);"
        "   border: 3px solid #EEDD82;"
        "   box-shadow: "
        "       0 2px 4px rgba(138, 109, 11, 0.3),"
        "       inset 0 4px 8px rgba(0, 0, 0, 0.2);"
        "   transform: translateY(1px);"
        "   padding-top: 13px;"
        "   padding-bottom: 11px;"
        "}"
    );

    // Add adorable twinkling effect
    QGraphicsDropShadowEffect* glowEffect = new QGraphicsDropShadowEffect();
    glowEffect->setBlurRadius(20);
    glowEffect->setColor(QColor(255, 215, 0, 150));
    glowEffect->setOffset(0, 0);
    ui->go_btn->setGraphicsEffect(glowEffect);

    // Optional: Add pulsing animation for extra charm
    QPropertyAnimation* pulseAnim = new QPropertyAnimation(glowEffect, "blurRadius");
    pulseAnim->setDuration(2000);
    pulseAnim->setLoopCount(-1); // Infinite
    pulseAnim->setKeyValueAt(0, 20);
    pulseAnim->setKeyValueAt(0.5, 25);
    pulseAnim->setKeyValueAt(1, 20);
    pulseAnim->start();




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
