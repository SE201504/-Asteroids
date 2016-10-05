#include "main.h"
#include "blast.h"
#include "spaceship.h"

void init_blast(Blast blast[])
{

    for(int i = 0; i < BLAST_NUM ; i++){

        blast[i].sx = 0;
        blast[i].sy = 0;
        blast[i].live = false;
            blast[i].speed = 9;
            blast[i].bitmap = al_load_bitmap("../nonespace/img/blast.png");
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
