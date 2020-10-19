/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <mderri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 18:32:07 by slaanani          #+#    #+#             */
/*   Updated: 2020/10/19 05:19:43 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				cast_object(t_rt *r)
{
	t_obj		*obj;
	t_obj		*compos; ////

	obj = r->head;
	
	r->obj = NULL;
	while (obj)
	{
		compos = obj->compos; /// 
		while (compos)
		{
			if (compos->type == tplane)
				rat_trace_plane(r, compos);
			else if (compos->type == tsphere)
				rat_trace_sphere(r, compos);
			else if (compos->type == tcylinder)
				rat_trace_cylinder(r, compos);
			else if (compos->type == tcone)
				rat_trace_cone(r, compos);
			else if (compos->type == ttorus)
				rat_trace_torus(r, compos);
			else if (compos->type == tparaboloid)
				rat_trace_paraboloid(r, compos);
			else if (compos->type == tellipsoid)
				rat_trace_ellipsoid(r, compos);
			else if (compos->type == thyperboloid)
				rat_trace_hyperboloid(r, compos);
			else if (compos->type == tcubet)
				rat_trace_cubet(r, compos);
			else if (compos->type == tmoebius)
				rat_trace_moebius(r, compos);
			else if (compos->type == tdingdong)
				rat_trace_dingdong(r, compos);
			else if (compos->type == tgoursat)
				rat_trace_goursat(r, compos);
			else if (compos->type == tteardrop)
				rat_trace_teardrop(r, compos);
			else if (compos->type == tdisk)
				rat_trace_disk(r, compos);
			compos = compos->next;
		}
		obj = obj->next;
	}
	if (r->obj)
		return (1);
	return (0);
}

static void		assign_colors(t_rt *r, int res)
{
	t_point p;

	p.y = r->v1.y;
	while (p.y < r->v1.y + res)
	{
		p.x = r->v1.x;
		while (p.x < r->v1.x + res)
		{
			r->mlx.d.pic_str[(int)(p.y * r->mlx.w + p.x)] =
	rgb(r->color.r, r->color.g, r->color.b);
			p.x++;
		}
		p.y++;
	}
}

static void		raytracer_aliasing(t_rt *r)
{
	int		res;

	res = 1 / r->res;
	while (r->v1.y < r->mlx.h)
	{
		r->v1.x = 0;
		while (r->v1.x < r->mlx.w)
		{
			r->v2 = r->v1;
			make_ray(r);
			r->u = normalise(r->ray.direct);
			r->dis = MAX;
			if (cast_object(r))
			{
				lighting(r);
				assign_colors(r, res);
			}
			r->v1.x += res;
		}
		r->v1.y += res;
	}
}

static void		raytracer_anti_aliasing(t_rt *rt)
{
	int i = 0;
	t_color color;

	color = (t_color){.type = c_default, .r = 0, .g = 0, .b = 0};
	rt->v2.y = rt->v1.y * (int)rt->res;
	while (rt->v2.y < (rt->v1.y * (int)rt->res + (int)rt->res))
	{
		rt->v2.x = rt->v1.x * (int)rt->res;
		while (rt->v2.x < (rt->v1.x * (int)rt->res + (int)rt->res))
		{
			i++;
			make_ray(rt);
			rt->u = normalise(rt->ray.direct);
			rt->dis = MAX;
			if (cast_object(rt))
			{
				lighting(rt);
				color.r += rt->color.r;
				color.g += rt->color.g;
				color.b += rt->color.b;
			}
			rt->v2.x++;
		}
		rt->v2.y++;
	}
	rt->mlx.d.pic_str[(int)(rt->v1.y * rt->mlx.w + rt->v1.x)] =
	rgb(color.r / (rt->res * rt->res),
	color.g / (rt->res * rt->res), color.b / (rt->res * rt->res));
}

void			raytracer(t_rt *r)
{
	reset_image(r, &r->mlx.d);
	r->v1.y = 0;
	if (r->res >= 1)
		while (r->v1.y < r->mlx.h)
		{
			r->v1.x = 0;
			while (r->v1.x < r->mlx.w)
			{
					raytracer_anti_aliasing(r);
				r->v1.x++;
			}
			r->v1.y++;
		}
	else
		raytracer_aliasing(r);
	filtre(r);
	mlx_put_image_to_window(r->mlx.ptr, r->mlx.win, r->mlx.d.img_ptr, 126, 190);
}
