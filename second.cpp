#include "second.h"
#include "ui_second.h"
#include "gallerypage.h"
#include "login.h"
#include <QGraphicsDropShadowEffect>

// project done

second::second(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::second)
{
    ui->setupUi(this);


    // Gallery Button - CoC Style
    ui->gallery_btn->setFixedSize(210, 50);
    ui->gallery_btn->setStyleSheet(
        "QPushButton {"
        "   border-radius: 8px;"
        "   background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,"
        "                             stop:0 #F9D423, stop:0.5 #E65C00, stop:0.51 #B06B00, stop:1 #8B4E03);"
        "   color: #FFF5D6;"
        "   font: bold 14pt 'Supercell-Magic';"
        "   border: 3px solid;"
        "   border-top-color: #FFE873;"
        "   border-left-color: #D4A017;"
        "   border-right-color: #D4A017;"
        "   border-bottom-color: #8B4E03;"
        "   padding: 8px 20px;"
        "   text-shadow: 1px 1px 2px #000000;"
        "   box-shadow: "
        "       inset 0 2px 4px rgba(255, 232, 115, 0.4),"
        "       inset 0 -3px 6px rgba(139, 78, 3, 0.4),"
        "       0 4px 8px rgba(0, 0, 0, 0.5);"
        "}"
        "QPushButton:hover {"
        "   background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,"
        "                             stop:0 #FFE138, stop:0.5 #FF7B00, stop:0.51 #D18B00, stop:1 #9C5A00);"
        "   border-top-color: #FFED8A;"
        "   box-shadow: "
        "       inset 0 2px 6px rgba(255, 240, 150, 0.5),"
        "       inset 0 -3px 8px rgba(156, 90, 0, 0.5),"
        "       0 6px 12px rgba(0, 0, 0, 0.6);"
        "}"
        "QPushButton:pressed {"
        "   background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,"
        "                             stop:0 #E6B422, stop:0.5 #CC4D00, stop:0.51 #9B6000, stop:1 #6B3D00);"
        "   padding-top: 10px;"
        "   padding-bottom: 6px;"
        "   border-top-color: #D4A017;"
        "   border-bottom-color: #6B3D00;"
        "   box-shadow: "
        "       inset 0 3px 6px rgba(110, 60, 0, 0.6),"
        "       0 2px 4px rgba(0, 0, 0, 0.4);"
        "}"
    );

    // Start Button - Main CoC Button Style (More prominent)
    ui->start_btn->setFixedSize(210, 50);
    ui->start_btn->setStyleSheet(
        "QPushButton {"
        "   border-radius: 10px;"
        "   background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,"
        "                             stop:0 #FFD700, stop:0.4 #FF8C00, stop:0.41 #C76B00, stop:1 #8B4500);"
        "   color: #FFF5D6;"
        "   font: bold 18pt 'Supercell-Magic';"
        "   border: 4px solid;"
        "   border-top-color: #FFEE58;"
        "   border-left-color: #FFC107;"
        "   border-right-color: #FFC107;"
        "   border-bottom-color: #8B4500;"
        "   padding: 12px 30px;"
        "   text-shadow: 1px 1px 3px #000000, -1px -1px 0px rgba(255, 255, 255, 0.3);"
        "   box-shadow: "
        "       inset 0 3px 6px rgba(255, 240, 100, 0.5),"
        "       inset 0 -4px 8px rgba(139, 69, 0, 0.5),"
        "       0 6px 12px rgba(0, 0, 0, 0.7),"
        "       0 0 0 4px rgba(100, 50, 0, 0.3);"
        "}"
        "QPushButton:hover {"
        "   background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,"
        "                             stop:0 #FFE44D, stop:0.4 #FF9E00, stop:0.41 #E07D00, stop:1 #A05200);"
        "   border-top-color: #FFF176;"
        "   box-shadow: "
        "       inset 0 4px 8px rgba(255, 245, 150, 0.6),"
        "       inset 0 -5px 10px rgba(160, 82, 0, 0.6),"
        "       0 8px 16px rgba(0, 0, 0, 0.8),"
        "       0 0 0 4px rgba(120, 60, 0, 0.4);"
        "}"
        "QPushButton:pressed {"
        "   background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,"
        "                             stop:0 #E6C142, stop:0.4 #E67C00, stop:0.41 #B55B00, stop:1 #7A3D00);"
        "   padding-top: 14px;"
        "   padding-bottom: 10px;"
        "   border-top-color: #FFC107;"
        "   border-bottom-color: #7A3D00;"
        "   box-shadow: "
        "       inset 0 5px 10px rgba(122, 61, 0, 0.7),"
        "       0 4px 8px rgba(0, 0, 0, 0.5),"
        "       0 0 0 4px rgba(90, 45, 0, 0.3);"
        "}"
    );

    // Add 3D depth effects
    QGraphicsDropShadowEffect* cocGalleryEffect = new QGraphicsDropShadowEffect();
    cocGalleryEffect->setBlurRadius(15);
    cocGalleryEffect->setColor(QColor(139, 78, 3, 150));
    cocGalleryEffect->setOffset(3, 5);
    ui->gallery_btn->setGraphicsEffect(cocGalleryEffect);

    QGraphicsDropShadowEffect* cocStartEffect = new QGraphicsDropShadowEffect();
    cocStartEffect->setBlurRadius(20);
    cocStartEffect->setColor(QColor(139, 69, 0, 180));
    cocStartEffect->setOffset(4, 7);
    ui->start_btn->setGraphicsEffect(cocStartEffect);


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
