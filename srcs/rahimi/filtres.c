/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filtres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 20:50:25 by erahimi           #+#    #+#             */
/*   Updated: 2020/10/14 14:23:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void   filtre(t_rt *rt)
{
    if (rt->cam.f == filter_mb)
        ft_filter_mb(rt->mlx.d.pic_str);
    if(rt->cam.f == filter_sepia)
        sepia_filtre(rt->mlx.d.pic_str);
}
