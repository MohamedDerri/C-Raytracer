/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cubet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 02:54:43 by slaanani          #+#    #+#             */
/*   Updated: 2020/03/23 02:54:43 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	get_cubet(t_rt *rt, t_obj **obj)
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
		xobj->props = xobj->props->next;
	}
}