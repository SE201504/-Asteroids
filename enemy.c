#include "main.h"
#include "enemy.h"
#include "spaceship.h"
#include "blast.h"


void init_enemy(Enemy a[],int level,int type)
{
    if(type == 1)
    {
        if(level == 1)
        {
            for(int i = 0; i < ENEMY_NUMBER; i++)
            {
                a[i].sx = rand()%SCREEN_W+50;
                a[i].sy = -300;
                a[i].speed = 1.5;
                a[i].life = 0;
                a[i].time = 0;
                a[i].live = false;
                a[i].bitmap = al_load_bitmap("../nonespace/img/enemy.png");
                a[i].bitmap_w = al_get_bitmap_width(a[i].bitmap);
                a[i].bitmap_h = al_get_bitmap_height(a[i].bitmap);
            }
        }else if(level == 2)
        {
            for(int i = 0; i < ENEMY_NUMBER; i++)
            {
                a[i].sx = rand()%SCREEN_W+50;
                a[i].sy = -300;
                a[i].speed = 2.5;
                a[i].life = 0;
                a[i].time = 0;
                a[i].live = false;
                a[i].bitmap = al_load_bitmap("../nonespace/img/enemy0.png");
                a[i].bitmap_w = al_get_bitmap_width(a[i].bitmap);
                a[i].bitmap_h = al_get_bitmap_height(a[i].bitmap);
            }
        }
    }else if(type == 2)
    {
        if(level == 1)
        {
            for(int i = 0; i < ENEMY_NUMBER; i++)
            {
                a[i].sx = rand()%SCREEN_W+50;
                a[i].sy = -300;
                a[i].life = 0;
                a[i].time = 0;
                a[i].live = false;
                if(i%3==1){
                a[i].bitmap = al_load_bitmap("../nonespace/img/enemy0.png");
                a[i].bitmap_w = al_get_bitmap_width(a[i].bitmap);
                a[i].bitmap_h = al_get_bitmap_height(a[i].bitmap);
                a[i].speed = 2;
                } else if((rand()%2+1)==2){
                    a[i].bitmap = al_load_bitmap("../nonespace/img/enemy1.png");
                    a[i].bitmap_w = al_get_bitmap_width(a[i].bitmap);
                    a[i].bitmap_h = al_get_bitmap_height(a[i].bitmap);
                    a[i].speed = 2.5;
                } else {
                    a[i].bitmap = al_load_bitmap("../nonespace/img/enemy2.png");
                    a[i].bitmap_w = al_get_bitmap_width(a[i].bitmap);
                    a[i].bitmap_h = al_get_bitmap_height(a[i].bitmap);
                    a[i].speed = 3;
                }
            }
        }else if(level == 2)
        {
            for(int i = 0; i < ENEMY_NUMBER; i++)
            {
                a[i].sx = rand()%SCREEN_W+50;
                a[i].sy = -300;
                a[i].life = 0;
                a[i].time = 0;
                a[i].live = false;
                if(i%3==1){
                a[i].bitmap = al_load_bitmap("../nonespace/img/enemy0.png");
                a[i].bitmap_w = al_get_bitmap_width(a[i].bitmap);
                a[i].bitmap_h = al_get_bitmap_height(a[i].bitmap);
                a[i].speed = 2;
                } else if((rand()%2+1)==2){
                    a[i].bitmap = al_load_bitmap("../nonespace/img/enemy1.png");
                    a[i].bitmap_w = al_get_bitmap_width(a[i].bitmap);
                    a[i].bitmap_h = al_get_bitmap_height(a[i].bitmap);
                    a[i].speed = 2.5;
                } else {
                    a[i].bitmap = al_load_bitmap("../nonespace/img/enemy2.png");
                    a[i].bitmap_w = al_get_bitmap_width(a[i].bitmap);
                    a[i].bitmap_h = al_get_bitmap_height(a[i].bitmap);
                    a[i].speed = 3;
                }
            }
        }
    }
}


void init_new_enemy(Enemy a[],int runtime,int level,int type)
{
    if(type == 1)
    {
        for(int i = 0; i < ENEMY_NUMBER; i++)
    {
        if(runtime%FPS == 3)
        {
            if(!a[i].live)
            {

                if(level == 1)
                {
                    a[i].life = ENEMY_LIFE_1_1;
                } else if(level == 2) {
                    a[i].life = ENEMY_LIFE_1_2;
                }

                a[i].sx = rand()%SCREEN_W+50;
                a[i].sy = -300;
                a[i].live = true;
                break;
            }
        }
    }
    } else if(type == 2)
    {
        for(int i = 0; i < ENEMY_NUMBER; i++)
        {
            if(runtime%FPS == 3)
            {
                if(!a[i].live)
                {

                    if(level == 1)
                    {
                        a[i].life = ENEMY_LIFE_2_1;
                    } else if(level == 2) {
                        a[i].life = ENEMY_LIFE_2_2;
                    }
                    a[i].sx = rand()%SCREEN_W+50;
                    a[i].sy = -300;

                    a[i].live = true;
                    break;
                }
            }
        }
    }
}



void draw_enemy(Enemy a[])
{
    for(int i = 0; i < ENEMY_NUMBER ; i++)
    {

    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_translate_transform(&transform, a[i].sx, a[i].sy);
    al_use_transform(&transform);

    if(a[i].live)
    {
        al_draw_bitmap(a[i].bitmap,-a[i].bitmap_w/2,-a[i].bitmap_h/2,0);
    }
    }
}


void move_enemy(Enemy a[],Spaceship *s,int type)
{
    if(type == 1)
    {
    for(int i = 0; i < ENEMY_NUMBER; i++)
    {
        if(a[i].live)
        {
            a[i].sy += a[i].speed;
            if(a[i].sy >= SCREEN_H){
                a[i].live = false;
            }
            if(a[i].sx < 0){
                a[i].live = false;
            }
            if(a[i].sx > SCREEN_W){
                a[i].live = false;
            }
        }
    }
    }else if(type == 2){
        for(int i = 0; i < ENEMY_NUMBER; i++)
        {
            if(a[i].live)
            {
                a[i].sy += a[i].speed;
                if(s->sx - a[i].sx >= 0){
                    a[i].sx += a[i].speed/2;
                }else if(s->sx - a[i].sx < 0){
                    a[i].sx -= a[i].speed/2;
                }
                if(a[i].sy > SCREEN_H){
                    a[i].live = false;
                }
                if(a[i].sx < 0){
                    a[i].live = false;
                }
                if(a[i].sx > SCREEN_W){
                    a[i].live = false;
                }
            }
        }
    }
}

void time_plus(Enemy a[],Enemy b[])
{
    for(int i = 0; i < ENEMY_NUMBER;i ++)
    {
        if(a[i].live){
        a[i].time++;
        }
        if(b[i].live){
        b[i].time++;
        }
    }
}




