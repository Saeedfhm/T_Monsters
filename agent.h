#ifndef AGENT_H
#define AGENT_H

#pragma once
#include <QObject>
#include <QGraphicsPolygonItem>
#include <QColor>
#include <QPolygonF>
#include <QPointF>
#include <QtMath>
#include "hexagonitem.h"
class game_page;

const int AGENT_WIDTH = 250;
const int AGENT_HEIGHT = 510;
const int AGENT_COLS = 3;
const int AGENT_ROWS = 4;

class agent: public QObject, public QGraphicsPolygonItem{
public:
    agent(qreal size, int type, game_page* gamePage, QGraphicsItem *parent = nullptr);

     QColor getBaseColor() const;
     void setHighlight(bool highlight);

     void set_null();


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


signals:
    void clicked(agent* self);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:

    int a_row;
    int a_col;
    int power;
    bool a_isHighlighted;
    bool is_selected;
    qreal a_size;
    int a_type;
    QChar color;
    game_page* m_gamePage;

};



#endif // AGENT_H
