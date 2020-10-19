#include "rt.h"

t_color get_color(t_rt *rt)
{
    t_vecteur inter;
    t_vecteur p;

    if (rt->obj->color.type == c_default || rt->obj->color.type == c_texture)
        return (rt->obj->color);
    inter = sum(kv(rt->u, rt->dis), rt->ray.org);
    p = create_v(dot(inter, rt->obj->repere.i), dot(inter, rt->obj->repere.j), dot(inter, rt->obj->repere.k));

    if (rt->obj->color.type == c_voronoi)
        return (voronoi_noise(p));
    if (rt->obj->color.type == c_perlin)
        return (perlin(rt->ran, p, rt->obj));
    
     return (rt->obj->color);
}