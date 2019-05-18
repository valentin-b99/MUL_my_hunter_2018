/*
** EPITECH PROJECT, 2018
** change_rect
** File description:
** change_rect
*/

#include "../includes/myhunter.h"
#include "../includes/my_functions.h"

sfIntRect chg_rct_sprt_chiknrn(sfSprite *sprite, sfIntRect rect)
{
    if (rect.left >= 1030) {
        rect.left = 0;
    } else {
        rect.left += 206;
    }
    return (rect);
}

void chg_rct_sprt_chiknrns(struct s_main *Main, sfClock **clock)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(*clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.2 - (Main->Sb.lvl / 50)) {
        Main->Rect.chknrn_1 = chg_rct_sprt_chiknrn(Main->Sprites.chkndd_1,
        Main->Rect.chknrn_1);
        sfSprite_setTextureRect(Main->Sprites.chknrn_1, Main->Rect.chknrn_1);
        Main->Rect.chknrn_2 = chg_rct_sprt_chiknrn(Main->Sprites.chkndd_2,
        Main->Rect.chknrn_2);
        sfSprite_setTextureRect(Main->Sprites.chknrn_2, Main->Rect.chknrn_2);
        Main->Rect.chknrn_3 = chg_rct_sprt_chiknrn(Main->Sprites.chkndd_3,
        Main->Rect.chknrn_3);
        sfSprite_setTextureRect(Main->Sprites.chknrn_3, Main->Rect.chknrn_3);
        sfClock_restart(*clock);
    }
}

void chg_rct_sprt_impact(struct s_main *Main, sfClock **clock)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(*clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        Main->Rect.impact.left += 50;
        sfSprite_setTextureRect(Main->Sprites.impact, Main->Rect.impact);
        sfClock_restart(*clock);
    }
}

void chg_rct_sprt_gun(struct s_main *Main, sfClock **clock)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(*clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.08) {
        Main->Rect.gun.left = 0;
        sfSprite_setTextureRect(Main->Sprites.gun, Main->Rect.gun);
        sfClock_restart(*clock);
    }
}

void chg_rct_sprt_bonnus(struct s_sprites Sprites, sfClock **clock)
{
    sfTime time;
    float seconds = 0.0;
    sfIntRect rect = {0, 0, 0, 0};

    time = sfClock_getElapsedTime(*clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 1) {
        sfSprite_setTextureRect(Sprites.fly_bon, rect);
        sfSprite_setTextureRect(Sprites.x3_bon, rect);
        sfSprite_setTextureRect(Sprites.x2_bon, rect);
        sfClock_restart(*clock);
    }
}