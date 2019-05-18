/*
** EPITECH PROJECT, 2018
** draw2
** File description:
** draw2
*/

#include "../includes/myhunter.h"
#include "../includes/my_functions.h"

void draw_gunsights(sfRenderWindow *window, struct s_main *Main)
{
    sfVector2f position;
    sfVector2f position_gun = Main->Pos.gun;

    position.x = sfMouse_getPositionRenderWindow(window).x - 35;
    position.y = sfMouse_getPositionRenderWindow(window).y - 35;
    sfSprite_setPosition(Main->Sprites.gunsights, position);
    sfRenderWindow_drawSprite(window, Main->Sprites.gunsights, NULL);
    sfSprite_setRotation(Main->Sprites.gun, (position.x / 200) - 8);
    position_gun.y = Main->Pos.gun.y - (position.y / 80);
    sfSprite_setPosition(Main->Sprites.gun, position_gun);
}

void draw_chknrn_top(sfRenderWindow *window, sfSprite *sprite, int step)
{
    if (sfSprite_getPosition(sprite).y < 176 && step == 1)
        sfRenderWindow_drawSprite(window, sprite, NULL);
    if (sfSprite_getPosition(sprite).y < 415 && step == 2)
        sfRenderWindow_drawSprite(window, sprite, NULL);
    if (sfSprite_getPosition(sprite).y < 645 && step == 3)
        sfRenderWindow_drawSprite(window, sprite, NULL);
}

void draw_chknrns_top(sfRenderWindow *window, struct s_main *Main)
{
    draw_chknrn_top(window, Main->Sprites.chknrn_1, Main->Step.chkn_1);
    draw_chknrn_top(window, Main->Sprites.chknrn_2, Main->Step.chkn_2);
    draw_chknrn_top(window, Main->Sprites.chknrn_3, Main->Step.chkn_3);
}