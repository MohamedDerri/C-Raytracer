/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 13:51:09 by marvin            #+#    #+#             */
/*   Updated: 2020/10/14 13:51:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int r(int c)
{
    return ((c >> 16) & 0xFF);
}
int g(int c)
{
    return ((c >> 8) & 0xFF);
}
int b(int c)
{
    return (c & 0xFF);
}

int rgb_int(int r, int g, int b)
{
    return ((r << 16) | (g << 8) | b);
}

t_vecteur int_rgb(int c)
{
	return (create_v(r(c), g(c), b(c)));
}