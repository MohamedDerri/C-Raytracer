/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_float_or_percentage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 05:15:47 by slaanani          #+#    #+#             */
/*   Updated: 2020/03/14 05:16:08 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	is_percentage(char *input, size_t len)
{
	if (input[len - 1] != '%')
		return (0);
	if (!isdouble(ft_strsub(input, 0, ft_strlen(input) - 1)))
		return (0);
	return (1);
}

long double	xml_float_or_percentage(char *prop, char *input)
{
	size_t len;

	len = ft_strlen(input);
	if (isdouble(input))
		return (ft_atof(input));
	else if (is_percentage(input, len))
		return (ft_atof(ft_strsub(input, 0, len - 1)) / 100);
	else
		xml_error(ft_strjoin("Expected a float or a percentage value in\
 the following property:", prop));
	return (-1);
}