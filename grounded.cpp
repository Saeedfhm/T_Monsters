#include "grounded.h"

grounded::grounded(QString n, qreal size, int type, game_page* gamePage, QGraphicsItem* parent)
    : agent(n, size, type, gamePage, parent)
{

}


bool grounded::walk_ground(){
    return true;
}
bool  grounded::walk_water(){
    return false;
}

bool grounded::stay_mountain(){
    return false;
}

bool grounded::walk_mountain(){
    return false;
}

bool  grounded::stay_ground(){
    return true;
}
bool  grounded::stay_water(){
    return false;
}
