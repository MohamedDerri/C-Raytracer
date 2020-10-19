/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rt_props.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 09:26:41 by slaanani          #+#    #+#             */
/*   Updated: 2020/03/18 09:26:41 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	find_in_props(char *key, t_xml_object *obj)
{
	int i;
	int nb;

	i = 0;
	obj->props = obj->head_props;
	nb = obj->nb_props;
	while (nb--)
	{
		if (ft_strequ(obj->props->key, key))
			return (i);
		i++;
		obj->props = obj->props-> next;
	}
	return (-1);
}

void	check_rt_props(t_rt *rt, char **accepted, char **required, t_point sze)
{
	int	i;
	int	nb;

	i = 0;
	while (i < sze.y)
	{
		if (find_in_props(required[i], rt->xml->obj_list) < 0)
			xml_error(SYNTAX_ERROR);
		i++;
	}
	rt->xml->obj_list->props = rt->xml->obj_list->head_props;
	nb = rt->xml->obj_list->nb_props;
	while (nb--)
	{
		if (find_in_tab(rt->xml->obj_list->props->key, accepted, sze.x) < 0)
			xml_error(SYNTAX_ERROR);
		rt->xml->obj_list->props = rt->xml->obj_list->props->next;
	}
}