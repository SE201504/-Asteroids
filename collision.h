#ifndef COLLISION_H
#define COLLISION_H

#include "main.h"
#include "collision.h"
#include "spaceship.h"
#include "blast.h"
#include "enemy.h"


void hit_enemy(Blast blast[], Enemy a[],Enemy b[], Spaceship *s);
void hit_enemy2(Blast blast[], Enemy a[],Enemy b[], Spaceship *s);
void boom(Enemy *e);
void boom1(Enemy *e);

#endif // COLLISION_H
