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
            background-color: #00aa00;         /* رنگ پس‌زمینه */
            color: #eee;                    /* رنگ متن */
            font-size: 16px;                /* اندازه فونت */
            border: 2px solid #555;         /* حاشیه */
            border-radius: 8px;             /* گرد کردن گوشه‌ها */
        }
        QListWidget::item {
            padding: 10px;                  /* فاصله داخلی هر آیتم */
            border-bottom: 1px solid #444; /* خط جداکننده آیتم‌ها */
        }
        QListWidget::item:selected {
            background-color: #005500;  /* سبز تیره‌تر وقتی انتخاب شده */
            color: white;
            font-weight: bold;
        }
        QListWidget::item:hover {
            background-color: #009900;         /* رنگ پس‌زمینه هنگام هاور */
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

    connect(agentslist, &QListWidget::itemClicked, this, &login::onItemClicked);

    gp = new game_page (this);

    agentslist->hide();

    statusLabel->setStyleSheet("color: green; font-size: 16px; background-color: transparent;");
    statusLabel->move(500 , 200);
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
    agentslist->setWindowTitle("Agent List");
    agentslist->resize(300, 400);

    QVBoxLayout *layout = new QVBoxLayout(agentslist);

    agentslist->setLayout(layout);

    agentslist->show();

    agentslist->move(500 , 300);

    statusLabel->show();

    gp->set_name(p1,p2);
}

void login::onItemClicked(QListWidgetItem *item){
    QString name = item->text();
    add_agent(name);
}

void login::add_agent(QString name){
    if(gp->a_size() < 10 && gp->a_size() + 1 != 10){
        if(gp->a_size() < 5 && gp->a_size() + 1 != 5){
          statusLabel->setText("Turn Player 1");
        }else statusLabel->setText("Turn Player 2");
        gp->set_agents_name(name);
    }else{
        this->hide();
        gp->show();
    }
}

