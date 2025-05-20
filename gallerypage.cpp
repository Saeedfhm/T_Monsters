#include "gallerypage.h"
#include "ui_gallerypage.h"
#include "second.h"

gallerypage::gallerypage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gallerypage)
{
    ui->setupUi(this);
//    ui->back_btn->setFixedSize(150, 50); // عرض: 100 پیکسل، ارتفاع: 50 پیکسل

    ui->Billy->setText(
        "<table><tr>"
        "<h2> Billy</h2>"
        "<td><img src=':/Billy.webp' width='64' height='64'></td>"
        "<td style='padding-left:10px;'>"
        "HP: 320<br>"
        "Mobility: 3<br>"
        "Damage: 90<br>"
        "AttackRange: 1"
        "</td>"
        "</tr></table>"
    );

    ui->Reketon->setText(
        "<table><tr>"
        "<h2> Reketon</h2>"
        "<td><img src=':/Reketon.webp' width='64' height='64'></td>"
        "<td style='padding-left:10px;'>"
        "HP: 320<br>"
        "Mobility: 2<br>"
        "Damage: 80<br>"
        "AttackRange: 2"
        "</td>"
        "</tr></table>"
    );

    ui->Angus->setText(
        "<table><tr>"
        "<h2> Angus</h2>"
        "<td><img src=':/Angus.webp' width='64' height='64'></td>"
        "<td style='padding-left:10px;'>"
        "HP: 400<br>"
        "Mobility: 2<br>"
        "Damage: 100<br>"
        "AttackRange: 1"
        "</td>"
        "</tr></table>"
    );

    ui->Duraham->setText(
        "<table><tr>"
        "<h2> Duraham</h2>"
        "<td><img src=':/Duraham.webp' width='64' height='64'></td>"
        "<td style='padding-left:10px;'>"
        "HP: 320<br>"
        "Mobility: 2<br>"
        "Damage: 100<br>"
        "AttackRange: 2"
        "</td>"
        "</tr></table>"
    );

    ui->ColonelBaba->setText(
        "<table><tr>"
        "<h2> ColonelBaba </h2>"
        "<td><img src=':/Colonel_baba.webp' width='64' height='64'></td>"
        "<td style='padding-left:10px;'>"
        "HP: 400<br>"
        "Mobility: 2<br>"
        "Damage: 100<br>"
        "AttackRange: 1"
        "</td>"
        "</tr></table>"
    );

    ui->Medusa->setText(
        "<table><tr>"
        "<h2> Medusa</h2>"
        "<td><img src=':/Medusa.webp' width='64' height='64'></td>"
        "<td style='padding-left:10px;'>"
        "HP: 320<br>"
        "Mobility: 2<br>"
        "Damage: 90<br>"
        "AttackRange: 2"
        "</td>"
        "</tr></table>"
    );

    ui->Bunka->setText(
        "<table><tr>"
        "<h2> Bunka</h2>"
        "<td><img src=':/Bunka.webp' width='64' height='64'></td>"
        "<td style='padding-left:10px;'>"
        "HP: 320<br>"
        "Mobility: 3<br>"
        "Damage: 100<br>"
        "AttackRange: 1"
        "</td>"
        "</tr></table>"
    );

    ui->Sanka->setText(
        "<table><tr>"
        "<h2> Sanka</h2>"
        "<td><img src=':/Sanka.webp' width='64' height='64'></td>"
        "<td style='padding-left:10px;'>"
        "HP: 320<`br>"
        "Mobility: 3<br>"
        "Damage: 100<br>"
        "AttackRange: 1"
        "</td>"
        "</tr></table>"
    );

    ui->kanar->setText(
        "<table><tr>"
        "<h2> kanar</h2>"
        "<td><img src=':/Kanar.webp' width='64' height='64'></td>"
        "<td style='padding-left:10px;'>"
        "HP: 320<`br>"
        "Mobility: 3<br>"
        "Damage: 100<br>"
        "AttackRange: 1"
        "</td>"
        "</tr></table>"
    );

    ui->Sirlimok->setText(
        "<table><tr>"
        "<h2> Reketon</h2>"
        "<td><img src=':/Lamorak.webp' width='64' height='64'></td>"
        "<td style='padding-left:10px;'>"
        "HP: 320<`br>"
        "Mobility: 3<br>"
        "Damage: 100<br>"
        "AttackRange: 1"
        "</td>"
        "</tr></table>"
    );

    ui->Sirlimok->setText(
        "<table><tr>"
        "<h2> Reketon</h2>"
        "<td><img src=':/Kabu.webp' width='64' height='64'></td>"
        "<td style='padding-left:10px;'>"
        "HP: 320<`br>"
        "Mobility: 3<br>"
        "Damage: 100<br>"
        "AttackRange: 1"
        "</td>"
        "</tr></table>"
    );

    ui->Salih->setText(
        "<table><tr>"
        "<h2> Salih</h2>"
        "<td><img src=':/Salih.webp' width='64' height='64'></td>"
        "<td style='padding-left:10px;'>"
        "HP: 320<`br>"
        "Mobility: 3<br>"
        "Damage: 100<br>"
        "AttackRange: 1"
        "</td>"
        "</tr></table>"
    );

    ui->Khan->setText(
        "<table><tr>"
        "<h2> Khan</h2>"
        "<td><img src=':/Khan.webp' width='64' height='64'></td>"
        "<td style='padding-left:10px;'>"
        "HP: 320<`br>"
        "Mobility: 3<br>"
        "Damage: 100<br>"
        "AttackRange: 1"
        "</td>"
        "</tr></table>"
    );

    ui->Boi->setText(
        "<table><tr>"
        "<h2> Boi</h2>"
        "<td><img src=':/Boi.webp' width='64' height='64'></td>"
        "<td style='padding-left:10px;'>"
        "HP: 320<`br>"
        "Mobility: 3<br>"
        "Damage: 100<br>"
        "AttackRange: 1"
        "</td>"
        "</tr></table>"
    );

    ui->Eloi->setText(
        "<table><tr>"
        "<h2> Eloi </h2>"
        "<td><img src=':/Eloi.webp' width='64' height='64'></td>"
        "<td style='padding-left:10px;'>"
        "HP: 320<`br>"
        "Mobility: 3<br>"
        "Damage: 100<br>"
        "AttackRange: 1"
        "</td>"
        "</tr></table>"
    );

    ui->Elsa->setText(
        "<table><tr>"
        "<h2> Elsa </h2>"
        "<td><img src=':/Elsa.webp' width='64' height='64'></td>"
        "<td style='padding-left:10px;'>"
        "HP: 320<`br>"
        "Mobility: 3<br>"
        "Damage: 100<br>"
        "AttackRange: 1"
        "</td>"
        "</tr></table>"
    );

    ui->Karissa->setText(
        "<table><tr>"
        "<h2> Karissa </h2>"
        "<td><img src=':/Karissa.webp' width='64' height='64'></td>"
        "<td style='padding-left:10px;'>"
        "HP: 320<`br>"
        "Mobility: 3<br>"
        "Damage: 100<br>"
        "AttackRange: 1"
        "</td>"
        "</tr></table>"
    );

    ui->Sirphilph->setText(
        "<table><tr>"
        "<h2> Sirphilph </h2>"
        "<td><img src=':/Tusk.webp' width='64' height='64'></td>"
        "<td style='padding-left:10px;'>"
        "HP: 320<`br>"
        "Mobility: 3<br>"
        "Damage: 100<br>"
        "AttackRange: 1"
        "</td>"
        "</tr></table>"
    );

    ui->Frost->setText(
        "<table><tr>"
        "<h2> Frost </h2>"
        "<td><img src=':/Tusk.webp' width='64' height='64'></td>"
        "<td style='padding-left:10px;'>"
        "HP: 320<`br>"
        "Mobility: 3<br>"
        "Damage: 100<br>"
        "AttackRange: 1"
        "</td>"
        "</tr></table>"
    );

    ui->Tusk->setText(
        "<table><tr>"
        "<h2> Tusk </h2>"
        "<td><img src=':/Tusk.webp' width='64' height='64'></td>"
        "<td style='padding-left:10px;'>"
        "HP: 320<`br>"
        "Mobility: 3<br>"
        "Damage: 100<br>"
        "AttackRange: 1"
        "</td>"
        "</tr></table>"
    );

    ui->Rambu->setText(
        "<table><tr>"
        "<h2> Rambu </h2>"
        "<td><img src=':/Rajakal.webp' width='64' height='64'></td>"
        "<td style='padding-left:10px;'>"
        "HP: 320<`br>"
        "Mobility: 3<br>"
        "Damage: 100<br>"
        "AttackRange: 1"
        "</td>"
        "</tr></table>"
    );

    ui->Rajakal->setText(
        "<table><tr>"
        "<h2> Rajakal</h2>"
        "<td><img src=':/Rajakal.webp' width='64' height='64'></td>"
        "<td style='padding-left:10px;'>"
        "HP: 320<`br>"
        "Mobility: 3<br>"
        "Damage: 100<br>"
        "AttackRange: 1"
        "</td>"
        "</tr></table>"
    );

    ui->Sabrina->setText(
        "<table><tr>"
        "<h2> Sabrina</h2>"
        "<td><img src=':/Sabrina.webp' width='64' height='64'></td>"
        "<td style='padding-left:10px;'>"
        "HP: 320<`br>"
        "Mobility: 3<br>"
        "Damage: 100<br>"
        "AttackRange: 1"
        "</td>"
        "</tr></table>"
    );

    ui->Death->setText(
        "<table><tr>"
        "<h2> Death </h2>"
        "<td><img src=':/Sabrina.webp' width='64' height='64'></td>"
        "<td style='padding-left:10px;'>"
        "HP: 320<`br>"
        "Mobility: 3<br>"
        "Damage: 100<br>"
        "AttackRange: 1"
        "</td>"
        "</tr></table>"
    );



//    ui->back_btn->setStyleSheet(
//        "QPushButton {"
//        "   border-radius: 15px;"
//        "   background-color: #470505;"
//        "   color: white;"
//        "   padding: 8px;"
//        "}"
//        "QPushButton:hover {"
//        "   background-color: #983737;" /* تغییر رنگ هنگام هاور */
//        "}"
//    );
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
