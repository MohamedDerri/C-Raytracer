/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_stock_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 05:26:31 by slaanani          #+#    #+#             */
/*   Updated: 2020/10/14 18:49:31 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		xml_get_name(t_xml_object *data, char *line, size_t index)
{
	size_t	len;
	size_t	save;
	int		i;

	len = 0;
	i = 0;
	save = index;
	while (!is_whitespace(line[index++]))
		len++;
	data->name = ft_strnew(len);
	while (len--)
	{
		data->name[i] = line[save];
		i++;
		save++;
	}
	return (save);
}

static void		get_property_value(char *string, t_xml_props **prop)
{
	char	**tab;
	size_t	len;

	tab = ft_strsplit(string, '=');
	if (!tab[1])
		xml_error(SYNTAX_ERROR);
	len = ft_strlen(tab[1]);
	(*prop)->value = ft_strtrim(ft_strsub(tab[1], 1, len - 2));
	free_splited(tab);
}

static void		get_property_key(char *string, t_xml_props **prop)
{
	char	**tab;

	tab = ft_strsplit(string, '=');
	(*prop)->key = ft_strdup(tab[0]);
	free_splited(tab);
}

static void		xml_get_props(t_xml_helper *xml, char *line, size_t index)
{
	char			**tab;
	int				i;

	tab = custom_split(line, index);
	i = 0;
	xml->obj_list->props = (t_xml_props *)ft_memalloc(sizeof(t_xml_props));
	xml->obj_list->nb_props = 0;
	xml->obj_list->head_props = xml->obj_list->props;
	while (tab[i])
	{
		get_property_key(tab[i], &xml->obj_list->props);
		get_property_value(tab[i], &xml->obj_list->props);
		xml->obj_list->nb_props++;
		xml->obj_list->props->next = (t_xml_props *)ft_memalloc(sizeof(t_xml_props));
		xml->obj_list->tmp_props = xml->obj_list->props;
		xml->obj_list->props = xml->obj_list->props->next;
		i++;
	}
	xml->obj_list->tmp_props = NULL;
}

void	xml_stock_object(t_xml_helper *xml, char *line)
{
	size_t	index;

	index = xml_get_name(xml->obj_list, line, 1);
	xml_get_props(xml, line, index);
}