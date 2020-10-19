/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 01:35:48 by slaanani          #+#    #+#             */
/*   Updated: 2020/03/20 01:35:48 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	get_cylinder(t_rt *rt, t_obj **obj)
{
	t_xml_object	*xobj;
	int				nb;

	xobj = rt->xml->obj_list;
	xobj->props = xobj->head_props;
	nb = xobj->nb_props;
	(*obj)->color = (t_color){.type = c_default, .r = 0, .g = 255, .b = 0};
	while (nb--)
	{
		get_standard_props(xobj->props->key, xobj->props->value, obj);
		if (ft_strequ(xobj->props->key, "rayon"))
			(*obj)->k = xml_float_or_percentage(xobj->props->key,
xobj->props->value);
		else if (ft_strequ(xobj->props->key, "axe"))
			(*obj)->axe = xml_vector(xobj->props->value, xobj->props->value);
		else if (ft_strequ(xobj->props->key, "limit"))
			(*obj)->limit =
xml_float_or_percentage(xobj->props->key, xobj->props->value);
		xobj->props = xobj->props->next;
	}
}
