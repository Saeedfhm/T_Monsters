#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "game_page.h"
#include <QListWidgetItem>
login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->game_btn->setFixedSize(80, 30); // عرض: 100 پیکسل، ارتفاع: 50 پیکسل
    setFixedSize(1200, 800);

    agentslist = new QListWidget(this);

    agentslist->addItem("Billy");
    agentslist->addItem("Reketon");
    agentslist->addItem("Angus");
    agentslist->addItem("Duraham");
    agentslist->addItem("Colonel Baba");
    agentslist->addItem("Medusa");
    agentslist->addItem("Bunka");
    agentslist->addItem("Sanka");
    agentslist->addItem("Sir Lamorak");
    agentslist->addItem("Kabu");
    agentslist->addItem("Salih");
    agentslist->addItem("Khan");
    agentslist->addItem("Boi");
    agentslist->addItem("Eloi");
    agentslist->addItem("Kanar");
    agentslist->addItem("Elsa");
    agentslist->addItem("Karissa");
    agentslist->addItem("Sir Philip");
    agentslist->addItem("Frost");
    agentslist->addItem("Tusk");
    agentslist->addItem("Rambu");
    agentslist->addItem("Sabrina");
    agentslist->addItem("Death");

    agentslist->setStyleSheet(R"(
        QListWidget {
        background: qlineargradient(
          x1: 0, y1: 0, x2: 1, y2: 0,
          stop: 0 #667eea, stop: 1 #764ba2
        );
        color: #eee;
        font-size: 16px;
        border: 2px solid #555;
        border-radius: 8px;
        }
        QListWidget::item {
        padding: 10px;
        border-bottom: 1px solid #444;
        }
        QListWidget::item:selected {
        background-color: rgba(255, 255, 255, 0.15);
        border-style: none;
        }
        QListWidget::item:hover {
        background-color: rgba(255, 255, 255, 0.2);
        border: none;
        }
    )");


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

void login::on_game_btn_clicked()
{

    QString p1 = ui->P1_name->text();
    QString p2 = ui->P2_name->text();
    ui->widget->hide();
    agentslist->resize(300, 400);

    QVBoxLayout *layout = new QVBoxLayout(agentslist);

    agentslist->setLayout(layout);

    agentslist->show();

    ui->statusLabel->setText("Turn Player 1");

    agentslist->move(400 , 300);

    gp->set_name(p1,p2);
}

void login::onItemClicked(QListWidgetItem *item){
    QString name = item->text();
    if(gp->a_size() < 10 && gp->a_size() + 1 != 10){
        if(gp->a_size() > 4){
               ui->statusLabel->setText("Turn Player 2");
        }
        gp->set_agents_name(name);
    }
    else if(gp->a_size() + 1 == 10){
        gp->set_agents_name(name);
        this->hide();
        gp->show();
    }
}

