/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 04:32:13 by mderri            #+#    #+#             */
/*   Updated: 2020/03/18 13:00:12 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_solve_quadric(long double w[3], long double s[2])
{
	long double	p;
	long double	q;
	long double	d;

	p = w[1] / (2.0 * w[2]);
	q = w[0] / w[2];
	d = p * p - q;
	if (IS_ZERO(d))
	{
		s[0] = -p;
		return (1);
	}
	else if (d < 0)
		return (0);
	else
	{
		d = sqrt(d);
		s[0] = d - p;
		s[1] = -d - p;
		return (2);
	}
}
