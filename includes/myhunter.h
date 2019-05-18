/*
** EPITECH PROJECT, 2018
** myhunter
** File description:
** myhunter
*/

#ifndef MYHUNTER_H_
# define MYHUNTER_H_

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/Audio.h>

struct s_sprites
{
    sfSprite *bg_1;
    sfSprite *bg_2;
    sfSprite *chknrn_1;
    sfSprite *chknrn_2;
    sfSprite *chknrn_3;
    sfSprite *chkndd_1;
    sfSprite *chkndd_2;
    sfSprite *chkndd_3;
    sfSprite *gunsights;
    sfSprite *gun;
    sfSprite *impact;
    sfSprite *sb;
    sfSprite *heart;
    sfSprite *ammo;
    sfSprite *fly_bon;
    sfSprite *x3_bon;
    sfSprite *x2_bon;
};

struct s_text
{
    sfText *score;
    sfText *kills;
    sfText *lvl;
    sfText *gameover;
    sfText *menu;
};

struct s_sounds
{
    sfMusic *fire;
    sfMusic *damage;
    sfMusic *chknhurt;
    sfMusic *bonus;
    sfMusic *lvlup;
    sfMusic *gameover;
    sfMusic *crischevre;
};

struct s_vectors
{
    sfVector2f chiknfly;
    sfVector2f chiknrn;
    sfVector2f chikndd;
};

struct s_positions
{
    sfVector2f bg_1;
    sfVector2f bg_2;
    sfVector2f chiknrn_1;
    sfVector2f chiknrn_2;
    sfVector2f chiknrn_3;
    sfVector2f chikndd;
    sfVector2f gunsights;
    sfVector2f gun;
    sfVector2f impact;
    sfVector2f sb;
    sfVector2f heart;
    sfVector2f ammo;
    sfVector2f fly_bon;
    sfVector2f x3_bon;
    sfVector2f x2_bon;
    sfVector2f text_score;
    sfVector2f text_kills;
    sfVector2f text_lvl;
    sfVector2f text_gameover;
    sfVector2f text_menu;
};

struct s_stepchkn
{
    int chkn_1;
    int chkn_2;
    int chkn_3;
};

struct s_rect
{
    sfIntRect chknrn_1;
    sfIntRect chknrn_2;
    sfIntRect chknrn_3;
    sfIntRect gun;
    sfIntRect impact;
    sfIntRect heart;
};

struct s_floor
{
    int chkn_1;
    int chkn_2;
    int chkn_3;
};

struct s_sb
{
    int score;
    int kills;
    int tmp_kills;
    int lvl;
    int life;
};

struct s_main
{
    struct s_sprites Sprites;
    struct s_text Texts;
    struct s_sounds Sounds;
    struct s_vectors Vect;
    struct s_positions Pos;
    struct s_stepchkn Step;
    struct s_rect Rect;
    struct s_floor Floor;
    struct s_sb Sb;
};


sfRenderWindow *create_windows(sfRenderWindow *);
sfSprite *create_sprite(char *, sfVector2f);
void set_chknrn_pos(struct s_positions *);
struct s_sprites create_sprites_next(struct s_positions *);
struct s_sprites create_sprites(struct s_positions *, struct s_rect);
sfText *create_text(char *, int, sfVector2f);
struct s_text create_texts(struct s_positions);
struct s_sounds create_sounds(void);
struct s_main create_main_struct(void);
int test_hit_chknrn(sfRenderWindow *, sfEvent, sfSprite *);
void chg_sprt_aft_hit(sfSprite *, sfSprite *, int *, struct s_main *);
void chg_chknrn_to_fly(sfSprite **, sfIntRect, int *);
int test_flykill(sfSprite *, int, int);
void special_score(int, int *, struct s_main *);
int test_bonnus_next(struct s_main *, int *);
void test_bonnus(struct s_main *, int *);
void test_all_hit_chknrn_next(struct s_main *, int *);
void test_all_hit_chknrn(sfRenderWindow *, sfEvent, struct s_main *);
void test_hit_chknrns(sfRenderWindow *, sfEvent, struct s_main *);
void analyse_events(sfRenderWindow *, struct s_main *);
void draw_gunsights(sfRenderWindow *, struct s_main *);
void draw_chknrn_top(sfRenderWindow *, sfSprite *, int);
void draw_chknrns_top(sfRenderWindow *, struct s_main *);
int test_step_chkn(sfSprite *, int, int *, struct s_main *);
void move_chknrns(struct s_main *);
void chkn_no_kill_chkn3(struct s_main *);
void chkn_no_kill_chkn2(struct s_main *);
void chkn_no_kill(struct s_main *);
void draw_sprites_next(struct s_main *);
void draw_sprites(sfRenderWindow *, struct s_main *);
void draw_texts(sfRenderWindow *, struct s_main *);
void draw_all(sfRenderWindow *, struct s_main *);
sfIntRect chg_rct_sprt_chiknrn(sfSprite *, sfIntRect);
void chg_rct_sprt_chiknrns(struct s_main *, sfClock **);
void chg_rct_sprt_impact(struct s_main *, sfClock **);
void chg_rct_sprt_gun(struct s_main *, sfClock **);
void chg_rct_sprt_bonnus(struct s_sprites, sfClock **);
void destroy_sprites(struct s_sprites *);
void destroy_texts(struct s_text *);
void destroy_sounds(struct s_sounds *);
void destroy_all(sfRenderWindow *, struct s_main *);
void chg_lvl(struct s_main *);
void set_lvl(int, struct s_main *);
sfText *set_text_gameover(sfText *, sfVector2f, int, sfColor);
struct s_text set_texts_gameover(struct s_text, struct s_main *);
void draw_gameover(sfRenderWindow *, struct s_text);
void analyse_gameover_events(sfRenderWindow *);
void gameover(sfRenderWindow *window, struct s_main *);
void my_hunter(int);

#endif /* !MYHUNTER_H_ */
