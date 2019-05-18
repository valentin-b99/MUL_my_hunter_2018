/*
** EPITECH PROJECT, 2018
** create_sprites
** File description:
** create_sprites
*/

#include "../includes/myhunter.h"
#include "../includes/my_functions.h"

sfSprite *create_sprite(char *path, sfVector2f position)
{
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, position);
    return (sprite);
}

struct s_sprites create_sprites_next(struct s_positions *Pos)
{
    struct s_sprites Sprites;

    Sprites.chknrn_1 = create_sprite("./imgs/chickenfly.png", Pos->chiknrn_1);
    Sprites.chknrn_2 = create_sprite("./imgs/chickenfly.png", Pos->chiknrn_2);
    Sprites.chknrn_3 = create_sprite("./imgs/chickenfly.png", Pos->chiknrn_3);
    Sprites.chkndd_1 = create_sprite("./imgs/chickendead.png", Pos->chikndd);
    Sprites.chkndd_2 = create_sprite("./imgs/chickendead.png", Pos->chikndd);
    Sprites.chkndd_3 = create_sprite("./imgs/chickendead.png", Pos->chikndd);
    Sprites.gunsights = create_sprite("./imgs/gunsights.png", Pos->gunsights);
    Sprites.gun = create_sprite("./imgs/gun.png", Pos->gun);
    Sprites.impact = create_sprite("./imgs/impact.png", Pos->impact);
    Sprites.sb = create_sprite("./imgs/scoreboard.png", Pos->sb);
    Sprites.heart = create_sprite("./imgs/heart.png", Pos->heart);
    Sprites.ammo = create_sprite("./imgs/ammo.png", Pos->ammo);
    Sprites.fly_bon = create_sprite("./imgs/flybonnus.png", Pos->fly_bon);
    Sprites.x3_bon = create_sprite("./imgs/x3bonnus.png", Pos->x3_bon);
    Sprites.x2_bon = create_sprite("./imgs/x2bonnus.png", Pos->x2_bon);
    return (Sprites);
}

struct s_sprites create_sprites(struct s_positions *Pos, struct s_rect Rect)
{
    struct s_sprites Sprites = create_sprites_next(Pos);
    sfIntRect rect_bonnus = {0, 0, 0, 0};

    set_chknrn_pos(Pos);
    Sprites.bg_1 = create_sprite("./imgs/bg1.png", Pos->bg_1);
    Sprites.bg_2 = create_sprite("./imgs/bg2.png", Pos->bg_2);
    sfSprite_setTextureRect(Sprites.chknrn_1, Rect.chknrn_1);
    sfSprite_setTextureRect(Sprites.chknrn_2, Rect.chknrn_2);
    sfSprite_setTextureRect(Sprites.chknrn_3, Rect.chknrn_3);
    sfSprite_setTextureRect(Sprites.gun, Rect.gun);
    sfSprite_setTextureRect(Sprites.fly_bon, rect_bonnus);
    sfSprite_setTextureRect(Sprites.x3_bon, rect_bonnus);
    sfSprite_setTextureRect(Sprites.x2_bon, rect_bonnus);
    return (Sprites);
}