/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 01:34:50 by slaanani          #+#    #+#             */
/*   Updated: 2020/03/20 01:34:50 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	get_plane(t_rt *rt, t_obj **obj)
{
	t_xml_object	*xobj;
	int				nb;

	xobj = rt->xml->obj_list;
	xobj->props = xobj->head_props;
	nb = xobj->nb_props;
	(*obj)->color = (t_color){.type = c_default, .r = 0, .g = 255, .b = 255};
	while (nb--)
	{
		get_standard_props(xobj->props->key, xobj->props->value, obj);
		if (ft_strequ(xobj->props->key, "normal"))
			(*obj)->axe = xml_vector(xobj->props->key, xobj->props->value);
		else if (ft_strequ(xobj->props->key, "limit"))
			(*obj)->limit =
xml_float_or_percentage(xobj->props->key, xobj->props->value);
		xobj->props = xobj->props->next;
	}
}
