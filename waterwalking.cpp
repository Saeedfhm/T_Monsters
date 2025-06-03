#include "waterwalking.h"
#include "agent.h"
#include <QGraphicsItem>
#include <QString>

Waterwalking::Waterwalking(QString n, qreal size, int type, game_page* gamePage, QGraphicsItem* parent)
    : agent(n, size, type, gamePage, parent)
{}


bool Waterwalking::walk_ground(){
    return true;
}
bool  Waterwalking::walk_water(){
    return true;
}
bool  Waterwalking::stay_ground(){
    return true;
}
bool  Waterwalking::stay_water(){
    return true;
}

bool  Waterwalking::stay_mountain(){
    return false;
}

bool  Waterwalking::walk_mountain(){
    return false;
}
