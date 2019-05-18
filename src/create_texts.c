/*
** EPITECH PROJECT, 2018
** create_texts
** File description:
** create_texts
*/

#include "../includes/myhunter.h"
#include "../includes/my_functions.h"

sfText *create_text(char *d_text, int size, sfVector2f position)
{
    sfText *text = sfText_create();

    sfText_setString(text, d_text);
    sfText_setFont(text, sfFont_createFromFile("./fonts/GROBOLD.ttf"));
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, position);
    return (text);
}

struct s_text create_texts(struct s_positions Pos)
{
    struct s_text Texts;

    Texts.score = create_text("Score: 0", 45, Pos.text_score);
    Texts.kills = create_text("Kills: 0", 30, Pos.text_kills);
    Texts.lvl = create_text("Level: 0", 30, Pos.text_lvl);
    Texts.gameover = create_text("GameOver :(", 120, Pos.text_gameover);
    Texts.menu = create_text("Return for exit", 30, Pos.text_menu);
    return (Texts);
}
