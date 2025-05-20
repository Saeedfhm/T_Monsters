#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "game_page.h"
#include "agent.h"
#include "waterwalking.h"
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

private slots:

    void onItemClicked(QListWidgetItem *item);
    void on_game_btn_clicked();

private:
    Ui::login *ui;
    game_page *gp;
    QListWidget* agentslist;
    QVector <agent *> agents;

};

#endif // LOGIN_H
