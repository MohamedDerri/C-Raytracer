/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 05:15:47 by slaanani          #+#    #+#             */
/*   Updated: 2020/03/14 05:16:08 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			xml_int(char *prop, char *input)
{
	int		i;

	i = 0;
	while (input[i])
	{
		if (!ft_isdigit(input[i]))
			xml_error(ft_strjoin("Expected an integer value in the following\
 property: ", prop));
		i++;
	}
	return (ft_atoi(input));
}
