/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 09:54:36 by ozakkare          #+#    #+#             */
/*   Updated: 2019/12/02 12:18:40 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		cover(unsigned int c, char f)
{
	if (c >= 10 && c <= 15 && f == 'u')
		return (65 + (c - 10));
	else if (c >= 10 && c <= 15 && f == 'l')
		return (97 + (c - 10));
	else
		return (c + 48);
}

char		*hexadecimal(unsigned long long hex, char f)
{
	char					*r;
	int						i;
	unsigned long long		x;

	i = 0;
	x = hex;
	while (hex /= 16)
		i++;
	r = malloc(i + 1);
	r[i + 1] = '\0';
	while (i >= 0)
	{
		r[i] = cover(x % 16, f);
		x /= 16;
		i--;
	}
	return (r);
}

void		xinitialiseargs(t_args *args, t_flag *flag)
{
	int f;

	if (flag->conv == 'X')
		f = 'u';
	else
		f = 'l';
	args->dcm = NULL;
	args->b = 0;
	args->n = 0;
	args->prec = ft_atoi(flag->prec);
	args->z = 0;
	args->forzero = 0;
	if ((ft_atoi(args->dcm = hexadecimal((unsigned int)flag->arg, f))) < 0)
	{
		args->n = 1;
		if (flag->zero && (ft_atoi(flag->width) > 0) && flag->prec)
			args->prec++;
	}
	if (ft_atoi(flag->width) > ft_strlen(args->dcm))
		args->zeros = ft_atoi(flag->width);
	else
		args->zeros = 0;
}

void		xcases(t_args *args, t_flag *flag)
{
	if ((args->wdt = ft_atoi(flag->width)) < 0)
	{
		args->wdt *= -1;
		flag->minus = 1;
		flag->zero = 0;
	}
	if (flag->zero && (args->prec > args->wdt))
		args->wdt = 0;
	else if (((flag->zero && (args->prec < args->wdt)) && !flag->ford)
	|| (flag->salib && flag->zero))
	{
		args->prec = args->wdt;
		args->wdt = args->wdt - ft_atoi(flag->prec);
		if (ft_atoi(flag->width) > ft_strlen(args->dcm) && flag->prec)
			args->forzero = args->wdt;
	}
	if (!flag->zero && args->n)
		args->z = 1;
}

int			xix(t_flag *flag)
{
	t_args *args;

	args = malloc(sizeof(t_args));
	xinitialiseargs(args, flag);
	xcases(args, flag);
	if (!flag->width && args->prec == 0 && *args->dcm == '0' && flag->ford == 1)
		return (0);
	if (flag->ford == 1 && args->prec == 0 && *args->dcm == '0')
		args->dcm = " ";
	if (args->prec)
		args->dcm = editstr(args->dcm, args->n, '0',
			(args->prec - (ft_strlen(args->dcm) - args->z) - args->forzero));
	if (flag->width && (args->wdt >= (int)ft_strlen(args->dcm)))
	{
		if (!(flag->minus))
			args->b += ft_putchar(' ', args->wdt - ft_strlen(args->dcm));
		ft_putstr(args->dcm);
		if (flag->minus || args->wdt < 0)
			args->b += ft_putchar(' ', args->wdt - ft_strlen(args->dcm));
	}
	if (((flag->width == NULL && flag->prec == NULL)
	|| args->wdt < ft_strlen(args->dcm)) && !args->forzero)
		ft_putstr(args->dcm);
	return (args->b + ft_strlen(args->dcm));
}
