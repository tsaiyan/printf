/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaiyan <tsaiyan@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:48:29 by tsaiyan           #+#    #+#             */
/*   Updated: 2020/12/03 17:48:36 by tsaiyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_align(long n, t_struct *box)
{
	if (box->znak)
	{
		ft_putchar(box->znak, box);
		box->new_wight--;
	}
	while (box->new_precision-- > 0)
		ft_putchar(48, box);
	(!n && !box->precision && box->point) ? box->retlen-- : ft_putnbr(n);
	box->new_wight += ((box->znak) ? 1 : 0);
	while (box->new_wight-- > 0)
		ft_putchar(32, box);
}

static void	ft_zero(long n, t_struct *box)
{
	if (box->precision >= 0)
	{
		while (box->new_wight-- > 0)
			ft_putchar(32, box);
		if (box->znak)
			ft_putchar(box->znak, box);
	}
	else
	{
		if (box->znak)
			ft_putchar(box->znak, box);
		while (box->new_wight-- > 0)
			ft_putchar(48, box);
	}
	while (box->new_precision-- > 0)
		ft_putchar(48, box);
	(!box->precision && !n) ? box->retlen-- : ft_putnbr((int)n);
}

static void	ft_else(long n, t_struct *box)
{
	while (box->new_wight-- > 0)
		ft_putchar(32, box);
	if (box->znak)
		ft_putchar(box->znak, box);
	while (box->new_precision-- > 0)
		ft_putchar(48, box);
	(!n && !box->precision && box->point) ? box->retlen-- : ft_putnbr(n);
}

void		display_int(t_struct *box)
{
	long n;

	n = va_arg(box->ap, int);
	if (n < 0 && (box->znak = '-'))
		n *= -1;
	box->new_precision = (int)(box->precision - ft_rank_count(n, 10));
	box->new_wight = box->wight - ((box->new_precision > 0) ? \
	box->new_precision : 0) - (int)ft_rank_count(n, 10) - ((box->znak) ? 1 : 0);
	(!n && !box->precision && box->point) ? box->new_wight++ : 0;
	if (box->align)
		ft_align(n, box);
	else
	{
		if (box->zero)
			ft_zero(n, box);
		else
			ft_else(n, box);
	}
	box->retlen += ft_rank_count(n, 10);
	ft_putnull(box);
}
