#ifndef GROUNDED_H
#define GROUNDED_H

#include <agent.h>

class grounded : public agent
{
public:
    grounded(QString n, qreal size, int type, game_page* gamePage, QGraphicsItem* parent = nullptr);


    bool walk_ground()  override;
    bool walk_water()  override;
    bool stay_ground()  override;
    bool stay_water()  override;

    bool walk_mountain()  override;
    bool stay_mountain()  override;
};

#endif // GROUNDED_H
