/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moebius.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 23:47:05 by mderri            #+#    #+#             */
/*   Updated: 2020/03/19 07:26:46 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		intersection_moebius(t_rt *r, t_obj *m)
{
	// t_vecteur   x;
	long double c[4];

	long double max;
	long double may;
	long double maz;
	long double mbx;
	long double mby;
	long double mbz;
	int ma;
	/*
	x = sub(r->ray.org, m->pos);
	c[3] = (r->u.y * r->u.y * r->u.y) - 2 * (r->u.y * r->u.y * r->u.z) +
	(r->u.x * r->u.x * r->u.y) + (r->u.z * r->u.z * r->u.y) -
	2 * (r->u.x * r->u.x * r->u.z);
	c[2] = 3 * r->u.y *r->u.y * x.y - 2 * r->u.y * r->u.y * x.z - 4 * r->u.y *
	r->u.z * x.y + r->u.x * r->u.x * x.y + 2 * r->u.x * r->u.y * x.x + r->u.z *
	r->u.z * x.y + 2 * r->u.z * r->u.x * x.z - 4 * r->u.x * r->u.z * x.x +
	r->u.x * r->u.x * x.z - 2 * r->u.x * r->u.z * m->k;
	c[1] = 3 * x.y * x.y * r->u.y - 4 * r->u.y * x.y * x.z - 2 * x.y * x.y *
	r->u.z + 2 * r->u.x * x.x * x.y + x.x * x.x * r->u.y + 2 * r->u.z * x.z *
	x.y + x.z * x.z * r->u.y - 2 * x.x * x.x * r->u.z - 4 * x.x * x.z * r->u.x -
	2 * x.x * r->u.z * m->k - 2 * x.z * r->u.x * m->k - m->k * m->k * r->u.y;
	c[0] = x.y * x.y * x.y - 2 * x.y * x.y * x.z + x.x * x.x * x.y + x.z * x.z *
	x.y - 2 * x.x * x.x * x.z - 2 * x.x * x.z * m->k - x.y * m->k * m->k;
	*/
	max = r->ray.org.x;
	may = r->ray.org.y;
	maz = r->ray.org.z;
	mbx = r->u.x;
	mby = r->u.y;
	mbz = r->u.z;
	ma = m->k;
	c[0] = may * may * may - 2 * may * may * maz + max * max * may
		+ may * maz * maz - may * ma * ma - 2 * max * max * maz
		- 2 * max * maz * ma;
	c[1] = 3 * mby * may * may - 4 * mby * may * maz - 2 * mbz * may
		* may + 2 * mbx * max * may + 2 * mbz * may * maz + mby
		* max * max + mby * maz * maz - mby * ma * ma
		- 4 * mbx * max * maz - 2 * mbz * max * max
		- 2 * mbz * max * ma - 2 * mbx * maz * ma;
	c[2] = 3 * mby * mby * may - 2 * mby * mby * maz
		+ mbx * mbx * may + mbz * mbz * may
		+ 2 * mbx * mby * max + 2 * mby * mbz * maz
		- 4 * mbx * mbz * max - 2 * mbx * mbz * ma
		- 2 * mbx * mbx * maz - 4 * mby * mbz * may;
	c[3] = mby * mby * mby + mbx * mbx * mby + mby * mbz * mbz
		- 2 * mbx * mbx * mbz - 2 * mby * mby * mbz;
	return (distances4(r, c, m));
}

int		in_moebius(t_obj *m, t_vecteur p)
{
	t_vecteur	param;
	long double		v;
	long double		u;
	long double km;
	km = m->k + 10;
	v = atan2(p.y, p.x);
	u = km;
	if (sin(v / 2) != 0.0)
		u = p.z / sin(v / 2);
	else if (cos(v) != 0.0 && cos(v / 2) != 0.0)
		u = (p.x / cos(v) - m->k) / cos(v / 2);
	else if (sin(v) != 0.0 && cos(v / 2) != 0.0)
		u = (p.y / sin(v) - m->k) / cos(v / 2);
	if (!(u >= -km && u <= km))
		return (0);
	param.x = (m->k + u * cos(v / 2)) * cos(v);
	param.y = (m->k + u * cos(v / 2)) * sin(v);
	param.z = u * sin(v / 2);
	param = sub(p, param);
	v = module(param);
	if (v > 0.000001 || v < -0.000001)
		return (0);
	return (1);
}


int		rat_trace_moebius(t_rt *r, t_obj *obj)
{
	if (intersection_moebius(r, obj))
	{
		obj->inter = sum(kv(r->u, r->dis), r->cam.position);
		get_normal(r, obj);
		r->obj = obj;
		return (1);
	}
	return (0);
}
