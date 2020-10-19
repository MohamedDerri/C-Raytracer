/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_filter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:56:19 by erahimi           #+#    #+#             */
/*   Updated: 2020/10/14 14:05:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		mb_loop(int *d, t_loop *loop, t_loop *filter, t_vecteur *c)
{
	t_loop	img;

	img.i = (int)(loop->i - FILTER_MB_W / 2 + filter->i + WIDTH)
		% WIDTH;
	img.j = (int)(loop->j - FILTER_MB_H / 2 + filter->j + HEIGHT)
		% HEIGHT;
	c->x += r(d[img.j * WIDTH + img.i])
		* (filter->i == filter->j ? 1 : 0);
	c->y += g(d[img.j * WIDTH + img.i])
		* (filter->i == filter->j ? 1 : 0);
	c->z += b(d[img.j * WIDTH + img.i])
		* (filter->i == filter->j ? 1 : 0);
}

void			ft_filter_mb(int *data)
{
	t_loop		loop;
	t_loop		filter;
	t_vecteur		c;

	loop.i = -1;
	while (++loop.i < WIDTH)
	{
		loop.j = -1;
		while (++loop.j < HEIGHT)
		{
			c = create_v(0.0, 0.0, 0.0);
			filter.j = -1;
			while (++filter.j < FILTER_MB_H)
			{
				filter.i = -1;
				while (++filter.i < FILTER_MB_W)
					mb_loop(data, &loop, &filter, &c);
				data[loop.j * (int)WIDTH + loop.i] =
					rgb_int(clamp((int)(c.x / 9.0), 255.0, 0.0),
							clamp((int)(c.y / 9.0), 255.0, 0.0),
							clamp((int)(c.z / 9.0), 255.0, 0.0));
			}
		}
	}
}
