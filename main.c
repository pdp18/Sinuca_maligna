#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <stdlib.h>
#include <stdio.h>
#include "Bola.h"
#include <time.h>

//bool inicializa(ALLEGRO_DISPLAY* janela, ALLEGRO_EVENT_QUEUE* fila);
void menu(Bola* b, Vetori* limhor, Vetori* limver); //Ser� que � �til?

int main()
{
    int n_bolas, i;
    float raio;
    Vetorf vel, pos;
    Vetori limhor, limver;
    Bola* b = NULL;
    srand(time(NULL));
    limhor.x = 100;
    limhor.y = 1266;

    limver.x = 100;
    limver.y = 668;

    printf("Qual a quantidade de bolas? ");
    scanf("%d", &n_bolas);

    printf("Qual o raio das bolas? ");
    scanf("%f", &raio);

    printf("Qual o velocidade da bola em pixels? ");
    scanf("%f%f", &vel.x, &vel.y);

    for (i = 0; i < n_bolas; i++)
    {


        pos.x =rand()%(limhor.y - 2*(int)raio + 1) + (int)raio + limhor.x;
        pos.y =rand()%(limver.y - 2*(int)raio + 1) +(int) raio + limver.x;
        b = insereBola(b, raio, &pos, &vel);
        Sleep(1001);
    }

    printf("BOLA1 velx: %f | vely: %f\n", b->vel.x, b->vel.y);
    //printf("BOLA2 velx: %f | vely: %f", b->prox->vel.x, b->prox->vel.y);

    if (!al_init())
    {
        int r = al_show_native_message_box(NULL, "Erro", "Al_Init", "Allegro n�o foi iniciada",NULL, ALLEGRO_MESSAGEBOX_ERROR);
        printf("%i",r);
        return true;
    }

    ALLEGRO_DISPLAY* janela = al_create_display(1366.f, 768.f);
    if (!janela)
    {
        int r = al_show_native_message_box(NULL, "Erro", "Window", "Janela n�o foi iniciada",NULL, ALLEGRO_MESSAGEBOX_ERROR);
        printf("%i",r);
        return true;
    }
    al_set_window_title(janela, "Sinuca Maligna");

    if (!al_init_primitives_addon())
    {
        int r = al_show_native_message_box(NULL, "Erro", "Primitives", "Primitivos n�o iniciados",NULL, ALLEGRO_MESSAGEBOX_ERROR);
        printf("%i",r);
        return true;
    }

    ALLEGRO_EVENT_QUEUE* fila = al_create_event_queue();

    if (!fila)
    {
        int r = al_show_native_message_box(NULL, "Erro", "Eventos", "Eventos n�o iniciados",NULL, ALLEGRO_MESSAGEBOX_ERROR);
        printf("%i",r);
        return true;
    }

    //if (inicializa(janela, fila))
        //return 1;

    ALLEGRO_TIMER* cronometro = cronometro = al_create_timer(1.f/60.f);
    al_register_event_source(fila, al_get_timer_event_source(cronometro));
    al_register_event_source(fila, al_get_display_event_source(janela));

    bool quit = false;
    bool menu = false;
    bool draw = true;

    al_start_timer(cronometro);

    while (!quit)
    {
        if (menu)
        {
            al_stop_timer(cronometro);

            limpaBolas(b);

            printf("Qual a quantidade de bolas? ");
            scanf("%d", &n_bolas);

            printf("Qual o raio das bolas? ");
            scanf("%f", &raio);

            printf("Qual o velocidade da bola em pixels? ");
            scanf("%f%f", &vel.x, &vel.y);

            for (i = 0; i < n_bolas; i++)
            {
                pos = posicaoAleatoria(raio, &limhor, &limver);
                b = insereBola(b, raio, &vel, &pos);
            }

            menu = false;

            al_start_timer(cronometro);
        }

        ALLEGRO_EVENT evento;

        al_wait_for_event(fila, &evento);

        switch (evento.type)
        {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                quit = true;
            break;

            case ALLEGRO_EVENT_KEY_DOWN:
            {
                if (evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                    menu = true;

                else if (evento.keyboard.keycode == ALLEGRO_KEY_P) //Pause a desenvolver
                {

                }
            }
            break;

            case ALLEGRO_EVENT_TIMER:
            {
                if (evento.timer.source == cronometro)
                {
                    Bola*  aux;
                    Bola* aux2;

                    for(aux = b; aux != NULL; aux = aux->prox)
                    {
                        somaVetorf(&aux->pos, &aux->vel);
                        colisaoParede(aux, &limhor, &limver);

                        for(aux2 = aux->prox; aux2 != NULL ;aux2=aux2->prox)
                            bola_com_bola(aux,aux2);

                        al_draw_filled_circle(aux->pos.x, aux->pos.y, aux->raio, al_map_rgb(255, 0, 0));
                    }

                    draw = true;
                }
            }
            break;

            default:
            break;
        }

        if (draw)
        {
            al_draw_rectangle(limhor.x, limver.x, limhor.y, limver.y, al_map_rgb(255, 255, 255), 1.0);
            al_flip_display();
            al_clear_to_color(al_map_rgb(0, 0, 0));
            draw = false;
        }
    }

    al_destroy_display(janela);
    al_destroy_event_queue(fila);

    return 0;
}

void menu(Bola* b, Vetori* limhor, Vetori* limver) //Ser� que � �til?
{

}

/*
bool inicializa(ALLEGRO_DISPLAY* janela, ALLEGRO_EVENT_QUEUE* fila)
{
    if (!al_init())
    {
        int r = al_show_native_message_box(NULL, "Erro", "Al_Init", "Allegro n�o foi iniciada",NULL, ALLEGRO_MESSAGEBOX_ERROR);
        printf("%i",r);
        return true;
    }

    janela = al_create_display(1366.f, 768.f);
    if (!janela)
    {
        int r = al_show_native_message_box(NULL, "Erro", "Window", "Janela n�o foi iniciada",NULL, ALLEGRO_MESSAGEBOX_ERROR);
        printf("%i",r);
        return true;
    }
    al_set_window_title(janela, "Sinuca Maligna");

    fila = al_create_event_queue();
    if (!fila)
    {
        int r = al_show_native_message_box(NULL, "Erro", "Eventos", "Eventos n�o iniciados",NULL, ALLEGRO_MESSAGEBOX_ERROR);
        printf("%i",r);
        return true;
    }

    if (!al_init_primitives_addon())
    {
        int r = al_show_native_message_box(NULL, "Erro", "Primitives", "Primitivos n�o iniciados",NULL, ALLEGRO_MESSAGEBOX_ERROR);
        printf("%i",r);
        return true;
    }

    return false;
}
*/
