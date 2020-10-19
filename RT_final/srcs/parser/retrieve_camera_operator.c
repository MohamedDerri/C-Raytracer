/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_camera_operator.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 12:14:13 by slaanani          #+#    #+#             */
/*   Updated: 2020/03/18 12:14:13 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	get_filter(char *value)
{
	if (ft_strequ(value, "sepia"))
		return filter_sepia;
	else if (ft_strequ(value, "motion blur"))
		return filter_mb;
	else
		xml_error("Invalid filter name");
	return (0);
}

void		retrieve_camera_operator(t_rt *rt)
{
	// char *accepted[3];
	// char *required[2];
	int nb;

	char *accepted[4] = {"position", "lookat", "focal_length", "filter"};
	char *required[2] = {"position", "lookat"};
	check_rt_props(rt, accepted, required, (t_point){4, 2});
	rt->cam.focal_length = 1;
	rt->xml->obj_list->props = rt->xml->obj_list->head_props;
	nb = rt->xml->obj_list->nb_props;
	while (nb--)
	{
		if (ft_strequ(rt->xml->obj_list->props->key, "position"))
			rt->cam.position =
xml_vector(rt->xml->obj_list->props->key, rt->xml->obj_list->props->value);
		else if (ft_strequ(rt->xml->obj_list->props->key, "lookat"))
			rt->cam.lookat =
xml_vector(rt->xml->obj_list->props->key, rt->xml->obj_list->props->value);
		else if (ft_strequ(rt->xml->obj_list->props->key, "focal_length"))
			rt->cam.focal_length =
xml_float_or_percentage(rt->xml->obj_list->props->key,
rt->xml->obj_list->props->value);
		else if (ft_strequ(rt->xml->obj_list->props->key, "filter"))
			rt->cam.f = get_filter(rt->xml->obj_list->props->value);
		rt->xml->obj_list->props = rt->xml->obj_list->props->next;
	}
}