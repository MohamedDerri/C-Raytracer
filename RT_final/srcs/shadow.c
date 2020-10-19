/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <mderri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 18:56:37 by slaanani          #+#    #+#             */
/*   Updated: 2020/10/19 05:59:53 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				shadow_s(t_rt *r, t_obj *obj)
{
	if (intersection_s(r, obj))
		return (1);
	return (0);
}

int				shadow_p(t_rt *r, t_obj *obj)
{
	if (obj->type == tplane && intersection_p(r, obj))
			return (1);
	if (obj->type == tdisk && disk_intersection(r, obj))
		return (1);
	return (0);
}

int				shadow_co(t_rt *r, t_obj *obj)
{
	if (intersection_co(r, obj))
		return (1);
	return (0);
}

int				shadow_c(t_rt *r, t_obj *obj)
{
	if (intersection_c(r, obj))
		return (1);
	return (0);
}

int				shadow_t(t_rt *r, t_obj *obj)
{
	if (intersection_t(r, obj))
		return (1);
	return (0);
}

int				shadow_pb(t_rt *r, t_obj *obj)
{
	if (intersection_pb(r, obj))
		return (1);
	return (0);
}

int				shadow_ell(t_rt *r, t_obj *obj)
{
	if (intersection_ell(r, obj))
		return(1);
	return (0);
}

int				shadow_hp(t_rt *r, t_obj *obj)
{
	if (intersection_hp(r, obj))
		return (1);
	return (0);
}

int				shadow_cubet(t_rt *r, t_obj *obj)
{
	if (intersection_cubet(r, obj))
		return (1);
	return (0);
}

int				shadow_moebius(t_rt *r, t_obj *obj)
{
	if (intersection_moebius(r, obj))
		return (1);
	return (0);
}

int				shadow_dingdong(t_rt *r, t_obj *obj)
{
	if (intersection_dingdong(r, obj))
		return (1);
	return (0);
}

int				shadow_goursat(t_rt *r, t_obj *obj)
{
	if (intersection_goursat(r, obj))
		return (1);
	return (0);
}

int				shadow_teardrop(t_rt *r, t_obj *obj)
{
	if (intersection_teardrop(r, obj))
		return (1);
	return (0);
}

int				cast_shadow(t_rt *r)
{
	t_obj		*obj_list;
	t_obj		*compos;

	obj_list = r->head;
	while (obj_list)
	{
		compos = obj_list->compos;
		while (compos)
		{
			if (compos == r->obj)
			{
				if (compos->next)
					compos = compos->next;
				else
					break ;
			}
			if ((compos->type == tsphere) && shadow_s(r, compos))
				return (1);
			if (((compos->type == tplane) || (compos->type == tdisk)) && shadow_p(r, compos))
				return (1);
			if ((compos->type == tcone) && shadow_co(r, compos))
				return (1);
			if ((compos->type == tcylinder) && shadow_c(r, compos))
				return (1);
			if ((compos->type == ttorus) && shadow_t(r, compos))
				return (1);
			if ((compos->type == tparaboloid) && shadow_pb(r, compos))
				return (1);
			if ((compos->type == tellipsoid) && shadow_ell(r, compos))
				return (1);
			if ((compos->type == thyperboloid) && shadow_hp(r, compos))
				return (1);
			if ((compos->type == tcubet) && shadow_cubet(r, compos))
				return (1);
			if ((compos->type == tmoebius) && shadow_moebius(r, compos))
				return (1);
			if ((compos->type == tdingdong) && shadow_dingdong(r, compos))
				return (1);
			if ((compos->type == tgoursat) && shadow_goursat(r, compos))
				return (1);
			if ((compos->type == tteardrop) && shadow_teardrop(r, compos))
				return (1);
			compos = compos->next;
		}
		obj_list = obj_list->next;
	}
	return (0);
}
