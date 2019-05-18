/*
** EPITECH PROJECT, 2018
** create_sounds
** File description:
** create_sounds
*/

#include "../includes/myhunter.h"
#include "../includes/my_functions.h"

struct s_sounds create_sounds(void)
{
    struct s_sounds Sounds;

    Sounds.fire = sfMusic_createFromFile("./sounds/fire.ogg");
    Sounds.damage = sfMusic_createFromFile("./sounds/damage.ogg");
    Sounds.chknhurt = sfMusic_createFromFile("./sounds/chickenhurt.ogg");
    Sounds.bonus = sfMusic_createFromFile("./sounds/bonus.ogg");
    Sounds.lvlup = sfMusic_createFromFile("./sounds/levelup.ogg");
    Sounds.gameover = sfMusic_createFromFile("./sounds/gameover.ogg");
    Sounds.crischevre = sfMusic_createFromFile("./sounds/crischevre.ogg");
    sfMusic_setVolume(Sounds.chknhurt, 40);
    return (Sounds);
}