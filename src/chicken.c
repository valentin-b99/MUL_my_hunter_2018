/*
** EPITECH PROJECT, 2018
** chicken
** File description:
** chicken
*/

#include "../includes/myhunter.h"
#include "../includes/my_functions.h"

void chg_chknrn_to_fly(sfSprite **sprite, sfIntRect rect, int *floor)
{
    sfTexture *tex = sfTexture_createFromFile("./imgs/chickenfly.png", NULL);
    sfSprite_setTexture(*sprite, tex, sfTrue);
    sfSprite_setTextureRect(*sprite, rect);
    *floor = 0;
}

int test_step_chkn(sfSprite *sprite, int step, int *floor, struct s_main *Main)
{
    sfTexture *texture;

    if ((sfSprite_getPosition(sprite).y < 176 && step == 1) ||
    (sfSprite_getPosition(sprite).y < 415 && step == 2) ||
    (sfSprite_getPosition(sprite).y < 645 && step == 3)) {
        sfSprite_move(sprite, Main->Vect.chiknfly);
    } else if (*floor == 0) {
        texture = sfTexture_createFromFile("./imgs/chickenrun.png", NULL);
        sfSprite_setTexture(sprite, texture, sfTrue);
        sfSprite_setTextureRect(sprite, Main->Rect.chknrn_1);
        *floor = 1;
    } else {
        sfSprite_move(sprite, Main->Vect.chiknrn);
    }
}

void move_chknrns(struct s_main *Main)
{
    test_step_chkn(Main->Sprites.chknrn_1, Main->Step.chkn_1,
    &Main->Floor.chkn_1, Main);
    test_step_chkn(Main->Sprites.chknrn_2, Main->Step.chkn_2,
    &Main->Floor.chkn_2, Main);
    test_step_chkn(Main->Sprites.chknrn_3, Main->Step.chkn_3,
    &Main->Floor.chkn_3, Main);
}