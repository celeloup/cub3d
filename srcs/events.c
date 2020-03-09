/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celeloup <celeloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 11:54:17 by celeloup          #+#    #+#             */
/*   Updated: 2020/03/09 12:41:09 by celeloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		key_press(int keycode, t_window *win)
{
	if (keycode == ESC_KEY)
		close_window(win);
	return (0);
}

void	hook_event(t_window *win)
{
	mlx_hook(win->win_ptr, 2, 0, key_press, win);
	mlx_hook(win->win_ptr, 17, (1L << 17), close_window, win);
}

int		close_window(t_window *win)
{
	free_win(win);
	mlx_destroy_image(win->mlx_ptr, win->img.img_ptr);
	if (LEAKS)
		system("leaks Cub3D");
	exit(0);
	return (0);
}

