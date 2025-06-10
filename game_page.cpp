#include "ui_game_page.h"
#include "game_page.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QtMultimedia>
#include <QSoundEffect>
#include <QDebug>
#include <QVector>
#include <algorithm>
#include <QObject>
#include <QRandomGenerator>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QQueue>
#include <QPair>
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

// project done

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
//    connect(turnTimer, &QTimer::timeout, this, &game_page::updateTimer);
//    startPlayerTurn();
    if(count == 10) ui->Message->setText("Pls click start button to start the game");
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
        }
        else {
            x = 840;
            y = asize * sqrt(3.0) * (j);
            j++;
        }
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

void game_page::parse(const QString &filepath){

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
    int r = rand() % 8 + 1;
    parse("D:/barname_sazi/project(c++)/tacticalmonster2025_f2_v2/grid" + QString::number(r) + ".txt");
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
        ui->Message->setText("Time Finished!!!");
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
    if(count >= 10) startPlayerTurn();
}

void game_page::agentSelected(agent* selected)
{


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

void game_page::removerange(){
    for (int i = 0; i < 5; ++i){

        for (int j = 0; j < 9; ++j)
            if (hexGrid[i][j] != nullptr) {
                hexGrid[i][j]->is_inRange = false;
                hexGrid[i][j]->is_inAttackRange = false;
                hexGrid[i][j]->update();
            }
        }
}

void game_page::replacement(int row, int col, hexagonitem *h, agent* attacker) {
    if (!attacker) return;

    for (hexagonitem* neighbor : h->neghibours) {
        agent* other = neighbor->placed_agent;
        if (other != nullptr && other != attacker) {
            return;
        }
    }

    if(hexGrid[row][col]->placed_agent == nullptr) return;

    QVector<QVector<bool>> visited(5, QVector<bool>(9, false));
    QQueue<hexagonitem*> q;

    q.push_back(hexGrid[row][col]);
    visited[row][col] = true;

    QVector<hexagonitem*> candidates;

    while (!q.isEmpty()) {
        hexagonitem* current = q.front();
        q.pop_front();

        for (hexagonitem* neighbor : current->neghibours) {
            int nrow = neighbor->get_m_row();
            int ncol = neighbor->get_m_col();

            if (!visited[nrow][ncol]) {
                visited[nrow][ncol] = true;

                int type = neighbor->get_m_type();
                bool can_stay = true;

                if (type == 3 && !attacker->stay_water()) can_stay = false;
                if (type == 4 && !attacker->stay_mountain()) can_stay = false;
                if (type == 5 && !attacker->stay_ground()) can_stay = false;

                if (can_stay && neighbor->placed_agent == nullptr) {
                    candidates.push_back(neighbor); // خانه‌های معتبر
                }

                q.push_back(neighbor);
            }
        }
    }

    if (candidates.isEmpty()) {
        if (ui && ui->Message)
            ui->Message->setText("جایگزینی ممکن نیست - جایی مناسب برای این agent یافت نشد.");
        return;
    }

    int minDist = INT_MAX;
    hexagonitem* bestTarget = nullptr;

    for (hexagonitem* target : candidates) {
        QVector<QVector<bool>> visited(5, QVector<bool>(9, false));
        QVector<QVector<int>> dist(5, QVector<int>(9, 0));
        QQueue<hexagonitem*> q1;

        int sr = h->get_m_row();
        int sc = h->get_m_col();
        visited[sr][sc] = true;

        q1.push_back(h);

        while (!q1.isEmpty()) {
            hexagonitem* current = q1.front();
            q1.pop_front();

            int r = current->get_m_row();
            int c = current->get_m_col();

            for (hexagonitem* neighbor : current->neghibours) {
                int nr = neighbor->get_m_row();
                int nc = neighbor->get_m_col();

                if (!visited[nr][nc]) {
                    visited[nr][nc] = true;
                    dist[nr][nc] = dist[r][c] + 1;

                    if (neighbor == target) {
                        if (dist[nr][nc] < minDist) {
                            minDist = dist[nr][nc];
                            bestTarget = neighbor;
                        }
                    } else {
                        q1.push_back(neighbor);
                    }
                }
            }
        }
    }

    if (bestTarget) {
        int tr = bestTarget->get_m_row();
        int tc = bestTarget->get_m_col();
        bestTarget->placed_agent = attacker;
        h->placed_agent = nullptr;
        h->set_pixmap("");
        h->owner = 0;

        hexGrid[tr][tc]->owner = (currentPlayer == 1 ? 2 : 1);
        QString path = attacker->Get_Name();
        hexGrid[tr][tc]->set_pixmap(":/" + path + ".webp");
        hexGrid[tr][tc]->update();
    } else {
        if (ui && ui->Message)
            ui->Message->setText("جایگزینی ممکن نیست - مسیر مناسب پیدا نشد.");
    }
}

void game_page::showVictoryScene(int winner) {
    // 1. پیام متنی
    QGraphicsTextItem* victoryText = new QGraphicsTextItem();
    victoryText->setPlainText("🏆 Player " + QString::number(winner) + " Wins! 🏆");
    victoryText->setDefaultTextColor(Qt::yellow);
    victoryText->setFont(QFont("Montserrat", 40, QFont::Bold));
    victoryText->setZValue(1000);
    victoryText->setPos(150, 180);
    scene->addItem(victoryText);

    // 2. افکت شفافیت
    QGraphicsOpacityEffect* effect = new QGraphicsOpacityEffect();
    victoryText->setGraphicsEffect(effect);

    QPropertyAnimation* animation = new QPropertyAnimation(effect, "opacity");
    animation->setDuration(2000);
    animation->setStartValue(0.0);
    animation->setEndValue(1.0);
    animation->setEasingCurve(QEasingCurve::OutCubic);
    animation->start(QAbstractAnimation::DeleteWhenStopped);

    // 3. صدای پیروزی
    QSoundEffect* victorySound = new QSoundEffect(this);
    victorySound->setSource(QUrl::fromLocalFile(":/sounds/orchestral-win-331233.wav"));
    victorySound->setVolume(0.8);
    victorySound->play();

    // 4. دکمه "بازی مجدد"
    //    QPushButton* replayButton = new QPushButton("بازی مجدد", this);
    //    replayButton->setGeometry(200, 300, 120, 40);
    //    replayButton->show();
    //    connect(replayButton, &QPushButton::clicked, this, &game_page::resetGame);

    QPushButton* exitButton = new QPushButton("خروج", this);
    exitButton->setGeometry(540, 380, 120, 40);
    exitButton->show();

    connect(exitButton, &QPushButton::clicked, this, &QWidget::close);

    // پایان بازی
    gameOver = true;
    turnTimer->stop();
}

void game_page::BFS(int r , int c , int mb , int ar){
    QVector<QVector<hexagonitem*>> parent(5, QVector<hexagonitem*>(9, nullptr));
    QVector<QVector<bool>> visited(5 , QVector<bool>(9 , false));
    QVector<QVector<int>> dist(5 , QVector<int>(9 , 0));
    QQueue <hexagonitem *> q;


    if(hexGrid[r][c]->placed_agent==nullptr) return;

    bool walkwater = hexGrid[r][c]->placed_agent->walk_water();
    bool walkmountain = hexGrid[r][c]->placed_agent->walk_mountain();
    bool walkground = hexGrid[r][c]->placed_agent->walk_ground();

    q.push_back(hexGrid[r][c]);

    visited[r][c] = true;
    while(!q.empty()){
        hexagonitem* p = q.front();
        q.pop_front();
        for(int i = 0; i < p->neghibours.size(); i++){
            int row = p->get_m_row();
            int col = p->get_m_col();
            hexagonitem* n = p->neghibours[i];
            int nrow = n->get_m_row();
            int ncol = n->get_m_col();
            bool can_walk = true;

            if(visited[nrow][ncol] == false){
                visited[nrow][ncol] = true;
                parent[nrow][ncol] = p;
                dist[nrow][ncol] = dist[row][col] + 1;
                if(hexGrid[nrow][ncol]->get_m_type() == 6){
                    can_walk = false;
                }
                if(hexGrid[nrow][ncol]->get_m_type() == 3){
                    if(!walkwater) can_walk = false;
                }

                if(hexGrid[nrow][ncol]->get_m_type() == 4){
                    if(!walkmountain) can_walk = false;
                }

                if(hexGrid[nrow][ncol]->get_m_type() == 5){
                    if(!walkground) can_walk = false;
                }

                bool can_stay = true;
                if(hexGrid[nrow][ncol]->get_m_type() == 3 && hexGrid[r][c]->placed_agent && !hexGrid[r][c]->placed_agent->stay_water()) can_stay = false;
                if(hexGrid[nrow][ncol]->get_m_type() == 4 && hexGrid[r][c]->placed_agent && !hexGrid[r][c]->placed_agent->stay_mountain()) can_stay = false;
                if(hexGrid[nrow][ncol]->get_m_type() == 5 && hexGrid[r][c]->placed_agent && !hexGrid[r][c]->placed_agent->stay_ground()) can_stay = false;

                if(dist[nrow][ncol] <= mb && hexGrid[nrow][ncol]->placed_agent==nullptr && can_walk){
                    q.push_back(n);
                    if(can_stay) hexGrid[nrow][ncol]->is_inRange = true;
                    else hexGrid[nrow][ncol]->is_inRange = false;
                }
                if(dist[nrow][ncol] <= ar && hexGrid[nrow][ncol]->placed_agent && hexGrid[nrow][ncol]->owner!=currentPlayer) hexGrid[nrow][ncol]->is_inAttackRange = true;
                hexGrid[nrow][ncol]->update();
            }
        }
    }
}

void game_page::handleHexagonClick(int row, int col) {
    qDebug() << "Hex clicked at:" << row << "," << col;

    if (count < 10) {
        // جلوگیری از گذاشتن agent روی agentهای قبلی خودی
        if (hexGrid[row][col]->placed_agent != nullptr) {
            ui->Message->setText("Hexagon already occupied. Choose another one.");
            return;
        }
    }

    if(hexGrid[row][col]->placed_agent == nullptr && count >= 10 && tempAgent == nullptr) return;

    if((currentPlayer == 1 && hexGrid[row][col]->owner == 2 && tempAgent== nullptr) || (currentPlayer == 2 && hexGrid[row][col]->owner == 1 && tempAgent== nullptr)) return;
    // ------------ first click after arangment of agents in bord ------------------
     if(hexGrid[row][col]->placed_agent != nullptr && count >= 10 && tempAgent==nullptr) {
         if(ui->start_game->isEnabled()){
            ui->Message->setText("You have not Start the game");
            return;
         }
         if ((currentPlayer == 1 &&   hexGrid[row][col]->owner == 1) ||
             (currentPlayer == 2 &&   hexGrid[row][col]->owner == 2)) {
                temph = hexGrid[row][col];
                tempAgent = hexGrid[row][col]->placed_agent;
                int mb = hexGrid[row][col]->placed_agent->Get_Mobility();
                int ar = hexGrid[row][col]->placed_agent->Get_AttackRange();
                BFS(row , col , mb , ar);
                return;
         }
    }

     if((hexGrid[row][col]->owner == 1 && temph->owner == 1 && count >= 10 ) || (hexGrid[row][col]->owner == 2 && temph->owner == 2 && count >= 10 )){
         removerange();
         ui->Message->setText("Same owner. please chose another hexa");
         tempAgent = nullptr;
         return;
     }

     if(hexGrid[row][col] == temph){
         removerange();
         tempAgent = nullptr;
         return;
     }

     // ------------ second click after arangment of agents(move operation) ------------------
    if(hexGrid[row][col]->placed_agent==nullptr && count >= 10){
        if ((currentPlayer == 1 &&  hexGrid[row][col]->owner == 0 && hexGrid[row][col]->is_inRange) ||
            (currentPlayer == 2 &&  hexGrid[row][col]->owner == 0 && hexGrid[row][col]->is_inRange)) {

                bool staywater = temph->placed_agent->stay_water();
                bool staymountain = temph->placed_agent->stay_mountain();
                bool stayground = temph->placed_agent->stay_ground();

                bool c1 = true;
                bool c2 = true;
                bool c3 = true;

                if(hexGrid[row][col]->get_m_type() == 3){
                    if(!staywater) c1 = false;
                }

                if(hexGrid[row][col]->get_m_type() == 4){
                    if(!staymountain) c2 = false;
                }

                if(hexGrid[row][col]->get_m_type() == 5){
                    if(!stayground) c3 = false;
                }

                if(c1 && c2 && c3){

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
                    removerange();
                    return;
                }
        }else{
            ui->Message->setText("far hexagon");
            return;
        }
    }

    // useless clicked
    if (!selectedAgent && count < 10) return;



    // ------------ second click after arangment of agents(attack operation) ----------------------
    if(hexGrid[row][col]->placed_agent!=nullptr && count >= 10){
        if (((currentPlayer == 1 &&  hexGrid[row][col]->owner == 2) ||
            (currentPlayer == 2 &&  hexGrid[row][col]->owner == 1)) && hexGrid[row][col]->is_inAttackRange) {
                int Dam = temph->placed_agent->Get_Damage();
                int hp =  hexGrid[row][col]->placed_agent->Get_Hp();
                hp-=Dam;
                temph->placed_agent->set_Hp(temph->placed_agent->Get_Hp() - hexGrid[row][col]->placed_agent->Get_Damage() / 2);
                hexGrid[row][col]->placed_agent->set_Hp(hp);
                QString defender = hexGrid[row][col]->placed_agent->Get_Name();
                QString attacker = temph->placed_agent->Get_Name();


                ui->Message->setText("Agent " + defender + " was defender Hp:  " + QString::number(hp) + "\nAgent " + attacker + " was attacker Hp:  " + QString::number(temph->placed_agent->Get_Hp()));

                if(hexGrid[row][col]->placed_agent->Get_Hp() <= 0) {
                    hexGrid[row][col]->placed_agent = nullptr;
                    hexGrid[row][col]->set_m_type(6);
                    hexGrid[row][col]->owner = 0;
                    ui->Message->setText("Agent " + defender + " died in " + QString::number(row) + " , " + QString::number(col));
                    if(currentPlayer == 1) p2_count--;
                    if(currentPlayer == 2) p1_count--;
                }
                bool both = false;
                if(temph->placed_agent->Get_Hp() <= 0){
                    ui->Message->setText("Agent " + attacker + " died in " + QString::number(row) + " , " + QString::number(col));
                    int r = temph->get_m_row();
                    int c = temph->get_m_col();
                    hexGrid[r][c]->owner = 0;
                    hexGrid[r][c]->placed_agent = nullptr;
                    hexGrid[r][c]->set_m_type(6);
                    temph = nullptr;
                    if(currentPlayer == 1) p1_count--;
                    if(currentPlayer == 2) p2_count--;
                    both = true;
                }

                hexGrid[row][col]->update();
                turnTimer->stop();
                switchPlayer();
                tempAgent = nullptr;
                if(!both) replacement(row , col , temph ,temph->placed_agent);
                removerange();
                if(p1_count == 0 && p2_count > 0) showVictoryScene(2);
                if(p1_count > 0 && p2_count == 0) showVictoryScene(1);

                return;
        }
        else{
            ui->Message->setText("invalid agent");
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

//        turnTimer->stop();
        switchPlayer();

        count++;
        qDebug() << "count:" << count;

        return;
        }

    return;
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

void game_page::on_start_game_clicked()
{
    ui->Message->setText("Game starts");
    connect(turnTimer, &QTimer::timeout, this, &game_page::updateTimer);
    startPlayerTurn();
    ui->start_game->setDisabled(true);
}
