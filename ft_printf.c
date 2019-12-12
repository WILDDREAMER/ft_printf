/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 03:02:06 by ozakkare          #+#    #+#             */
/*   Updated: 2019/12/11 15:12:40 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ignore(const char *format, int *i)
{
	int b;

	b = 0;
	if (format[*i] != '%' && format[*i])
	{
		b++;
		ft_putchar(format[*i], 1);
		*i += 1;
	}
	if (format[*i] == '%' && format[*i + 1] == '%')
	{
		b++;
		ft_putstr("%");
		*i += 2;
	}
	return (b);
}

void		initialise(t_flag *flag)
{
	flag->minus = 0;
	flag->zero = 0;
	flag->width = NULL;
	flag->prec = NULL;
	flag->conv = '\0';
	flag->arg = NULL;
	flag->ford = 0;
	flag->fors = 0;
	flag->salib = 0;
}

int			operations(t_flag *flag)
{
	int b;

	b = 0;
	if (flag->conv == 's')
		b += s(flag);
	if (flag->conv == 'u')
		b += u(flag);
	if (flag->conv == 'd' || flag->conv == 'i')
		b += di(flag);
	if (flag->conv == 'c' || flag->conv == '%')
		b += c(flag);
	if (flag->conv == 'x' || flag->conv == 'X')
		b += xix(flag);
	if (flag->conv == 'p')
		b += p(flag);
	return (b);
}

int			checkflags(const char *format, int *i, va_list lst)
{
	int		b;
	t_flag	*flag;

	b = 0;
	flag = malloc(1 * sizeof(t_flag));
	initialise(flag);
	if (format[*i] == '%')
	{
		*i += 1;
		while (!(flag->conv))
			flagg(flag, format, i, lst);
	}
	if (flag->arg == NULL && flag->conv == 's')
		flag->arg = "(null)";
	if ((flag->conv))
		b += operations(flag);
	free(flag);
	return (b);
}

int			ft_printf(const char *format, ...)
{
	int		i;
	int		b;
	va_list lst;

	va_start(lst, format);
	b = 0;
	i = 0;
	while (format[i])
	{
		b += ignore(format, &i);
		b += checkflags(format, &i, lst);
	}
	va_end(lst);
	return (b);
}
