/*
** EPITECH PROJECT, 2018
** gameover
** File description:
** gameover
*/

#include "../includes/myhunter.h"
#include "../includes/my_functions.h"

sfText *set_text_gameover(sfText *text, sfVector2f pos, int size, sfColor color)
{
    sfVector2f center;

    sfText_setCharacterSize(text, size);
    center.x = sfText_getLocalBounds(text).width / 2;
    sfText_setOrigin(text, center);
    sfText_setPosition(text, pos);
    sfText_setColor(text, color);
    return (text);
}

struct s_text set_texts_gameover(struct s_text OTexts, struct s_main *Main)
{
    struct s_text Texts;
    sfVector2f pos_score = {960, 500};
    sfVector2f pos_kills = {800, 700};
    sfVector2f pos_lvl = {1120, 700};

    Texts.gameover = set_text_gameover(OTexts.gameover, Main->Pos.text_gameover,
    130, sfYellow);
    Texts.score = set_text_gameover(OTexts.score, pos_score, 90, sfWhite);
    Texts.kills = set_text_gameover(OTexts.kills, pos_kills, 50, sfWhite);
    Texts.lvl = set_text_gameover(OTexts.lvl, pos_lvl, 50, sfWhite);
    Texts.menu = set_text_gameover(OTexts.menu, Main->Pos.text_menu, 20,
    sfWhite);
    return (Texts);
}

void draw_gameover(sfRenderWindow *window, struct s_text Texts)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawText(window, Texts.gameover, NULL);
    sfRenderWindow_drawText(window, Texts.score, NULL);
    sfRenderWindow_drawText(window, Texts.kills, NULL);
    sfRenderWindow_drawText(window, Texts.lvl, NULL);
    sfRenderWindow_drawText(window, Texts.menu, NULL);
    sfRenderWindow_display(window);
}

void analyse_gameover_events(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.key.code == sfKeyEscape)
            sfRenderWindow_close(window);
        if (event.key.code == sfKeyReturn)
            sfRenderWindow_close(window);
    }
}

void gameover(sfRenderWindow *window, struct s_main *Main)
{
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    sfMusic_play(Main->Sounds.gameover);
    while (sfRenderWindow_isOpen(window)) {
        analyse_gameover_events(window);
        Main->Texts = set_texts_gameover(Main->Texts, Main);
        draw_gameover(window, Main->Texts);
    }
}