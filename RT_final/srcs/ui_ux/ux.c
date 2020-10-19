/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ux.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 01:04:06 by slaanani          #+#    #+#             */
/*   Updated: 2020/03/25 01:04:06 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	select_object(t_rt *rt, int x, int y)
{
	rt->v2.x = x - 126;
	rt->v2.y = y - 190;
	make_ray(rt);
	rt->u = normalise(rt->ray.direct);
	rt->dis = MAX;
	if (cast_object(rt))
	{
		if (rt->selected)
			rt->last_selected = rt->selected;
		rt->selected = rt->obj;
		update_ui(rt);
	}
	else
		rt->selected = NULL;
}