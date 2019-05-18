/*
** EPITECH PROJECT, 2018
** hits
** File description:
** hits
*/

#include "../includes/myhunter.h"
#include "../includes/my_functions.h"

int test_hit_chknrn(sfRenderWindow *window, sfEvent event,
sfSprite *sprite)
{
    if (event.key.code != sfMouseLeft && event.type != sfEvtMouseButtonPressed)
        return (0);
    if (sfMouse_getPositionRenderWindow(window).x <
        sfSprite_getPosition(sprite).x)
        return (0);
    if (sfMouse_getPositionRenderWindow(window).x >
        sfSprite_getPosition(sprite).x + 206)
        return (0);
    if (sfMouse_getPositionRenderWindow(window).y <
        sfSprite_getPosition(sprite).y)
        return (0);
    if (sfMouse_getPositionRenderWindow(window).y >
        sfSprite_getPosition(sprite).y + 170)
        return (0);
    return (1);
}

void test_all_hit_chknrn_next(struct s_main *Main, int *hits)
{
    if (hits[1]) {
        chg_chknrn_to_fly(&Main->Sprites.chknrn_2, Main->Rect.chknrn_2,
        &Main->Floor.chkn_2);
        chg_sprt_aft_hit(Main->Sprites.chknrn_2, Main->Sprites.chkndd_2,
        &Main->Step.chkn_2, Main);
        Main->Sb.kills += 1;
        Main->Sb.score += 1;
        sfMusic_play(Main->Sounds.chknhurt);
    }
    if (hits[2]) {
        chg_chknrn_to_fly(&Main->Sprites.chknrn_3, Main->Rect.chknrn_3,
        &Main->Floor.chkn_3);
        chg_sprt_aft_hit(Main->Sprites.chknrn_3, Main->Sprites.chkndd_3,
        &Main->Step.chkn_3, Main);
        Main->Sb.kills += 1;
        Main->Sb.score += 1;
        sfMusic_play(Main->Sounds.chknhurt);
    }
}

void test_all_hit_chknrn(sfRenderWindow *window, sfEvent event,
struct s_main *Main)
{
    int hits[3];

    hits[0] = test_hit_chknrn(window, event, Main->Sprites.chknrn_1);
    hits[1] = test_hit_chknrn(window, event, Main->Sprites.chknrn_2);
    hits[2] = test_hit_chknrn(window, event, Main->Sprites.chknrn_3);
    test_bonnus(Main, hits);
    if (hits[0]) {
        chg_chknrn_to_fly(&Main->Sprites.chknrn_1, Main->Rect.chknrn_1,
        &Main->Floor.chkn_1);
        chg_sprt_aft_hit(Main->Sprites.chknrn_1, Main->Sprites.chkndd_1,
        &Main->Step.chkn_1, Main);
        Main->Sb.kills += 1;
        Main->Sb.score += 1;
        sfMusic_play(Main->Sounds.chknhurt);
    }
    test_all_hit_chknrn_next(Main, hits);
}

void test_hit_chknrns(sfRenderWindow *window, sfEvent event,
struct s_main *Main)
{
    if (!test_hit_chknrn(window, event, Main->Sprites.chknrn_1) &&
    !test_hit_chknrn(window, event, Main->Sprites.chknrn_2) &&
    !test_hit_chknrn(window, event, Main->Sprites.chknrn_3) &&
    event.key.code == sfMouseLeft && event.type == sfEvtMouseButtonPressed) {
        Main->Pos.impact.x = sfMouse_getPositionRenderWindow(window).x - 25;
        Main->Pos.impact.y = sfMouse_getPositionRenderWindow(window).y - 25;
        sfSprite_setPosition(Main->Sprites.impact, Main->Pos.impact);
        Main->Rect.impact.left = 0;
        sfSprite_setTextureRect(Main->Sprites.impact, Main->Rect.impact);
    }
    if (event.key.code == sfMouseLeft &&
    event.type == sfEvtMouseButtonPressed) {
        Main->Rect.gun.left = 374;
        sfSprite_setTextureRect(Main->Sprites.gun, Main->Rect.gun);
        sfMusic_play(Main->Sounds.fire);
    }
    test_all_hit_chknrn(window, event, Main);
}

void chg_sprt_aft_hit(sfSprite *chknrn, sfSprite *chkndd, int *step,
struct s_main *Main)
{
    sfSprite_setPosition(chkndd, sfSprite_getPosition(chknrn));
    set_chknrn_pos(&Main->Pos);
    sfSprite_setPosition(chknrn, Main->Pos.chiknrn_1);
    *step = rand() % 3 + 1;
}