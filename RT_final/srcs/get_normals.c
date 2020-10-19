/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 02:35:11 by slaanani          #+#    #+#             */
/*   Updated: 2020/10/15 17:27:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			sphere_normal(t_obj *obj)
{
	obj->normal = sub(obj->inter, obj->pos);
	obj->normal = normalise(obj->normal);
}

void			plane_normal(t_obj *obj)
{
	
	obj->normal = create_v(0.0,1.0,0.0);//normalise(obj->axe);
}

void			cylinder_normal(t_rt *r, t_obj *obj)
{
	t_vecteur	assist;
	long double	m;
	t_vecteur	v;

	v = normalise(obj->axe);
	m = dot(r->u, kv(v, r->dis));
	m += dot(sub(r->ray.org, obj->pos), v);
	assist = sub(obj->inter, obj->pos);
	obj->normal = sub(assist, kv(v, m));
	obj->normal = normalise(obj->normal);
}

void			cone_normal(t_rt *r, t_obj *obj)
{
	t_vecteur	assist;
	long double	m;
	t_vecteur	v;

	v = normalise(obj->axe);
	m = dot(r->u, kv(v, r->dis));
	m += dot(sub(r->ray.org, obj->pos), v);
	assist = sub(obj->inter, obj->pos);
	obj->normal = sub(assist, kv(v, (1 + obj->k * obj->k) * m));
	obj->normal = normalise(obj->normal);
}

void			torus_normal(t_rt *r, t_obj *obj)
{
	long double k;
	long double m;
	t_vecteur   a;
	t_vecteur	v;

	a = r->u;
	v = normalise(obj->axe);
	k = dot(sub(obj->inter, obj->pos), v);
	a = sub(obj->inter, kv(v, k));
	m = obj->k * obj->k - k * k;
	m = sqrt(m);
	obj->normal = sub(obj->inter, sub(a, kv(sub(obj->pos, a),
	m / obj->l + m)));
	obj->normal = normalise(obj->normal);
}

void			paraboloid_normal(t_rt *r, t_obj *obj)
{
	long double  m;
	t_vecteur	 v;

	v = normalise(obj->axe);
	m = dot(r->u, kv(v, r->dis));
	m += dot(sub(r->ray.org, obj->pos), v);
	obj->normal = sub(sub(obj->inter, obj->pos), kv(obj->axe, m + obj->k));
	obj->normal = normalise(obj->normal);
}

void			ellipsoid_normal(t_rt *r, t_obj *obj)
{
	t_vecteur	p;

	p = r->u;
	p = sub(obj->inter, obj->pos);
	obj->normal.x = 2 * p.x / obj->axe.x * obj->axe.x;
	obj->normal.y = 2 * p.y / obj->axe.y * obj->axe.y;
	obj->normal.z = 2 * p.z / obj->axe.z * obj->axe.z;
	obj->normal = normalise(obj->normal);
}

void			hyperboloid_normal(t_rt *r, t_obj *obj)
{
	t_vecteur		p;
	
	p = r->u;
	p = sub(obj->inter, obj->pos);
	obj->normal.x = 2 * p.x / obj->axe.x * obj->axe.x;
	obj->normal.y = 2 * p.y / obj->axe.y * obj->axe.y;
	obj->normal.z = -2 * p.z / obj->axe.z * obj->axe.z;
	obj->normal = normalise(obj->normal);
}

void			cubet_normal(t_rt *r, t_obj *obj)
{
	t_vecteur		p;

	p = r->u;
	p = sub(obj->inter, obj->pos);
	obj->normal.x = 4 * p.x * p.x * p.x - 10 * p.x;
	obj->normal.y = 4 * p.y * p.y * p.y - 10 * p.y;
	obj->normal.z = 4 * p.z * p.z * p.z - 10 * p.z;
	obj->normal = normalise(obj->normal);
}

void			moebius_normal(t_rt *r, t_obj *obj)
{
	t_vecteur		p;

	p = r->u;
	p = sub(obj->inter, obj->pos);
	obj->normal.x = 2 * p.x * p.y - 4 * p.x * p.z - 2 * p.z * obj->k;
	obj->normal.y = 3 * p.y * p.y - 4 * p.y * p.z + p.x * p.x + p.z * p.z -
	obj->k * obj->k;
	obj->normal.z = -2 * p.y * p.y + 2 * p.y * p.z - 4 *  p.x * p.z - 2 * p.x *
	obj->k;
	obj->normal = normalise(obj->normal);
}

void			dingdong_normal(t_rt *r, t_obj *obj)
{
	t_vecteur		p;

	p = r->u;
	p = sub(obj->inter, obj->pos);
	obj->normal.x = 2 * p.x;
	obj->normal.y = 2 * p.y;
	obj->normal.z = 3 * p.z * p.z - 2 * p.z;
	obj->normal = normalise(obj->normal);
}

void			goursat_normal(t_rt *r, t_obj *obj)
{
	t_vecteur		p;

	p = r->u;
	p = sub(obj->inter, obj->pos);
	obj->normal.x = 4 * p.x * p.x * p.x;
	obj->normal.y = 4 * p.y * p.y * p.y;
	obj->normal.z = 4 * p.z * p.z * p.z;
	obj->normal = normalise(obj->normal);
}

void			teardrop_normal(t_rt *r, t_obj *obj)
{
	t_vecteur		p;

	p = r->u;
	p = sub(obj->inter, obj->pos);
	obj->normal.x = 2 * p.x;
	obj->normal.y = 2 * p.y;
	obj->normal.z = 4 * p.z * p.z * p.z - 3 * p.z * p.z;
	obj->normal = normalise(obj->normal);
}

void			get_normal(t_rt *r, t_obj *obj)
{
	if (obj->type == tplane || obj->type == tdisk)
		plane_normal(obj);
	if (obj->type == tsphere)
		sphere_normal(obj);
	if (obj->type == tcylinder)
		cylinder_normal(r, obj);
	if (obj->type == tcone)
		cone_normal(r, obj);
	if (obj->type == ttorus)
		torus_normal(r, obj);
	if (obj->type == tparaboloid)
		paraboloid_normal(r, obj);
	if (obj->type == tellipsoid)
		ellipsoid_normal(r, obj);
	if (obj->type == thyperboloid)
		hyperboloid_normal(r, obj);
	if (obj->type == tcubet)
		cubet_normal(r, obj);
	if (obj->type == tmoebius)
		moebius_normal(r, obj);
	if (obj->type == tdingdong)
		dingdong_normal(r, obj);
	if (obj->type == tgoursat)
		goursat_normal(r, obj);
	if (obj->type == tteardrop)
		teardrop_normal(r, obj);
}
