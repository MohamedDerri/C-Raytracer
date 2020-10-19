#include "rt.h"
void duplicate(t_obj *obj)
{
    obj->compos = (struct s_obj *)malloc(sizeof(struct s_obj));
    obj->compos->type = obj->type;
    obj->compos->color = obj->color;
    obj->compos->pos = obj->pos;
    obj->compos->axe = obj->axe;
    if (obj->type != tplane)
        obj->compos->k = obj->k;
    obj->compos->repere = obj->repere;
    obj->compos->limit = obj->limit;
    obj->compos->txt = obj->txt;
    obj->compos->color.type = obj->color.type;
    obj->compos->t2 = obj->t2;
    obj->compos->sliced = obj->sliced;
    if (obj->color.type == c_texture)
    {
        obj->compos->txt = obj->txt;
        obj->compos->txt->coup = obj->txt->coup;
        obj->compos->txt->hi = obj->txt->hi;
    }
    if (obj->type == tplane)
    {
        obj->compos->limitx = obj->limitx;
        obj->compos->limitz = obj->limitz;
    }
}
void dup_compos(t_obj *obj, t_obj *compos, long double x, long double r)
{
    compos->type = tdisk;
    compos->color = obj->color;
    compos->pos = sum(obj->pos, kv(obj->axe, x * obj->limit));
    compos->axe = obj->axe;
    compos->repere = obj->repere;
    compos->k = r;
    compos->color.type = obj->color.type;
    compos->t2 = obj->t2;
}
void add_plane_compos(t_obj *obj)
{
    obj->compos = (struct s_obj *)malloc(sizeof(struct s_obj));
    duplicate(obj);
    obj->compos->next = NULL;
}
void add_cylinder_compos(t_obj *obj)
{
    obj->compos = (struct s_obj *)malloc(sizeof(struct s_obj));
    duplicate(obj);
    if (obj->sliced == 0)
        obj->compos->next = NULL;
    else
    {
        obj->compos->next = (struct s_obj *)malloc(sizeof(struct s_obj));
        dup_compos(obj, obj->compos->next, 1.0, obj->k);
        obj->compos->next->next = (struct s_obj *)malloc(sizeof(struct s_obj));
        dup_compos(obj, obj->compos->next->next, -1.0, obj->k);
        obj->compos->next->next->next = NULL;
    }
}
void add_cone_compos(t_obj *obj)
{
    obj->compos = (struct s_obj *)malloc(sizeof(struct s_obj));
    duplicate(obj);
    if (obj->sliced == 0)
        obj->compos->next = NULL;
    else
    {
        obj->compos->next = (struct s_obj *)malloc(sizeof(struct s_obj));
        dup_compos(obj, obj->compos->next, 1.0, tan((obj->k)) * obj->limit);
        obj->compos->next->next = (struct s_obj *)malloc(sizeof(struct s_obj));
        dup_compos(obj, obj->compos->next->next, -1.0, tan((obj->k)) * obj->limit);
        obj->compos->next->next->next = NULL;
    }
}
void add_cube_compos(t_obj *obj)
{
    obj->compos = (struct s_obj *)malloc(sizeof(struct s_obj));
    obj->compos = (struct s_obj *)malloc(sizeof(struct s_obj));
    obj->compos->sliced = 1;
    obj->compos->type = tplane;
    obj->compos->color = obj->color;
    obj->compos->pos = sum(obj->pos, kv(obj->repere.j, 1.0 * obj->k));
    obj->compos->axe = obj->repere.j;
    obj->compos->repere = obj->repere;
    obj->compos->limitx = obj->k;
    obj->compos->limitz = obj->k;
    obj->compos->color.type = obj->color.type;
    obj->compos->t2 = obj->t2;
    obj->compos->next = (struct s_obj *)malloc(sizeof(struct s_obj));
    obj->compos->next->sliced = 1;
    obj->compos->next->type = tplane;
    obj->compos->next->color = obj->color;
    obj->compos->next->pos = sum(obj->pos, kv(obj->repere.j, -1.0 * obj->k));
    obj->compos->next->axe = kv(obj->repere.j, -1.0);
    obj->compos->next->repere = obj->repere;
    obj->compos->next->limitx = obj->k;
    obj->compos->next->limitz = obj->k;
    obj->compos->next->color.type = obj->color.type;
    obj->compos->next->t2 = obj->t2;
    obj->compos->next->next = (struct s_obj *)malloc(sizeof(struct s_obj));
    obj->compos->next->next = (struct s_obj *)malloc(sizeof(struct s_obj));
    obj->compos->next->next->sliced = 1;
    obj->compos->next->next->type = tplane;
    obj->compos->next->next->color = obj->color;
    obj->compos->next->next->pos = sum(obj->pos, kv(obj->repere.i, 1.0 * obj->k));
    obj->compos->next->next->axe = kv(obj->repere.i, -1.0);
    obj->compos->next->next->repere.i = obj->repere.j;
    obj->compos->next->next->repere.k = obj->repere.k;
    obj->compos->next->next->repere.j = obj->repere.i;
    obj->compos->next->next->limitx = obj->k;
    obj->compos->next->next->limitz = obj->k;
    obj->compos->next->next->color.type = obj->color.type;
    obj->compos->next->next->t2 = obj->t2;
    obj->compos->next->next->next = (struct s_obj *)malloc(sizeof(struct s_obj));
    obj->compos->next->next->next->sliced = 1;
    obj->compos->next->next->next->type = tplane;
    obj->compos->next->next->next->color = obj->color;
    obj->compos->next->next->next->pos = sum(obj->pos, kv(obj->repere.i, -1.0 * obj->k));
    obj->compos->next->next->next->axe = kv(obj->repere.i, -1.0);
    obj->compos->next->next->next->repere.i = obj->repere.j;
    obj->compos->next->next->next->repere.k = obj->repere.k;
    obj->compos->next->next->next->repere.j = obj->repere.i;
    obj->compos->next->next->next->limitx = obj->k;
    obj->compos->next->next->next->limitz = obj->k;
    obj->compos->next->next->next->color.type = obj->color.type;
    obj->compos->next->next->next->t2 = obj->t2;
    obj->compos->next->next->next->next = (struct s_obj *)malloc(sizeof(struct s_obj));
    obj->compos->next->next->next->next->sliced = 1;
    obj->compos->next->next->next->next->type = tplane;
    obj->compos->next->next->next->next->color = obj->color;
    obj->compos->next->next->next->next->pos = sum(obj->pos, kv(obj->repere.k, 1.0 * obj->k));
    obj->compos->next->next->next->next->axe = obj->repere.k;
    obj->compos->next->next->next->next->repere.i = obj->repere.i;
    obj->compos->next->next->next->next->repere.j = obj->repere.k;
    obj->compos->next->next->next->next->repere.k = obj->repere.j;
    obj->compos->next->next->next->next->limitx = obj->k;
    obj->compos->next->next->next->next->limitz = obj->k;
    obj->compos->next->next->next->next->color.type = obj->color.type;
    obj->compos->next->next->next->next->t2 = obj->t2;
    obj->compos->next->next->next->next->next = (struct s_obj *)malloc(sizeof(struct s_obj));
    obj->compos->next->next->next->next->next->sliced = 1;
    obj->compos->next->next->next->next->next->type = tplane;
    obj->compos->next->next->next->next->next->color = obj->color;
    obj->compos->next->next->next->next->next->pos = sum(obj->pos, kv(obj->repere.k, -1.0 * obj->k));
    obj->compos->next->next->next->next->next->axe = kv(obj->repere.k, -1.0);
    obj->compos->next->next->next->next->next->repere.i = obj->repere.i;
    obj->compos->next->next->next->next->next->repere.j = obj->repere.k;
    obj->compos->next->next->next->next->next->repere.k = obj->repere.j;
    obj->compos->next->next->next->next->next->limitx = obj->k;
    obj->compos->next->next->next->next->next->limitz = obj->k;
    obj->compos->next->next->next->next->next->color.type = obj->color.type;
    obj->compos->next->next->next->next->next->t2 = obj->t2;
    obj->compos->next->next->next->next->next->next = NULL;
    // obj->compos->next->next = NULL;
}
void add_sphere_compos(t_obj *obj)
{
    obj->limit = 0.0;
    obj->compos = (struct s_obj *)malloc(sizeof(struct s_obj));
    duplicate(obj);
    if (obj->sliced == 0)
        obj->compos->next = NULL;
    else
    {
        // obj->compos->next = (struct s_obj *)malloc(sizeof(struct s_obj));
        // dup_compos(obj,obj->compos->next, 1.0, obj->k);
        // obj->compos->next->next = NULL;
    }
}
void add_compos(t_obj *obj)
{
    if (obj->type == tplane)
        add_plane_compos(obj);
    if (obj->type == tcylinder)
        add_cylinder_compos(obj);
    else if (obj->type == tcone)
        add_cone_compos(obj);
    else if (obj->type == tsphere)
        add_sphere_compos(obj);
    else if (obj->type == tcube)
        add_cube_compos(obj);
		else if (obj->type == ttorus || obj->type == tparaboloid || obj->type == tellipsoid ||
		obj->type == thyperboloid || obj->type == tcubet || obj->type == tmoebius || obj->type == tdingdong ||
		obj->type == tgoursat || obj->type == tteardrop)
		{
			duplicate(obj);
			obj->compos->next = NULL;
		}
    // duplicate(obj);
    // obj->compos->next = NULL;
}














// #include "rt.h"

// void duplicate(t_obj *obj)
// {
// 	obj->compos = (struct s_obj *)malloc(sizeof(struct s_obj));
// 	obj->compos->type = obj->type;
// 	obj->compos->color = obj->color;
// 	obj->compos->pos = obj->pos;
// 	obj->compos->axe = obj->axe;
// 	if(obj->type != tplane)
// 		obj->compos->k = obj->k;
// 	obj->compos->repere = obj->repere;
// 	obj->compos->limit = obj->limit;
// 	obj->compos->txt = obj->txt;
// 	obj->compos->color.type = obj->color.type;
// 	obj->compos->t2 = obj->t2;
// 	obj->compos->sliced = obj->sliced;
// 	if(obj->color.type == c_texture)
// 	{
// 		obj->compos->txt = obj->txt;
// 		obj->compos->txt->coup = obj->txt->coup;
// 		obj->compos->txt->hi = obj->txt->hi;
// 	}
// 	if(obj->type == tplane)
// 	{
// 		obj->compos->limitx = obj->limitx;
// 		obj->compos->limitz = obj->limitz;
// 	}
// }

// void dup_compos(t_obj *obj, t_obj *compos, long double x , long double r)
// {
// 	compos->type = tdisk;
// 	compos->color =  obj->color;
// 	compos->pos = sum(obj->pos, kv(obj->axe, x * obj->limit));
// 	compos->axe = obj->axe;
// 	compos->repere = obj->repere;
// 	compos->k = r;
// 	compos->color.type = obj->color.type;
// 	compos->t2 = obj->t2;
// }
// void	add_plane_compos(t_obj *obj)
// {
// 	obj->compos = (struct s_obj *)malloc(sizeof(struct s_obj));
// 	duplicate(obj);
// 	obj->compos->next = NULL;
// }

// void	add_cylinder_compos(t_obj *obj)
// {
// 	obj->compos = (struct s_obj *)malloc(sizeof(struct s_obj));
// 	duplicate(obj);
// 	if(obj->sliced == 0)
// 		obj->compos->next = NULL;
// 	else{
// 	obj->compos->next = (struct s_obj *)malloc(sizeof(struct s_obj));
// 	dup_compos(obj,obj->compos->next, 1.0, obj->k);
// 	obj->compos->next->next = (struct s_obj *)malloc(sizeof(struct s_obj));
// 	dup_compos(obj,obj->compos->next->next, -1.0, obj->k);
// 	obj->compos->next->next->next = NULL;
// 	}
// }

// void	add_cone_compos(t_obj *obj)
// {	
// 	obj->compos = (struct s_obj *)malloc(sizeof(struct s_obj));
// 	duplicate(obj);
// 	if(obj->sliced == 0)
// 		obj->compos->next = NULL;
// 	else{
// 	obj->compos->next = (struct s_obj *)malloc(sizeof(struct s_obj));
// 	dup_compos(obj,obj->compos->next, 1.0, tan((obj->k)) * obj->limit);
// 	obj->compos->next->next = (struct s_obj *)malloc(sizeof(struct s_obj));
// 	dup_compos(obj,obj->compos->next->next, -1.0, tan((obj->k)) * obj->limit);
// 	obj->compos->next->next->next = NULL;
// 	}
// }

// void	add_sphere_compos(t_obj *obj)
// {
// 	obj->limit = 0.0;
// 	obj->compos = (struct s_obj *)malloc(sizeof(struct s_obj));
// 	duplicate(obj);
// 	if(obj->sliced == 0)
// 		obj->compos->next = NULL;
// 	else{
// 	// obj->compos->next = (struct s_obj *)malloc(sizeof(struct s_obj));
// 	// dup_compos(obj,obj->compos->next, 1.0, obj->k);
// 	// obj->compos->next->next = NULL;
// 	} 
// }

// void	add_compos(t_obj *obj)
// {
// 		if (obj->type == tplane)
// 			add_plane_compos(obj);
// 		else if (obj->type == tcylinder)
// 			add_cylinder_compos(obj);
// 		else if (obj->type == tcone)
// 			add_cone_compos(obj);
// 		else if (obj->type == tsphere)
// 			add_sphere_compos(obj);
// 		else if (obj->type == ttorus || obj->type == tparaboloid || obj->type == tellipsoid ||
// 		obj->type == thyperboloid || obj->type == tcubet || obj->type == tmoebius || obj->type == tdingdong ||
// 		obj->type == tgoursat || obj->type == tteardrop)
// 		{
// 			duplicate(obj);
// 			obj->compos->next = NULL;
// 		}
// }