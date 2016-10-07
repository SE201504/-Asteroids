#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "main.h"
#include "weapen.h"

typedef struct{
    float sx;
    float sy;
    int score;
    int time;
    int gone;
    int life;
    ALLEGRO_COLOR color;
    ALLEGRO_BITMAP *bitmap;
    ALLEGRO_BITMAP *bitmap_s;
    int bitmap_h;
    int bitmap_w;
    int bitmap_s_h;
    int bitmap_s_w;
} Spaceship;

void init_spaceship(Spaceship* s, int level);
void draw_spaceship(Spaceship *s, int *weapen_class);
void ship_live(Spaceship *s,ALLEGRO_FONT *font);
void spaceship_hit_weapen(Spaceship *s , Weapen *weapen, int *weapen_class);
void ship_score(Spaceship *s, ALLEGRO_FONT *score);

char *itoa(int num,char *str,int radix);

#endif // SPACESHIP_H
