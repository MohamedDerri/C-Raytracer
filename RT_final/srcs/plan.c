/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <mderri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 03:09:09 by mderri            #+#    #+#             */
/*   Updated: 2020/10/19 16:35:51 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

long double			intersection_p(t_rt *r, t_obj *p)
{
	long double		t;
	long double			i;

	i = dot(normalise(p->axe), r->u);
	if (fabs((double)(double)i) > MIN)
	{
		t = dot(normalise(p->axe), sub(p->pos, r->ray.org)) / i;
		if (t > MIN && r->dis > t  && getColorFromTexture(r, p,t))
		{
			r->dis = t;
			return (1);
		}
	}
	return (0);
}

int					rat_trace_plane(t_rt *r, t_obj *obj)
{
	if (intersection_p(r, obj))
	{
		obj->inter = sum(kv(r->u, r->dis), r->cam.position);
		get_normal(r, obj);
		r->obj = obj;
		return (1);
	}
	return (0);
}


int  GetAnglePlan(t_obj *plane_temp , t_vecteur p)
{


	plane_temp->txt->Um = p.x * 0.01;
	plane_temp->txt->Vm = p.z * 0.01;


	if(!plane_temp->txt->coup)
		plane_temp->txt->Um -= floor(plane_temp->txt->Um);
	else
	{
		if(plane_temp->txt->Um > 1.0 || plane_temp->txt->Um < 0.0)
			return(0);
	}
	if(!plane_temp->txt->coup)
		plane_temp->txt->Vm -= floor(plane_temp->txt->Vm);
	else
	{
		if(plane_temp->txt->Vm > 1.0 || plane_temp->txt->Vm < 0.0)
			return(0);
	}
	return(1);
}