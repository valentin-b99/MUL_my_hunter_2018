/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "../includes/myhunter.h"
#include "../includes/my_functions.h"
#include "../includes/structs.h"
#include <unistd.h>

sfRenderWindow *create_windows(sfRenderWindow *window)
{
    sfVideoMode mode = {1920, 1020, 32};

    window = sfRenderWindow_create(mode, "Chicken Run",
    sfResize | sfClose, NULL);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setIcon(window, 206, 206,
    sfImage_getPixelsPtr(sfImage_createFromFile("./imgs/icon.png")));
    return (window);
}

struct s_main create_main_struct(void)
{
    struct s_sprites Sprites = create_sprites(&Pos, Rect);
    struct s_text Texts = create_texts(Pos);
    struct s_sounds Sounds = create_sounds();
    struct s_main Main =
    {Sprites, Texts, Sounds, Vectors, Pos, Step, Rect, Floor, Sb};

    return (Main);
}

void my_hunter(int level)
{
    sfRenderWindow *window = create_windows(window);
    struct s_main Main = create_main_struct();
    sfClock *chkn_clock = sfClock_create();
    sfClock *impct_clock = sfClock_create();
    sfClock *gun_clock = sfClock_create();
    sfClock *bonnus_clock = sfClock_create();

    set_lvl(level, &Main);
    while (sfRenderWindow_isOpen(window) && Main.Sb.life > 0) {
        analyse_events(window, &Main);
        draw_all(window, &Main);
        chg_rct_sprt_chiknrns(&Main, &chkn_clock);
        chg_rct_sprt_impact(&Main, &impct_clock);
        chg_rct_sprt_gun(&Main, &gun_clock);
        chg_rct_sprt_bonnus(Main.Sprites, &bonnus_clock);
        chg_lvl(&Main);
    }
    gameover(window, &Main);
    destroy_all(window, &Main);
}

int main(int ac, char **av)
{
    if (ac == 1) {
        my_hunter(1);
    } else if (av[1][0] == '-' && av[1][1] == 'h') {
        write(1, "USAGE\n", 6);
        write(1, "\t./my_hunter [level]\n\n", 22);
        write(1, "DESCRIPTION\n", 12);
        write(1, "\tlevel    level (greater than or equal to zero) from", 52);
        write(1, " which you want to start playing.\n\n", 35);
        write(1, "\tGoal of the game    Kill the most chicken and have ", 52);
        write(1, "the best score!\n", 16);
        write(1, "\tScore bonus    Do double / triple kills or kills ", 50);
        write(1, "when a chicken is flying for more or less bonus.\n", 49);
        write(1, "\tLevels    Every ten kills, you increase one level.", 51);
        write(1, " Chickens are going faster and faster.\n", 39);
        write(1, "\tLifes    Whenever a chicken is not killed in time,", 51);
        write(1, " you lose a life. When you have no life, you have lost!", 54);
        write(1, " In addition, at each level you earn a living if you ", 52);
        write(1, "have less than 6.\n", 18);
    } else
        my_hunter(my_getnbr(av[1]));
}
