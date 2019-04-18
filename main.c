#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

#include <stdlib.h>
#include <stdio.h>

#include "Bola.h"

bool inicializa(ALLEGRO_DISPLAY* janela, ALLEGRO_EVENT_QUEUE* fila);

int main()
{
    ALLEGRO_DISPLAY* janela = NULL;
    ALLEGRO_EVENT_QUEUE* fila = NULL;

    int n_bolas, i;
    float raio ;
    Vetorf vel, pos;
    Vetori limx, limy;
    Bola* b = NULL;

    limx.x = 100;
    limx.y = 1124;

    limy.x = 100;
    limy.y = 820;

    printf("Qual a quantidade de bolas? ");
    scanf("%d", &n_bolas);

    printf("Qual o raio das bolas? ");
    scanf("%f", &raio);

    printf("Qual o velocidade da bola em pixels? ");
    scanf("%f%f", &vel.x, &vel.y);

    for (i = 0; i < n_bolas; i++)
    {
        pos = posicaoAleatoria(raio, &limx, &limy);
        b = insereBola(b, raio, &vel, &pos);
    }

    if (inicializa(janela, fila))
        return 1;

    al_register_event_source(fila, al_get_display_event_source(janela));

    al_flip_display();

    while (1)
    {
        ALLEGRO_EVENT evento;
        ALLEGRO_TIMEOUT timeout;
        al_init_timeout(&timeout, 0.05);

        int tem_eventos = al_wait_for_event_until(fila, &evento, &timeout);

        if (tem_eventos && evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            break;

        al_clear_to_color(al_map_rgb(255, 255, 255));
        al_flip_display();
    }

    al_destroy_display(janela);
    al_destroy_event_queue(fila);

    return 0;
}

bool inicializa(ALLEGRO_DISPLAY* janela, ALLEGRO_EVENT_QUEUE* fila)
{
    if (!al_init())
    {
        int r = al_show_native_message_box(NULL, "Erro", "Al_Init", "Allegro não foi iniciada",NULL, ALLEGRO_MESSAGEBOX_ERROR);
        printf("%i",r);
        return true;
    }

    if (!al_init_primitives_addon())
    {
        int r = al_show_native_message_box(NULL, "Erro", "Primitives", "Primitivos não iniciados",NULL, ALLEGRO_MESSAGEBOX_ERROR);
        printf("%i",r);
        return true;
    }

    janela = al_create_display(1366.f, 768.f);
    if (!janela)
    {
        int r = al_show_native_message_box(NULL, "Erro", "Window", "Janela não foi iniciada",NULL, ALLEGRO_MESSAGEBOX_ERROR);
        printf("%i",r);
        return true;
    }

    fila = al_create_event_queue();
    if (!fila)
    {
        int r = al_show_native_message_box(NULL, "Erro", "Eventos", "Eventos não iniciados",NULL, ALLEGRO_MESSAGEBOX_ERROR);
        printf("%i",r);
        return true;
    }

    return false;
}
