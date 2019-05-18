/*
** EPITECH PROJECT, 2018
** events_and_pos
** File description:
** events_and_pos
*/

#include "../includes/myhunter.h"
#include "../includes/my_functions.h"

void set_chknrn_pos(struct s_positions *Pos)
{
    Pos->chiknrn_1.x = (rand() % 1000) - 500;
    Pos->chiknrn_1.y = (rand() % 500) - 500;
    Pos->chiknrn_2.x = (rand() % 1000) - 500;
    Pos->chiknrn_2.y = (rand() % 500) - 500;
    Pos->chiknrn_3.x = (rand() % 1000) - 500;
    Pos->chiknrn_3.y = (rand() % 500) - 500;
    if (Pos->chiknrn_1.x > 430)
        Pos->chiknrn_1.x = (rand() % 700) + 500;
    if (Pos->chiknrn_2.x > 430)
        Pos->chiknrn_2.x = (rand() % 700) + 500;
    if (Pos->chiknrn_3.x > 430)
        Pos->chiknrn_3.x = (rand() % 700) + 500;
}

void analyse_events(sfRenderWindow *window, struct s_main *Main)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.key.code == sfKeyEscape)
            sfRenderWindow_close(window);
        test_hit_chknrns(window, event, Main);
    }
}
