#ifndef GAME_PAGE_H
#define GAME_PAGE_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "hexagonitem.h"
#include "agent.h"
#include <QVector>

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

    ~game_page();

private slots:

    void on_load_game_btn_clicked();
    void updateTimer();
    void agentSelected(agent* selected);
private:
    int hrows;
    int hcols;
    Ui::game_page *ui;
    QGraphicsScene *scene;
    QVector<QVector<hexagonitem*>> hexGrid;
    std::vector<std::vector<QChar>> fgrid;
    int currentPlayer;
    QTimer *turnTimer;
    int timeRemaining;
    agent *selectedAgent;
    hexagonitem *targetHex;
};

#endif // GAME_PAGE_H
