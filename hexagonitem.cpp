#include "hexagonitem.h"
#include <QPen>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QDebug>
#include <QApplication>
#include "game_page.h"

// project done

QColor typeToColor(int type) {
    switch(type) {
        case 1: return Qt::green;
        case 2: return Qt::red;
        case 3: return Qt::blue;
        case 4: return Qt::gray;
        case 5: return Qt::black;
        case 6: return QColor(205, 134, 134);
        case 7: return QColor(50, 100, 18);
        case 8: return QColor(60, 60, 160);
        case 9: return QColor(0, 128, 250);//Qt::green;
        case 10: return QColor(205, 34, 134);
        case 11: return QColor(0, 0, 158);
        case 12: return QColor(60, 60, 60);
        default: return QColor(100, 100, 100);
    }
}
hexagonitem::hexagonitem(qreal size, int type, game_page* gamePage, QGraphicsItem *parent)
    : QGraphicsPolygonItem(parent),
    m_gamePage(gamePage),
    m_type(type),
    m_size(size)

{
    QPolygonF hexagon;
    for (int i = 0; i < 6; ++i) {
            qreal angle = 60 * i ;
            qreal x = m_size * qCos(qDegreesToRadians(angle));
            qreal y = m_size * qSin(qDegreesToRadians(angle));
            hexagon << QPointF(x, y);
        }
        setPolygon(hexagon);
        setAcceptHoverEvents(true);
        setFlag(QGraphicsItem::ItemIsSelectable);
}

void hexagonitem :: set_mIshighlight(bool b) {
    m_isHighlighted = b;
}
bool hexagonitem :: get_mIshighlight(){
    return m_isHighlighted;
}

void hexagonitem::set_m_row(int m){
    m_row = m;
}
int hexagonitem::get_m_row(){
    return  m_row;
}

void hexagonitem::set_m_col(int m){
    m_col = m;
}
int hexagonitem::get_m_col(){
    return  m_col;
}

int hexagonitem::get_m_type(){
    return m_type;
}
void hexagonitem::set_m_type(int m){
    m_type = m;
}

QColor hexagonitem::getBaseColor() const
{
    switch(m_type) {
    case 1: return QColor("#1E90FF");
    case 2: return QColor("#FF4500");
    case 3: return QColor("#5DADE2");
    case 4: return QColor("#7D7D7D");
    case 5: return QColor("#A9DFBF");
    case 6: return QColor(205, 134, 134);
    case 7: return QColor(50, 100, 18);
    case 8: return QColor(60, 60, 160);
    case 9: return QColor(0, 128, 250);//Qt::green;
    case 10: return QColor(205, 34, 134);
    case 11: return QColor(0, 0, 158);
    case 12: return QColor(60, 60, 60);
    default: return QColor(100, 100, 100);
    }
}

void hexagonitem::setType(int type)
{
    m_type = type;
    update();
}

void hexagonitem::setHighlight(bool highlight)
{
    m_isHighlighted = highlight;
    update();
}

void hexagonitem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);

     if (event->button() == Qt::LeftButton && m_gamePage) {
         m_gamePage->handleHexagonClick(m_row, m_col);
         qDebug() << "Mouse pressed on hex at row:" << m_row << "col:" << m_col;
             }
 QGraphicsPolygonItem::mousePressEvent(event);

}



void hexagonitem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)  {
        Q_UNUSED(event);

          if (event->button() == Qt::LeftButton) {
              if (QApplication::mouseButtons() & Qt::LeftButton) {
                qDebug() << "Mouse was held down and released on hex at row:"
                << m_row << "col:" << m_col;
             }
             else{
               qDebug() << "Mouse released on hex (normal click) at row:"
               << m_row << "col:" << m_col;
             }
             setBrush(typeToColor(m_type));
          }
          QGraphicsPolygonItem::mouseReleaseEvent(event);
 }


void hexagonitem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    setHighlight(true);
}

void hexagonitem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    setHighlight(false);
}



void hexagonitem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QColor color = getBaseColor();
      if (m_isHighlighted) {
          color = color.lighter(200);
      }

      if(owner == 1) color = QColor(50, 100, 18);

      if(owner == 2) color = QColor(220, 38, 38);

      if(is_inRange) color = QColor(205, 34, 134);

      painter->setBrush(color);
      painter->setPen(QPen(Qt::white, 1));
      painter->drawPolygon(polygon());

       QString text;
       switch(m_type) {
           case 1: text = "1"; break;
           case 2: text = "2"; break;
           case 3: text = "~"; break;
           case 4: text = "#"; break;
           default: text = "";
       }

       if (!text.isEmpty()) {
           painter->setPen(m_isHighlighted ? Qt::yellow : Qt::white);
           QFont font = painter->font();
           font.setPointSize(m_size / 2);
           font.setBold(true);
           painter->setFont(font);
           painter->drawText(boundingRect(), Qt::AlignCenter, text);
       }

       if (placed_agent && !pixmap.isNull()) {
           QPainterPath path;
           path.addPolygon(polygon());

           // کشیدن عکس فقط داخل شش‌ضلعی
           painter->save();
           painter->setClipPath(path);

           QRectF imageRect = polygon().boundingRect();
           painter->drawPixmap(imageRect, pixmap, pixmap.rect());

           painter->restore(); // خیلی مهم: clip رو حذف کن

           // حالا بردر قرمز دور همون شش‌ضلعی بکش — روی تصویر دیده می‌شه

       }

       if(owner == 1){
           QPen pen(QColor("#191970"));
           pen.setWidth(4); // ضخامت واضح
           painter->setPen(pen);
           painter->setBrush(Qt::NoBrush); // فقط خط دور، بدون پر کردن
           painter->drawPolygon(polygon());
       }

       if(owner == 2){
           QPen pen(Qt::red);
           pen.setWidth(4); // ضخامت واضح
           painter->setPen(pen);
           painter->setBrush(Qt::NoBrush); // فقط خط دور، بدون پر کردن
           painter->drawPolygon(polygon());
       }

       if (is_inAttackRange) {
           QPen pen(Qt::yellow);
           pen.setWidth(4); // ضخامت واضح
           painter->setPen(pen);
           painter->setBrush(Qt::NoBrush);
           painter->drawPolygon(polygon());
       }

       if (m_type == 6) {
           painter->setRenderHint(QPainter::Antialiasing);
           painter->setPen(QPen(Qt::red, 3));

           QRectF rect = boundingRect();
           qreal marginX = rect.width() * 0.2;
           qreal marginY = rect.height() * 0.2;

           QPointF topLeft = rect.topLeft() + QPointF(marginX, marginY);
           QPointF topRight = rect.topRight() + QPointF(-marginX, marginY);
           QPointF bottomLeft = rect.bottomLeft() + QPointF(marginX, -marginY);
           QPointF bottomRight = rect.bottomRight() + QPointF(-marginX, -marginY);

           painter->drawLine(topLeft, bottomRight);
           painter->drawLine(topRight, bottomLeft);
       }
}
