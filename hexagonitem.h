#ifndef HEXAGONITEM_H
#define HEXAGONITEM_H

#pragma once
#include <QObject>
#include <QGraphicsPolygonItem>
#include <QColor>
#include <QPolygonF>
#include <QPointF>
#include <QtMath>
#include "agent.h"
class game_page; //
class agent;


const int VIEW_WIDTH = 600;
const int VIEW_HEIGHT = 400;
const int HEX_COLS = 9;
const int HEX_ROWS = 5;


class hexagonitem : public QObject, public QGraphicsPolygonItem {
//    Q_OBJECT
public:
    hexagonitem(qreal size, int type, game_page* gamePage, QGraphicsItem *parent = nullptr);
    void setType(int type);
    void setHighlight(bool highlight);

    game_page* m_gamePage;




    void set_mIshighlight(bool);
    bool get_mIshighlight();

    void set_m_row(int);
    int get_m_row();

    void set_m_col(int);
    int get_m_col();

    int get_m_type();
    void set_m_type(int);


    void set_x(qreal a){
        x = a;
    }

    qreal get_x(){
        return x;
    }

    void set_y(qreal a){
        y = a;
    }

    qreal get_y(){
        return y;
    }

    void set_pixmap(const QString path) {pixmap.load(path);}


    QPointF Pos;

    agent* placed_agent;
    hexagonitem* upNeig;
    hexagonitem* upLNeig;
    hexagonitem* dnLNeig;
    hexagonitem* dnNeig;
    hexagonitem* dnRNeig;
    hexagonitem* upRNeig;


signals:
        //void clicked(hexagonitem* self);
//        void hexClicked(hexagonitem*);
        void clicked(hexagonitem* self);
        void hoverEntered();
        void hoverLeft();

    ~hexagonitem() override = default;  // مهم: اضافه کردن destructor

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:

      bool m_isHighlighted;
      int m_row;
      int m_col;

      int m_type;
      qreal x;
      qreal y;
      qreal m_size;
      QColor getBaseColor() const;

      QPixmap pixmap;
      QString path;


};

#endif // HEXAGONITEM_H
