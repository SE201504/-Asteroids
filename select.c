/*
 * main.c
 * 选择界面.
 *
 */

#include "main.h"
#include "gif/algif.h"
#include "select.h"
#include "run.h"

int selects(void)
{

    bool ifrun = true;
    enum SET_KEYS{SET_UP, SET_DOWN, ENTER};
    bool set_keys[3] = {false, false, false};
    bool click_mouse1 = false;
    bool click_mouse2 = false;

    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;//声明事件队列
    ALLEGRO_TIMER *timer = NULL;//声明计时器
    ALLEGRO_FONT *font40 = NULL;
    ALLEGRO_FONT *font100 = NULL;
    ALLEGRO_FONT *font32 = NULL;
    ALLEGRO_BITMAP *setbackimage = NULL;//back image

    ALGIF_ANIMATION *gif;

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
    al_set_window_position(display,0,0);

    al_init_font_addon();
    al_init_ttf_addon();

    display = al_create_display(SCREEN_W,SCREEN_H);
    if(!display){
        return -1;
    }

    font40 = al_load_font("../nonespace/img/kaiti.ttf",40,0);
    font32 = al_load_font("../nonespace/img/kaiti.ttf",32,0);
    font100 = al_load_font("../nonespace/img/can.ttf",100,0);
    setbackimage = al_load_bitmap("../nonespace/img/start2.jpg");
    gif = algif_load_animation("../nonespace/gif/boom1.gif");

    timer = al_create_timer(1.0 / FPS);//创建计时器
    event_queue = al_create_event_queue();//创建事件队列
    al_register_event_source(event_queue, al_get_keyboard_event_source());//获得键盘事件装入队列
    al_register_event_source(event_queue, al_get_timer_event_source(timer));//获得计时器事件装入队列
    al_register_event_source(event_queue, al_get_display_event_source(display));//获得显示事件装入队列
    al_register_event_source(event_queue, al_get_mouse_event_source());//mouse event

    al_clear_to_color(al_map_rgb(0,0,0));
    al_flip_display();
    al_start_timer(timer);//开始计时器
    int count = 0;

    while(ifrun)
    {
        ALLEGRO_EVENT event;
        int dz;
        int dy;
        int d_w;

        al_wait_for_event(event_queue,&event);//把事件队列里的事件装入事件 event
        if(event.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            switch(event.keyboard.keycode)
            {
            case ALLEGRO_KEY_UP:
                set_keys[SET_UP] = true;
                count --;
                if (count == -1) count = 1;
                break;
            case ALLEGRO_KEY_DOWN:
                set_keys[SET_DOWN] = true;
                count ++;
                break;
            case ALLEGRO_KEY_ENTER:
                set_keys[ENTER] = true;
                break;
            }
        }
        else if(event.type == ALLEGRO_EVENT_KEY_UP)
        {
            switch(event.keyboard.keycode)
            {
            case ALLEGRO_KEY_UP:
                set_keys[SET_UP] = true;
                break;
            case ALLEGRO_KEY_DOWN:
                set_keys[SET_DOWN] = false;
                break;
            case ALLEGRO_KEY_ENTER:
                set_keys[ENTER] = false;
                break;
            case ALLEGRO_KEY_ESCAPE:
                al_destroy_display(display);
                break;
            }
        }

        else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            al_clear_to_color(al_map_rgb(0,0,0));
            al_destroy_display(display);
            break;
        }
        else if(event.type == ALLEGRO_EVENT_MOUSE_AXES || event.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY){
            d_w = event.mouse.x - SCREEN_W/2;
            dy = event.mouse.y - (SCREEN_H*2)/5;
            dz = event.mouse.y - (SCREEN_H*3)/5;
            if(dy > -25 && dy < 25 && d_w > -40 && d_w < 40) count = 0;
            if(dz > -25 && dz < 25 && d_w > -40 && d_w < 40) count = 1;
        }
        else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
            if(dy > -25 && dy < 25 && d_w > -40 && d_w < 40){
                click_mouse1=true;
                count = 0;
            }

            if(dz > -25 && dz < 25 && d_w > -40 && d_w < 40){
                click_mouse2=true;
                count = 1;
            }

        }
        else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            click_mouse1 = false;
            click_mouse2 = false;
        }
        else if(event.type == ALLEGRO_EVENT_TIMER)
        {
            if (count%2 == 0) {
                al_draw_bitmap(setbackimage,0,0,0);
                al_draw_text(font40,al_map_rgb(0,180,0),SCREEN_W/2,(SCREEN_H*2)/5,ALLEGRO_ALIGN_CENTER,"简单");
                al_draw_text(font40,al_map_rgb(225,225,225),SCREEN_W/2,(SCREEN_H*3)/5,ALLEGRO_ALIGN_CENTER,"困难");
                al_draw_bitmap(algif_get_bitmap(gif, al_get_time()), 200, 200, 0);
            }else if(count%2 ==1){
                al_draw_bitmap(setbackimage,0,0,0);
                al_draw_text(font32,al_map_rgb(225,225,255),SCREEN_W/2,(SCREEN_H*2)/5,ALLEGRO_ALIGN_CENTER,"简单");
                al_draw_text(font40,al_map_rgb(0,180,0),SCREEN_W/2,(SCREEN_H*3)/5,ALLEGRO_ALIGN_CENTER,"困难");
                al_draw_bitmap(algif_get_bitmap(gif, al_get_time()), 200,320,0);
            }


            if((set_keys[ENTER] || click_mouse1) && (count%2 == 0))
            {
                ifrun = false;

                al_destroy_display(display);
                run(1);
            }
            else if((set_keys[ENTER] || click_mouse2) && (count%2 == 1))
            {

                ifrun = false;

                al_destroy_display(display);
                run(2);
            }

            else if(ifrun && al_is_event_queue_empty(event_queue ))
            {
                al_draw_text(font100,al_map_rgb(0,0,180),SCREEN_W/2,SCREEN_H/6,ALLEGRO_ALIGN_CENTER,"<Asteroids>");
                al_flip_display();
            }
        }

    }
    al_destroy_timer(timer);
    algif_destroy_bitmap(gif);
    al_destroy_bitmap(setbackimage);
    al_destroy_event_queue(event_queue);
    al_destroy_font(font40);
    al_destroy_font(font100);
    al_destroy_font(font32);

    return 0;
}


