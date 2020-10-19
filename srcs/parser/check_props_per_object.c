/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_props_per_object.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 10:44:34 by slaanani          #+#    #+#             */
/*   Updated: 2020/03/18 10:44:34 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	check_plane_props(t_rt *rt)
{
	// char *accepted[3];
	// char *required[2];

	char *accepted[6] = {"position", "normal", "color", "translation", "rotation", "noise"};
	char *required[2] = {"position", "normal"};
	check_rt_props(rt, accepted, required, (t_point){6, 2});
}

void	check_sphere_props(t_rt *rt)
{
	// char *accepted[3];
	char *required[2];

	char *accepted[5] = {"position", "rayon", "color", "translation", "noise"};
	// char *required[2] = {"position", "rayon"};
	required[0] = "position";
	required[1] = "rayon";
	check_rt_props(rt, accepted, required, (t_point){5, 2});
}

void	check_cylinder_props(t_rt *rt)
{
	// char *accepted[4];
	// char *required[2];

	char *accepted[7] = {"position", "rayon", "axe", "color", "translation", "rotation", "noise"};
	char *required[2] = {"position", "rayon"};
	check_rt_props(rt, accepted, required, (t_point){7, 2});
}

void	check_cone_props(t_rt *rt)
{
	// char *accepted[5];
	// char *required[2];

	char *accepted[7] = {"position", "axe", "k", "color", "translation", "rotation", "noise"};
	char *required[2] = {"position", "k"};
	check_rt_props(rt, accepted, required, (t_point){7, 2});
}

void	check_torus_props(t_rt *rt)
{
	// char *accepted[5];
	// char *required[2];

	char *accepted[8] = {"position", "axe", "k", "l", "color", "translation", "rotation", "noise"};
	char *required[3] = {"position", "k", "l"};
	check_rt_props(rt, accepted, required, (t_point){8, 3});
}