/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_ui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <mderri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 01:58:49 by mderri            #+#    #+#             */
/*   Updated: 2020/10/19 07:00:38 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	write_selected(t_rt *rt)
{
	int	type;

	type = rt->selected->type;
	if (type == tplane)
		mlx_string_put(rt->mlx.ptr, rt->mlx.win, 335, 60, 0xffffff, "Plane");
	else if (type == tsphere)
		mlx_string_put(rt->mlx.ptr, rt->mlx.win, 335, 60, 0xffffff, "Sphere");
	else if (type == tcylinder)
		mlx_string_put(rt->mlx.ptr, rt->mlx.win, 335, 60, 0xffffff, "Cylinder");
	else if (type == tcone)
		mlx_string_put(rt->mlx.ptr, rt->mlx.win, 335, 60, 0xffffff, "Cone");
	else if (type == ttorus)
		mlx_string_put(rt->mlx.ptr, rt->mlx.win, 335, 60, 0xffffff, "Torus");
	else if (type == tparaboloid)
		mlx_string_put(rt->mlx.ptr, rt->mlx.win, 335, 60, 0xffffff, "Paraboloid");
	else if (type == tellipsoid)
		mlx_string_put(rt->mlx.ptr, rt->mlx.win, 335, 60, 0xffffff, "Ellipsoid");
	else if (type == thyperboloid)
		mlx_string_put(rt->mlx.ptr, rt->mlx.win, 335, 60, 0xffffff, "Hyperboloid");
	else if (type == tcubet)
		mlx_string_put(rt->mlx.ptr, rt->mlx.win, 335, 60, 0xffffff, "Cube troué");
	else if (type == tmoebius)
		mlx_string_put(rt->mlx.ptr, rt->mlx.win, 335, 60, 0xffffff, "Moebius");
	else if (type == tdingdong)
		mlx_string_put(rt->mlx.ptr, rt->mlx.win, 335, 60, 0xffffff, "Dingdong");
	else if (type == tgoursat)
		mlx_string_put(rt->mlx.ptr, rt->mlx.win, 335, 60, 0xffffff, "Goursat");
	else if (type == tteardrop)
		mlx_string_put(rt->mlx.ptr, rt->mlx.win, 335, 60, 0xffffff, "Teardrop");
}

static void	put_images(t_rt *rt)
{
	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.toolbar_top->ptr,
rt->ui.toolbar_top->x, rt->ui.toolbar_top->y);
	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.toolbar_left->ptr,
rt->ui.toolbar_left->x, rt->ui.toolbar_left->y);
	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.tab_bar->ptr,
rt->ui.tab_bar->x, rt->ui.tab_bar->y);
	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.tab->ptr,
rt->ui.tab->x, rt->ui.tab->y);
	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.logo_small->ptr,
rt->ui.logo_small->x, rt->ui.logo_small->y);
// 	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.logo_large->ptr,
// rt->ui.logo_large->x, rt->ui.logo_large->y);
	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.add_sphere->ptr,
rt->ui.add_sphere->x, rt->ui.add_sphere->y);
	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.add_cylinder->ptr,
rt->ui.add_cylinder->x, rt->ui.add_cylinder->y);
	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.add_cone->ptr,
rt->ui.add_cone->x, rt->ui.add_cone->y);
	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.add_plane->ptr,
rt->ui.add_plane->x, rt->ui.add_plane->y);
	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.selected->ptr,
rt->ui.selected->x, rt->ui.selected->y);
	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.none->ptr,
rt->ui.none->x, rt->ui.none->y);
	// mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.texture1->ptr,
// rt->ui.texture1->x, rt->ui.texture1->y);
// 	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.texture2->ptr,
// rt->ui.texture2->x, rt->ui.texture2->y);
// 	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.texture3->ptr,
// rt->ui.texture3->x, rt->ui.texture3->y);
	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.noise_voronoi->ptr,
rt->ui.noise_voronoi->x, rt->ui.noise_voronoi->y);
	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.noise_perlin->ptr,
rt->ui.noise_perlin->x, rt->ui.noise_perlin->y);
	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.noise_damier->ptr,
rt->ui.noise_damier->x, rt->ui.noise_damier->y);
// 	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.aa_half->ptr,
// rt->ui.aa_half->x, rt->ui.aa_half->y);
// 	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.aa_one->ptr,
// rt->ui.aa_one->x, rt->ui.aa_one->y);
// 	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.aa_two->ptr,
// rt->ui.aa_two->x, rt->ui.aa_two->y);
	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.close->ptr,
rt->ui.close->x, rt->ui.close->y);
	if (rt->selected)
		mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->ui.remove->ptr,
rt->ui.remove->x, rt->ui.remove->y);
}

void	update_ui(t_rt *rt)
{
	// if (rt->selected)
		
	put_images(rt);
	mlx_put_image_to_window(rt->mlx.ptr, rt->mlx.win, rt->mlx.d.img_ptr, 126, 190);
	mlx_string_put(rt->mlx.ptr, rt->mlx.win, 140, 156, 0xffffff,
ft_strjoin(rt->name, ft_strjoin(" @ ", ft_strjoin(ft_itoa((int)(rt->res * 100)), "%"))));
	if (rt->selected)
		write_selected(rt);
}