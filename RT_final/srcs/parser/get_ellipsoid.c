/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paraboloid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 08:58:00 by slaanani          #+#    #+#             */
/*   Updated: 2020/03/22 08:58:00 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	get_ellipsoid(t_rt *rt, t_obj **obj)
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
		if (ft_strequ(xobj->props->key, "parameters"))
			(*obj)->axe = xml_vector(xobj->props->key, xobj->props->value);
		xobj->props = xobj->props->next;
	}
}
