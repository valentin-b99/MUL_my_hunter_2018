/*
** EPITECH PROJECT, 2018
** levels.c
** File description:
** levels
*/

#include "../includes/myhunter.h"
#include "../includes/my_functions.h"

void chg_lvl(struct s_main *Main)
{
    if (Main->Sb.kills >= Main->Sb.tmp_kills + 10) {
        Main->Sb.tmp_kills += 10;
        Main->Sb.lvl += 1;
        Main->Vect.chiknfly.x += 0.5;
        Main->Vect.chiknfly.y += 0.5;
        Main->Vect.chiknrn.x += 0.5;
        Main->Vect.chikndd.y += 0.5;
        sfMusic_play(Main->Sounds.lvlup);
        if (Main->Sb.life < 6) {
            Main->Sb.life += 1;
            Main->Rect.heart.width += 45;
            sfSprite_setTextureRect(Main->Sprites.heart, Main->Rect.heart);
        }
    }
}

void set_lvl(int level, struct s_main *Main)
{
    if (level < 1)
        level = 1;
    Main->Vect.chiknfly.x += 0.5 * (level - 1);
    Main->Vect.chiknfly.y += 0.5 * (level - 1);
    Main->Vect.chiknrn.x += 0.5 * (level - 1);
    Main->Vect.chikndd.y += 0.5 * (level - 1);
    Main->Sb.lvl = level;
}