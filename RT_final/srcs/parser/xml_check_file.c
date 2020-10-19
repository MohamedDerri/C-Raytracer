/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_check_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 05:13:22 by slaanani          #+#    #+#             */
/*   Updated: 2020/10/14 18:48:20 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	check_tag_props(char *line, size_t index, size_t len)
{
	int key;
	int value;

	index = skip_whitespaces(line, index);
	key = 1;
	value = 0;
	while (index < len - 2)
	{
		if (line[index] == '=' && key)
		{
			index ++;
			key = 0;
			value = 1;
		}
		if (key)
		{
			if (!strchr(VALID_CHARACTERS, line[index]))
				xml_error(SYNTAX_ERROR);
		}
		if (value)
		{
			if (line[index] != '"')
				xml_error(SYNTAX_ERROR);
			index++;
			while (line[index] && line[index] != '"')
				index++;
			if (line[index] != '"')
				xml_error(SYNTAX_ERROR);
			if (is_whitespace(line[index + 1]))
			{
				index = skip_whitespaces(line, index + 1);
				value = 0;
				key = 1;
				continue ;
			}
			else
			{
				if (line[index + 1] != '/' && line[index + 2] != '>')
					xml_error(SYNTAX_ERROR);
			}
		}
		index++;
	}
}

static void	check_tag_elements(char *line, size_t len)
{
	size_t	index;

	index = 1;
	while (!is_whitespace(line[index]))
	{
		if (!strchr(VALID_CHARACTERS, line[index]))
			xml_error(SYNTAX_ERROR);
		index++;
	}
	if (index > 1)
		check_tag_props(line, index, len);
}

static void	check_tag_format(char *line, size_t len)
{
	len = ft_strlen(line);
	if (line[len - 1] == 13)
		len--;
	if (line[0] != '<')
		xml_error(SYNTAX_ERROR);
	else if (line[len - 2] != '/' || line[len - 1] != '>')
		xml_error(SYNTAX_ERROR);
	else
		check_tag_elements(line, len);
}

void	xml_check_object(char *line, size_t len)
{
	line = ft_strtrim(line);
	check_tag_format(line, len);
}