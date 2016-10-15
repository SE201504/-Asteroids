#include "main.h"
#include "unionship.h"
#include "spaceship.h"
#include "blast.h"

void init_unionship(Unionship a[])
{
                a[0].sx = -100;
                a[0].sy = -200;
                a[0].time = 0;
                a[0].speed = 20;
                a[0].live = false;
                a[0].bitmap = al_load_bitmap("../nonespace/img/union.png");
                a[0].bitmap_w = al_get_bitmap_width(a[0].bitmap);
                a[0].bitmap_h = al_get_bitmap_height(a[0].bitmap);

                a[1].sx = 100;
                a[1].sy = -200;
                a[1].time = 0;
                a[1].speed = 20;
                a[1].live = false;
                a[1].bitmap = al_load_bitmap("../nonespace/img/union.png");
                a[1].bitmap_w = al_get_bitmap_width(a[1].bitmap);
                a[1].bitmap_h = al_get_bitmap_height(a[1].bitmap);
}


void draw_unionship(Unionship a[], int weapen_class)
{
    if(weapen_class == 2)
    {
        a[0].live = true;
        a[1].live = true;

    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_translate_transform(&transform, a[0].sx, a[0].sy);
    al_use_transform(&transform);

    if(a[0].live)
    {
        al_draw_bitmap(a[0].bitmap,-a[0].bitmap_w/2 + 30,-a[0].bitmap_h/2 - 20,0);
    }

    ALLEGRO_TRANSFORM transforms;
    al_identity_transform(&transforms);
    al_translate_transform(&transforms, a[1].sx, a[1].sy);
    al_use_transform(&transforms);

    if(a[1].live)
    {
        al_draw_bitmap(a[1].bitmap,-a[1].bitmap_w/2 -30,-a[1].bitmap_h/2 - 20,0);
    }
    }
}

void fire_union_blast(Blast blast[],Unionship a[],int weapen_class,int runtime)
{
    if(weapen_class == 2)
    {
        if(runtime%10 == 1)
        {
            for(int i = 0; i < ENEMY_NUMBER -1;i++)
            {
                if(!blast[i].live)
                {
                    blast[i].sx = a[0].sx + 30;
                    blast[i].sy = a[0].sy - 30;
                    blast[i].live = true;

                    blast[i+1].sx = a[1].sx - 30;
                    blast[i+1].sy = a[1].sy - 30;
                    blast[i+1].live = true;
                    break;
                }
            }
        }
    }
}

void move_unionship(Unionship a[],Spaceship *s)
{ 
    if(a[0].live)
    {
        a[0].sx = s->sx - 60;
        a[1].sx = s->sx + 60;

        a[0].sy = s->sy + 70;
        a[1].sy = s->sy + 70;
    }

}


