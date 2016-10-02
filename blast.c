#include "main.h"
#include "blast.h"
#include "spaceship.h"

void init_blast(Blast blast[],int weapen)
{

    for(int i = 0; i < BLAST_NUM ; i++){

        blast[i].sx = 0;
        blast[i].sy = 0;
        blast[i].live = false;
        if(weapen == 1){
            blast[i].speed = 9;
            blast[i].bitmap = al_load_bitmap("../nonespace/img/blast.png");
            blast[i].bitmap_w = al_get_bitmap_width(blast[i].bitmap);
            blast[i].bitmap_h = al_get_bitmap_height(blast[i].bitmap);
        }
        if(weapen == 2){
            blast[i].speed = 10;
            blast[i].bitmap = al_load_bitmap("../nonespace/img/blast.png");
            blast[i].bitmap_w = al_get_bitmap_width(blast[i].bitmap);
            blast[i].bitmap_h = al_get_bitmap_height(blast[i].bitmap);
        }
    }
}

void fire_blast(Blast blast[], Spaceship *s,int weapen)
{
    if(weapen == 1) {
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
    } else if(weapen== 2){
        for(int i = 0; i < BLAST_NUM ; i++)
        {
            if(!blast[i].live)
            {
                blast[i].sx = s->sx;
                blast[i].sy = s->sy;
                blast[i].live = true;
            }
            if(i == BLAST_NUM -1) {
                i = 0;
            } else {
                i++;
            }

            bool init_blast_2 =true;
            while(init_blast_2){
                if(!blast[i].live){
                    blast[i].sx = s->sx;
                    blast[i].sy = s->sy;
                    blast[i].live = true;

                    init_blast_2 = false ;
                }else {
                    if(i == BLAST_NUM -1) {
                        i = 0;
                    } else {
                        i++;
                    }
                }
            }
            break;
        }
    }
}

void draw_blast(Blast blast[],int weapen)
{

    if(weapen == 1) {
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
    else if(weapen == 2) {
        for( int i = 0; i < BLAST_NUM; i++)
        {
            if(blast[i].live){
                ALLEGRO_TRANSFORM transform;
                al_identity_transform(&transform);
                al_translate_transform(&transform, blast[i].sx, blast[i].sy);
                al_use_transform(&transform);

                al_draw_bitmap(blast[i].bitmap,- blast[i].bitmap_w/2 +20,- blast[i].bitmap_h/2,0);

                bool draw_blast_2 =true;
                int j = 0;
                if(blast[i].live){
                    while(draw_blast_2){
                        if(blast[j].live){
                            al_draw_bitmap(blast[j].bitmap,- blast[j].bitmap_w/2 -20,- blast[j].bitmap_h/2,0);
                            draw_blast_2 = false;
                        }else {
                            if(j == BLAST_NUM -1) {
                                j = 0;
                            } else {
                                j++;
                            }
                        }
                    }
                }
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
