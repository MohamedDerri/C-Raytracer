/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 04:31:46 by mderri            #+#    #+#             */
/*   Updated: 2020/10/15 20:25:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			distances(t_rt *r)
{
	if (((r->sol2 < r->sol1 || r->sol1 < MIN) && r->sol2 > MIN)
			&& (r->sol2 < r->dis))
	{
		r->dis = r->sol2;
		return (1);
	}
	else if (((r->sol1 < r->sol2 || r->sol2 < MIN) && r->sol1 > MIN)
			&& (r->sol1 < r->dis))
	{
		r->dis = r->sol1;
		return (1);
	}
	else
		return (0);
}

int			distances_tex(t_rt *r, t_obj *s)
{
	if (((r->sol2 < r->sol1 || r->sol1 < MIN) && r->sol2 > MIN)
			&& (r->sol2 < r->dis) )
	{
		if( getColorFromTexture(r, s, r->sol2))
		{
		r->dis = r->sol2;
		return (1);
		}
		else{

			 if( ( r->sol1 > MIN)
			&& (r->sol1 < r->dis) && getColorFromTexture(r, s, r->sol1))
			{
				r->dis = r->sol1;
				return (1);
			}
	
		}
		
	}
	else if (((r->sol1 < r->sol2 || r->sol2 < MIN) && r->sol1 > MIN)
			&& (r->sol1 < r->dis))
	{
			if( getColorFromTexture(r, s, r->sol1))
		{
		r->dis = r->sol1;
		return (1);
		}
		else{

			 if( ( r->sol2 > MIN)
			&& (r->sol2 < r->dis) && getColorFromTexture(r, s, r->sol2))
			{
				r->dis = r->sol2;
				return (1);
			}
	
		}
	}
		return (0);
}

int			distances2(t_rt *r, long double  c[5])
{
	long double	s[4];
	int			i;
	int			num;
	long double	min;

	i = -1;
	min = MAX;
	if ((num = ft_solve_quartic(c, s)))
	{
		while (++i < num)
		{
			// if (num == 4)
			//     printf(" %Lf ", s[i]);
			if (s[i] < min && s[i] > MIN)
				min = s[i];
		// }
		// if (num == 4)
		//     printf(" and min = %Lf\n", min);
		}
		if (min < r->dis && min > MIN)
		{
			r->dis = min;
			return (1);
		}
	}
	return (0);
}

int         distances3(t_rt *r, long double  c[4])
{
	long double s[3];
	int         i;
	int         num;
	long double  min;

	i = -1;
	min = MAX;
	if ((num = ft_solve_cubic(c, s)))
	{
		while (++i < num)
		{
			// if (num == 3)
				// printf(" %Lf ", s[i]);
			if (s[i] < min && s[i] > MIN)
				min = s[i];
		}
		// if (num == 3)
			// printf(" and min = %Lf\n", min);
		if (min < r->dis && min > MIN)
		{
			r->dis = min;
			return (1);
		}
	}
	return (0);
}

int         distances4(t_rt *r, long double  c[4], t_obj *m)
{
	long double s[3];
	int         i;
	int         num;
	long double  min;
	t_vecteur p;
	int x = 0;

	i = -1;
	min = MAX;
	if ((num = ft_solve_cubic(c, s)))
	{
		while (++i < num)
		{
			// if (num == 3)
				// printf(" %Lf ", s[i]);
			if (s[i] < min && s[i] > MIN)
			{
				min = s[i];
				r->dis = min;
				p = sum(kv(r->u, r->dis), r->cam.position);
				if (in_moebius(m, p))
					x = 1;
				// sum(kv(r->u, r->dis), r->cam.position)
			}
		}
		return (x == 1);
		// if (num == 3)
		//     printf(" and min = %Lf\n", min);
		// if (min < r->dis && min > MIN)
		// {
		//     r->dis = min;
		//     p = sum(kv(r->u, r->dis), r->cam.position);
		//     if (in_moebius(m, p))
		//         return (1);
		// }
	}
	return (0);
}