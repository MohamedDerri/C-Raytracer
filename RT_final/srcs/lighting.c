/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <mderri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 03:43:43 by slaanani          #+#    #+#             */
/*   Updated: 2020/10/19 16:33:56 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			final_color(t_rt *r)
{
	r->color.r += r->diff.r + r->spec.r;
	r->color.g += r->diff.g + r->spec.g;
	r->color.b += r->diff.b + r->spec.b;
}

void			ambient(t_rt *r , t_color new)
{
	r->color.r += r->amb * new.r;
	r->color.g += r->amb * new.g;
	r->color.b += r->amb * new.b;
}

void			diffuse(t_rt *r, long double d, t_light_lst *lst , t_color new)
{
	

	r->diff.r = d * 0.6 *
(long double)(lst->color.r * lst->intensity / 255) * new.r;
	r->diff.g = d * 0.6 *
(long double)(lst->color.g * lst->intensity / 255) * new.g;
	r->diff.b = d * 0.6 *
(long double)(lst->color.b * lst->intensity / 255) * new.b;
}

void			specular(t_rt *r, long double d, t_vecteur dir, t_light_lst *l)
{
	t_vecteur	v1;
	t_vecteur	v2;
	long double	tmp;

	if (d == 0)
		tmp = 0;
	else
	{
		v1 = kv(dir, -1.0);
		v2 = sub(kv(r->obj->normal, 2.0 * d), r->u);
		tmp = pow(fmax(dot(v2, v1), 0.0), SPECULAR_POWER);
	}
	r->spec.r = 0.6 * tmp * l->color.r * l->intensity;
	r->spec.g = 0.6 * tmp * l->color.g * l->intensity;
	r->spec.b = 0.6 * tmp * l->color.b * l->intensity;
}

void			lighting(t_rt *r)
{
	t_vecteur	dir;
	long double	d;
	t_light_lst	*lst;

t_color new = get_color(r);
	lst = r->light;
	r->diff = (t_color){.r = 0.0, .g = 0.0, .b = 0.0};
	r->spec = (t_color){.r = 0.0, .g = 0.0, .b = 0.0};
	r->color = (t_color){.r = 0.0, .g = 0.0, .b = 0.0};
	dir = r->ray.direct;
	ambient(r,new);
	while (lst)
	{
		r->ray.org = r->obj->inter;
		r->ray.direct = sub(lst->org, r->obj->inter);
		r->dis = module(r->ray.direct);
		r->u = normalise(r->ray.direct);
		d = fmax(dot(r->obj->normal, r->u), 0.0);
		if (!cast_shadow(r))
		{
			diffuse(r, d, lst,new);
			specular(r, d, dir, lst);
			final_color(r);
		}
		lst = lst->next;
	}
}




// #include "rt.h"

// void			final_color(t_rt *r)
// {
// 	r->color.r += r->diff.r + r->spec.r;
// 	r->color.g += r->diff.g + r->spec.g;
// 	r->color.b += r->diff.b + r->spec.b;
// }

// void			ambient(t_rt *r)
// {
// 	r->color.r += r->amb * r->obj->color.r;
// 	r->color.g += r->amb * r->obj->color.g;
// 	r->color.b += r->amb * r->obj->color.b;
// }

// void			diffuse(t_rt *r, long double d, t_light_lst *lst)
// {
// 	r->diff.r = d * 0.6 *
// (long double)(lst->color.r * lst->intensity / 255) * r->obj->color.r;
// 	r->diff.g = d * 0.6 *
// (long double)(lst->color.g * lst->intensity / 255) * r->obj->color.g;
// 	r->diff.b = d * 0.6 *
// (long double)(lst->color.b * lst->intensity / 255) * r->obj->color.b;
// }

// void			specular(t_rt *r, long double d, t_vecteur dir, t_light_lst *l)
// {
// 	t_vecteur	v1;
// 	t_vecteur	v2;
// 	long double	tmp;

// 	if (d == 0)
// 		tmp = 0;
// 	else
// 	{
// 		v1 = kv(dir, -1.0);
// 		v2 = sub(kv(r->obj->normal, 2.0 * d), r->u);
// 		tmp = pow(fmax(dot(v2, v1), 0.0), SPECULAR_POWER);
// 	}
// 	r->spec.r = 0.6 * tmp * l->color.r * l->intensity;
// 	r->spec.g = 0.6 * tmp * l->color.g * l->intensity;
// 	r->spec.b = 0.6 * tmp * l->color.b * l->intensity;
// }

// void			lighting(t_rt *r)
// {
// 	t_vecteur	dir;
// 	long double	d;
// 	t_light_lst	*lst;

// 	lst = r->light;
// 	r->diff = (t_color){.r = 0.0, .g = 0.0, .b = 0.0};
// 	r->spec = (t_color){.r = 0.0, .g = 0.0, .b = 0.0};
// 	r->color = (t_color){.r = 0.0, .g = 0.0, .b = 0.0};
// 	dir = r->ray.direct;
// 	ambient(r);
// 	while (lst)
// 	{
// 		r->ray.org = r->obj->inter;
// 		r->ray.direct = sub(lst->org, r->obj->inter);
// 		r->dis = module(r->ray.direct);
// 		r->u = normalise(r->ray.direct);
// 		d = fmax(dot(r->obj->normal, r->u), 0.0);
// 		if (!cast_shadow(r))
// 		{
// 			diffuse(r, d, lst);
// 			specular(r, d, dir, lst);
// 			final_color(r);
// 		}
// 		lst = lst->next;
// 	}
// }
