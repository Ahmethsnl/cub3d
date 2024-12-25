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
    if (raycast(engine) == 0)
        return (0);
    else
    {
        wall_pos = raycast(engine);
        //draw_line(engine, wall_pos);
    }
    return (0);
}
