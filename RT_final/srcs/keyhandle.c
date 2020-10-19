/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <mderri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:21:38 by mderri            #+#    #+#             */
/*   Updated: 2020/10/19 05:11:01 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_close(t_rt *r)
{
	mlx_destroy_image(r->mlx.ptr, r->mlx.d.img_ptr);
	mlx_destroy_window(r->mlx.ptr, r->mlx.win);
	free_all(r);
	exit(0);
}

int		key_press_handle(int keycode, t_rt *r)
{
	if (keycode == ESC)
		ft_close(r);
	if (keycode == UP || keycode == DOWN || keycode == LEFT ||
keycode == RIGHT || keycode == FORWARD || keycode == BACKWARD ||
keycode == PLUS || keycode == MINUS)
	{
		if (r->selected)
		{
			if (keycode == UP)
				r->selected->pos.y -= r->move_factor;
			if (keycode == DOWN)
				r->selected->pos.y += r->move_factor;
			if (keycode == LEFT)
				r->selected->pos.x -= r->move_factor;
			if (keycode == RIGHT)
				r->selected->pos.x += r->move_factor;
			if (keycode == FORWARD)
				r->selected->pos.z += r->move_factor;
			if (keycode == BACKWARD)
				r->selected->pos.z -= r->move_factor;
		}
		if (keycode == PLUS)
			r->res = (r->res * 2) >= 1 ? (int)(r->res * 2) : (r->res *2);
		if (keycode == MINUS)
			r->res = fmax(0.1f, r->res / 2);
		raytracer(r);
	}
	return (0);
}

int		key_release_handle(int keycode, t_rt *r)
{
	r->res = keycode - keycode + 1;
	raytracer(r);
	return (0);
}


int		mouse_handle(int keycode, int x, int y, t_rt *r)
{
	if (keycode == RIGHT_CLICK) {
		select_object(r, x, y);
	}
	if (keycode == LEFT_CLICK)
	{
		if (r->selected)
		{
			r->last_selected = r->selected;
			r->selected = NULL;
		}
		add_object_event(r, x, y);
	}
	update_selection(r);
	raytracer(r);
	return (0);
}

int		mouse_move(int x, int y, void *param)
{
	t_rt *r;

	r = (t_rt *)param;
	hover(r, x, y);
	return (0);
}