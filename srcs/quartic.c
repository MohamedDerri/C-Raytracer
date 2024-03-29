/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quartic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 04:32:21 by mderri            #+#    #+#             */
/*   Updated: 2020/03/18 13:00:12 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	ft_case_one(long double coeffs[4], long double s[4], long double *q,
long double *p)
{
	int		num;

	coeffs[0] = *q;
	coeffs[1] = *p;
	coeffs[2] = 0.0;
	coeffs[3] = 1.0;
	num = ft_solve_cubic(coeffs, s);
	s[num++] = 0.0;
	return (num);
}

static int	ft_case_norm(t_quartic *q)
{
	if (IS_ZERO(q->u))
		q->u = 0;
	else if (q->u > 0.0f)
		q->u = sqrt(q->u);
	else
		return (0);
	if (IS_ZERO(q->v))
		q->v = 0.0;
	else if (q->v > 0.0f)
		q->v = sqrt(q->v);
	else
		return (0);
	return (1);
}

static int	ft_case_two(long double coeffs[4], long double s[4], t_quartic *q)
{
	int		num;

	coeffs[0] = 1.0 / 2.0 * q->r * q->p - 1.0 / 8.0 * q->q * q->q;
	coeffs[1] = -q->r;
	coeffs[2] = -1.0 / 2.0 * q->p;
	coeffs[3] = 1.0;
	(void)ft_solve_cubic(coeffs, s);
	q->z = s[0];
	q->u = q->z * q->z - q->r;
	q->v = 2.0 * q->z - q->p;
	if (!ft_case_norm(q))
		return (0);
	coeffs[0] = q->z - q->u;
	coeffs[1] = q->q < 0.0f ? -q->v : q->v;
	coeffs[2] = 1;
	num = ft_solve_quadric(coeffs, s);
	coeffs[0] = q->z + q->u;
	coeffs[1] = q->q < 0.0f ? q->v : -q->v;
	coeffs[2] = 1;
	num += ft_solve_quadric(coeffs, s + num);
	return (num);
}

int			ft_solve_quartic(long double w[5], long double s[4])
{
	long double		coeffs[4];
	t_quartic	q;
	int			i;
	int			num;

	q.a = w[3] / w[4];
	q.b = w[2] / w[4];
	q.c = w[1] / w[4];
	q.d = w[0] / w[4];
	q.sq_a = q.a * q.a;
	q.p = -3.0 / 8.0 * q.sq_a + q.b;
	q.q = 1.0 / 8.0 * q.sq_a * q.a - 1.0 / 2.0 * q.a * q.b + q.c;
	q.r = -3.0 / 256.0 * q.sq_a * q.sq_a + 1.0 / 16.0 * q.sq_a * q.b -
		1.0 / 4.0 * q.a * q.c + q.d;
	if (IS_ZERO(q.r))
		num = ft_case_one(coeffs, s, &q.q, &q.p);
	else
		num = ft_case_two(coeffs, s, &q);
	q.sub = 1.0 / 4.0 * q.a;
	i = -1;
	while (++i < num)
		s[i] -= q.sub;
	return (num);
}
