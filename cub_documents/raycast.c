/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 14:20:07 by ahmsanli          #+#    #+#             */
/*   Updated: 2024/12/25 14:20:07 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_engine.h"

int init_raycast(t_raycast  *raycast)
{
    raycast->camera_x = 0;
    raycast->step.x = 0;
    raycast->step.y = 0;
    raycast->plane.x = 0;
    raycast->plane.y = 0;
    raycast->origin.x = 0;
    raycast->origin.y = 0;
    raycast->direction.x = 0;
    raycast->direction.y = 0;
    raycast->side_distance.x = 0;
    raycast->side_distance.y = 0;
    raycast->delta_distance.x = 0;
    raycast->delta_distance.y = 0;
    //Formüller
    //raycast->camera_x = 2 * x / (double)WIDTH - 1;
    raycast->plane.x = 0;
    raycast->plane.y = 0.66;
    raycast->direction.x + plane.x * camera_x;
    raycast->direction.y + plane.y * camera_x;
    return (0);
}

t_vector2 raycast(t_engine *engine)
{
    t_raycast   *raycast;
    t_transform *transform;
    t_vector2   *position;
    t_vector2   *direction;
    t_vector2   *plane;
    t_vector2   *side_distance;
    t_vector2   *delta_distance;
    double      camera_x;
    t_vector2   *step;

    raycast = engine->physics->raycast;
    transform = engine->physics->transform;
    position = &transform->position;
    direction = &raycast->direction;
    plane = &raycast->plane;
    side_distance = &raycast->side_distance;
    delta_distance = &raycast->delta_distance;
    camera_x = raycast->camera_x;
    step = &raycast->step;
    while (1)
    if ((int)position->y < 0 || (int)position->x < 0 ||
        (int)position->y >= engine->map->height ||
        (int)position->x >= engine->map->width)
        return (1); // Hata: Harita sınırlarının dışına çıkıldı
    {
        if (side_distance->x < side_distance->y)
        {
            side_distance->x += delta_distance->x;
            position->x += step->x;
            raycast->side = 0;
        }
        else
        {
            side_distance->y += delta_distance->y;
            position->y += step->y;
            raycast->side = 1;
        }
        if (engine->map->map[(int)position->y][(int)position->x] == '1')
        {
            return (position);
        }
    }
    return (0);
}

int ray_main(t_engine *engine)
{
    t_vector2   *wall_pos;
    if (init_raycast(engine->physics->raycast) == -1)
        return (-1);
    wall_pos = raycast(engine);
    if (!wall_pos)
        return (1);
    //draw_line(engine, wall_pos);
    return (0);
}
void another(t_engine *engine) // perfect spaghetti
{
    for (int x = 0; x < SCREEN_WIDTH; x++)
    {
        engine->physics->raycast->camera_x = 2 * x / (double)SCREEN_WIDTH - 1; // Kamera koordinatları
        engine->physics->raycast->direction.x = engine->physics->transform->direction.x + engine->physics->raycast->plane.x * engine->physics->raycast->camera_x;  // Işın yönü X
        engine->physics->raycast->direction.y = engine->physics->transform->direction.y + engine->physics->raycast->plane.y * engine->physics->raycast->camera_x;  // Işın yönü Y

        int mapX = (int)engine->physics->transform->position.x;
        int mapY = (int)engine->physics->transform->position.y;

        double posX = engine->physics->transform->position.x;
        double posY = engine->physics->transform->position.y;

        engine->physics->raycast->delta_distance.x = fabs(1 / engine->physics->raycast->direction.x);
        engine->physics->raycast->delta_distance.y = fabs(1 / engine->physics->raycast->direction.y);
        double perpWallDist = engine->physics->raycast->perpWallDist;

        int stepX = engine->physics->raycast->step.x;
        int stepY = engine->physics->raycast->step.y;
        int hit = 0;
        int side;

        // Başlangıç ray yayılma adımı
        if (engine->physics->raycast->direction.x < 0)
        {
            stepX = -1;
            engine->physics->raycast->side_distance.x = (posX - mapX) * engine->physics->raycast->delta_distance.x;
        }
        else
        {
            stepX = 1;
            engine->physics->raycast->side_distance.x = (mapX + 1.0 - posX) * engine->physics->raycast->delta_distance.x;;
        }
        if (rayDirY < 0)
        {
            stepY = -1;
            engine->physics->raycast->side_distance.y = (posY - mapY) * engine->physics->raycast->delta_distance.y;
        }
        else
        {
            stepY = 1;
            engine->physics->raycast->side_distance.y = (mapY + 1.0 - posY) * engine->physics->raycast->delta_distance.y;;
        }

        // DDA (Digital Differential Analysis) Algoritması ile ışın izleme
        while (hit == 0)
        {
            if (engine->physics->raycast->side_distance.x < engine->physics->raycast->side_distance.y)
            {
                engine->physics->raycast->side_distance.x += engine->physics->raycast->delta_distance.x;
                mapX += stepX;
                side = 0;
            }
            else
            {
                engine->physics->raycast->side_distance.y += engine->physics->raycast->delta_distance.y;
                mapY += stepY;
                side = 1;
            }
            if (worldMap[mapX][mapY] > 0) hit = 1;
        }

        // Mesafe hesaplaması
        if (side == 0) perpWallDist = (mapX - posX + (1 - stepX) / 2) / engine->physics->raycast->direction.x;
        else perpWallDist = (mapY - posY + (1 - stepY) / 2) / engine->physics->raycast->direction.y;

        int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);

        int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
        if (drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
        if (drawEnd >= SCREEN_HEIGHT) drawEnd = SCREEN_HEIGHT - 1;

        int color = 0xFF0000; // Kırmızı duvar
        if (side == 1) color = color / 2; // Yansıyan yüzeyde rengin koyulaşması

        // Duvar çizimi
        for (int y = drawStart; y < drawEnd; y++)
        {
            //put_pixel(x, y, color);
            write(1, "waiting", 1);
        }
    }
}
