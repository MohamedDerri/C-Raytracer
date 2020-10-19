/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <mderri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 01:05:21 by mderri            #+#    #+#             */
/*   Updated: 2020/10/19 16:34:58 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				intersection_co(t_rt *r, t_obj *c)
{
	t_vecteur	param;

	param.x = dot(r->u, r->u) - ((dot(r->u, normalise(c->axe)) * dot(r->u,
	normalise(c->axe))) * (1 + c->k * c->k));
	param.y = 2 * (dot(r->u, sub(r->ray.org, c->pos)) - ((dot(r->u,
	normalise(c->axe)) * dot(normalise(c->axe), sub(r->ray.org, c->pos))))
	* (1 + c->k * c->k));
	param.z = module(sub(r->ray.org, c->pos)) * module(sub(r->ray.org, c->pos))
	- ((dot(sub(r->ray.org, c->pos), normalise(c->axe)) * dot(sub(r->ray.org,
	c->pos), normalise(c->axe))) * (1 + c->k * c->k));
	r->delta = param.y * param.y - 4 * param.x * param.z;
	if (r->delta < 0)
		return (0);
	r->sol1 = (-param.y - sqrt(r->delta)) / (2 * param.x);
	r->sol2 = (-param.y + sqrt(r->delta)) / (2 * param.x);
	return (distances_tex(r, c));
}

int				rat_trace_cone(t_rt *r, t_obj *obj)
{
	if (intersection_co(r, obj))
	{
		obj->inter = sum(kv(r->u, r->dis), r->cam.position);
		get_normal(r, obj);
		r->obj = obj;
		return (1);
	}
	return (0);
}

int GetAngleCone(t_obj *cone_temp, t_vecteur p)
{
	cone_temp->txt->Um = (atan2(p.x, p.z) / (2.0 * M_PI));
	cone_temp->txt->Vm = (p.y + 5.0 /2 )/ 5.0;
	cone_temp->txt->Um -= floor(cone_temp->txt->Um);
	if(!cone_temp->txt->coup)
		cone_temp->txt->Vm -= floor(cone_temp->txt->Vm);
	else
	{
		if(cone_temp->txt->Vm > 1.0 || cone_temp->txt->Vm < 0.0)
			return(0);
	}
	return(1);
}