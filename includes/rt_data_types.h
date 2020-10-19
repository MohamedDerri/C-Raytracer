/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_data_types.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 14:16:13 by slaanani          #+#    #+#             */
/*   Updated: 2020/03/18 14:16:13 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DATA_TYPES_H
# define RT_DATA_TYPES_H

typedef struct	s_vecteur
{
	long double	x;
	long double	y;
	long double	z;
}				t_vecteur;

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct		s_repere
{
	t_vecteur		i;
	t_vecteur		j;
	t_vecteur		k;
}					t_repere;

typedef struct		s_coor
{
	int		x;
	int		y;
	int		w;
	int		h;
}					t_coor;

#endif