/*
** EPITECH PROJECT, 2018
** draw
** File description:
** draw
*/

#include "../includes/myhunter.h"
#include "../includes/my_functions.h"

void draw_sprites_next(struct s_main *Main)
{
    sfSprite_setTextureRect(Main->Sprites.gun, Main->Rect.gun);
    move_chknrns(Main);
    sfSprite_move(Main->Sprites.chkndd_1, Main->Vect.chikndd);
    sfSprite_move(Main->Sprites.chkndd_2, Main->Vect.chikndd);
    sfSprite_move(Main->Sprites.chkndd_3, Main->Vect.chikndd);
    chkn_no_kill(Main);
}

void draw_sprites(sfRenderWindow *window, struct s_main *Main)
{
    sfRenderWindow_drawSprite(window, Main->Sprites.bg_1, NULL);
    sfRenderWindow_drawSprite(window, Main->Sprites.chknrn_1, NULL);
    sfRenderWindow_drawSprite(window, Main->Sprites.chknrn_2, NULL);
    sfRenderWindow_drawSprite(window, Main->Sprites.chknrn_3, NULL);
    sfRenderWindow_drawSprite(window, Main->Sprites.bg_2, NULL);
    sfRenderWindow_drawSprite(window, Main->Sprites.impact, NULL);
    draw_chknrns_top(window, Main);
    sfRenderWindow_drawSprite(window, Main->Sprites.chkndd_1, NULL);
    sfRenderWindow_drawSprite(window, Main->Sprites.chkndd_2, NULL);
    sfRenderWindow_drawSprite(window, Main->Sprites.chkndd_3, NULL);
    sfRenderWindow_drawSprite(window, Main->Sprites.gun, NULL);
    sfRenderWindow_drawSprite(window, Main->Sprites.sb, NULL);
    sfRenderWindow_drawSprite(window, Main->Sprites.heart, NULL);
    sfRenderWindow_drawSprite(window, Main->Sprites.ammo, NULL);
    sfRenderWindow_drawSprite(window, Main->Sprites.fly_bon, NULL);
    sfRenderWindow_drawSprite(window, Main->Sprites.x3_bon, NULL);
    sfRenderWindow_drawSprite(window, Main->Sprites.x2_bon, NULL);
    draw_gunsights(window, Main);
    draw_sprites_next(Main);
}

void draw_texts(sfRenderWindow *window, struct s_main *Main)
{
    char score[20] = "Score: ";
    char kills[20] = "Kills: ";
    char lvl[20] = "Level: ";

    my_strcat(score, int_to_char(Main->Sb.score));
    sfText_setString(Main->Texts.score, score);
    my_strcat(kills, int_to_char(Main->Sb.kills));
    sfText_setString(Main->Texts.kills, kills);
    my_strcat(lvl, int_to_char(Main->Sb.lvl));
    sfText_setString(Main->Texts.lvl, lvl);
    sfRenderWindow_drawText(window, Main->Texts.score, NULL);
    sfRenderWindow_drawText(window, Main->Texts.kills, NULL);
    sfRenderWindow_drawText(window, Main->Texts.lvl, NULL);
}

void draw_all(sfRenderWindow *window, struct s_main *Main)
{
    draw_sprites(window, Main);
    draw_texts(window, Main);
    sfRenderWindow_display(window);
}