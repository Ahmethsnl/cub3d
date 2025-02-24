/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 05:53:51 by ahmsanli          #+#    #+#             */
/*   Updated: 2025/01/16 05:53:51 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_engine.h"

void	wall_hit(t_engine *engine)
{
	engine.physics->raycast->wall_hit = 0;
	while (!engine.physics->raycast->wall_hit)
	{
		if (engine.physics->raycast->side_distance.x < engine.physics->raycast->side_distance.y)
		{
			engine.physics->raycast->side_distance.x += engine.physics->raycast->delta_distance.x;
			engine.physics->raycast->map.x += physics->raycast->step.x;
			engine.physics->raycast->side = 0;
		}
		else
		{
			engine.physics->raycast->side_distance.y += engine.physics->raycast->delta_distance.y;
			engine.physics->raycast->map.y += engine.physics->raycast->step.y;
			engine.physics->raycast->side = 1;
		}
		if (engine.physics->map->map[engine.physics->raycast->map.x][engine.physics->raycast->map.y] == WALL)
			engine.physics->raycast->wall_hit = 1;
	}
}
void	send_ray(t_engine *engine)
{
	direction(engine);
	wall_hit(engine);
	raydist(engine);
	render_wall(engine);
}
