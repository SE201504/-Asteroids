#include "main.h"
#include "blast.h"
#include "spaceship.h"
#include "boss.h"
#include "enemy.h"

void init_blast(Blast blast[])
{

    for(int i = 0; i < BLAST_NUM ; i++){

        blast[i].sx = 0;
        blast[i].sy = 0;
        blast[i].live = false;
            blast[i].speed = 9;
            blast[i].heading = 0;
            blast[i].bitmap = al_load_bitmap("../nonespace/img/blast.png");
            blast[i].bitmap_w = al_get_bitmap_width(blast[i].bitmap);
            blast[i].bitmap_h = al_get_bitmap_height(blast[i].bitmap);
    }
}

void init_enenmy_blast(Blast blast[],int type)
{

    if(type == 1)
    {
    for(int i = 0; i < BLAST_NUM ; i++){

        blast[i].sx = 0;
        blast[i].sy = 0;
        blast[i].live = false;
            blast[i].speed = 12;
            blast[i].heading = 0;
            blast[i].bitmap = al_load_bitmap("../nonespace/img/laser.png");
            blast[i].bitmap_w = al_get_bitmap_width(blast[i].bitmap);
            blast[i].bitmap_h = al_get_bitmap_height(blast[i].bitmap);
    }
    }else {
        for(int i = 0; i < BLAST_NUM ; i++){

            blast[i].sx = 0;
            blast[i].sy = 0;
            blast[i].live = false;
                blast[i].speed = 12;
                blast[i].heading = 0;
                blast[i].bitmap = al_load_bitmap("../nonespace/img/blast1.png");
                blast[i].bitmap_w = al_get_bitmap_width(blast[i].bitmap);
                blast[i].bitmap_h = al_get_bitmap_height(blast[i].bitmap);
        }
    }
}

void init_boss_blast(Blast blast[])
{

    for(int i = 0; i < BLAST_NUM ; i++){

        blast[i].sx = 0;
        blast[i].sy = 0;
        blast[i].live = false;
            blast[i].speed = 3;
            blast[i].heading = 0;
            blast[i].bitmap = al_load_bitmap("../nonespace/img/boss_blast.png");
            blast[i].bitmap_w = al_get_bitmap_width(blast[i].bitmap);
            blast[i].bitmap_h = al_get_bitmap_height(blast[i].bitmap);
    }
}

void init_blast2(Blast blast[])
{
    for(int i = 0; i < BLAST_NUM ; i++){
        blast[i].sx = 0;
        blast[i].sy = 0;
        blast[i].live = false;
            blast[i].speed = 9;
            blast[i].heading = 0;
            blast[i].bitmap = al_load_bitmap("../nonespace/img/blast2.png");
            blast[i].bitmap_w = al_get_bitmap_width(blast[i].bitmap);
            blast[i].bitmap_h = al_get_bitmap_height(blast[i].bitmap);
    }

}

void fire_blast(Blast blast[], Blast blast2[], Spaceship *s,int weapen)
{
    if(weapen == 1)
    {
        for(int i = 0; i < BLAST_NUM ; i++)
        {
            if(!blast[i].live)
            {
                blast[i].sx = s->sx;
                blast[i].sy = s->sy;
                blast[i].live = true;
                break;
            }
        }
    }
    if(weapen== 2){
        for(int i = 0; i < BLAST_NUM ; i++)
        {
            if(i == BLAST_NUM -1) {
                i = 0;
            }

            if(!blast2[i].live)
            {
                blast2[i].sx = s->sx;
                blast2[i].sy = s->sy;
                blast2[i].live = true;

                blast2[i+1].sx = s->sx;
                blast2[i+1].sy = s->sy;
                blast2[i+1].live = true;
                break;
            }
        }
    }
}

void fire_enemy_blast(Blast blast[],Blast blast2[],Enemy a[],Enemy b[])
{
    for(int i = 0; i < ENEMY_NUMBER;i++)
    {
        if(a[i].live)
        {
            if(a[i].time % FPS == 2)
            {
                for(int j = 0; j < BLAST_NUM ; j++)
                {
                    if(!blast[j].live)
                    {
                        blast[j].sx = a[i].sx;
                        blast[j].sy = a[i].sy;
                        blast[j].live = true;
                        break;
                    }
                }
            }
        }

        if(b[i].live)
        {
            if(b[i].time % FPS == 1)
            {
                for(int j = 0; j < BLAST_NUM ; j++)
                {
                    if(!blast2[j].live)
                    {
                        blast2[j].sx = b[i].sx;
                        blast2[j].sy = b[i].sy;
                        blast2[j].live = true;
                        break;
                    }
                }
            }
            break;
        }
    }
}

void draw_blast(Blast blast[])
{
        for( int i = 0; i < BLAST_NUM; i++)
        {

            if(blast[i].live){
                ALLEGRO_TRANSFORM transform;
                al_identity_transform(&transform);
                al_translate_transform(&transform, blast[i].sx, blast[i].sy);
                al_use_transform(&transform);

                al_draw_bitmap(blast[i].bitmap,- blast[i].bitmap_w/2,- blast[i].bitmap_h/2,0);
            }
        }
}

void draw_blast2(Blast blast[])
{
        for( int i = 0; i < BLAST_NUM; i++)
        {
            if(blast[i].live){
                if(i%2 == 0){
                ALLEGRO_TRANSFORM transform;
                al_identity_transform(&transform);
                al_translate_transform(&transform, blast[i].sx, blast[i].sy);
                al_use_transform(&transform);

                al_draw_bitmap(blast[i].bitmap,- blast[i].bitmap_w/2 -20,- blast[i].bitmap_h/2 +20,0);
                } else if (i%2 == 1){
                    ALLEGRO_TRANSFORM transform;
                    al_identity_transform(&transform);
                    al_translate_transform(&transform, blast[i].sx, blast[i].sy);
                    al_use_transform(&transform);

                    al_draw_bitmap(blast[i].bitmap,- blast[i].bitmap_w/2 +20,- blast[i].bitmap_h/2 +20,0);
                }
            }
        }
}

void move_blast(Blast blast[])
{
    for(int i = 0; i < BLAST_NUM; i++)
    {
        if(blast[i].live)
        {
            blast[i].sy -= blast[i].speed ;
            check(blast);
        }
    }
}

void move_enemy_blast(Blast blast[])
{
    for(int i = 0; i < BLAST_NUM; i++)
    {
        if(blast[i].live)
        {
            blast[i].sy += blast[i].speed ;
            check(blast);
        }
    }
}

void move_boss_blast(Blast blast[])
{
    for(int i = 0; i < BLAST_NUM; i++)
    {
        if(blast[i].live)
        {
            blast[i].sy += blast[i].speed * cos(blast[i].heading);
            blast[i].sx -= blast[i].speed * sin(blast[i].heading);
            check(blast);
        }
    }
}

void check(Blast blast[])
{
    for(int i = 0; i < BLAST_NUM; i++)
    {
        if(blast[i].sy < 0){
            blast[i].live = false;
        }
        if(blast[i].sy > SCREEN_H){
            blast[i].live = false;
        }
        if(blast[i].sx < 0){
            blast[i].live = false;
        }
        if(blast[i].sx > SCREEN_W){
            blast[i].live = false;
        }

    }

}

