#ifndef GAME_PAGE_H
#define GAME_PAGE_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "hexagonitem.h"
#include "agent.h"
#include <QVector>
#include <QListWidgetItem>

struct HexData {
    hexagonitem* hexItem;
};

namespace Ui{
class game_page;
}

class game_page : public QMainWindow
{
    Q_OBJECT

public:
    explicit game_page(QWidget *parent = nullptr);
    void set_name(const QString &, const QString &);
    void parse();
    void create_board();
    void create_agent();
    void startPlayerTurn();
    void switchPlayer();
    void updateTimerDisplay();
    void handleHexagonClick(int row, int col);
    void handleAgentClick(agent* clickedAgent);

    // even array
    QVector<QPair<int , int>> even= {

        {-1 , 0} , // up

        {-1 , 1} ,//right up

        {0 , 1} , // right down

        {1 , 0}, // down

        {0 , -1}, // left down

        {-1 , -1} , // left up

    };

    // odd array
     QVector<QPair<int , int>> odd {
        {-1 , 0} , // up

        {0 , 1}, //right up

        {1 , 1}, // right down

        {1 , 0}, // down

        {1 , -1}, // left down

        {0 , -1} // left up

    };

    void add_agent();

    int selected_agent_count;

    void set_agents_name(QString agents);
    int a_size();

    void validation_negihbour();

    int count = 0;

    void BFS(int row , int col , int mobility);

    ~game_page();

private slots:

    void on_load_game_btn_clicked();
    void updateTimer();
    void agentSelected(agent* selected);

private:
    int hrows;
    int hcols;
    Ui::game_page *ui;
    QGraphicsView *graphicsView;
    QGraphicsScene *scene;
    QVector<QVector<hexagonitem*>> hexGrid;
    std::vector<std::vector<QChar>> fgrid;
    int currentPlayer;
    QTimer *turnTimer;
    int timeRemaining;
    agent *selectedAgent;
    agent *tempAgent = nullptr;
    QVector<agent*> p1_a;
    QVector<agent*> p2_a;
    QVector<QString> agents_name;
    hexagonitem *targetHex;
    hexagonitem *temph;
    bool a_t = false;
    int type;
};

#endif // GAME_PAGE_H
