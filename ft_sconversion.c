/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sconversion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:17:59 by ozakkare          #+#    #+#             */
/*   Updated: 2019/11/22 03:26:09 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	s(t_flag *flag)
{
	char	*string;
	int		wdt;
	int		b;

	b = 0;
	string = (char*)flag->arg;
	if ((wdt = ft_atoi(flag->width)) < 0)
		wdt *= -1;
	if (flag->prec)
		string = ft_substr(string, 0, ft_atoi(flag->prec));
	if ((flag->width == NULL && flag->prec == NULL)
			|| wdt < ft_strlen(string))
		ft_putstr(string);
	else if (flag->width)
	{
		if (wdt >= (int)ft_strlen(string))
		{
			if (!(flag->minus))
				b += ft_putchar(' ', (wdt - ft_strlen(string)));
			ft_putstr(string);
			if (flag->minus || wdt < 0)
				b += ft_putchar(' ', (wdt - ft_strlen(string)));
		}
	}
	return (b + ft_strlen(string));
}
