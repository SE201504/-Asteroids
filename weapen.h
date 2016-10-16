#ifndef WEAPEN_H
#define WEAPEN_H

#include "main.h"

#define WEAPEN_APPEAR 10 //奖励物品出现时间

typedef struct{
    float sx;
    float sy;
    bool live;
    int time;
    int type;
    ALLEGRO_BITMAP *bitmap;
    int bitmap_h;
    int bitmap_w;
} Weapen;

void init_weapen(Weapen *weapen); //初始化奖励物品
void re_init_weapen(Weapen *weapen, int weapen_class); //重新初始化奖励物品
void draw_weapen(Weapen *weapen); //画出奖励物品
void move_weapen(Weapen *weapen); //移动奖励物品

#endif // WEAPEN_H
