/*
** EPITECH PROJECT, 2018
** structs
** File description:
** structs
*/

#ifndef STRUCTS_H_
#define STRUCTS_H_

struct s_vectors Vectors =
{
    {4, 10},
    {5, 0},
    {0, 12}
};

struct s_positions Pos =
{
    {0, 0},
    {0, 0},
    {-1000, -1000},
    {-1000, -1000},
    {-1000, -1000},
    {-300, 0},
    {0, 0},
    {1550, 800},
    {-1000, -1000},
    {0, 853},
    {20, 908},
    {20, 955},
    {103, 948},
    {230, 948},
    {168, 948},
    {350, 895},
    {350, 960},
    {550, 960},
    {960, 200},
    {960, 950}
};

struct s_stepchkn Step = {1, 2, 3};

struct s_rect Rect =
{
    {0, 0, 206, 170},
    {618, 0, 206, 170},
    {1030, 0, 206, 170},
    {0, 0, 374, 280},
    {0, 0, 50, 50},
    {0, 0, 268, 35}
};

struct s_floor Floor = {0, 0, 0};

struct s_sb Sb = {0, 0, 0, 1, 6};

#endif /* !STRUCTS_H_ */
