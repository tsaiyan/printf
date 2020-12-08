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

void	display_unsigned(t_struct *box)
{
	unsigned n;
	int accuracy;
	int wight;

	n = va_arg(box->argument_pointer, int);
/* меняет знак, если n < 0 */
	accuracy = (int)(box->accuracy - ft_rank_count(n, 10));
	wight = box->wight - ((accuracy > 0) ? accuracy : 0) - (int)ft_rank_count(n, 10)\
															- ((box->znak) ? 1 : 0);
	(!n && !box->accuracy && box->point)? wight++ : 0;
/* если есть выравнивание */
	if (box->align)
	{
		if (box->znak)
		{
			ft_putchar(box->znak, box);
			wight--;
		}
		while (accuracy-- > 0)
			ft_putchar(48, box);
		(!n && !box->accuracy && box->point)? box->retlen-- : ft_putnbr(n);
		wight += ((box->znak) ? 1 : 0);
		while (wight-- > 0)
			ft_putchar(32, box);
	}
/* если нет выравнивания */
	else
	{
		/* если есть zero */
		if (box->zero)
		{
			if (box->accuracy)
			{
				while (wight-- > 0)
					ft_putchar(32, box);
				if (box->znak)
				ft_putchar(box->znak, box);
			}
			else
			{
				if (box->znak)
					ft_putchar(box->znak, box);
				while (wight-- > 0)
					ft_putchar(48, box);
			}
			while (accuracy-- > 0)
				ft_putchar(48, box);
			ft_putnbr((int)n);
		}
		/* если нет zero */
		else
		{
			while (wight-- > 0)
				ft_putchar(32, box);
			/* есть есть знак */
			if (box->znak)
				ft_putchar(box->znak, box);
			while (accuracy-- > 0)
				ft_putchar(48, box);
			(!n && !box->accuracy && box->point)? box->retlen-- : ft_putnbr(n);
		}
	}
	ft_putnull(box);
	box->retlen += ft_rank_count(n, 10);
}