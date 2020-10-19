#include "rt.h"

int		intersection_dingdong(t_rt *r, t_obj *d)
{
	t_vecteur	x;
	long double	c[4];

	x = sub(r->ray.org, d->pos);
	c[3] = (r->u.z * r->u.z * r->u.z);
	c[2] = (r->u.x * r->u.x) + (r->u.y * r->u.y) + (3 * r->u.z * r->u.z * x.z) -
	(r->u.z * r->u.z);
	c[1] = 2 * (r->u.x * x.x + r->u.y * x.y - r->u.z * x.z) +
	3 * (r->u.z * x.z * x.z);
	c[0] = (x.x * x.x) + (x.y * x.y) - (x.z * x.z) + (x.z * x.z * x.z);
	return (distances3(r, c));
}

int		rat_trace_dingdong(t_rt *r, t_obj *obj)
{
	if (intersection_dingdong(r, obj))
	{
		obj->inter = sum(kv(r->u, r->dis), r->cam.position);
		get_normal(r, obj);
		r->obj = obj;
		return (1);
	}
	return (0);
}