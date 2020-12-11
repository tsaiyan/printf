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

void	ft_putin(t_struct *box)
{
	box->wight = 0;
	box->align = 0;
	box->znak = 0;
	box->zero = 0;
	box->precision = -1;
	box->point = 0;
	box->ox = "0x";
	box->flag_int = 0;
}
