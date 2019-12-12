/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cconversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:21:50 by ozakkare          #+#    #+#             */
/*   Updated: 2019/11/22 02:22:30 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	arggg(t_arg *arg, t_flag *flag)
{
	arg->m = "%";
	arg->c = (char)flag->arg;
	if (flag->conv == *arg->m)
		arg->c = '%';
	if (flag->conv == *arg->m && flag->zero)
		arg->chartoprint = '0';
	else
		arg->chartoprint = ' ';
	arg->b = 0;
}

int		c(t_flag *flag)
{
	t_arg	*arg;

	arg = malloc(1 * sizeof(t_arg));
	arggg(arg, flag);
	if ((arg->wdt = ft_atoi(flag->width)) < 0)
		arg->wdt *= -1;
	if (arg->wdt > 1)
	{
		if (!(flag->minus))
			arg->b += ft_putchar(arg->chartoprint, (arg->wdt - 1));
		arg->b += ft_putchar(arg->c, 1);
		if (flag->minus || arg->wdt < 0)
			arg->b += ft_putchar(arg->chartoprint, (arg->wdt - 1));
	}
	else
		arg->b += ft_putchar(arg->c, 1);
	return (arg->b);
}
