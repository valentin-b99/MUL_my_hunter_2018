/*
** EPITECH PROJECT, 2018
** destroy
** File description:
** destroy
*/

#include "../includes/myhunter.h"
#include "../includes/my_functions.h"

void destroy_sprites(struct s_sprites *Sprites)
{
    sfSprite_destroy(Sprites->bg_1);
    sfSprite_destroy(Sprites->bg_2);
    sfSprite_destroy(Sprites->chknrn_1);
    sfSprite_destroy(Sprites->chknrn_2);
    sfSprite_destroy(Sprites->chknrn_3);
    sfSprite_destroy(Sprites->chkndd_1);
    sfSprite_destroy(Sprites->chkndd_2);
    sfSprite_destroy(Sprites->chkndd_3);
    sfSprite_destroy(Sprites->gunsights);
    sfSprite_destroy(Sprites->gun);
    sfSprite_destroy(Sprites->impact);
    sfSprite_destroy(Sprites->sb);
    sfSprite_destroy(Sprites->heart);
    sfSprite_destroy(Sprites->ammo);
    sfSprite_destroy(Sprites->fly_bon);
    sfSprite_destroy(Sprites->x3_bon);
    sfSprite_destroy(Sprites->x2_bon);
}

void destroy_texts(struct s_text *Texts)
{
    sfText_destroy(Texts->score);
    sfText_destroy(Texts->kills);
    sfText_destroy(Texts->lvl);
    sfText_destroy(Texts->gameover);
    sfText_destroy(Texts->menu);
}

void destroy_sounds(struct s_sounds *Sounds)
{
    sfMusic_destroy(Sounds->fire);
    sfMusic_destroy(Sounds->damage);
    sfMusic_destroy(Sounds->chknhurt);
    sfMusic_destroy(Sounds->bonus);
    sfMusic_destroy(Sounds->lvlup);
    sfMusic_destroy(Sounds->gameover);
    sfMusic_destroy(Sounds->crischevre);
}

void destroy_all(sfRenderWindow *window, struct s_main *Main)
{
    destroy_sprites(&Main->Sprites);
    destroy_texts(&Main->Texts);
    destroy_sounds(&Main->Sounds);
    sfRenderWindow_destroy(window);
}