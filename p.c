/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:57:44 by ozakkare          #+#    #+#             */
/*   Updated: 2019/11/22 05:03:29 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		p(t_flag *flag)
{
	char	*adress;
	int		wdt;
	int		b;

	b = 0;
	adress = hexadecimal((unsigned long long)flag->arg, 'l');
	if ((wdt = ft_atoi(flag->width)) < 0)
		wdt *= -1;
	adress = editstr(adress, 0, '0', 1);
	adress = editstr(adress, 1, 'x', 1);
	flag->prec = NULL;
	if ((flag->width == NULL && flag->prec == NULL) || wdt < ft_strlen(adress))
		ft_putstr(adress);
	else if (flag->width)
	{
		if (wdt >= (int)ft_strlen(adress))
		{
			if (!(flag->minus))
				b += ft_putchar(' ', (wdt - ft_strlen(adress)));
			ft_putstr(adress);
			if (flag->minus || wdt < 0)
				b += ft_putchar(' ', (wdt - ft_strlen(adress)));
		}
	}
	return (b + ft_strlen(adress));
}
