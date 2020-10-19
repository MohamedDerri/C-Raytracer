/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 09:34:26 by slaanani          #+#    #+#             */
/*   Updated: 2020/03/09 08:00:28 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		retrieve_obj_type(char *name)
{
	// char	*tab[17];
	int		type;

	char	*tab[17] = {"world", "screen", "light", "camera",
"plane", "sphere", "cylinder", "cone", "torus", "paraboloid",
"ellipsoid", "hyperboloid", "cubet", "moebius", "dingdong", "goursat",
"teardrop"};

	if ((type = find_in_tab(name, tab, 17)) < 0)
		xml_error(ft_strjoin("No such an RT object name: ", name));
	return (type);
}

static void		xml_to_rt(t_rt *rt)
{
	int	type;

	rt->xml->obj_list = rt->xml->head_obj;
	while (rt->xml->obj_list)
	{
		type = retrieve_obj_type(rt->xml->obj_list->name);
		if (type == tworld)
			retrieve_world_operator(rt);
		else if (type == tscreen)
			retrieve_screen_operator(rt);
		else if (type == tlight)
			push_rt_light(rt);
		else if (type == tcamera)
			retrieve_camera_operator(rt);
		else
			push_rt_object(rt, type);
		rt->xml->obj_list = rt->xml->obj_list->next;
	}
}

void			xml_parse(char *file, t_rt *rt)
{
	char			*line;
	size_t			len;
	int				fd;

	rt->xml->obj_list = (t_xml_object *)ft_memalloc(sizeof(t_xml_object));
	rt->xml->nb_obj = 0;
	rt->xml->head_obj = rt->xml->obj_list;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		xml_error("Cannot open this file.");
	while (get_next_line(fd, &line))
	{
		len = ft_strlen(line);
		line = ft_strtrim(line);
		xml_check_object(line, len);
		rt->xml->nb_obj++;
		xml_stock_object(rt->xml, line);
		rt->xml->obj_list->next =
(t_xml_object *)ft_memalloc(sizeof(t_xml_object));
		rt->xml->tmp_obj = rt->xml->obj_list;
		rt->xml->obj_list = rt->xml->obj_list->next;
	}
	rt->xml->tmp_obj->next = NULL;
	/*
	**   everybody_here?
	**   dont forget to check if the necessary objects are there !! (world, screen, camera ..)
	*/
	xml_to_rt(rt);
}
