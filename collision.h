#ifndef COLLISION_H
#define COLLISION_H

#include "main.h"
#include "collision.h"
#include "spaceship.h"
#include "blast.h"
#include "enemy.h"
#include "boss.h"


void hit_enemy(Blast blast[], Enemy a[],Enemy b[], Spaceship *s);//飞船子弹与敌机碰撞检测
void hit_enemy2(Blast blast[], Enemy a[],Enemy b[], Spaceship *s);//飞船子弹与敌机碰撞检测
void hit_boss(Blast blast[], Blast blast2[], Boss *b, Spaceship *s);//飞船子弹与BOSS碰撞检测
void hit_spaceship(Blast blast[],Spaceship *s); //敌机子弹与飞船的碰撞检测
void crash_spaceship(Spaceship *s,Enemy a[],Enemy b[],Boss *boss); //敌机与飞船的碰撞检测

void boom(Enemy *e);//爆炸效果
void boom1(Enemy *e);//爆炸效果
void spaceship_boom(Spaceship *e);//爆炸效果
int voice(void);

#endif // COLLISION_H
