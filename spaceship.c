#include "main.h"
#include "spaceship.h"
#include "weapen.h"
#include "blast.h"


void init_spaceship(Spaceship* s,int level)
{


    s->sx = SCREEN_W/2.0;
    s->sy = SCREEN_H/2.0;
    s->gone = 3;
    s->score = 0;
    s->time = 0;
    s->color = al_map_rgb(222,80,222);
    if(level == 1)
    {
    s->bitmap = al_load_bitmap("../nonespace/img/spaceship0.png");
    s->bitmap_s = al_load_bitmap("../nonespace/img/spaceship_moving.png");
    s->bitmap_w = al_get_bitmap_width(s->bitmap);
    s->bitmap_h = al_get_bitmap_height(s->bitmap);
    s->bitmap_s_w = al_get_bitmap_width(s->bitmap_s);
    s->bitmap_s_h = al_get_bitmap_height(s->bitmap_s);
    } else
    if(level == 2)
    {
    s->bitmap = al_load_bitmap("../nonespace/img/spaceship2.png");
    s->bitmap_s = al_load_bitmap("../nonespace/img/spaceship_moving.png");
    s->bitmap_w = al_get_bitmap_width(s->bitmap);
    s->bitmap_h = al_get_bitmap_height(s->bitmap);
    s->bitmap_s_w = al_get_bitmap_width(s->bitmap_s);
    s->bitmap_s_h = al_get_bitmap_height(s->bitmap_s);
    }
}

void draw_spaceship(Spaceship *s)
{
    ALLEGRO_BITMAP *protect = NULL;
    protect = al_load_bitmap("../nonespace/img/trans.png");

    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_translate_transform(&transform, s->sx, s->sy);
    al_use_transform(&transform);


        al_draw_bitmap(s->bitmap,- s->bitmap_w/2,- s->bitmap_h/2,0);
        if(s->time%3 == 0) {
        al_draw_bitmap(s->bitmap_s,- s->bitmap_s_w/2, 23,0);
        }

    if(s->time <= FPS * 3) {
        if(s->time % 10 == 0)
        al_draw_bitmap(protect,-al_get_bitmap_width(protect)/2,-al_get_bitmap_height(protect)/2,0);
    }

}

void ship_live(Spaceship *s)
{
    if(s->gone == 1)
    {
    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_translate_transform(&transform, 20, 20);
    al_use_transform(&transform);

    al_draw_bitmap(s->bitmap,0,0,0);
    }else if(s->gone == 2)
    {
        ALLEGRO_TRANSFORM transform;
        al_identity_transform(&transform);
        al_translate_transform(&transform, 20, 20);
        al_use_transform(&transform);
        al_draw_bitmap(s->bitmap,0,0,0);


        al_identity_transform(&transform);
        al_translate_transform(&transform, 70, 20);
        al_use_transform(&transform);

        al_draw_bitmap(s->bitmap,0,0,0);

    }else if(s->gone == 3)
    {
        ALLEGRO_TRANSFORM transform;
        al_identity_transform(&transform);
        al_translate_transform(&transform, 20, 20);
        al_use_transform(&transform);

        al_draw_bitmap(s->bitmap,0,0,0);

        al_identity_transform(&transform);
        al_translate_transform(&transform, 70, 20);
        al_use_transform(&transform);

        al_draw_bitmap(s->bitmap,0,0,0);

        al_identity_transform(&transform);
        al_translate_transform(&transform, 120, 20);
        al_use_transform(&transform);

        al_draw_bitmap(s->bitmap,0,0,0);
    }

}

void spaceship_hit_weapen(Spaceship *s, Weapen *weapen,int* weapen_class)
{
    if(weapen->live) {
        if((pow((s->sx - weapen->sx),2) + pow((s->sy - weapen->sy),2))  < 200){
                weapen->live = false;
                *weapen_class = 2;
        }
    }

}
