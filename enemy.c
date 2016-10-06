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
                a[i].live = false;
                a[i].bitmap = al_load_bitmap("../nonespace/img/enemy.png");
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
                a[i].speed = 2.5;
                a[i].life = 0;
                a[i].live = false;
                a[i].bitmap = al_load_bitmap("../nonespace/img/enemy1.png");
                a[i].bitmap_w = al_get_bitmap_width(a[i].bitmap);
                a[i].bitmap_h = al_get_bitmap_height(a[i].bitmap);
            }
        }else if(level == 2){
            for(int i = 0; i < ENEMY_NUMBER; i++)
            {
                a[i].sx = rand()%SCREEN_W+50;
                a[i].sy = -300;
                a[i].speed = 3.5;
                a[i].life = 0;
                a[i].live = false;
                a[i].bitmap = al_load_bitmap("../nonespace/img/enemy1.png");
                a[i].bitmap_w = al_get_bitmap_width(a[i].bitmap);
                a[i].bitmap_h = al_get_bitmap_height(a[i].bitmap);
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
            if(a[i].life == 0)
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
                if(a[i].life == 0)
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

//void init_enemy_s(Enemy a[],int size)
//{
//    for(int i = 0; i < size; i++)
//    {

//    a[i].sx = 0;
//    a[i].sy = 0;
//    a[i].heading = 0;
//    a[i].speed = 2.5;
//    a[i].twist = 0;
//    a[i].live = false;
//    a[i].color = al_map_rgb(0,255,0);
//    a[i].bitmap =al_load_bitmap("../Spaceship/img/asteriod_s.png");
//    a[i].bitmap_w = al_get_bitmap_width(a[i].bitmap);
//    a[i].bitmap_h = al_get_bitmap_height(a[i].bitmap);
//    }

//}

//void creat_small_enemy(enemy a[],enemy b[], int i)
//{

//    for(int j = 0; j < enemy_num*2 - 1; j++)
//        if(!b[j].live)
//        {
//            b[j].sx = a[i].sx + 20;
//            b[j].sy = a[i].sy + 20;
//            b[j].heading = a[i].heading + 0.5;
//            b[j].live = true;
//            b[j].twist = 0;
//            b[j].speed = 3;
//            b[j].bitmap =al_load_bitmap("../Spaceship/img/asteriod_s.png");
//            b[j].bitmap_w = al_get_bitmap_width(b[j].bitmap);
//            b[j].bitmap_h = al_get_bitmap_height(b[j].bitmap);

//            b[j+1].sx = a[i].sx;
//            b[j+1].sy = a[i].sy;
//            b[j+1].heading = a[i].heading - 0.5;
//            b[j+1].twist = 0;
//            b[j+1].live = true;
//            b[j+1].speed = 3;
//            b[j+1].bitmap =al_load_bitmap("../Spaceship/img/asteriod_s.png");
//            b[j+1].bitmap_w = al_get_bitmap_width(b[j].bitmap);
//            b[j+1].bitmap_h = al_get_bitmap_height(b[j].bitmap);
//            break;
//        }






//}

//void init_new_enemy(enemy a[],enemy b[],int i)
//{
//    creat_small_enemy(a,b,i);

//    a[i].sx = rand()%20+1;
//    a[i].sy = rand()%20+1;
//    a[i].heading = rand()%SCREEN_H+1;
//    a[i].speed = 2;
//    a[i].twist = 0;
//    a[i].live = true;
//    a[i].color =al_map_rgb(0,255,0);
//    a[i].bitmap = al_load_bitmap("../Spaceship/img/asteriod.png");
//    a[i].bitmap_w = al_get_bitmap_width(a[i].bitmap);
//    a[i].bitmap_h = al_get_bitmap_height(a[i].bitmap);



//}

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
//void draw_enemy_s(enemy a[],int size)
//{
//    for(int i = 0; i < size ; i++)
//    {

//    ALLEGRO_TRANSFORM transform;
//    al_identity_transform(&transform);
//    al_rotate_transform(&transform, a[i].twist);
//    al_translate_transform(&transform, a[i].sx, a[i].sy);
//    al_use_transform(&transform);

//    if(a[i].live)
//    {
//        al_draw_bitmap(a[i].bitmap,- a[i].bitmap_w/2,- a[i].bitmap_h/2,0);
//    }
//    }
//}

void move_enemy(Enemy a[],Spaceship *s,int type)
{
    if(type == 1)
    {
    for(int i = 0; i < ENEMY_NUMBER; i++)
    {
        if(a[i].live)
        {
            a[i].sy += a[i].speed;

//            if(a[i].sy < 0){
//                a[i].live = false;
//            }
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
    }else {
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






