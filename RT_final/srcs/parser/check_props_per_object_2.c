/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_props_per_object_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 10:57:51 by slaanani          #+#    #+#             */
/*   Updated: 2020/03/18 10:57:51 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	check_paraboloid_props(t_rt *rt)
{
	// char *accepted[3];
	// char *required[2];

	char *accepted[6] = {"position", "k", "axe", "color", "translation",
"rotation"};
	char *required[3] = {"position", "axe", "k"};
	check_rt_props(rt, accepted, required, (t_point){6, 3});
}

void	check_cubet_props(t_rt *rt)
{
	// char *accepted[3];
	// char *required[2];

	char *accepted[6] = {"position", "color", "translation"};
	char *required[3] = {"position"};
	check_rt_props(rt, accepted, required, (t_point){3, 1});
}

void	check_ellipsoid_props(t_rt *rt)
{
	// char *accepted[3];
	// char *required[2];

	char *accepted[6] = {"position", "parameters", "color", "translation"};
	char *required[3] = {"position", "parameters"};
	check_rt_props(rt, accepted, required, (t_point){4, 2});
}

void	check_moebius_props(t_rt *rt)
{
	// char *accepted[3];
	// char *required[2];

	char *accepted[6] = {"k", "color", "translation"};
	char *required[3] = {"k"};
	check_rt_props(rt, accepted, required, (t_point){3, 1});
}