/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <mderri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 15:42:46 by mderri            #+#    #+#             */
/*   Updated: 2020/10/19 16:36:10 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			intersection_s(t_rt *r, t_obj *s)
{
	t_vecteur	param;

	param.x = 1;
	param.y = 2 * dot(r->u, sub(r->ray.org, s->pos));
	param.z = module(sub(r->ray.org, s->pos)) * module(sub(r->ray.org,
	s->pos)) - s->k * s->k;
	r->delta = param.y * param.y - 4 * param.x * param.z;
	if (r->delta < 0)
		return (0);
	r->sol1 = (-param.y - sqrt(r->delta)) / (2 * param.x);
	r->sol2 = (-param.y + sqrt(r->delta)) / (2 * param.x);
	return (distances_tex(r, s));
}

int			rat_trace_sphere(t_rt *r, t_obj *obj)
{
	if (intersection_s(r, obj))
	{
		obj->inter = sum(kv(r->u, r->dis), r->cam.position);
		get_normal(r, obj);
		r->obj = obj;
		return (1);
	}
	return (0);
}



int GetAngleSphere(t_obj *sphere_temp, t_vecteur p)
{
	long double phi;
	long double theta;

	phi = atan2(p.z, p.x);
	theta = asin(p.y / sphere_temp->k);
	/*
if (dot(sphere_temp->repere.k, constrector(0, 0, -1)) >= 0.0)
		sphere_temp->txt->Um = (phi + M_PI) / (2.0 * M_PI);
	else*/
	sphere_temp->txt->Um = 1 - (phi + M_PI) / (2.0 * M_PI);
	sphere_temp->txt->Vm = (theta + M_PI / 2.0) / M_PI;
	return (1);
}
