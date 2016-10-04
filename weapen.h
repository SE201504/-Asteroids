#ifndef WEAPEN_H
#define WEAPEN_H

#include "main.h"

#define WEAPEN_APPEAR 5

typedef struct{
    float sx;
    float sy;
    bool live;
    int time;
    ALLEGRO_BITMAP *bitmap;
    int bitmap_h;
    int bitmap_w;
} Weapen;

void init_weapen(Weapen *weapen);
void re_init_weapen(Weapen *weapen,int runtime);
void draw_weapen(Weapen *weapen);

#endif // WEAPEN_H
