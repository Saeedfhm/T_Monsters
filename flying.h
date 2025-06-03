#ifndef FLYING_H
#define FLYING_H

#include <agent.h>

class flying : public agent
{
public:
    flying(QString, qreal size, int type, game_page* gamePage,QGraphicsItem *parent = nullptr);

    bool walk_ground()  override;
    bool walk_water()  override;
    bool stay_ground()  override;
    bool stay_water()  override;
    bool walk_mountain()  override;
    bool stay_mountain()  override;
};

#endif // FLYING_H
