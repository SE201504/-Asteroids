/*
 * introduce.c
 * 游戏介绍
 *
 */

#include "main.h"
#include "start.h"
#include "introduce.h"

int introduce_the_game(void)
{
    bool doexit = false;
    enum SET_KEYS{ESCAPE, ENTER};
    bool set_keys[2] = {false, false};
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;//声明事件队列
    ALLEGRO_TIMER *timer = NULL;//声明计时器
    ALLEGRO_FONT *font32 = NULL;
    ALLEGRO_BITMAP *setbackimage = NULL;//back image
    int m4 = SCREEN_H / 2;

    if(!al_init()){
        return -1;
    }
    if(!al_install_mouse()) {
       return -1;
    }
    if(!al_init_image_addon()){
        return -1;
    }
    if(!al_install_keyboard()){
        return -1;
    }
//    al_set_window_position(display,0,0);

    al_init_font_addon();
    al_init_ttf_addon();

    display = al_create_display(SCREEN_W,SCREEN_H);
    if(!display){
        return -1;
    }

    font32 = al_load_font("../nonespace/img/kaiti.ttf",32,0);
    setbackimage = al_load_bitmap("../nonespace/img/start2.jpg");


    timer = al_create_timer(1.0 / FPS);//创建计时器
    event_queue = al_create_event_queue();//创建事件队列
    al_register_event_source(event_queue, al_get_keyboard_event_source());//获得键盘事件装入队列
    al_register_event_source(event_queue, al_get_timer_event_source(timer));//获得计时器事件装入队列
    al_register_event_source(event_queue, al_get_display_event_source(display));//获得显示事件装入队列
    al_register_event_source(event_queue, al_get_mouse_event_source());//mouse event

//    al_clear_to_color(al_map_rgb(0,0,0));
    al_flip_display();
    al_start_timer(timer);//开始计时器

    ALLEGRO_EVENT event;

    while(!doexit)
    {

        al_wait_for_event(event_queue,&event);//把事件队列里的事件装入事件 event


        if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){

            al_clear_to_color(al_map_rgb(0,0,0));
            al_destroy_display(display);
            break;

        }
        else if(event.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            switch(event.keyboard.keycode)
            {
            case ALLEGRO_KEY_ESCAPE:
                set_keys[ESCAPE] = true;
//                doexit = true;
                break;
            }

        }
        else if(event.type == ALLEGRO_EVENT_KEY_UP)
        {
            switch(event.keyboard.keycode)
            {

            case ALLEGRO_KEY_ESCAPE:
                set_keys[ESCAPE] = false;
                break;
            }
        }
        if(al_is_event_queue_empty(event_queue))
        {
            al_draw_bitmap(setbackimage, 0, 0 ,0);

            ALLEGRO_TRANSFORM transform;
            al_identity_transform(&transform);
            al_translate_transform(&transform,0,0);
            al_use_transform(&transform);

            m4--;
            al_draw_text(font32,al_map_rgb(220,220,220),SCREEN_W/2.0,m4,ALLEGRO_ALIGN_CENTER,"long long ago");
            al_draw_text(font32,al_map_rgb(220,220,220),SCREEN_W/2.0,m4+150,ALLEGRO_ALIGN_CENTER,"It's a beautiful...");
            al_draw_text(font32,al_map_rgb(220,220,220),SCREEN_W/2.0,m4+300,ALLEGRO_ALIGN_CENTER,"but...");
            al_draw_text(font32,al_map_rgb(220,220,220),SCREEN_W/2.0,m4+450,ALLEGRO_ALIGN_CENTER,"......");
            al_draw_text(font32,al_map_rgb(220,220,220),SCREEN_W/2.0,m4+600,ALLEGRO_ALIGN_CENTER,"fiifhi");
            al_draw_text(font32,al_map_rgb(220,220,220),SCREEN_W/2.0,m4+750,ALLEGRO_ALIGN_CENTER,"break out ");
            al_draw_text(font32,al_map_rgb(220,220,220),SCREEN_W/2.0,m4+900,ALLEGRO_ALIGN_CENTER,"stop ");
            al_draw_text(font32,al_map_rgb(220,220,220),SCREEN_W/2.0,m4+1050,ALLEGRO_ALIGN_CENTER,"start ");
            al_draw_text(font32,al_map_rgb(220,220,220),SCREEN_W/2.0,m4+1200,ALLEGRO_ALIGN_CENTER,"向着胜利出发了!");

            al_flip_display();
        }
        if(set_keys[ESCAPE] && event.type == ALLEGRO_EVENT_TIMER) {
            doexit = true;
            al_destroy_display(display);
            start();
        }

    }



    al_destroy_timer(timer);
    al_destroy_bitmap(setbackimage);
    al_destroy_event_queue(event_queue);
    al_destroy_font(font32);

    return 0;
}
