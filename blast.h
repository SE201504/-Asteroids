#ifndef BLAST_H
#define BLAST_H

#include "main.h"
#include "spaceship.h"
#include "enemy.h"

#define BLAST_NUM  20 //定义最大子弹数目

typedef struct{
    float sx;
    float sy;
    bool live;
    float speed;
    float heading;
    ALLEGRO_COLOR color;
    ALLEGRO_BITMAP *bitmap;
    int bitmap_h;
    int bitmap_w;
}Blast;

void init_blast(Blast blast[]);// 初始化第一种子弹
void init_blast2(Blast blast[]);//初始化第二种子弹
void init_enenmy_blast(Blast blast[], int type);//初始化敌机子弹
void init_boss_blast(Blast blast[]);//初始化boss子弹
void fire_blast(Blast blast[], Blast blast2[], Spaceship *s, int weapen);//发射飞船子弹
void fire_enemy_blast(Blast blast[], Blast blast2[], Enemy a[], Enemy b[]);//发射敌机子弹
void draw_blast(Blast blast[]);//画出第一种子弹
void draw_blast2(Blast blast[]);//画出第二种子弹
void move_blast(Blast blast[]);//移动飞船子弹
void move_enemy_blast(Blast blast[]);// 移动敌机子弹
void move_boss_blast(Blast blast[]);// 移动boss子弹
void check(Blast blast[]);//检查子弹越界

#endif // BLAST_H
