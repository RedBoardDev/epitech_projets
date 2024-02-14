/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** get_color.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

sfColor get_color1(my_quad_t quad)
{
    sfColor color;
    int z = 0;

    if (quad.a.coords.z == -100 || quad.b.coords.z == -100 ||
    quad.c.coords.z == -100 || quad.d.coords.z == -100)
        z = -100;
    else {
        z = get_highest_point(quad.a.coords.z, quad.b.coords.z,
        quad.c.coords.z, quad.d.coords.z);
        if (z == -1)
            z = quad.a.coords.z;
    }
    color = get_color_with_z(z);
    color.a = (quad.a.coords.x % 2 == 0 && quad.a.coords.y % 2 == 0) ?
    color.a - 6 : (quad.a.coords.x % 2 == 1 && quad.a.coords.y % 2 == 1) ?
    color.a - 3 : color.a;
    return (color);
}

sfColor get_color2(my_quad_t quad)
{
    sfColor color;
    int z = 0;

    if (quad.a.coords.z == -100 || quad.b.coords.z == -100 ||
    quad.c.coords.z == -100 || quad.d.coords.z == -100)
        z = -100;
    else {
        z = get_highest_point(quad.a.coords.z, quad.b.coords.z,
        quad.c.coords.z, quad.d.coords.z);
        if (z == -1)
            z = quad.b.coords.z;
    }
    color = get_color_with_z(z);
    color.a = (quad.b.coords.x % 2 == 0 && quad.b.coords.y % 2 == 0) ?
    color.a - 6 : (quad.b.coords.x % 2 == 1 && quad.b.coords.y % 2 == 1) ?
    color.a - 3 : color.a;
    return (color);
}

sfColor get_color3(my_quad_t quad)
{
    sfColor color;
    int z = 0;

    if (quad.a.coords.z == -100 || quad.b.coords.z == -100 ||
    quad.c.coords.z == -100 || quad.d.coords.z == -100)
        z = -100;
    else {
        z = get_highest_point(quad.a.coords.z, quad.b.coords.z,
        quad.c.coords.z, quad.d.coords.z);
        if (z == -1)
            z = quad.d.coords.z;
    }
    color = get_color_with_z(z);
    color.a = (quad.d.coords.x % 2 == 0 && quad.d.coords.y % 2 == 0) ?
    color.a - 6 : (quad.d.coords.x % 2 == 1 && quad.d.coords.y % 2 == 1) ?
    color.a - 3 : color.a;
    return (color);
}

sfColor get_color4(my_quad_t quad)
{
    sfColor color;
    int z = 0;

    if (quad.a.coords.z == -100 || quad.b.coords.z == -100 ||
    quad.c.coords.z == -100 || quad.d.coords.z == -100)
        z = -100;
    else {
        z = get_highest_point(quad.a.coords.z, quad.b.coords.z,
        quad.c.coords.z, quad.d.coords.z);
        if (z == -1)
            z = quad.c.coords.z;
    }
    color = get_color_with_z(z);
    color.a = (quad.c.coords.x % 2 == 0 && quad.c.coords.y % 2 == 0) ?
    color.a - 6 : (quad.c.coords.x % 2 == 1 && quad.c.coords.y % 2 == 1) ?
    color.a - 3 : color.a;
    return (color);
}

sfColor get_color(my_quad_t quad, int angle)
{
    sfColor color;

    if ((angle % 360 >= 315 && angle % 360 <= 360) ||
    (angle % 360 >= 0 && angle % 360 < 45))
        color = get_color1(quad);
    if (angle % 360 >= 45 && angle % 360 < 135)
        color = get_color2(quad);
    if (angle % 360 >= 135 && angle % 360 < 225)
        color = get_color3(quad);
    if (angle % 360 >= 225 && angle % 360 < 315)
        color = get_color4(quad);
    return (color);
}
