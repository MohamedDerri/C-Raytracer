/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <mderri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 09:04:42 by mderri            #+#    #+#             */
/*   Updated: 2020/10/19 16:35:21 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				intersection_c(t_rt *r, t_obj *c)
{
	t_vecteur	param;
	t_vecteur	newv;

	newv = c->axe;
	param.x = dot(r->u, r->u) - (dot(r->u, normalise(newv)) * dot(r->u,
	normalise(newv)));
	param.y = 2 * (dot(r->u, sub(r->ray.org, c->pos)) - (dot(r->u,
	normalise(newv)) * dot(normalise(newv), sub(r->ray.org, c->pos))));
	param.z = module(sub(r->ray.org, c->pos)) * module(sub(r->ray.org, c->pos))
	- (dot(sub(r->ray.org, c->pos), normalise(newv)) * dot(sub(r->ray.org,
	c->pos), normalise(newv))) - c->k * c->k;
	r->delta = param.y * param.y - 4 * param.x * param.z;
	if (r->delta < 0)
		return (0);
	r->sol1 = (-param.y - sqrt(r->delta)) / (2 * param.x);
	r->sol2 = (-param.y + sqrt(r->delta)) / (2 * param.x);
	return (distances_tex(r, c));
}

int				rat_trace_cylinder(t_rt *r, t_obj *obj)
{
	if (intersection_c(r, obj))
	{
		obj->inter = sum(kv(r->u, r->dis), r->cam.position);
		get_normal(r, obj);
		r->obj = obj;
		return (1);
	}
	return (0);
}

int GetAngleCylinder(t_obj *plane_temp , t_vecteur p)
{

	plane_temp->txt->Um = (atan2(p.x, p.z) / (2.0 * M_PI));
	plane_temp->txt->Vm = (p.y + 5.0 /2 )/ 5.0;
	plane_temp->txt->Um -= floor(plane_temp->txt->Um);
	if(!plane_temp->txt->coup)
		plane_temp->txt->Vm -= floor(plane_temp->txt->Vm);
	else
	{
		if(plane_temp->txt->Vm > 1.0 || plane_temp->txt->Vm < 0.0)
			return(0);
	}
	return(1);
}