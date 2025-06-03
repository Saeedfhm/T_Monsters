#include "flying.h"

flying::flying(QString n, qreal size, int type, game_page* gamePage, QGraphicsItem* parent)
  : agent(n, size, type, gamePage, parent) {}


bool flying::walk_ground(){
    return true;
}
bool  flying::walk_water(){
    return true;
}

bool flying::walk_mountain(){
    return true;
}

bool  flying::stay_ground(){
    return true;
}

bool  flying::stay_water(){
    return false;
}

bool flying::stay_mountain(){
    return false;
}

