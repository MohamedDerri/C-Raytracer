/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_selection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 02:35:19 by slaanani          #+#    #+#             */
/*   Updated: 2020/03/25 02:35:19 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color	multiply_colors(t_color col1, t_color col2)
{
	return ((t_color){
.type = c_default,
.r = fmin(col1.r + col2.r, 255),
.g = fmin(col1.g + col2.g, 255),
.b = fmin(col1.b + col2.b, 255),
	});
}

void	update_selection(t_rt *r)
{
	t_color color;

	if (r->selected && r->selected->color.type != c_default)
		return ;
	if (r->last_selected && r->last_selected->color.type != c_default)
		return ;
	color = (t_color){.type = c_default, .r = 255, .g = 127, .b = 39};
	if (r->selected)
	{
		if (r->last_selected)
			r->last_selected->color =
r->selected_color;
		r->selected_color = r->selected->color;
		r->selected->color = color;//multiply_colors(r->selected->color, color);
	}
	else if (r->last_selected)
		r->last_selected->color = r->selected_color;
	update_ui(r);
}