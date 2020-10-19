/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_screen_operator.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 05:15:47 by slaanani          #+#    #+#             */
/*   Updated: 2020/03/14 05:16:08 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			retrieve_screen_operator(t_rt *rt)
{
	// char *accepted[3];
	// char *required[2];
	int	nb;

	rt->res = 1;
	rt->xml->obj_list->props = rt->xml->obj_list->head_props;
	nb = rt->xml->obj_list->nb_props;
	while (nb--)
	{
		if (ft_strequ(rt->xml->obj_list->props->key, "resolution"))
				rt->res = xml_float_or_percentage(rt->xml->obj_list->props->key,
rt->xml->obj_list->props->value);
		rt->xml->obj_list->props = rt->xml->obj_list->props->next;
	}
}