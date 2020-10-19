/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_world_operator.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 05:15:47 by slaanani          #+#    #+#             */
/*   Updated: 2020/03/14 05:16:08 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			retrieve_world_operator(t_rt *rt)
{
	int nb;
	char *accepted[2] = {"name", "ambient"};
	char *required[1] = {"ambient"};

	check_rt_props(rt, accepted, required, (t_point){2, 1});
	rt->xml->obj_list->props = rt->xml->obj_list->head_props;
	nb = rt->xml->obj_list->nb_props;
	while (nb--)
	{
		if (ft_strequ(rt->xml->obj_list->props->key, "ambient"))
			rt->amb = xml_float_or_percentage(rt->xml->obj_list->props->key,
rt->xml->obj_list->props->value);
		else if (ft_strequ(rt->xml->obj_list->props->key, "name"))
			rt->name = ft_strdup(rt->xml->obj_list->props->value);
		rt->xml->obj_list->props = rt->xml->obj_list->props->next;
	}
}