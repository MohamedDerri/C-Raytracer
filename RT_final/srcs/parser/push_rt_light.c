/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 09:14:32 by slaanani          #+#    #+#             */
/*   Updated: 2020/03/18 09:14:32 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		get_light_type(char *value)
{
	int type;
	char *tab[3] = {"default", "directional", "parallel"};

	type = find_in_tab(value, tab, 3);
	if (type < 0)
		xml_error("No such a light type.");
	return (type);
}

static void		get_light(t_rt *rt, t_light_lst **light)
{
	t_xml_object	*obj;
	int				nb;

	obj = rt->xml->obj_list;
	obj->props = obj->head_props;
	nb = obj->nb_props;
	while (nb--)
	{
		if (ft_strequ(obj->props->key, "position"))
			(*light)->org = xml_vector(obj->props->key, obj->props->value);
		else if (ft_strequ(obj->props->key, "type"))
			(*light)->type = get_light_type(obj->props->value);
		else if (ft_strequ(obj->props->key, "intensity"))
			(*light)->intensity = xml_float_or_percentage(obj->props->key,
obj->props->value);
		else if (ft_strequ(obj->props->key, "color"))
			(*light)->color = xml_color(obj->props->value);
		obj->props = obj->props->next;
	}
}

static void		check_light_props(t_rt *rt)
{
	// char *accepted[4];
	// char *required[1];

	char *accepted[4] = {"position", "type", "intensity", "color"};
	char *required[1] = {"position"};
	check_rt_props(rt, accepted, required, (t_point){4, 1});
}

void		push_rt_light(t_rt *rt)
{
	t_light_lst	*light;

	check_light_props(rt);
	if (!rt->last_light)
	{
		rt->light = (t_light_lst *)ft_memalloc(sizeof(t_light_lst));
		light = rt->light;
	}
	else
	{
		rt->last_light->next = (t_light_lst *)ft_memalloc(sizeof(t_light_lst));
		light = rt->last_light->next;
	}
	light->type = lt_default;
	light->intensity = 1;
	light->color = (t_color){.r = 255, .g = 255, .b = 255};
	get_light(rt, &light);
	light->next = NULL;
	rt->last_light = light;
}