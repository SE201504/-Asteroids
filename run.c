#include "main.h"
#include "spaceship.h"
#include "blast.h"
#include "weapen.h"
#include "enemy.h"
#include "boss.h"
#include "collision.h"
#include "unionship.h"
#include "restart.h"

bool doexit = false;

int run(int level)
{

    bool redraw;
    int weapen_class = 1;//weapen level
    int runtime = 0;

    //类型声明
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;//声明事件队列
    ALLEGRO_TIMER *timer = NULL;//声明计时器
    ALLEGRO_FONT *font24 = NULL;
    ALLEGRO_FONT *font56 = NULL;
    ALLEGRO_BITMAP *backimage1 = NULL;
    ALLEGRO_BITMAP *backimage2 = NULL;




    //结构体声明
    Spaceship *s = (Spaceship*)malloc(sizeof(Spaceship));
    Weapen *weapen = (Weapen*)malloc(sizeof(Weapen));
    Blast blast[BLAST_NUM];
    Blast blast2[BLAST_NUM];
    Blast enemy_blast[BLAST_NUM];
    Blast boss_blast[BLAST_NUM];
    Blast enemy_blast2[BLAST_NUM];
    Enemy enemy[ENEMY_NUMBER];
    Enemy enemy2[ENEMY_NUMBER];
    Unionship unionship[2];
    Boss *b = (Boss*)malloc(sizeof(Boss));
    int h1;
    int h2;
    int backimage2_heigh;

    //显示系统初始化
    if(!al_init()){
        return -1;
    }
    if(!al_init_image_addon()){
        return -1;
    }
    if(!al_install_keyboard()){
        return -1;
    }
    if(!al_init_font_addon()){
        return -1;
    }
    if(!al_init_ttf_addon()){
        return -1;
    }
    if(!al_install_mouse()){
        return -1;
    }

    al_set_window_position(display,0,0);

    display = al_create_display(SCREEN_W,SCREEN_H);
    al_hide_mouse_cursor(display);

    backimage1 = al_load_bitmap("../nonespace/img/back.jpg");
    backimage2 = al_load_bitmap("../nonespace/img/back.jpg");
    h1 = 0;
    h2 = al_get_bitmap_height(backimage2);
    backimage2_heigh = al_get_bitmap_height(backimage2);
    font24 = al_load_font("../nonespace/img/kaiti.ttf",24,0);
    font56 = al_load_font("../nonespace/img/kaiti.ttf",56,0);

    timer = al_create_timer(1.0 / FPS);//创建计时器
    event_queue = al_create_event_queue();//创建事件队列
    al_register_event_source(event_queue, al_get_mouse_event_source());//get mouse event
    al_register_event_source(event_queue, al_get_timer_event_source(timer));//获得计时器事件装入队列
    al_register_event_source(event_queue, al_get_display_event_source(display));//获得显示事件装入队列
    al_clear_to_color(al_map_rgb(0,0,0));

    al_flip_display();


    //结构体初始化
    init_spaceship(s,level);
    init_blast(blast);
    init_blast2(blast2);
    init_enenmy_blast(enemy_blast,1);
    init_enenmy_blast(enemy_blast2,2);
    init_boss_blast(boss_blast);
    init_weapen(weapen);
    init_enemy(enemy,level,1);
    init_enemy(enemy2,level,2);
    init_boss(b,level);
    init_unionship(unionship);



    //开始计时器
    al_start_timer(timer);

        while(s->gone != 0)
        {
            redraw = true;
            ALLEGRO_EVENT event;
            al_wait_for_event(event_queue,&event);//把事件队列里的事件装入事件 event

            if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                al_clear_to_color(al_map_rgb(0,0,0));
                al_destroy_display(display);
                break;
            }
            else if(event.type == ALLEGRO_EVENT_MOUSE_AXES){
                s->sx = event.mouse.x;
                s->sy = event.mouse.y;
            }
            else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
                fire_blast(blast,blast2,s,weapen_class);
            }
            else if(event.type == ALLEGRO_EVENT_TIMER)
            {
                al_clear_to_color(al_map_rgb(255,255,255));
                ALLEGRO_TRANSFORM transform;
                al_identity_transform(&transform);
                al_translate_transform(&transform, 0, 0);
                al_use_transform(&transform);

                h1 +=1;
                if (h1>backimage2_heigh) h1 = -backimage2_heigh + 10;
                h2 -=1;
                if (h2< -backimage2_heigh)  h2 = backimage2_heigh - 10;
                al_draw_bitmap(backimage1,-10,h1,0);
                al_draw_bitmap(backimage2,-10,-h2,0);



                s->time++;
                b->time++;
                weapen->time++;
                time_plus(enemy,enemy2);
                runtime++;

                re_init_weapen(weapen,weapen_class);
                init_new_enemy(enemy,runtime,level,1);
                init_new_enemy(enemy2,runtime,level,2);
                fire_boss_blast(boss_blast,b);
                fire_enemy_blast(enemy_blast,enemy_blast2,enemy,enemy2);
                fire_union_blast(blast,unionship,weapen_class,runtime);


                move_unionship(unionship,s);
                move_blast(blast);
                move_boss_blast(boss_blast);
                move_enemy_blast(enemy_blast);
                move_enemy_blast(enemy_blast2);
                move_blast(blast2);
                move_enemy(enemy,s,1);
                move_enemy(enemy2,s,2);
                move_boss(b,s,runtime);
                move_weapen(weapen);





                redraw = true;
                if(redraw && al_is_event_queue_empty(event_queue))
                {


                    //各种对象绘制
                    ship_score(s,font24);
                    ship_live(s,font24);
                    draw_enemy(enemy);
                    draw_enemy(enemy2);
                    draw_spaceship(s,&weapen_class);
                    draw_unionship(unionship,weapen_class);
                    draw_weapen(weapen);
                    draw_blast(blast);
                    draw_blast(boss_blast);
                    draw_blast2(blast2);
                    draw_blast(enemy_blast);
                    draw_blast(enemy_blast2);
                    draw_boss(b,s,runtime);

                    // 碰撞检测系统

                    spaceship_hit_weapen(s,weapen,&weapen_class);
                    if(s->time > FPS * 3)
                    {
                    hit_enemy(blast,enemy,enemy2,s);
                    hit_enemy2(blast2,enemy,enemy2,s);
                    hit_boss(blast,blast2,b,s);
                    hit_spaceship(enemy_blast,s);
                    hit_spaceship(enemy_blast2,s);
                    hit_spaceship(boss_blast,s);
                    crash_spaceship(s,enemy,enemy2,b);
                    }

                    al_flip_display();
                    redraw = false;
                }
            }
        }

    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue);
    al_destroy_font(font24);
    al_destroy_font(font56);

    if(!doexit)
        restart(s->score);
    return 0;
}

