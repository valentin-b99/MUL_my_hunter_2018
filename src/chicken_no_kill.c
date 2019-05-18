/*
** EPITECH PROJECT, 2018
** chicken_no_kill
** File description:
** chicken_no_kill
*/

#include "../includes/myhunter.h"
#include "../includes/my_functions.h"

void chkn_no_kill_chkn3(struct s_main *Main)
{
    if (sfSprite_getPosition(Main->Sprites.chknrn_3).x > 1920) {
        set_chknrn_pos(&Main->Pos);
        chg_chknrn_to_fly(&Main->Sprites.chknrn_3, Main->Rect.chknrn_3,
        &Main->Floor.chkn_3);
        sfSprite_setPosition(Main->Sprites.chknrn_3, Main->Pos.chiknrn_3);
        Main->Step.chkn_3 = rand() % 3 + 1;
        Main->Sb.life -= 1;
        Main->Rect.heart.width -= 45;
        sfMusic_play(Main->Sounds.damage);
        sfSprite_setTextureRect(Main->Sprites.heart, Main->Rect.heart);
    }
}

void chkn_no_kill_chkn2(struct s_main *Main)
{
    if (sfSprite_getPosition(Main->Sprites.chknrn_2).x > 1920) {
        set_chknrn_pos(&Main->Pos);
        chg_chknrn_to_fly(&Main->Sprites.chknrn_2, Main->Rect.chknrn_2,
        &Main->Floor.chkn_2);
        sfSprite_setPosition(Main->Sprites.chknrn_2, Main->Pos.chiknrn_2);
        Main->Step.chkn_2 = rand() % 3 + 1;
        Main->Sb.life -= 1;
        Main->Rect.heart.width -= 45;
        sfMusic_play(Main->Sounds.damage);
        sfSprite_setTextureRect(Main->Sprites.heart, Main->Rect.heart);
    }
}

void chkn_no_kill(struct s_main *Main)
{
    if (sfSprite_getPosition(Main->Sprites.chknrn_1).x > 1920) {
        set_chknrn_pos(&Main->Pos);
        chg_chknrn_to_fly(&Main->Sprites.chknrn_1, Main->Rect.chknrn_1,
        &Main->Floor.chkn_1);
        sfSprite_setPosition(Main->Sprites.chknrn_1, Main->Pos.chiknrn_1);
        Main->Step.chkn_1 = rand() % 3 + 1;
        Main->Sb.life -= 1;
        Main->Rect.heart.width -= 45;
        sfMusic_play(Main->Sounds.damage);
        sfSprite_setTextureRect(Main->Sprites.heart, Main->Rect.heart);
    }
    chkn_no_kill_chkn2(Main);
    chkn_no_kill_chkn3(Main);
}