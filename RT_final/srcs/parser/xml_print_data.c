/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_print_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 05:18:42 by slaanani          #+#    #+#             */
/*   Updated: 2020/03/19 07:44:38 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("%s\n" , tab[i]);
		i++;
	}
}

void	print_xml_props(t_xml_props *data, size_t nb)
{
	int		i;

	i = 0;
	while (nb--)
	{
		printf("\t| PROP %d |\n\t|key:   |%s|\n", i, data->key);
		printf("\t|value: |%s|\n", data->value);
		i++;
		data = data->next;
	}
}

void	print_xml_data(t_xml_helper *xml)
{
	int				i;
	t_xml_object	*data;

	data = xml->head_obj;
	i = 0;
	while (data)
	{
		printf("| OBJECT %d |\n|name: |%s|\n", i, data->name);
		print_xml_props(data->head_props, data->nb_props);
		i++;
		data = data->next;
	}
}
