/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <mderri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 23:55:04 by slaanani          #+#    #+#             */
/*   Updated: 2020/10/19 05:17:08 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color			c(short red, short green, short blue)
{
	t_color color;

	color.r = red;
	color.g = green;
	color.b = blue;
	return (color);
}

long double		map(long double x, long double size, int w)
{
	return (x * size / w - (size / 2));
}

long double			deg_to_rad(long double angle)
{
	return ((angle * PI) / 180);
}

void			make_ray(t_rt *r)
{
	t_vecteur	left;
	t_vecteur	up;
	t_vecteur	forward;
	t_vecteur	sumupleft;
	int			fact;

	fact = (r->res >= 1) ? r->res : 1;
	left = kv(r->cam.left, map(r->v2.x, r->cam.frame_width,
r->mlx.w * fact));
	up = kv(r->cam.up, map(r->v2.y, r->cam.frame_height, r->mlx.h * fact));
	forward = kv(r->cam.forward, r->cam.focal_length);
	sumupleft = sum(up, left);
	r->ray.direct = sum(sumupleft, forward);
	r->ray.org = create_v(r->cam.position.x, r->cam.position.y,
	r->cam.position.z);
}

void			reset_image(t_rt *rt, t_data *data)
{
	mlx_destroy_image(rt->mlx.ptr, data->img_ptr);
	data->img_ptr = mlx_new_image(rt->mlx.ptr, rt->mlx.w, rt->mlx.h);
	data->pic_str = (int *)mlx_get_data_addr(data->img_ptr, &data->bpp,
&data->s_l, &data->endian);
}