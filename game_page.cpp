#include "game_page.h"
#include "ui_game_page.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QObject>
#include <QRandomGenerator>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QString>
#include <QMessageBox>
#include <QTimer>
#include <QFileDialog>
#include <QGraphicsProxyWidget>
#include <waterwalking.h>
#include <grounded.h>
#include <flying.h>
#include <floating.h>
#include "agent.h"

game_page::game_page(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::game_page),
    scene(new QGraphicsScene(this))
{

    setFixedSize(1200, 800);
    setWindowTitle("game");

    ui->setupUi(this);

    ui->start_game->setFixedSize(100, 50);
    ui->start_game->setStyleSheet(
       "QPushButton {"
       "   border-radius: 15px;"
       "   background-color: #4CAF50;"
       "   padding: 8px;"
       "   color: white;"
       "   font: 75 25pt C059;"
       "}"
    );

    ui->load_game_btn->setFixedSize(100, 50);
    ui->load_game_btn->setStyleSheet(
        "QPushButton {"
        "   border-radius: 15px;"
        "   background-color: #4CAF50;"
        "   padding: 8px;"
        "   color: white;"
        "   font: 75 25pt C059;"
        "}"
    );

    ui->vw1->setRenderHint(QPainter::Antialiasing);
    ui->vw1->setScene(scene);
    currentPlayer = 1;
    timeRemaining = 2 * 60;
    selectedAgent = nullptr;
    targetHex = nullptr;
    ui->vw1->setDragMode(QGraphicsView::NoDrag);
    turnTimer = new QTimer(this);
    connect(turnTimer, &QTimer::timeout, this, &game_page::updateTimer);
    startPlayerTurn();
}

game_page::~game_page()
{
    delete ui;
}



void game_page::add_agent(){

    int j = 0;

    for(int i = 0; i < agents_name.size(); i++){
         QString name = agents_name[i];
        if (name.isEmpty()) return;
        agent* a = nullptr;

        if(i < 5) {
            type = 1;
        }
        else {
            type = 2;
        }

        // ------------------- waterwalking agents --------------------

        if (name == "Billy") {
            a = new Waterwalking("Billy", 36, type,this);
            a->set_Hp(320);
            a->set_Mobility(3);
            a->set_Damage(90);
            a->set_AttackRange(1);
            a->set_pixmap(":/Billy.webp");
        }
        else if (name == "Reketon") {
            a = new Waterwalking("Reketon", 36, type,this);
            a->set_Hp(320);
            a->set_Mobility(2);
            a->set_Damage(80);
            a->set_AttackRange(2);
            a->set_pixmap(":/Reketon.webp");
        }
        else if (name == "Angus") {
            a = new Waterwalking("Angus", 36, type,this);
            a->set_Hp(400);
            a->set_Mobility(2);
            a->set_Damage(100);
            a->set_AttackRange(1);
            a->set_pixmap(":/Angus.webp");
        }
        else if (name == "Duraham") {
            a = new Waterwalking("Duraham", 36, type,this);
            a->set_Hp(320);
            a->set_Mobility(2);
            a->set_Damage(100);
            a->set_AttackRange(2);
            a->set_pixmap(":/Duraham.webp");
        }

        else if (name == "Colonel_baba") {
            a = new Waterwalking("Colonel_baba", 36, type,this);
            a->set_Hp(400);
            a->set_Mobility(2);
            a->set_Damage(100);
            a->set_AttackRange(1);
            a->set_pixmap(":/Colonel_baba.webp");
        }

        else if (name == "Medusa") {
            a = new Waterwalking("Medusa", 36, type,this);
            a->set_Hp(320);
            a->set_Mobility(2);
            a->set_Damage(90);
            a->set_AttackRange(2);
            a->set_pixmap(":/Medusa.webp");
           }

        else if (name == "Bunka") {
            a = new Waterwalking("Bunka", 36, type,this);
            a->set_Hp(320);
            a->set_Mobility(3);
            a->set_Damage(100);
            a->set_AttackRange(1);
            a->set_pixmap(":/Bunka.webp");
        }

        else if (name == "Sanka") {
            a = new Waterwalking("Sanka", 36, type,this);
            a->set_Hp(320);
            a->set_Mobility(3);
            a->set_Damage(100);
            a->set_AttackRange(1);
            a->set_pixmap(":/Sanka.webp");
        }
        // ------------------ grounded agents ---------------------
        else if (name == "SirLamorak") {
            a = new grounded("SirLamorak", 36, type,this);
            a->set_Hp(320);
            a->set_Mobility(3);
            a->set_Damage(110);
            a->set_AttackRange(1);
            a->set_pixmap(":/SirLamorak.webp");
        }

        else if (name == "Kabu") {
            a = new grounded("Kabu", 36, type,this);
            a->set_Hp(400);
            a->set_Mobility(2);
            a->set_Damage(120);
            a->set_AttackRange(1);
            a->set_pixmap(":/Kabu.webp");
        }

        else if (name == "Rajakal") {
            a = new grounded("Rajakal", 36, type,this);
            a->set_Hp(320);
            a->set_Mobility(2);
            a->set_Damage(130);
            a->set_AttackRange(1);
            a->set_pixmap(":/Rajakal.webp");
        }

        else if (name == "Salih") {
            a = new grounded("Salih", 36, type,this);
            a->set_Hp(400);
            a->set_Mobility(2);
            a->set_Damage(80);
            a->set_AttackRange(1);
            a->set_pixmap(":/Salih.webp");
        }

        else if (name == "Khan") {
            a = new grounded("Khan", 36, type,this);
            a->set_Hp(320);
            a->set_Mobility(2);
            a->set_Damage(90);
            a->set_AttackRange(1);
            a->set_pixmap(":/Khan.webp");
        }

        else if (name == "Boi") {
            a = new grounded("Boi", 36, type,this);
            a->set_Hp(400);
            a->set_Mobility(2);
            a->set_Damage(100);
            a->set_AttackRange(1);
            a->set_pixmap(":/Boi.webp");
        }

        else if (name == "Eloi") {
            a = new grounded("Eloi", 36, type,this);
            a->set_Hp(240);
            a->set_Mobility(2);
            a->set_Damage(100);
            a->set_AttackRange(2);
            a->set_pixmap(":/Eloi.webp");
        }

        else if (name == "Kanar") {
            a = new grounded("Kanar", 36, type,this);
            a->set_Hp(160);
            a->set_Mobility(2);
            a->set_Damage(100);
            a->set_AttackRange(2);
            a->set_pixmap(":/Kanar.webp");
        }

        else if (name == "Elsa") {
            a = new grounded("Elsa", 36, type,this);
            a->set_Hp(320);
            a->set_Mobility(2);
            a->set_Damage(140);
            a->set_AttackRange(2);
            a->set_pixmap(":/Elsa.webp");
        }

        else if (name == "Karissa") {
            a = new grounded("Karissa", 36, type,this);
            a->set_Hp(280);
            a->set_Mobility(2);
            a->set_Damage(80);
            a->set_AttackRange(2);
            a->set_pixmap(":/Karissa.webp");
        }

        else if (name == "SirPhilip") {
            a = new grounded("SirPhilip", 36, type,this);
            a->set_Hp(400);
            a->set_Mobility(2);
            a->set_Damage(100);
            a->set_AttackRange(1);
            a->set_pixmap(":/SirPhilip.webp");
        }

        else if (name == "Frost") {
            a = new grounded("Frost", 36, type,this);
            a->set_Hp(260);
            a->set_Mobility(2);
            a->set_Damage(80);
            a->set_AttackRange(2);
            a->set_pixmap(":/Frost.webp");
        }

        else if (name == "Tusk") {
            a = new grounded("Tusk", 36, type,this);
            a->set_Hp(400);
            a->set_Mobility(2);
            a->set_Damage(100);
            a->set_AttackRange(1);
            a->set_pixmap(":/Tusk.webp");
        }

        //  ---------------- flying agents ---------------------

        else if (name == "Rambu") {
            a = new flying("Rambu", 36, type,this);
            a->set_Hp(320);
            a->set_Mobility(3);
            a->set_Damage(120);
            a->set_AttackRange(1);
            a->set_pixmap(":/Rambu.webp");
        }

        // ----------------- floating agents --------------------

        else if (name == "Sabrina") {
            a = new floating("Sabrina", 36, type,this);
            a->set_Hp(320);
            a->set_Mobility(3);
            a->set_Damage(100);
            a->set_AttackRange(1);
            a->set_pixmap(":/Sabrina.webp");
        }

        else if (name == "Death") {
            a = new floating("Death", 36, type,this);
            a->set_Hp(240);
            a->set_Mobility(3);
            a->set_Damage(120);
            a->set_AttackRange(2);
            a->set_pixmap(":/Death.webp");

        }

        else {
            QMessageBox::warning(this, "خطا", "این agent شناخته‌شده نیست.");
            return;
        }
        qreal asize = 40;
        qreal x = 0;
        qreal y = 0;
        if(type==1) {
            x = 0;
            y = asize * sqrt(3.0) * (i);
//            agents_name.erase(agents_name.begin() + i);
        }
        else {
            x = 840;
            y = asize * sqrt(3.0) * (j);
//            agents_name.erase(agents_name.begin() + j);
            j++;
        }
        p1_a.append(a);
        a->setPos(x, y);
        scene->addItem(a);

    }
}

void game_page::create_board(){

    hexGrid.resize(HEX_ROWS);
    for (int row = 0; row < HEX_ROWS; ++row) {
        hexGrid[row].resize(HEX_COLS);
    }

    for (int row = 0; row < HEX_ROWS; ++row) {
        for(int col = 0; col < HEX_COLS; col++){
           hexGrid[row][col] = nullptr;
        }
    }

    qreal hexSize = qMin(
        (VIEW_WIDTH-80) / (HEX_COLS * 1.5),
        (VIEW_HEIGHT-80) / ((HEX_ROWS + 0.5) * sqrt(3.0))
    );
    hexSize=36;
    qreal hexWidth = hexSize * 2.0;
    qreal hexHeight = hexSize * sqrt(3.0);

    for (int col = 0; col < HEX_COLS; ++col) {
       for (int row = 0; row < HEX_ROWS - (col % 2); ++row) {
             qreal x = col * hexWidth * 0.75*1.05+200;
             qreal y = hexHeight * (row + 0.5 * (col % 2))*1.05+60;

             int hexType;
             QString text= fgrid[row][col];
             if (text == "1") {
                hexType = 1;
             } else if (text == "2") {
                hexType = 2;
             } else if (text == "~") {
                hexType = 3;
             } else if (text == "#") {
                hexType = 4;
             } else {
                hexType = 5;
             }

             hexagonitem* hex = new hexagonitem(hexSize, hexType, this);

             hex->set_mIshighlight(false);
             hex->set_m_row(row);
             hex->set_m_col(col);

             hex->setPos(x, y);
             scene->addItem(hex);
             hex->setPen(QPen(Qt::white, 1));
             hexGrid[row][col] = {
                 hex
                };
              hexGrid[row][col]->set_x(x);
              hexGrid[row][col]->set_y(y);
              hexGrid[row][col]->Pos.setX(x);
              hexGrid[row][col]->Pos.setY(y);
              hexGrid[row][col]->placed_agent = nullptr;

             }
       }

        for(int row = 0; row < HEX_ROWS; row++){
            for(int cols = 0; cols < HEX_COLS; cols++){
                if (hexGrid[row][cols] == nullptr) continue;
                for(int i = 0; i < 6; i++){
                    int nx;
                    int ny;
                    if(cols%2==0){
                        nx = row +  even[i].first;
                        ny = cols +  even[i].second;
                        if(nx >= 0 && nx < HEX_ROWS && ny >= 0 && ny < HEX_COLS &&
                           hexGrid[nx][ny] != nullptr) {
                            hexGrid[row][cols]->neghibours.append(hexGrid[nx][ny]);
                        }
                        }else {
                        nx = row +  odd[i].first;
                        ny = cols +  odd[i].second;
                        if(nx >= 0 && nx < HEX_ROWS && ny >= 0 && ny < HEX_COLS &&
                           hexGrid[nx][ny] != nullptr) {
                            hexGrid[row][cols]->neghibours.append(hexGrid[nx][ny]);
                        }
                    }
                }
            }
        }
}


void game_page::parse(){

    QString filepath = QFileDialog::getOpenFileName(this, "Select a File", "", "Text Files (*.txt);;All Files (*)");
    QFile file(filepath);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::critical(this , "error" , "connot open file");
        QString timeText = "connot open file";
        ui->Message->setText(timeText);
        return;
     }

     QTextStream in(&file);
     QStringList lines;

     while(!in.atEnd()) lines << in.readLine();
     unsigned long row = 0;
     unsigned long col = 0;

     int j = 0;
     int i = 1;

     hrows = lines.size()/2;
     hcols = lines[0].length()/3;

           qDebug() << "Mouse pressed on hex at row:" << hrows << "col:" << hcols;
           qDebug() << "Mouse pressed on hex at row:" << lines.size() << "col:" << lines[0].length();


     fgrid.resize(hrows);


     for (int row = 0; row < hrows; ++row) {
         fgrid[row].resize(5);
         for (int col = 0; col < 5; ++col) {
             fgrid[row][col]= ' ';
         }
     }



     while(i < lines.size()){
           QString line_e = lines[i];
           QString line_o = lines[i + 1];

           col = 0;
           j = 1;
           while(j < line_e.length()){
                QChar c = line_e[j];
                fgrid[row][col] =c.toLatin1();
                col+=2;
                j +=6;
           }
           col = 1;
           j = 4;
           while(j < line_o.length()){
                fgrid[row][col] = line_o[j];
                col+=2;
                j +=6;
          }

          row++;
          i +=2 ;
     }
      create_board();
      add_agent();

      for (int row = 0; row < HEX_ROWS; row++) {
          for (int col = 0; col < HEX_COLS; col++) {

              if (hexGrid[row][col] == nullptr) continue;

              qDebug() << "hexagon neighbours: row:" << row << "col:" << col;

              for (int i = 0; i < hexGrid[row][col]->neghibours.size(); i++) {
                  hexagonitem* neighbor = hexGrid[row][col]->neghibours[i];
                  if (neighbor != nullptr) {
                      qDebug() << i << ". neighbour at: "
                               << neighbor->get_m_row()
                               << neighbor->get_m_col();
                  } else {
                      qDebug() << i << ". neighbour is nullptr";
                  }
              }
          }
      }
 }

void game_page::set_name(const QString &name1, const QString & name2){

   ui->p1_name->setText(name1);
   ui->p2_name->setText(name2);
}

void game_page::on_load_game_btn_clicked()
{
    parse();
    ui->load_game_btn->setDisabled(true);
}

void game_page::startPlayerTurn()
{
    timeRemaining = 2 * 60;
    updateTimerDisplay();
    turnTimer->start(1000);
    QList<QGraphicsItem*> items = scene->items();
    for (QGraphicsItem* item : items) {
        if (agent* a = dynamic_cast<agent*>(item)) {
            bool isLeftAgent = a->x() < scene->width() / 2;
            a->setEnabled((currentPlayer == 1 && isLeftAgent) || (currentPlayer == 2 && !isLeftAgent));
        }
    }
}

void game_page::updateTimer()
{
    timeRemaining--;
    updateTimerDisplay();

    if (timeRemaining <= 0) {
        turnTimer->stop();
        switchPlayer();
    }
}

void game_page::updateTimerDisplay()
{
    int minutes = timeRemaining / 60;
    int seconds = timeRemaining % 60;
    QString timeText = QString("%1:%2")
    .arg(minutes, 2, 10, QLatin1Char('0'))
    .arg(seconds, 2, 10, QLatin1Char('0'));
    if (currentPlayer == 1) {
        ui->player1Timer->setText(timeText);
    } else {
        ui->player2Timer->setText(timeText);
    }
}

void game_page::switchPlayer()
{
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
    startPlayerTurn();
}

void game_page::agentSelected(agent* selected)
{
     qDebug() << "Agent clicked at power:" << selected->get_power();

     QList<QGraphicsItem*> items = scene->items();
     for (QGraphicsItem* item : items) {
         agent* a = dynamic_cast<agent*>(item);
         if (a) {
             a->Set_IsAselected(false);
         }
     }

     selectedAgent = selected;
     if(selectedAgent->Get_IsAselected()) selectedAgent->Set_IsAselected(false);
     else  selectedAgent->Set_IsAselected(true);
}

void game_page::handleHexagonClick(int row, int col) {
    qDebug() << "Hex clicked at:" << row << "," << col;

    if(hexGrid[row][col]->placed_agent == nullptr && count >= 10 && tempAgent == nullptr) return;

//    if(count > 10){
//        int mob = hexGrid[row][col]->placed_agent->Get_Mobility();
//           bool inraneg = true;
//           for(int i = 0; i < 6 ; i++){
//               int nx = dx[i] + row;
//               int ny = dy[i] + col;
//               if(nx >= 0 && nx < 5 && nx <= mob && ny >= 0 && ny < 9 && ny <= mob){

//               }
//           }

//    }

    if((currentPlayer == 1 && hexGrid[row][col]->owner == 2 && tempAgent== nullptr) || (currentPlayer == 2 && hexGrid[row][col]->owner == 1 && tempAgent== nullptr)) return;
    // ------------ first click after arangment of agents in bord ------------------
     if(hexGrid[row][col]->placed_agent != nullptr && count >= 10 && tempAgent==nullptr) {
         if ((currentPlayer == 1 &&   hexGrid[row][col]->owner == 1) ||
             (currentPlayer == 2 &&   hexGrid[row][col]->owner == 2)) {
                tempAgent = hexGrid[row][col]->placed_agent;
                temph = hexGrid[row][col];
                return;
         }
    }
     if((hexGrid[row][col]->owner == 1 && temph->owner == 1 && count >= 10 ) || (hexGrid[row][col]->owner == 2 && temph->owner == 2 && count >= 10 )){
         ui->Message->setText("Same owner. please chose another hexa");
         tempAgent = nullptr;
         return;
     }
     if(hexGrid[row][col] == temph){
         tempAgent = nullptr;
         return;
     }
     // ------------ second click after arangment of agents(move operation) ------------------
    if(hexGrid[row][col]->placed_agent==nullptr && count >= 10){
        if ((currentPlayer == 1 &&  hexGrid[row][col]->owner == 0) ||
            (currentPlayer == 2 &&  hexGrid[row][col]->owner == 0)) {
                hexGrid[row][col]->placed_agent=tempAgent;
                QString path = hexGrid[row][col]->placed_agent->Get_Name();
                hexGrid[row][col]->set_pixmap(":/" + path + ".webp");
                hexGrid[row][col]->update();
                turnTimer->stop();
                temph->placed_agent = nullptr;
                hexGrid[row][col]->owner = currentPlayer;
                switchPlayer();

                temph->owner = 0;
                tempAgent = nullptr;
                return;
        }
    }

    if (!selectedAgent && count < 10) return;



    // ------------ second click after arangment of agents(attack operation) ----------------------


    if(hexGrid[row][col]->placed_agent!=nullptr && count >= 10){
        if ((currentPlayer == 1 &&  hexGrid[row][col]->owner == 2) ||
            (currentPlayer == 2 &&  hexGrid[row][col]->owner == 1)) {
                int Dam = temph->placed_agent->Get_Damage();
                int hp =  hexGrid[row][col]->placed_agent->Get_Hp();
                hp-=Dam;
                hexGrid[row][col]->placed_agent->set_Hp(hp);
                QString name = hexGrid[row][col]->placed_agent->Get_Name();

                ui->Message->setText("Agent " + name + " Hp:  " + QString::number(hp));

                if(hexGrid[row][col]->placed_agent->Get_Hp() <= 0) {
                    hexGrid[row][col]->placed_agent = nullptr;
                    hexGrid[row][col]->owner = 0;
                    ui->Message->setText("Agent " + name + " died in " + QString::number(row) + " , " + QString::number(col));
                }
                hexGrid[row][col]->update();
                turnTimer->stop();
                switchPlayer();
                agent* t = tempAgent;
                tempAgent = nullptr;
                temph->placed_agent = t;
                return;
        }
    }



    // ------------ first click for arangment of agents in bord ------------------
    if ((currentPlayer == 1 &&  hexGrid[row][col]->get_m_type() == 1) ||
        (currentPlayer == 2 &&  hexGrid[row][col]->get_m_type() == 2)) {

        if(hexGrid[row][col]->placed_agent==nullptr) hexGrid[row][col]->placed_agent = selectedAgent;

        QString path = hexGrid[row][col]->placed_agent->Get_Name();

        hexGrid[row][col]->set_pixmap(":/" + path + ".webp");

        hexGrid[row][col]->owner = currentPlayer;

        hexGrid[row][col]->update();

        selectedAgent->hide();

        selectedAgent = nullptr;

        turnTimer->stop();
        switchPlayer();

        count++;
        qDebug() << "count:" << count;

        return;
        }
}
int game_page::a_size(){
    return agents_name.size();
}

void game_page::handleAgentClick(agent* clickedAgent) {
    agentSelected(clickedAgent);
}

void game_page::set_agents_name(QString name){
    agents_name.append(name);
}

