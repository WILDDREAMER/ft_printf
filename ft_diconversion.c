/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diconversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 08:37:13 by ozakkare          #+#    #+#             */
/*   Updated: 2019/12/10 10:53:26 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialiseargs(t_args *args, t_flag *flag)
{
	args->dcm = NULL;
	args->b = 0;
	args->n = 0;
	args->prec = ft_atoi(flag->prec);
	args->z = 0;
	args->forzero = 0;
	if ((ft_atoi(args->dcm = ft_itoa((int)flag->arg))) < 0)
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

void	cases(t_args *args, t_flag *flag)
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

int		di(t_flag *flag)
{
	t_args *args;

	args = malloc(sizeof(t_args));
	initialiseargs(args, flag);
	cases(args, flag);
	if (!flag->width && args->prec == 0 && *args->dcm == '0' && flag->ford == 1)
		return (0);
	if (flag->ford == 1 && args->prec == 0 && *args->dcm == '0')
		args->dcm = "";
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
