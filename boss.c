#include "main.h"
#include "boss.h"
#include "spaceship.h"
#include "blast.h"

void init_boss(Boss *s,int level)
{

    s->sx = 100;
    s->sy = -200;
    s->speed = 1;
    s->gone = 5;
    s->time=0;
    s->color = al_map_rgb(222,80,222);
    if(level == 1)
    {
    s->bitmap = al_load_bitmap("../nonespace/img/boss.png");
    } else {
        s->bitmap = al_load_bitmap("../nonespace/img/boss.png");
    }
    s->bitmap_w = al_get_bitmap_width(s->bitmap);
    s->bitmap_h = al_get_bitmap_height(s->bitmap);
}


void draw_boss(Boss *s,int runtime)
{
    if(runtime > FPS * BOSS_TIME)
    {
        if(s->gone !=0){
            ALLEGRO_TRANSFORM transform;
            al_identity_transform(&transform);
            al_translate_transform(&transform, s->sx, s->sy);
            al_use_transform(&transform);
            al_draw_bitmap(s->bitmap,- s->bitmap_w/2,- s->bitmap_h/2,0);
        }
    }

}

void move_boss(Boss *b,Spaceship *s,int runtime)
{
    if(runtime > FPS * BOSS_TIME)
    {
        if(b->gone!=0)
        {

            if(s->sx - b->sx >= 0){
                b->sx += b->speed/2;
            }else if(s->sx - b->sx < 0){
                b->sx -= b->speed/2;
            }

            if(b->sy > SCREEN_H/3){

            }else {
                b->sy += b->speed;
            }
            if(b->sx < 0){
                b->sx -= b->speed;
            }
            if(b->sx > SCREEN_W){
                b->sx += b->speed;
            }
        }
    }
}


void boss_hit_spaceship(Spaceship *s,Blast blast[])
{
            for(int i = 0; i < BLAST_NUM;i++)
            {
                if(blast[i].live)
                {

                    if((pow((blast[i].sx - s->sx),2) + pow((blast[i].sy - s->sy),2))  < 500){
                        blast[i].live = false;
                        s->gone --;
                }
                }
            }

}


//void al_destory_enemy(Enemy *e){
//    free(e);
//}
