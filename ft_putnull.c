/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_null_to_struct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaiyan <tsaiyan@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 19:16:43 by tsaiyan           #+#    #+#             */
/*   Updated: 2020/12/03 19:16:45 by tsaiyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnull(t_struct *box)
{
	box->wight = 0;
	box->align = 0;
	box->znak = 0;
	box->zero = 0;
	box->accuracy = 0;
	box->retlen = 0;
	box->point = 0;
}
