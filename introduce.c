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
    bool click_mouse1 = false;
    enum SET_KEYS{ESCAPE, ENTER};
    bool set_keys[2] = {false, false};
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;//声明事件队列
    ALLEGRO_TIMER *timer = NULL;//声明计时器
    ALLEGRO_FONT *font32 = NULL;
    ALLEGRO_BITMAP *setbackimage = NULL;//back image
    ALLEGRO_BITMAP *reback = NULL;


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
    reback = al_load_bitmap("../nonespace/img/reback.png");


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

        int dx;
        al_wait_for_event(event_queue,&event);//把事件队列里的事件装入事件 event


        if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){

            al_clear_to_color(al_map_rgb(0,0,0));
            al_destroy_display(display);
            break;

        }
        else if(event.type == ALLEGRO_EVENT_MOUSE_AXES || event.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY){
            dx = event.mouse.y - 4;
        }
        else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
            if(dx > -50 && dx < 50){
                click_mouse1=true;
            }

        }
        else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            click_mouse1 = false;
        }
        else if(event.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            switch(event.keyboard.keycode)
            {
            case ALLEGRO_KEY_ESCAPE:
                set_keys[ESCAPE] = true;
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
            al_draw_bitmap(reback,4,4,0);

            ALLEGRO_TRANSFORM transform;
            al_identity_transform(&transform);
            al_translate_transform(&transform,0,0);
            al_use_transform(&transform);

            m4--;
            al_draw_text(font32,al_map_rgb(220,220,220),SCREEN_W/2.0,m4,ALLEGRO_ALIGN_CENTER,"一颗叫做“多美星”的星球");
            al_draw_text(font32,al_map_rgb(220,220,220),SCREEN_W/2.0,m4+100,ALLEGRO_ALIGN_CENTER,"星球原住民多美星人在自己的家园中无忧无虑的生活着");
            al_draw_text(font32,al_map_rgb(220,220,220),SCREEN_W/2.0,m4+200,ALLEGRO_ALIGN_CENTER,"但多美星上空突然出现的巨大时空裂缝");
            al_draw_text(font32,al_map_rgb(220,220,220),SCREEN_W/2.0,m4+300,ALLEGRO_ALIGN_CENTER,"无数邪恶的异次元生物从时空裂缝中来到了这个世界");
            al_draw_text(font32,al_map_rgb(220,220,220),SCREEN_W/2.0,m4+400,ALLEGRO_ALIGN_CENTER,"妄图毁灭整个银河系");
            al_draw_text(font32,al_map_rgb(220,220,220),SCREEN_W/2.0,m4+500,ALLEGRO_ALIGN_CENTER,"面对毁灭");
            al_draw_text(font32,al_map_rgb(220,220,220),SCREEN_W/2.0,m4+600,ALLEGRO_ALIGN_CENTER,"多美星人决定找一位勇士将时空裂缝封印");
            al_draw_text(font32,al_map_rgb(220,220,220),SCREEN_W/2.0,m4+700,ALLEGRO_ALIGN_CENTER,"于是");
            al_draw_text(font32,al_map_rgb(220,220,220),SCREEN_W/2.0,m4+800,ALLEGRO_ALIGN_CENTER,"一场勇士与恶势力的战争拉开了序幕......");
             al_draw_text(font32,al_map_rgb(220,220,220),SCREEN_W/2.0,m4+900,ALLEGRO_ALIGN_CENTER,"点击鼠标左键发射子弹,移动鼠标可以移动飞船");
             al_draw_text(font32,al_map_rgb(220,220,220),SCREEN_W/2.0,m4+1000,ALLEGRO_ALIGN_CENTER,"接到桃心、火焰等可以增加对应的生命值及炮弹发射强度");
             al_draw_text(font32,al_map_rgb(220,220,220),SCREEN_W/2.0,m4+1100,ALLEGRO_ALIGN_CENTER,"接下来，时间交给你.");

            al_flip_display();
        }
        if((set_keys[ESCAPE] || click_mouse1) && event.type == ALLEGRO_EVENT_TIMER) {
            doexit = true;
            al_destroy_display(display);
            start();
        }

    }



    al_destroy_timer(timer);
    al_destroy_bitmap(setbackimage);
    al_destroy_bitmap(reback);
    al_destroy_event_queue(event_queue);
    al_destroy_font(font32);

    return 0;
}
