#ifndef ENEMY_H
#define ENEMY_H
#include "main.h"

#define ENEMY_NUMBER 3

typedef struct{
    float sx;
    float sy;
    float speed;
    bool live;
    ALLEGRO_COLOR color;
    ALLEGRO_BITMAP *bitmap;
    ALLEGRO_BITMAP *bitmap_s;
    int bitmap_h;
    int bitmap_w;

} Enemy;

void init_enemy(Enemy a[]);
void draw_enemy(Enemy a[]);
void move_enemy(Enemy a[]);
void init_new_enemy(Enemy a[],int runtime);


#endif // ENEMY_H
