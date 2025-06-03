#ifndef WATERWAKLING_H
#define WATERWAKLING_H

#include "agent.h"
#include <QGraphicsPolygonItem>

class Waterwalking : public agent
{
public:
    Waterwalking(QString n, qreal size, int type, game_page* gamePage, QGraphicsItem* parent = nullptr);

    bool walk_ground()  override;
    bool walk_water()  override;
    bool stay_ground()  override;
    bool stay_water()  override;
    bool stay_mountain() override;
    bool walk_mountain() override;

private:
};

#endif // WATERWAKLING_H
