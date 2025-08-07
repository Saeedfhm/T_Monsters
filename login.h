#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "game_page.h"
#include "agent.h"
#include "waterwalking.h"
#include <QLabel>
namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    void add_agent(QString name);


    ~login();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void onItemClicked(QListWidgetItem *item);
    void on_game_btn_clicked();

    void on_go_to_gamepage_clicked();

private:
    Ui::login *ui;
    game_page *gp;
    QListWidget* agentslist;
    QVector <agent *> agents;
    QLabel* statusLabel = new QLabel(this);
    QString Player_1_agents = "Player1\n";
    QString Player_2_agents = "Player2\n";
    int Turn = 1;
    bool is_Done = false;
    bool is_agents_choose = false;

};

#endif // LOGIN_H
