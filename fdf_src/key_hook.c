/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:30:20 by rburri            #+#    #+#             */
/*   Updated: 2022/02/04 10:18:39 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	key_hook(int keycode, t_mlx *data)
{
	if (keycode == ESC_CODE)
	{
		mlx_destroy_window(data->mlx, data->win);
		free(data->mlx);
		ft_free_map(data->map);
		exit (0);
	}
	return (0);
}
