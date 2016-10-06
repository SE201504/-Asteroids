#ifndef BOSS_H
#define BOSS_H

#include "main.h"
#include "blast.h"
#include "spaceship.h"


#define BOSS_TIME 20

typedef struct{
    float sx;
    float sy;
    float speed;
    int gone;
    int time;
    ALLEGRO_COLOR color;
    ALLEGRO_BITMAP *bitmap;
    int bitmap_h;
    int bitmap_w;
} Boss;

void init_boss(Boss *s,int level);
void draw_boss(Boss *s, int runtime);
void move_boss(Boss *b, Spaceship *s, int runtime);
void boss_hit_spaceship(Spaceship *s,Blast blast[]);


#endif // BOSS_H
