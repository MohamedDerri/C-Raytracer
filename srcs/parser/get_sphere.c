/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 01:35:21 by slaanani          #+#    #+#             */
/*   Updated: 2020/03/20 01:35:21 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	get_noise_type(char *value)
{
	if (ft_strequ(value, "voronoi"))
		return (c_voronoi);
	else if (ft_strequ(value, "perlin"))
		return (c_perlin);
	else if (ft_strequ(value, "damier"))
		return (c_damier);
	else
		xml_error("Unknown noise name.");
	return (-1);
}

void	get_standard_props(char *key, char *value, t_obj **obj)
{
	if (ft_strequ(key, "position"))
		(*obj)->pos = xml_vector(key, value);
	else if (ft_strequ(key, "color"))
		(*obj)->color = xml_color(value);
	else if (ft_strequ(key, "translation"))
		(*obj)->tr = xml_vector(key, value);
	else if (ft_strequ(key, "rotation"))
		(*obj)->rot = xml_vector(key, value);
	else if (ft_strequ(key, "noise"))
		(*obj)->color.type = get_noise_type(value);
}

void	get_sphere(t_rt *rt, t_obj **obj)
{
	t_xml_object	*xobj;
	int				nb;

	xobj = rt->xml->obj_list;
	xobj->props = xobj->head_props;
	nb = xobj->nb_props;
	(*obj)->color = (t_color){.type = c_default, .r = 255, .g = 0, .b = 0};
	while (nb--)
	{
		get_standard_props(xobj->props->key, xobj->props->value, obj);
		if (ft_strequ(xobj->props->key, "rayon"))
			(*obj)->k = xml_float_or_percentage(xobj->props->key,
xobj->props->value);
		else if (ft_strequ(xobj->props->key, "limit"))
			(*obj)->limit =
xml_float_or_percentage(xobj->props->key, xobj->props->value);
		xobj->props = xobj->props->next;
	}
}
