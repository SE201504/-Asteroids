#ifndef COLLISION_H
#define COLLISION_H

#include "main.h"
#include "collision.h"
#include "spaceship.h"
#include "blast.h"
#include "enemy.h"
#include "boss.h"


void hit_enemy(Blast blast[], Enemy a[],Enemy b[], Spaceship *s);
void hit_enemy2(Blast blast[], Enemy a[],Enemy b[], Spaceship *s);
void hit_boss(Blast blast[], Blast blast2[], Boss *b, Spaceship *s);
void hit_spaceship(Blast blast[],Spaceship *s);
void crash_spaceship(Spaceship *s,Enemy a[],Enemy b[],Boss *boss);

void boom(Enemy *e);
void boom1(Enemy *e);

#endif // COLLISION_H
