#include "main.h"
#include "weapen.h"
#include "spaceship.h"


void init_weapen(Weapen *weapen)
{
    weapen->sx = rand()%SCREEN_W + 0;
    weapen->sy = rand()%SCREEN_H/3 + 0;
    weapen->time=0;
    weapen->live = false;
    if((rand()%3+1)==2){
    weapen->type = 1;
    weapen->bitmap = al_load_bitmap("../nonespace/img/weapen.png");
    weapen->bitmap_w = al_get_bitmap_width(weapen->bitmap);
    weapen->bitmap_h = al_get_bitmap_height(weapen->bitmap);
    } else     if((rand()%2+1)!=1){
        weapen->type = 2;
        weapen->bitmap = al_load_bitmap("../nonespace/img/life.png");
        weapen->bitmap_w = al_get_bitmap_width(weapen->bitmap);
        weapen->bitmap_h = al_get_bitmap_height(weapen->bitmap);
        }
}

void re_init_weapen(Weapen *weapen,int weapen_class)
{
    if(weapen_class == 1)
    {
    if(weapen->time == FPS * WEAPEN_APPEAR) {
        weapen->live = true;
        weapen->sx = rand()%SCREEN_W + 0;
        weapen->sy = rand()%SCREEN_H/3 + 0;

        if((rand()%3+1)==2){
        weapen->type = 1;
        weapen->bitmap = al_load_bitmap("../nonespace/img/weapen.png");
        weapen->bitmap_w = al_get_bitmap_width(weapen->bitmap);
        weapen->bitmap_h = al_get_bitmap_height(weapen->bitmap);
        } else  if((rand()%2+1)!=1){
            weapen->type = 2;
            weapen->bitmap = al_load_bitmap("../nonespace/img/life.png");
            weapen->bitmap_w = al_get_bitmap_width(weapen->bitmap);
            weapen->bitmap_h = al_get_bitmap_height(weapen->bitmap);
            }
    }
    }
}

void draw_weapen(Weapen *weapen)
{
    if(weapen->live){
    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_translate_transform(&transform, weapen->sx, weapen->sy);
    al_use_transform(&transform);

    al_draw_bitmap(weapen->bitmap,-weapen->bitmap_w/2,-weapen->bitmap_h/2,0);
    }

}









