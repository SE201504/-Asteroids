#include "main.h"
#include "spaceship.h"



int run(int i)
{

    enum KEYS{UP, DOWN, LEFT, RIGHT, SPACE, ENTER};

    bool keys[6] = {false, false, false, false, false, false};
    bool redraw;
    int grades = 0;

    //类型声明
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;//声明事件队列
    ALLEGRO_TIMER *timer = NULL;//声明计时器
    ALLEGRO_FONT *font24 = NULL;
    ALLEGRO_FONT *font56 = NULL;

    //结构体声明
    Spaceship *s = malloc(sizeof(Spaceship));



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

    display = al_create_display(SCREEN_W,SCREEN_H);
    font24 = al_load_font("../nonespace/img/fontl.ttf",24,0);
    font56 = al_load_font("../nonespace/img/fontl.ttf",56,0);

    timer = al_create_timer(1.0 / FPS);//创建计时器
    event_queue = al_create_event_queue();//创建事件队列
    al_register_event_source(event_queue, al_get_keyboard_event_source());//获得键盘事件装入队列
    al_register_event_source(event_queue, al_get_mouse_event_source());//get mouse event
    al_register_event_source(event_queue, al_get_timer_event_source(timer));//获得计时器事件装入队列
    al_register_event_source(event_queue, al_get_display_event_source(display));//获得显示事件装入队列
    al_clear_to_color(al_map_rgb(0,0,0));
    al_flip_display();


    //结构体初始化
    init_spaceship(s);

    //开始计时器
    al_start_timer(timer);

        while(s->gone != 0)
        {
            redraw = true;
            ALLEGRO_EVENT event;
            al_wait_for_event(event_queue,&event);//把事件队列里的事件装入事件 event

            if(event.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                switch(event.keyboard.keycode)
                {
                case ALLEGRO_KEY_SPACE:
                    keys[SPACE] = true;
//                    fire_blast(blast,blast_num,s);
                    break;
                }
            }
            else if(event.type == ALLEGRO_EVENT_KEY_UP)
            {
                switch(event.keyboard.keycode)
                {
                case ALLEGRO_KEY_SPACE:
                    keys[SPACE] = false;
                    break;
                case ALLEGRO_KEY_ESCAPE:
                    s->gone = 0;
                    break;
                }
            }
            else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                al_clear_to_color(al_map_rgb(0,0,0));
                break;
            }
            else if(event.type == ALLEGRO_EVENT_MOUSE_AXES){
                s->heading = 0;
                s->speed = 0;
                s->sx = event.mouse.x;
                s->sy = event.mouse.y;
            }
            else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
//                fire_blast(blast,blast_num,s);
            }
            else if(event.type == ALLEGRO_EVENT_TIMER)
            {
                al_clear_to_color(al_map_rgb(0,0,0));
                s->time++;


                // 碰撞检测系统

                redraw = true;

             if(redraw && al_is_event_queue_empty(event_queue))
                {


                    //各种对象绘制
                    ship_live(s);
                    draw_spaceship(s);
                    al_flip_display();
                    redraw = false;
                }
            }
        grades = s->score;
        }

    al_flip_display();
    al_destroy_display(display);
    free(s);
    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue);
    al_destroy_font(font24);
    al_destroy_font(font56);

    return 0;
}


