#include "main.h"
#include "boss.h"
#include "spaceship.h"
#include "blast.h"

void init_boss(Boss *s,int level)
{

    s->sx = 100;
    s->sy = -200;
    s->speed = 3;
    s->life = 100;
    s->live = false;
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


void draw_boss(Boss *s,Spaceship *a, int runtime)
{   
    if(runtime > FPS * BOSS_TIME)
    {
        s->live = true;
        ALLEGRO_TRANSFORM transform1;
        al_identity_transform(&transform1);
        al_translate_transform(&transform1, 270, -150);
        al_use_transform(&transform1);

        al_draw_filled_rounded_rectangle(20,190,500,210,10,10,al_map_rgb(200,200,200));
        al_draw_filled_rounded_rectangle(20,190,s->life * 5,210,10,10,al_map_rgb(200,0,0));
        }

    if(s->live){
        ALLEGRO_TRANSFORM transform;
        al_identity_transform(&transform);
        al_translate_transform(&transform, s->sx, s->sy);
        al_use_transform(&transform);
        al_draw_bitmap(s->bitmap,- s->bitmap_w/2,- s->bitmap_h/2,0);

    }
    if(s->life <= 0){
        a->gone = 0;
    }


}

void move_boss(Boss *b,Spaceship *s,int runtime)
{
    if(runtime > FPS * BOSS_TIME)
    {
        if(b->live)
        {

            if(s->sx - b->sx >= 0){
                b->sx += b->speed/2;
            }else if(s->sx - b->sx < 0){
                b->sx -= b->speed/2;
            }

            if(b->sy > SCREEN_H/4){

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

void fire_boss_blast(Blast blast[],Boss *s)
{
    if(s->live)
    {
        if(s->time == 60 * 7){
            for(int i = 0; i < BLAST_NUM ; i++)
            {
                    blast[i].sx = s->sx;
                    blast[i].sy = s->sy;
                    blast[i].heading = i*2;
                    blast[i].live = true;

            }
            s->time = 0;

        }
    }
}


//void al_destory_enemy(Enemy *e){
//    free(e);
//}
