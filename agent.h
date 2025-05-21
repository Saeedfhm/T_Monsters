#ifndef AGENT_H
#define AGENT_H

#pragma once
#include <QObject>
#include <QGraphicsPolygonItem>
#include <QColor>
#include <QPolygonF>
#include <QPointF>
#include <QtMath>
#include <QString>
#include "hexagonitem.h"
#include <QGraphicsProxyWidget>
#include <QLabel>
#include <QPropertyAnimation>
class game_page;

const int AGENT_WIDTH = 250;
const int AGENT_HEIGHT = 510;
const int AGENT_COLS = 3;
const int AGENT_ROWS = 4;

class agent: public QObject, public QGraphicsPolygonItem
{
     Q_OBJECT
public:
     agent(QString, qreal size, int type, game_page* gamePage,QGraphicsItem *parent = nullptr);

     QColor getBaseColor() const;

     void setHighlight(bool highlight);
     void set_null();

     void set_Name(QString);
     QString Get_Name(){
         return  name;
     }

     void set_Hp(int);
     int Get_Hp();

     void set_Mobility(int);
     int Get_Mobility();

     void set_Damage(int);
     int Get_Damage();

     void set_AttackRange(int);
     int Get_AttackRange();

     void set_power(int);
     int get_power();

     void Set_aishighlight(bool);
     bool  Get_aishighlight();

     void Set_IsAselected(bool);
     bool Get_IsAselected();

     void Set_aRow(int);
     int Get_aRow();

     void Set_aCol(int);
     int Get_aCol();

     QString getInfoText();

     QGraphicsProxyWidget* info_widget_proxy;
     QLabel* info_label;
     QPropertyAnimation* fade_anim;

     void setupInfoWidget();

     virtual bool walk_ground();
     virtual bool walk_water();

     virtual bool stay_ground();
     virtual bool stay_water();

     void set_aname(QString n) { a_name = n; }
     void set_pixmap(const QString path) {pixmap.load(path);}
signals:
    void clicked(agent* self);
protected:

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    QString name;
    int HP;
    int Mobility;
    int Damage;
    int AttackRange;

     QGraphicsTextItem* hover_info_text;
private:
    int a_row;
    int a_col;
    int power;
    bool a_isHighlighted;
    bool is_selected;
    qreal a_size;
    int a_type;
    QChar color;
    QString a_name;
    QPixmap pixmap;
    game_page* m_gamePage;
};



#endif // AGENT_H
