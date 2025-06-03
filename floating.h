#ifndef FLOATING_H
#define FLOATING_H

#include "agent.h"

class floating : public agent
{
public:
     floating(QString n, qreal size, int type, game_page* gamePage, QGraphicsItem* parent = nullptr);

    bool walk_ground()  override;
    bool walk_water()  override;
    bool stay_ground()  override;
    bool stay_water()  override;
    bool walk_mountain()  override;
    bool stay_mountain()  override;
};

#endif // FLOATING_H
