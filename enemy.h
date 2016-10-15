#ifndef ENEMY_H
#define ENEMY_H
#include "main.h"
#include "spaceship.h"
#include "enemy.h"

#define ENEMY_NUMBER 4
#define ENEMY_LIFE_1_1 2
#define ENEMY_LIFE_1_2 3
#define ENEMY_LIFE_2_1 1
#define ENEMY_LIFE_2_2 2

typedef struct{
    float sx;
    float sy;
    float speed;
    bool live;
    int life;
    int time;
    ALLEGRO_COLOR color;
    ALLEGRO_BITMAP *bitmap;
    ALLEGRO_BITMAP *bitmap_s;
    int bitmap_h;
    int bitmap_w;

} Enemy;

void init_enemy(Enemy a[], int level, int type);
void draw_enemy(Enemy a[]);
void move_enemy(Enemy a[],Spaceship *s,int type);
void init_new_enemy(Enemy a[], int runtime, int level, int type);
void time_plus(Enemy a[],Enemy b[]);

#endif // ENEMY_H
