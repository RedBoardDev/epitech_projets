/*
** EPITECH PROJECT, 2021
** project
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/myworld.h"

void draw_map_all(beginning_t *begin, events_t *all_events, map_t *maps)
{
    float delta = sfClock_getElapsedTime(begin->fps.clock).microseconds / 1000;
    float timer = begin->fps.timer + delta;

    while (timer >= 16) {
        if (begin->guiworld.rotate_360)
            ++maps->angle.x;
        else
            play_sound(begin->sound.gngngn, begin->sound.volume);
        timer -= 16;
    }
    exec_events_map(all_events, maps, begin);
    begin->fps.timer = timer;
    sfClock_restart(begin->fps.clock);
    create_2d_map(maps, maps->size);
    draw_2d_map(begin, maps);
    my_draw_circle(begin->framebuffer, all_events->mouse.pos, maps->radius,
    (sfColor){0, 0, 0, 100});
}

void draw_all(world_t *world)
{
    if (world->begin.screen.world) {
        my_draw_rectangle(world->begin.framebuffer, (sfIntRect){0, 0, 470, 105},
        (sfColor){100, 100, 100, 150});
        if (world->begin.guiworld.toggle_move ||
        world->begin.guiworld.toggle_rotate)
            my_draw_rectangle(world->begin.framebuffer,
            (sfIntRect){1670, 908, 1920, 1080}, (sfColor){100, 100, 100, 150});
    }
    sfSprite_setTexture(world->begin.sprite, world->begin.texture, sfFalse);
    sfTexture_updateFromPixels(world->begin.texture,
    world->begin.framebuffer, WIDTH, HEIGHT, 0, 0);
    sfRenderWindow_drawSprite(world->begin.window,
    world->begin.sprite, NULL);
    put_all_spritesheets(&world->begin, world->spritesheet, world->load_button);
    put_text_imput(&world->begin, &world->all_events);
    sfRenderWindow_display(world->begin.window);
}

void move_sound_box(world_t *world)
{
    int pos_x = world->all_events.mouse.pos.x;

    if (world->begin.screen.soundbox != 2)
        return;
    if (pos_x >= WIDTH - 380 && pos_x <= WIDTH - 120) {
        world->spritesheet[S_SOUND_SELECT].pos.x = pos_x;
        world->begin.sound.volume = (pos_x - (WIDTH - 378)) / 2.6;
    }
    world->begin.sound.volume < 0 ? world->begin.sound.volume = 0 : 0;
}

void big_loop(world_t *world)
{
    if (world->begin.init_map) {
        play_sound(world->begin.sound.launch_maps, world->begin.sound.volume);
        init_empty_map_with_size(&world->begin, &world->all_events,
        &world->maps);
        world->begin.init_map = false;
    }
    clean_window(&world->begin, sfBlack);
    my_events(&world->begin, &world->all_events);
    if (world->begin.screen.world)
        draw_map_all(&world->begin, &world->all_events, &world->maps);
    check_click_buttons(world);
    if (world->begin.get_file)
        init_display_folder_with_maps(world);
    events_menu(&world->begin, &world->all_events, world->load_button);
    check_mouse_on_all_buttons(&world->begin, &world->all_events,
    world->spritesheet, world->load_button);
    draw_all(world);
    move_sound_box(world);
}

void my_world(bool map, sfVector2i size, char *filepath)
{
    world_t world = {init_maps_begin(size), .all_events = init_all_events(),
    .spritesheet = malloc(sizeof(spritesheet_t) * NBR_SPRITE),
    .load_button = NULL};

    world.begin.fps.timer = 0;
    init_all(&world.begin, &world.maps, world.spritesheet,
    (size.x == -1 && size.y == -1) ? false : true);
    if (!world.begin.window || !world.begin.framebuffer)
        return;
    sfWindow_setFramerateLimit((sfWindow *)world.begin.window, 120);
    world.begin.fps.clock = sfClock_create();
    while (sfRenderWindow_isOpen(world.begin.window))
        big_loop(&world);
    destroy_all(&world.begin);
    for (int i = 0; i < world.maps.size.x; ++i)
        free(world.maps.map_2d[i]);
    free(world.maps.map_2d);
    free_int_array(world.maps.map_3d, world.maps.size.x);
}
