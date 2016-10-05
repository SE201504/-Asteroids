#ifndef BLAST_H
#define BLAST_H

#include "main.h"
#include "spaceship.h"

#define BLAST_NUM  20
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
void init_blast(Blast blast[]);
void init_blast2(Blast blast[]);
void fire_blast(Blast blast[], Blast blast2[], Spaceship *s, int weapen);
void draw_blast(Blast blast[]);
void draw_blast2(Blast blast[]);
void move_blast(Blast blast[]);
void check(Blast blast[]);

#endif // BLAST_H
