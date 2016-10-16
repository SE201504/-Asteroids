#ifndef BOSS_H
#define BOSS_H

#include "main.h"
#include "spaceship.h"
#include "blast.h"


#define BOSS_TIME 40 //定义boss出现时间

typedef struct{
    float sx;
    float sy;
    float speed;
    bool live;
    int life;
    int time;
    ALLEGRO_COLOR color;
    ALLEGRO_BITMAP *bitmap;
    int bitmap_h;
    int bitmap_w;
} Boss;

void init_boss(Boss *s,int level); //初始化boss子弹
void draw_boss(Boss *s, Spaceship *a, int runtime); //画出boss
void move_boss(Boss *b, Spaceship *s, int runtime);  //移动boss
void boss_hit_spaceship(Spaceship *s,Blast blast[]);  //boss的子弹和飞船的碰撞检测
void fire_boss_blast(Blast blast[],Boss *s); //发射boss子弹

#endif // BOSS_H
