#include "main.h"
#include "collision.h"
#include "spaceship.h"
#include "blast.h"
#include "enemy.h"
#include "boss.h"
#include "gif/algif.h"


void hit_enemy(Blast blast[],Enemy a[],Enemy b[], Spaceship *s)
{
    for(int i = 0; i < BLAST_NUM; i++)
    {
        if(blast[i].live)
        {
            for(int j = 0; j < ENEMY_NUMBER; j++)
            {
                if(a[j].live)
                {
                    if(sqrt((pow(a[j].sx - blast[i].sx,2) + pow(a[j].sy - blast[i].sy,2))) < a[j].bitmap_w/2 + blast[i].bitmap_w/2)
                    {
                        if(a[j].life == 0)
                        {
                            a[j].live = false;
                            boom1(&a[j]);
                        } else {
                            a[j].life --;
                            boom(&a[j]);
                        }

                        blast[i].live = false;
                        s->score +=100;
                    }
                }
                if(b[j].live)
                {
                    if(sqrt((pow(b[j].sx - blast[i].sx,2) + pow(b[j].sy - blast[i].sy,2))) < b[j].bitmap_w/2 + blast[i].bitmap_w/2)
                    {
                        if(b[j].life == 0)
                        {
                            b[j].live = false;
                            boom1(&b[j]);
                        } else {
                            b[j].life --;
                            boom(&b[j]);
                        }
                        blast[i].live = false;
                        s->score +=100;
                    }
                }
            }
        }
    }
}

void hit_enemy2(Blast blast[],Enemy a[],Enemy b[], Spaceship *s)
{
    for(int i = 0; i < BLAST_NUM; i++)
    {
        if(blast[i].live)
        {
            for(int j = 0; j < ENEMY_NUMBER; j++)
            {
                if(a[j].live)
                {
                    if(sqrt((pow(a[j].sx - blast[i].sx,2) + pow(a[j].sy - blast[i].sy,2))) < a[j].bitmap_w/2 + blast[j].bitmap_w/2)
                    {
                        if(i%2 == 0) {
                            blast[i].live = false;
                            blast[i+1].live = false;
                        } else if(i%2 == 1){
                            blast[i].live = false;
                            blast[i-1].live = false;
                        }
                        if(a[j].life == 0)
                        {
                            a[j].live = false;
                            boom1(&a[j]);
                        } else {
                            a[j].life --;
                            boom(&a[j]);
                        }
                        s->score +=100;
                    }
                }
                if(b[j].live)
                {
                    if(sqrt((pow(b[j].sx - blast[i].sx,2) + pow(b[j].sy - blast[i].sy,2))) < b[j].bitmap_w/2 + blast[i].bitmap_w/2)
                    {
                        if(i%2 == 0) {
                            blast[i].live = false;
                            blast[i+1].live = false;
                        } else if(i%2 == 1){
                            blast[i].live = false;
                            blast[i-1].live = false;
                        }
                        if(b[j].life == 0)
                        {
                            b[j].live = false;
                            boom1(&b[j]);
                        } else {
                            b[j].life --;
                            boom(&b[j]);
                        }
                        s->score +=100;
                    }
                }
            }
        }
    }
}

void hit_boss(Blast blast[], Blast blast2[], Boss *b, Spaceship *s)
{
    if(b->live)
    {
        for(int i = 0; i < BLAST_NUM; i++)
        {
            if(blast[i].live)
            {
                if(sqrt((pow(b->sx - blast[i].sx,2) + pow(b->sy - blast[i].sy,2))) < b->bitmap_h/2 + blast[i].bitmap_h/2)
                {
                    if(b->life == 0)
                    {
                        b->live = false;
                        boom1(b);

                    } else {
                        b->life --;
                        boom(b);
                    }

                    blast[i].live = false;
                    s->score +=100;
                }
            }
        }

        for(int i = 0; i < BLAST_NUM; i++)
        {
            if(blast2[i].live)
            {
                if(sqrt((pow(b->sx - blast2[i].sx,2) + pow(b->sy - blast2[i].sy,2))) < b->bitmap_h/2 + blast2[i].bitmap_h/2)
                {
                    if(i%2 == 0) {
                        blast2[i].live = false;
                        blast2[i+1].live = false;
                    } else if(i%2 == 1){
                        blast2[i].live = false;
                        blast2[i-1].live = false;
                    }
                    if(b->life == 0)
                    {
                        b->live = false;
                        boom1(b);


                    } else {
                        b->life --;
                        boom(b);
                    }
                    s->score +=100;
                }
            }
        }
    }
}

void hit_spaceship(Blast blast[],Spaceship *s)
{
    for(int i = 0; i < BLAST_NUM; i++)
    {
        if(blast[i].live)
        {
            if(sqrt((pow(s->sx - blast[i].sx,2) + pow(s->sy - blast[i].sy,2))) < s->bitmap_h/2 + blast[i].bitmap_h/2)
            {
                s->gone -- ;
                blast[i].live = false;
            }
        }
    }
}

void boom(Enemy *e)
{
    ALGIF_ANIMATION *boom = NULL;
    boom = algif_load_animation("../nonespace/gif/boom.gif");

    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_translate_transform(&transform, e->sx, e->sy);
    al_use_transform(&transform);

    al_draw_bitmap(algif_get_bitmap(boom,al_get_time()),-30,-30,2);
}

void boom1(Enemy *e)
{
    ALGIF_ANIMATION *boom = NULL;
    boom = algif_load_animation("../nonespace/gif/boom1.gif");

    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_translate_transform(&transform, e->sx, e->sy);
    al_use_transform(&transform);

    al_draw_bitmap(algif_get_bitmap(boom,al_get_time()),-75,-75,2);
}
