#ifndef WEAPEN_H
#define WEAPEN_H

#include "main.h"

#define WEAPEN_APPEAR 10

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

void init_weapen(Weapen *weapen);
void re_init_weapen(Weapen *weapen, int weapen_class);
void draw_weapen(Weapen *weapen);

#endif // WEAPEN_H
