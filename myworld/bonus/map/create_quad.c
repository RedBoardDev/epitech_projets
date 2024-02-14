/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** create_quad.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

sfVertexArray *append_array1(sfColor color, my_quad_t quad)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = quad.a.iso, .color = color};
    sfVertex vertex2 = {.position = quad.b.iso, .color = color};
    sfVertex vertex3 = {.position = quad.c.iso, .color = color};
    sfVertex vertex4 = {.position = quad.d.iso, .color = color};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex4);
    sfVertexArray_append(vertex_array, vertex3);
    return (vertex_array);
}

sfVertexArray *append_array2(sfColor color, my_quad_t quad)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = quad.a.iso, .color = color};
    sfVertex vertex2 = {.position = quad.b.iso, .color = color};
    sfVertex vertex3 = {.position = quad.c.iso, .color = color};
    sfVertex vertex4 = {.position = quad.d.iso, .color = color};

    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex4);
    return (vertex_array);
}

sfVertexArray *append_array3(sfColor color, my_quad_t quad)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = quad.a.iso, .color = color};
    sfVertex vertex2 = {.position = quad.b.iso, .color = color};
    sfVertex vertex3 = {.position = quad.c.iso, .color = color};
    sfVertex vertex4 = {.position = quad.d.iso, .color = color};

    sfVertexArray_append(vertex_array, vertex4);
    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    return (vertex_array);
}

sfVertexArray *append_array4(sfColor color, my_quad_t quad)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = quad.a.iso, .color = color};
    sfVertex vertex2 = {.position = quad.b.iso, .color = color};
    sfVertex vertex3 = {.position = quad.c.iso, .color = color};
    sfVertex vertex4 = {.position = quad.d.iso, .color = color};

    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex4);
    return (vertex_array);
}

void create_quad(beginning_t *begin, my_quad_t quad, int angle)
{
    sfColor color = get_color(quad, angle);
    sfVertexArray *vertex_array;

    if ((angle % 360 >= 315 && angle % 360 <= 360) ||
    (angle % 360 >= 0 && angle % 360 < 45))
        vertex_array = append_array1(color, quad);
    if (angle % 360 >= 45 && angle % 360 < 135)
        vertex_array = append_array2(color, quad);
    if (angle % 360 >= 135 && angle % 360 < 225)
        vertex_array = append_array3(color, quad);
    if (angle % 360 >= 225 && angle % 360 < 315)
        vertex_array = append_array4(color, quad);
    sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
    sfRenderWindow_drawVertexArray(begin->window, vertex_array, NULL);
    sfVertexArray_destroy(vertex_array);
}
