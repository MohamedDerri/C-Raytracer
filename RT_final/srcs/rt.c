/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderri <mderri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 23:59:02 by mderri            #+#    #+#             */
/*   Updated: 2020/10/19 16:48:26 by mderri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		basic_test(char *str)
{
	int i;

	i = ft_strlen(str);
	if (str[i - 1] == '.')
		return (0);
	return (1);
}

void	print_objs(t_obj *lst)
{
	int i = 0;

	while (lst)
	{
		printf ("OBJ N: %d\n", i);
		printf ("TYPE: %d\n", lst->type);
		printf ("POSITION: %.2Lf - %.2Lf - %.2Lf\n", lst->pos.x, lst->pos.y, lst->pos.z);
		printf ("COLOR: %d - %d - %d\n", lst->color.r, lst->color.g, lst->color.b);
		printf ("AXE: %.2Lf - %.2Lf - %.2Lf\n", lst->axe.x, lst->axe.y, lst->axe.z);
		printf("K: %.2Lf\n", lst->k);
		printf ("---------------------------\n");
		i++;
		lst = lst->next;
	}
}

void init_perlin(t_rt *rt)
{
	int i;

	if (!(rt->ran = (t_vecteur *)malloc(256 * sizeof(t_vecteur))))
		exit(0);
	i = 0;
	while (i < 256)
	{
		rt->ran[i].x = rand() % 255;
		rt->ran[i].y = rand() % 255;
		rt->ran[i].z = rand() % 255;
		rt->ran[i] = normalise(rt->ran[i]);
		i++;
	}
}

void	init_rt(t_rt *rt)
{
	rt->name = ft_strdup("RTv1 - slaanani & mderri");
	rt->xml = (t_xml_helper *)ft_memalloc(sizeof(t_xml_helper));
	rt->last_obj = NULL;
	rt->last_light = NULL;
	rt->obj_list = NULL;
	rt->light = NULL;
	rt->progress = 0;
	rt->last_progress = 0;
	rt->selected = NULL;
	rt->last_selected = NULL;
	rt->move_factor = 1;
	rt->mlx.w = RENDER_W;
	rt->mlx.h = RENDER_H;
	init_perlin(rt);
}

void	mlx_event_hook(t_rt *r)
{
	// mlx_key_hook(r->mlx.win, key_handle, r);
	mlx_do_key_autorepeaton(r->mlx.ptr);
	mlx_hook(r->mlx.win, 2, KeyPressMask, key_press_handle, r);
	mlx_hook(r->mlx.win, 6, 0, mouse_move, r);
	// mlx_hook(r->mlx.win, 3, KeyReleaseMask, key_release_handle, r);
	mlx_mouse_hook(r->mlx.win, mouse_handle, r);
	mlx_hook(r->mlx.win, 17, 1, ft_close, r);
}

int		main(int argc, char **argv)
{
	t_rt	r;

	if (argc != 2)
	{
		ft_putstr("Usage : ./rtv1 scene\n");
		exit(0);
	}
	init_rt(&r);
	xml_parse(argv[1], &r);
	create_camera(&r);
	r.head = r.obj_list;
	printf("%d\n", obj_lst_size(&r));
	r.mlx.ptr = mlx_init();
	r.mlx.win = mlx_new_window(r.mlx.ptr, WIDTH, HEIGHT, r.name);
	r.mlx.d.img_ptr = mlx_new_image(r.mlx.ptr, r.mlx.w, r.mlx.h);
	r.mlx.d.pic_str = (int *)mlx_get_data_addr(r.mlx.d.img_ptr, &r.mlx.d.bpp,
&r.mlx.d.s_l, &r.mlx.d.endian);
	raytracer(&r);
	ui(&r);
	mlx_event_hook(&r);
	mlx_loop(r.mlx.ptr);
	return (0);
}
