/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:26:40 by ahmsanli          #+#    #+#             */
/*   Updated: 2025/02/17 17:26:23 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	ft_exit(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	ft_free_data(data, 1);
	exit(0);
	return (0);
}

int	key_hook(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	ft_place_floor_ceiling(data);
	ft_move(data);
	ft_ray_cast(data, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->mlx_img, 0, 0);
	return (0);
}

int	ft_key_press(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == ESC_KEY)
		ft_exit(data);
	if (key == W_KEY)
		data->w_pressed = 1;
	if (key == A_KEY)
		data->a_pressed = 1;
	if (key == S_KEY)
		data->s_pressed = 1;
	if (key == D_KEY)
		data->d_pressed = 1;
	if (key == LEFT_ARROW)
		data->left = 1;
	if (key == RIGHT_ARROW)
		data->right = 1;
	return (0);
}

int	ft_key_released(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == W_KEY)
		data->w_pressed = 0;
	if (key == A_KEY)
		data->a_pressed = 0;
	if (key == S_KEY)
		data->s_pressed = 0;
	if (key == D_KEY)
		data->d_pressed = 0;
	if (key == LEFT_ARROW)
		data->left = 0;
	if (key == RIGHT_ARROW)
		data->right = 0;
	return (0);
}

void	ft_mlx_hook(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, key_hook, data);
	mlx_hook(data->win_ptr, 2, 1L << 0, ft_key_press, data);
	mlx_hook(data->win_ptr, 3, 1L << 1, ft_key_released, data);
	mlx_hook(data->win_ptr, 17, 0, ft_exit, data);
	mlx_loop(data->mlx_ptr);
}
