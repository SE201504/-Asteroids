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
    s->life = 100;
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

void draw_spaceship(Spaceship *s,int* weapen_class)
{
    ALLEGRO_BITMAP *protect = NULL;
    protect = al_load_bitmap("../nonespace/img/trans.png");

    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_translate_transform(&transform, s->sx, s->sy);
    al_use_transform(&transform);


    if(s->life!=0)
    {
        al_draw_bitmap(s->bitmap,- s->bitmap_w/2,- s->bitmap_h/2,0);
        if(s->time%3 == 0) {
        al_draw_bitmap(s->bitmap_s,- s->bitmap_s_w/2, 23,0);
        }

    if(s->time <= FPS * 3) {
        if(s->time % 10 == 0)
        al_draw_bitmap(protect,-al_get_bitmap_width(protect)/2,-al_get_bitmap_height(protect)/2,0);
    }
    } else {
        *weapen_class = 1;
        s->gone--;
        s->life = 100;
        s->time =0;
    }

}

void ship_live(Spaceship *s,ALLEGRO_FONT *font)
{
    char str[30];
    al_draw_text(font,al_map_rgb(0,255,0),10,100,0,"LIFE:");
    al_draw_text(font,al_map_rgb(0,255,0),130,100,0,itoa(s->life,str,10));

    al_draw_filled_rounded_rectangle(10,150,300,170,10,10,al_map_rgb(200,200,200));
    al_draw_filled_rounded_rectangle(10,150,s->life * 3,170,10,10,al_map_rgb(95,191,0));

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
        al_translate_transform(&transform, 100, 20);
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
        al_translate_transform(&transform, 100, 20);
        al_use_transform(&transform);

        al_draw_bitmap(s->bitmap,0,0,0);

        al_identity_transform(&transform);
        al_translate_transform(&transform, 180, 20);
        al_use_transform(&transform);

        al_draw_bitmap(s->bitmap,0,0,0);
    }



}

void spaceship_hit_weapen(Spaceship *s, Weapen *weapen,int* weapen_class)
{
    if(weapen->live) {
        if((pow((s->sx - weapen->sx),2) + pow((s->sy - weapen->sy),2))  < 200){
            if(weapen->type == 1)
            {
                weapen->live = false;
                weapen->time = 0;
                *weapen_class = 2;
            } else {
                weapen->live = false;
                weapen->time = 0;
                s->life = 100;
                s->time = 0;
            }
        }
    }

}

void ship_score(Spaceship *s, ALLEGRO_FONT *score)
{
    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_rotate_transform(&transform,0);
    al_translate_transform(&transform, 0, 0);
    al_use_transform(&transform);

    char str[30];
    al_draw_text(score,al_map_rgb(0,255,0),800,30,0,"Score:");
    al_draw_text(score,al_map_rgb(0,255,0),900,30,0,itoa(s->score,str,10));

}

char *itoa(int num,char *str,int radix)
{/*索引表*/
    char index[]="0123456789ABCDEF";
    unsigned unum;/*中间变量*/
    int i=0,j,k;
    /*确定unum的值*/
    if(radix==10&&num<0)/*十进制负数*/
    {
        unum=(unsigned)-num;
        str[i++]='-';
    }
    else unum=(unsigned)num;/*其他情况*/
    /*转换*/
    do{
        str[i++]=index[unum%(unsigned)radix];
        unum/=radix;
    }while(unum);
    str[i]='\0';
    /*逆序*/
    if(str[0]=='-')k=1;/*十进制负数*/
    else k=0;
    char temp;
    for(j=k;j<=(i-1)/2;j++)
    {
        temp=str[j];
        str[j]=str[i-1+k-j];
        str[i-1+k-j]=temp;
    }
    return str;
}
