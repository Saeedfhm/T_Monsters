#include "floating.h"

floating::floating(QString n, qreal size, int type, game_page* gamePage, QGraphicsItem* parent)
    : agent(n, size, type, gamePage, parent)
{}

// project done

bool floating::walk_ground(){
    return true;
}
bool  floating::walk_water(){
    return true;
}
bool  floating::stay_ground(){
    return true;
}
bool  floating::stay_water(){
    return true;
}

bool floating::walk_mountain(){
    return true;
}

bool  floating::stay_mountain(){
    return true;
}
