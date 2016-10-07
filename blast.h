#ifndef BLAST_H
#define BLAST_H

#include "main.h"
#include "spaceship.h"
#include "enemy.h"

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
void init_enenmy_blast(Blast blast[]);
void fire_blast(Blast blast[], Blast blast2[], Spaceship *s, int weapen);
void fire_enemy_blast(Blast blast[],Enemy a[],Enemy b[]);
void draw_blast(Blast blast[]);
void draw_blast2(Blast blast[]);
void move_blast(Blast blast[]);
void move_enemy_blast(Blast blast[]);
void check(Blast blast[]);

#endif // BLAST_H
