#ifndef BLAST_H
#define BLAST_H

#include "main.h"
#include "spaceship.h"

#define BLAST_NUM  10
typedef struct{
    float sx;
    float sy;
    bool live;
    float speed;
    ALLEGRO_COLOR color;
    ALLEGRO_BITMAP *bitmap;
    int bitmap_h;
    int bitmap_w;
}Blast;
//
void init_blast(Blast blast[], int weapen);
void fire_blast(Blast blast[], Spaceship *s, int weapen);
void draw_blast(Blast blast[], int weapen);
void move_blast(Blast blast[]);
void check(Blast blast[]);

#endif // BLAST_H
