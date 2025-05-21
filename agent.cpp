#include "agent.h"
#include <QPen>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QDebug>
#include <QApplication>
#include <QGraphicsPolygonItem>
#include <QPropertyAnimation>
#include <QGraphicsItem>
#include <QPen>
#include <QPainter>
#include "game_page.h"


agent::agent(QString n , qreal size, int type, game_page* gamePage, QGraphicsItem *parent)
    :   QObject(),
        QGraphicsPolygonItem(parent),
        name(n),
        a_size(size),
        a_type(type),
        m_gamePage(gamePage)
{
    QPolygonF rec;
    for (int i = 0; i < 6; ++i) {
            qreal angle = 60 * i ;
            qreal x = a_size * qCos(qDegreesToRadians(angle));
            qreal y = a_size * qSin(qDegreesToRadians(angle));
            rec << QPointF(x, y);
        }
        setPolygon(rec);
        setAcceptHoverEvents(true);
        setFlag(QGraphicsItem::ItemIsSelectable);
        hover_info_text = new QGraphicsTextItem(this);
        hover_info_text->setDefaultTextColor(Qt::white);
        hover_info_text->setVisible(false);
        hover_info_text->setZValue(10);
}

QString agent::getInfoText() {
    return QString("Name: %1\nHP: %2\nMobility: %3\nDamage: %4\nRange: %5")
        .arg(name)
        .arg(HP)
        .arg(Mobility)
        .arg(Damage)
        .arg(AttackRange);
    }

void agent::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawPolygon(polygon());

    if(a_type==1) painter->setPen(QPen(Qt::red, 3));
    else if(a_type==2) painter->setPen(QPen(Qt::blue, 3));

    if (is_selected) {
        QPen pen(Qt::red, 3);
        painter->setPen(pen);
        painter->drawPolygon(polygon());
    }
    QGraphicsPolygonItem::paint(painter, option, widget);

    QRectF bounds = polygon().boundingRect();
    if (!pixmap.isNull()) {
        QPainterPath path;
        path.addPolygon(polygon());
        painter->save();
        painter->setClipPath(path);
        painter->drawPixmap(bounds, pixmap, pixmap.rect());
        painter->restore();
    }
}

void agent::set_power(int p){
    power = p;
}
int agent::get_power(){
    return  power;
}



void agent::Set_aRow(int r){
    a_row = r;

}
int agent::Get_aRow(){
    return a_row;
}


void agent::Set_aCol(int a){
    a_col = a;

}
int agent::Get_aCol(){
    return a_col;
}



void agent::Set_aishighlight(bool t){
    a_isHighlighted = t;
}

bool agent::Get_aishighlight(){
    return a_isHighlighted;
}


void agent::Set_IsAselected(bool t){
    is_selected = t;
}
bool agent::Get_IsAselected(){
    return is_selected;
}



void agent::set_Hp(int h){
    HP = h;
}

void agent::set_Mobility(int m){
    Mobility = m;
}

void agent::set_Damage(int D){
    Damage = D;
}

void agent::set_AttackRange(int a){
    AttackRange = a;
}

int agent::Get_AttackRange(){
    return AttackRange;
}


bool agent::walk_ground(){
    return true;
}
bool  agent::walk_water(){
    return true;
}
bool  agent::stay_ground(){
    return true;
}
bool  agent::stay_water(){
    return true;
}


QColor agent::getBaseColor() const
{
    switch(Mobility) {
        case 1: return QColor(0, 128, 0);//Qt::green;
        case 2: return QColor(205, 234, 34);
        case 3: return QColor(0, 100, 158);
        default: return QColor(100, 100, 100);
    }
}


void agent::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && isEnabled() && m_gamePage) {
           m_gamePage->handleAgentClick(this); // یا ارسال row/col اگر دارد

            qDebug() << "Mouse pressed on hex at row:" << a_row << "col:" << a_col;

    }
    //emit clicked(this);
    QGraphicsPolygonItem::mousePressEvent(event);
}

void agent::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && isEnabled() && m_gamePage) {
       qDebug() << "Mouse Releasesd on hex at row:" << a_row << "col:" << a_col;
    }
    QGraphicsPolygonItem::mousePressEvent(event);
}


void agent::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
//   setHighlight(true);
//   setPos(x() - 10, y());
//   setScale(1.2);

   hover_info_text->setPlainText(getInfoText());

   QRectF bounds = polygon().boundingRect();
   QPointF pos = bounds.topRight() + QPointF(5, -5); // کنار ایجنت
   hover_info_text->setPos(pos);

   hover_info_text->setVisible(true);

   QGraphicsPolygonItem::hoverEnterEvent(event);
}

void agent::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
//    setHighlight(false);

//    setPos(x() + 10, y());
//    setScale(1.0);

    hover_info_text->setVisible(false);

    QGraphicsPolygonItem::hoverLeaveEvent(event);
}

void agent::setHighlight(bool highlight)
{
    a_isHighlighted = highlight;
    update();
}
