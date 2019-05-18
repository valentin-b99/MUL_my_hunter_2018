/*
** EPITECH PROJECT, 2018
** bonus
** File description:
** bonus
*/

#include "../includes/myhunter.h"
#include "../includes/my_functions.h"

int test_flykill(sfSprite *sprite, int hit, int step)
{
    if (hit && ((sfSprite_getPosition(sprite).y < 176 && step == 1) ||
    (sfSprite_getPosition(sprite).y < 415 && step == 2) ||
    (sfSprite_getPosition(sprite).y < 645 && step == 3))) {
        return (1);
    }
    return (0);
}

void special_score(int fly_kill, int *hits, struct s_main *Main)
{
    if (fly_kill && ((hits[0] && hits[1]) || (hits[0] && hits[2]) ||
    (hits[1] && hits[2]))) {
        Main->Sb.score += 4;
    } else if (fly_kill && hits[0] && hits[1] && hits[2]) {
        Main->Sb.score += 9;
    }
}

int test_bonnus_next(struct s_main *Main, int *hits)
{
    sfIntRect rect = {0, 0, 63, 64};
    int fly_kill = 0;

    if (test_flykill(Main->Sprites.chknrn_1, hits[0], Main->Step.chkn_1) ||
    test_flykill(Main->Sprites.chknrn_2, hits[1], Main->Step.chkn_2) ||
    test_flykill(Main->Sprites.chknrn_3, hits[2], Main->Step.chkn_3)) {
        sfSprite_setTextureRect(Main->Sprites.fly_bon, rect);
        Main->Sb.score += 10;
        fly_kill = 1;
        sfMusic_play(Main->Sounds.bonus);
    }
    return (fly_kill);
}

void test_bonnus(struct s_main *Main, int *hits)
{
    sfIntRect rect = {0, 0, 63, 64};
    int fly_kill = 0;

    if (hits[0] && hits[1] && hits[2]) {
        sfSprite_setTextureRect(Main->Sprites.x3_bon, rect);
        Main->Sb.score += 10;
        sfMusic_play(Main->Sounds.bonus);
    } else if ((hits[0] && hits[1]) || (hits[0] && hits[2]) ||
    (hits[1] && hits[2])) {
        sfSprite_setTextureRect(Main->Sprites.x2_bon, rect);
        Main->Sb.score += 5;
        sfMusic_play(Main->Sounds.bonus);
    }
    fly_kill = test_bonnus_next(Main, hits);
    special_score(fly_kill, hits, Main);
}