/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hover.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <mderri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 03:41:02 by mderri            #+#    #+#             */
/*   Updated: 2020/10/19 06:53:29 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	hover_add_sphere(t_rt *rt, int x, int y)
{
	if ((x > rt->ui.add_sphere->x && x < (rt->ui.add_sphere->x + rt->ui.add_sphere->w))
&& (y > rt->ui.add_sphere->y && y < (rt->ui.add_sphere->y + rt->ui.add_sphere->h)))
	{
		if (rt->ui.add_sphere->hovered == 0)
		{
			rt->ui.add_sphere->hovered = 1;
		update_ui_element(rt, &rt->ui.add_sphere,
"./assets/interface/button-add-sphere-hovered.png");
		}
	}
	else
	{
		if (rt->ui.add_sphere->hovered == 1)
		{
			rt->ui.add_sphere->hovered = 0;
		update_ui_element(rt, &rt->ui.add_sphere,
"./assets/interface/button-add-sphere-normal.png");
		}
	}
}

void	hover_add_cylinder(t_rt *rt, int x, int y)
{
	if ((x > rt->ui.add_cylinder->x && x < (rt->ui.add_cylinder->x + rt->ui.add_cylinder->w))
&& (y > rt->ui.add_cylinder->y && y < (rt->ui.add_cylinder->y + rt->ui.add_cylinder->h)))
	{
		if (rt->ui.add_cylinder->hovered == 0)
		{
			rt->ui.add_cylinder->hovered = 1;
		update_ui_element(rt, &rt->ui.add_cylinder,
"./assets/interface/button-add-cylinder-hovered.png");
		}
	}
	else
	{
		if (rt->ui.add_cylinder->hovered == 1)
		{
			rt->ui.add_cylinder->hovered = 0;
		update_ui_element(rt, &rt->ui.add_cylinder,
"./assets/interface/button-add-cylinder-normal.png");
		}
	}
}

void	hover_add_cone(t_rt *rt, int x, int y)
{
	if ((x > rt->ui.add_cone->x && x < (rt->ui.add_cone->x + rt->ui.add_cone->w))
&& (y > rt->ui.add_cone->y && y < (rt->ui.add_cone->y + rt->ui.add_cone->h)))
	{
		if (rt->ui.add_cone->hovered == 0)
		{
			rt->ui.add_cone->hovered = 1;
		update_ui_element(rt, &rt->ui.add_cone,
"./assets/interface/button-add-cone-hovered.png");
		}
	}
	else
	{
		if (rt->ui.add_cone->hovered == 1)
		{
			rt->ui.add_cone->hovered = 0;
		update_ui_element(rt, &rt->ui.add_cone,
"./assets/interface/button-add-cone-normal.png");
		}
	}
}

void	hover_add_plane(t_rt *rt, int x, int y)
{
	if ((x > rt->ui.add_plane->x && x < (rt->ui.add_plane->x + rt->ui.add_plane->w))
&& (y > rt->ui.add_plane->y && y < (rt->ui.add_plane->y + rt->ui.add_plane->h)))
	{
		if (rt->ui.add_plane->hovered == 0)
		{
			rt->ui.add_plane->hovered = 1;
		update_ui_element(rt, &rt->ui.add_plane,
"./assets/interface/button-add-plane-hovered.png");
		}
	}
	else
	{
		if (rt->ui.add_plane->hovered == 1)
		{
			rt->ui.add_plane->hovered = 0;
		update_ui_element(rt, &rt->ui.add_plane,
"./assets/interface/button-add-plane-normal.png");
		}
	}
}

void	hover_none(t_rt *rt, int x, int y)
{
	if ((x > rt->ui.none->x && x < (rt->ui.none->x + rt->ui.none->w))
&& (y > rt->ui.none->y && y < (rt->ui.none->y + rt->ui.none->h)))
	{
		if (rt->ui.none->hovered == 0)
		{
			rt->ui.none->hovered = 1;
		update_ui_element(rt, &rt->ui.none,
"./assets/interface/none-hovered.png");
		}
	}
	else
	{
		if (rt->ui.none->hovered == 1)
		{
			rt->ui.none->hovered = 0;
		update_ui_element(rt, &rt->ui.none,
"./assets/interface/none-normal.png");
		}
	}
}

void	hover_voronoi(t_rt *rt, int x, int y)
{
	if ((x > rt->ui.noise_voronoi->x && x < (rt->ui.noise_voronoi->x + rt->ui.noise_voronoi->w))
&& (y > rt->ui.noise_voronoi->y && y < (rt->ui.noise_voronoi->y + rt->ui.noise_voronoi->h)))
	{
		if (rt->ui.noise_voronoi->hovered == 0)
		{
			rt->ui.noise_voronoi->hovered = 1;
		update_ui_element(rt, &rt->ui.noise_voronoi,
"./assets/interface/noise-voronoi-hovered.png");
		}
	}
	else
	{
		if (rt->ui.noise_voronoi->hovered == 1)
		{
			rt->ui.noise_voronoi->hovered = 0;
		update_ui_element(rt, &rt->ui.noise_voronoi,
"./assets/interface/noise-voronoi-normal.png");
		}
	}
}

void	hover_perlin(t_rt *rt, int x, int y)
{
	if ((x > rt->ui.noise_perlin->x && x < (rt->ui.noise_perlin->x + rt->ui.noise_perlin->w))
&& (y > rt->ui.noise_perlin->y && y < (rt->ui.noise_perlin->y + rt->ui.noise_perlin->h)))
	{
		if (rt->ui.noise_perlin->hovered == 0)
		{
			rt->ui.noise_perlin->hovered = 1;
		update_ui_element(rt, &rt->ui.noise_perlin,
"./assets/interface/noise-perlin-hovered.png");
		}
	}
	else
	{
		if (rt->ui.noise_perlin->hovered == 1)
		{
			rt->ui.noise_perlin->hovered = 0;
		update_ui_element(rt, &rt->ui.noise_perlin,
"./assets/interface/noise-perlin-normal.png");
		}
	}
}

void	hover_damier(t_rt *rt, int x, int y)
{
	if ((x > rt->ui.noise_damier->x && x < (rt->ui.noise_damier->x + rt->ui.noise_damier->w))
&& (y > rt->ui.noise_damier->y && y < (rt->ui.noise_damier->y + rt->ui.noise_damier->h)))
	{
		if (rt->ui.noise_damier->hovered == 0)
		{
			rt->ui.noise_damier->hovered = 1;
		update_ui_element(rt, &rt->ui.noise_damier,
"./assets/interface/noise-damier-hovered.png");
		}
	}
	else
	{
		if (rt->ui.noise_damier->hovered == 1)
		{
			rt->ui.noise_damier->hovered = 0;
		update_ui_element(rt, &rt->ui.noise_damier,
"./assets/interface/noise-damier-normal.png");
		}
	}
}

void	hover_remove(t_rt *rt, int x, int y)
{
	if ((x > rt->ui.remove->x && x < (rt->ui.remove->x + rt->ui.remove->w))
&& (y > rt->ui.remove->y && y < (rt->ui.remove->y + rt->ui.remove->h)))
	{
		if (rt->ui.remove->hovered == 0)
		{
			rt->ui.remove->hovered = 1;
		update_ui_element(rt, &rt->ui.remove,
"./assets/interface/button-remove-hovered.png");
		}
	}
	else
	{
		if (rt->ui.remove->hovered == 1)
		{
			rt->ui.remove->hovered = 0;
		update_ui_element(rt, &rt->ui.remove,
"./assets/interface/button-remove-normal.png");
		}
	}
}

void	hover(t_rt *rt, int x, int y)
{
	hover_add_sphere(rt, x, y);
	hover_add_cylinder(rt, x, y);
	hover_add_cone(rt, x, y);
	hover_add_plane(rt, x, y);
	hover_none(rt, x, y);
	hover_voronoi(rt, x, y);
	hover_perlin(rt, x, y);
	hover_damier(rt, x, y);
	if (rt->selected)
		hover_remove(rt, x, y);
}