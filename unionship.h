#ifndef UNIONSHIP_H
#define UNIONSHIP_H

#include "main.h"
#include "spaceship.h"
#include "blast.h"

typedef struct{
    float sx;
    float sy;
    bool live;
    int time;
    ALLEGRO_COLOR color;
    ALLEGRO_BITMAP *bitmap;
    ALLEGRO_BITMAP *bitmap_s;
    int bitmap_h;
    int bitmap_w;
} Unionship;

void init_unionship(Unionship a[]);
void draw_unionship(Unionship a[], Spaceship *s, int weapen_class);
void fire_union_blast(Blast blast[],Spaceship *s,int weapen_class,int runtime);
void move_unionship(Unionship a[],Spaceship *s);

#endif // UNIONSHIP_H
