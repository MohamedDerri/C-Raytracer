#include "rt.h"

int GetAngle(t_obj *obj, t_vecteur inter)
{
	if (obj->type == tsphere)
		return (GetAngleSphere(obj, inter));
	else if (obj->type == tplane)
		return (GetAnglePlan(obj, inter));
	else if (obj->type == tcylinder)
		return (GetAngleCylinder(obj, inter));
	else if (obj->type == tcone)
		return (GetAngleCone(obj, inter));
	return (0);
}

int getColorFromTexture(t_rt *rt, t_obj *obj, long double t)
{
	int i;
	int j;
	t_vecteur inter;
	t_vecteur p;
	int c;

	inter =  sum(kv(rt->u, t), rt->ray.org);

	// p = sub(obj->pos,create_v(dot(inter,create_v(0.0 ,0.0, 1.0)), dot(inter, create_v(0.0 ,-1.0, 0.0)), dot(inter, create_v(1.0 ,0.0, 0.0))));
	p = create_v(dot(inter, obj->repere.i), dot(inter, obj->repere.j), dot(inter, obj->repere.k));

	if (obj->sliced == 1)
		return (slice(obj, p));

	if (obj->color.type == c_texture)
	{

		c = GetAngle(obj, p);
		i = obj->txt->Um * obj->txt->w;
		j = (1.0 - obj->txt->Vm) * obj->txt->h - 0.001;
		i = (i < 0) ? 0 : i;
		j = (j < 0) ? 0 : j;
		i = (i > obj->txt->w - 1) ? obj->txt->w - 1 : i;
		j = (j > obj->txt->h - 1) ? obj->txt->h - 1 : j;
		if (obj->txt->buf[j * obj->txt->w + i] == 0 || c == 0)
			return (0);
	
		obj->color.r = (obj->txt->buf[j * obj->txt->w + i] >> 16) & 0xFF;
		obj->color.g = (obj->txt->buf[j * obj->txt->w + i] >> 8) & 0xFF;
		obj->color.b = obj->txt->buf[j * obj->txt->w + i] & 0xFF;
	}
	
		// if (obj->color.type == c_perlin)
		// 	 perlin(rt->ran, p, obj);
		// if (obj->color.type == c_voronoi)
		// 	 voronoi_noise( p, obj);

	return (1);
}