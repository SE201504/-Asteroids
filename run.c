#include "main.h"
#include "spaceship.h"
#include "blast.h"
#include "weapen.h"
#include "enemy.h"



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
    ALLEGRO_BITMAP *backimage = NULL;




    //结构体声明
    Spaceship *s = malloc(sizeof(Spaceship));
    Weapen *weapen = malloc(sizeof(Weapen));
    Blast blast[BLAST_NUM];
    Enemy enemy[ENEMY_NUMBER];


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

    backimage = al_load_bitmap("../nonespace/img/backimage.jpg");
    font24 = al_load_font("../Spaceship/img/fontl.ttf",24,0);
    font56 = al_load_font("../Spaceship/img/fontl.ttf",56,0);

    timer = al_create_timer(1.0 / FPS);//创建计时器
    event_queue = al_create_event_queue();//创建事件队列
    al_register_event_source(event_queue, al_get_mouse_event_source());//get mouse event
    al_register_event_source(event_queue, al_get_timer_event_source(timer));//获得计时器事件装入队列
    al_register_event_source(event_queue, al_get_display_event_source(display));//获得显示事件装入队列
    al_clear_to_color(al_map_rgb(0,0,0));
    al_flip_display();


    //结构体初始化
    init_spaceship(s,level);
    init_blast(blast,weapen_class);
    init_weapen(weapen);
    init_enemy(enemy);



    //开始计时器
    al_start_timer(timer);

        while(s->gone != 0)
        {
            redraw = true;
            ALLEGRO_EVENT event;
            al_wait_for_event(event_queue,&event);//把事件队列里的事件装入事件 event

            if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                al_clear_to_color(al_map_rgb(0,0,0));
                break;
            }
            else if(event.type == ALLEGRO_EVENT_MOUSE_AXES){
                s->sx = event.mouse.x;
                s->sy = event.mouse.y;
            }
            else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
                fire_blast(blast,s,weapen_class);
            }
            else if(event.type == ALLEGRO_EVENT_TIMER)
            {
                al_clear_to_color(al_map_rgb(255,255,255));
                ALLEGRO_TRANSFORM transform;
                al_identity_transform(&transform);
                al_translate_transform(&transform, 0, 0);
                al_use_transform(&transform);

                al_draw_bitmap(backimage,0,0,0);


                s->time++;
                runtime++;
                re_init_weapen(weapen,runtime);
                init_new_enemy(enemy,runtime);


                move_blast(blast);
                move_enemy(enemy);


                // 碰撞检测系统


                spaceship_hit_weapen(s,weapen,&weapen_class);

                redraw = true;
                if(redraw && al_is_event_queue_empty(event_queue))
                {


                    //各种对象绘制
                    ship_live(s);
                    draw_enemy(enemy);
                    draw_spaceship(s);
                    draw_weapen(weapen);
                    draw_blast(blast,weapen_class);

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
    return 0;
}

