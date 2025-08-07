#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "game_page.h"
#include <QListWidgetItem>
#include <QMessageBox>
#include <QLabel>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QGraphicsDropShadowEffect>
#include <QMainWindow>
#include <QDebug>  // Add this with your other includes
// project done

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->game_btn->setFixedSize(80, 30);
    setFixedSize(1200, 800);

    ui->P1_name->setFocusPolicy(Qt::StrongFocus);
    ui->P2_name->setFocusPolicy(Qt::StrongFocus);

    agentslist = new QListWidget(this);

    ui->game_btn->setFocusPolicy(Qt::StrongFocus);

    setTabOrder(ui->P1_name, ui->P2_name);

    // Player 1 Agents List - Monster Team Blue
    ui->agents1->setStyleSheet(
        "QListWidget {"
        "   background: transparent;"
        "   background-color: rgba(10, 20, 40, 0.9);"
        "   border-radius: 10px;"
        "   border: 3px groove #3a7bd5;"
        "   color: #a7d8ff;"
        "   font: bold 14pt 'Franklin Gothic Medium';"
        "   padding: 8px;"
        "}"
        "QListWidget::item {"
        "   background-color: rgba(20, 40, 80, 0.5);"
        "   border-radius: 5px;"
        "   margin: 3px;"
        "   padding: 8px;"
        "   border-bottom: 1px solid #3a7bd5;"
        "}"
        "QListWidget::item:hover {"
        "   background-color: rgba(58, 123, 213, 0.3);"
        "   border-left: 3px solid #3a7bd5;"
        "}"
        "QListWidget::item:selected {"
        "   background-color: rgba(58, 123, 213, 0.5);"
        "   color: #ffffff;"
        "   border-left: 3px solid #00d2ff;"
        "}"
    );

    // Player 2 Agents List - Monster Team Red
    ui->agents2->setStyleSheet(
        "QListWidget {"
        "   background: transparent;"
        "   background-color: rgba(40, 10, 20, 0.9);"
        "   border-radius: 10px;"
        "   border: 3px groove #d53a7b;"
        "   color: #ffa7d8;"
        "   font: bold 14pt 'Franklin Gothic Medium';"
        "   padding: 8px;"
        "}"
        "QListWidget::item {"
        "   background-color: rgba(80, 20, 40, 0.5);"
        "   border-radius: 5px;"
        "   margin: 3px;"
        "   padding: 8px;"
        "   border-bottom: 1px solid #d53a7b;"
        "}"
        "QListWidget::item:hover {"
        "   background-color: rgba(213, 58, 123, 0.3);"
        "   border-left: 3px solid #d53a7b;"
        "}"
        "QListWidget::item:selected {"
        "   background-color: rgba(213, 58, 123, 0.5);"
        "   color: #ffffff;"
        "   border-left: 3px solid #ff00d4;"
        "}"
    );

    // Add monster-themed effects
    QGraphicsDropShadowEffect* p1Shadow = new QGraphicsDropShadowEffect();
    p1Shadow->setBlurRadius(15);
    p1Shadow->setColor(QColor(0, 210, 255, 150));
    p1Shadow->setOffset(2, 2);
    ui->agents1->setGraphicsEffect(p1Shadow);

    QGraphicsDropShadowEffect* p2Shadow = new QGraphicsDropShadowEffect();
    p2Shadow->setBlurRadius(15);
    p2Shadow->setColor(QColor(255, 0, 212, 150));
    p2Shadow->setOffset(2, 2);
    ui->agents2->setGraphicsEffect(p2Shadow);

    agentslist->addItem("Billy");
    agentslist->addItem("Reketon");
    agentslist->addItem("Angus");
    agentslist->addItem("Duraham");
    agentslist->addItem("Colonel_baba");
    agentslist->addItem("Medusa");
    agentslist->addItem("Bunka");
    agentslist->addItem("Sanka");
    agentslist->addItem("SirLamorak");
    agentslist->addItem("Kabu");
    agentslist->addItem("Salih");
    agentslist->addItem("Khan");
    agentslist->addItem("Boi");
    agentslist->addItem("Eloi");
    agentslist->addItem("Kanar");
    agentslist->addItem("Elsa");
    agentslist->addItem("Karissa");
    agentslist->addItem("SirPhilip");
    agentslist->addItem("Frost");
    agentslist->addItem("Tusk");
    agentslist->addItem("Rambu");
    agentslist->addItem("Sabrina");
    agentslist->addItem("Death");

//    agentslist->setStyleSheet(R"(
//        QListWidget {
//        background: qlineargradient(
//          x1: 0, y1: 0, x2: 1, y2: 0,
//          stop: 0 #667eea, stop: 1 #764ba2
//        );
//        color: #eee;
//        font-size: 16px;
//        border: 2px solid #555;
//        border-radius: 8px;
//        }
//        QListWidget::item {
//        padding: 10px;
//        border-bottom: 1px solid #444;
//        }
//        QListWidget::item:selected {
//        background-color: rgba(255, 255, 255, 0.15);
//        border-style: none;
//        }
//        QListWidget::item:hover {
//        background-color: rgba(255, 255, 255, 0.2);
//        border: none;
//        }
//    )");


    agentslist->setStyleSheet(
        "QListWidget {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #0F2027, stop:1 #2C5364);"
        "   color: #00FFAA;"
        "   font-size: 16px;"
        "   border: 2px solid #00FFFF;"
        "   border-radius: 8px;"
        "}"
        "QListWidget::item {"
        "   padding: 10px;"
        "   border-bottom: 1px solid rgba(0, 255, 255, 0.3);"
        "}"
        "QListWidget::item:selected {"
        "   background-color: rgba(255, 0, 255, 0.3);"
        "   color: white;"
        "}"
        "QListWidget::item:hover {"
        "   background-color: rgba(0, 255, 255, 0.2);"
        "}"
    );


    // Game button with gradient and animation
    ui->game_btn->setStyleSheet(
        "QPushButton {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #FF416C, stop:1 #FF4B2B);"
        "   border-radius: 7px;"
        "   color: white;"
        "   font-weight: bold;"
        "   padding: 5px;"
        "   border: 2px solid #FF4B2B;"
        "}"
        "QPushButton:hover {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #FF4B2B, stop:1 #FF416C);"
        "   border: 2px solid #FF8C00;"
        "}"
        "QPushButton:pressed {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #E04040, stop:1 #D12B2B);"
        "}"
    );

    ui->go_to_gamepage->setStyleSheet(
        "QPushButton {"
        "   background: rgb(85, 0, 0);"
        "   border-radius: 7px;"
        "   color: white;"
        "   font-weight: bold;"
        "   padding: 5px;"
        "   border: 2px solid #FF4B2B;"
        "}"
        "QPushButton:hover {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #FF4B2B, stop:1 #FF416C);"
        "   border: 2px solid #FF8C00;"
        "}"
        "QPushButton:pressed {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #E04040, stop:1 #D12B2B);"
        "}"
    );


    // Player 1 input with futuristic style
    ui->P1_name->setStyleSheet(
        "QLineEdit {"
        "   background-color: rgba(0, 10, 30, 0.7);"
        "   border-radius: 7px;"
        "   color: #00FFFF;"
        "   border: 2px solid #00BFFF;"
        "   padding: 5px;"
        "   font-weight: bold;"
        "   selection-background-color: #FF00FF;"
        "}"
        "QLineEdit:hover {"
        "   border: 2px solid #00FFFF;"
        "   background-color: rgba(0, 20, 40, 0.8);"
        "}"
        "QLineEdit:focus {"
        "   border: 2px solid #FF00FF;"
        "   background-color: rgba(0, 30, 50, 0.9);"
        "}"
    );

    // Player 2 input with complementary futuristic style
    ui->P2_name->setStyleSheet(
        "QLineEdit {"
        "   background-color: rgba(30, 0, 20, 0.7);"
        "   border-radius: 7px;"
        "   color: #FF00FF;"
        "   border: 2px solid #FF1493;"
        "   padding: 5px;"
        "   font-weight: bold;"
        "   selection-background-color: #00FFFF;"
        "}"
        "QLineEdit:hover {"
        "   border: 2px solid #FF00FF;"
        "   background-color: rgba(40, 0, 30, 0.8);"
        "}"
        "QLineEdit:focus {"
        "   border: 2px solid #00FFFF;"
        "   background-color: rgba(50, 0, 40, 0.9);"
        "}"
    );

    ui->go_to_gamepage->hide();

    qDebug() << "Current focus:" << this->focusWidget();


    // Add this to your window constructor
    QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect();
    shadowEffect->setBlurRadius(15);
    shadowEffect->setColor(QColor(255, 0, 255, 150));
    shadowEffect->setOffset(3, 3);
    ui->game_btn->setGraphicsEffect(shadowEffect);

    ui->title->setStyleSheet("background: transparent; color: #550000; font-size: 20pt;");
    ui->title->adjustSize();
    connect(agentslist, &QListWidget::itemClicked, this, &login::onItemClicked);

    gp = new game_page (this);

    agentslist->hide();

    ui->statusLabel->setStyleSheet(
       "background: transparent;"
       "color: #25004f; "
       "font-size: 25px; "
       "background-color: transparent;"
);
    ui->statusLabel->setWordWrap(true);
}

login::~login()
{
    delete ui;
}

void login::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Key pressed:" << event->key();

    // Handle Enter key
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
        if (!is_agents_choose) {
            on_game_btn_clicked();
            event->accept();
            return;
        }
        else if (ui->P1_name->text().isEmpty()) {
            ui->P2_name->setFocus();
            event->accept();
            return;
        }
        else if (gp && gp->a_size() >= 10) {
            on_go_to_gamepage_clicked();
            event->accept();
            return;
        }
    }

    // Handle PageUp/PageDown navigation
    if (event->key() == Qt::Key_PageUp) {
        if (ui->P1_name->isEnabled()) {
            ui->P1_name->setFocus();
            ui->P1_name->selectAll();
            event->accept();
            return;
        }
    }
    else if (event->key() == Qt::Key_PageDown) {
        if (ui->P2_name->isEnabled()) {
            ui->P2_name->setFocus();
            ui->P2_name->selectAll();
            event->accept();
            return;
        }
    }

    QMainWindow::keyPressEvent(event);
}

void login::on_game_btn_clicked(){
    if(ui->P1_name->text() == "" || ui->P2_name->text() == ""){
        QMessageBox::warning(this , "error" , "Please Fill Everything");
        return;
    }

    QString p1 = ui->P1_name->text();
    QString p2 = ui->P2_name->text();
    ui->widget->hide();
    agentslist->resize(600, 400);

    QVBoxLayout *layout = new QVBoxLayout(agentslist);

    agentslist->setLayout(layout);

    agentslist->show();

    ui->statusLabel->setText("Turn Player 1");

    agentslist->move(300 , 300);


    gp->set_name(p1,p2);

    ui->agents1->addItem(p1);
    ui->agents1->addItem("-----------------------");
    ui->agents2->addItem(p2);
    ui->agents2->addItem("-----------------------");

    is_agents_choose = true;
}

void login::onItemClicked(QListWidgetItem *item) {
    QString name = item->text();

    // Determine whose turn it is (first 5 for Player 1, next 5 for Player 2)
    Turn = (gp->a_size() < 5) ? 1 : 2;

    QVector<QString> agents = gp->set_agents_in_login();

    if(gp->a_size() < 10 && !is_Done) {
        // Check for duplicates - only within the current player's selections
        int start = (Turn == 1) ? 0 : 5;
        int end = (Turn == 1) ? 5 : 10;

        for (int i = start; i < end && i < agents.size(); i++) {
            if(agents[i] == name) {
                ui->statusLabel->setText("You've already chosen this agent.");
                return;
            }
        }

        if(Turn == 1) {
            Player_1_agents += name + "\n";
            ui->agents1->addItem(name);

            if(gp->a_size() + 1 == 5) {
                ui->statusLabel->setText("Turn Player 2");
            }
        }
        else {
            Player_2_agents += name + "\n";
            ui->agents2->addItem(name);
        }

        gp->set_agents_name(name);

        if(gp->a_size() == 10) {
            is_Done = true;
            agentslist->hide();
            ui->go_to_gamepage->show();
        }
    }
}

void login::on_go_to_gamepage_clicked()
{
    this->hide();
    gp->show();
}
