/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:13:23 by ozakkare          #+#    #+#             */
/*   Updated: 2019/12/09 21:01:24 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fillwidth(const char *format, int *i, va_list lst, t_flag *flag)
{
	int		x;
	char	*width;

	x = -1;
	width = NULL;
	if (format[*i] == '*')
	{
		*i += 1;
		width = ft_itoa(va_arg(lst, int));
		if (ft_atoi(width) < 0)
			flag->minus = 1;
		return (width);
	}
	while (ft_isdigit(format[*i]) && format[*i])
	{
		width = addchar(width, format[*i]);
		*i += 1;
	}
	if (ft_atoi(width) < 0)
		flag->minus = 1;
	return (width);
}

char	*fillprec(const char *format, int *i, va_list lst, t_flag *flag)
{
	char	*prec;

	prec = NULL;
	if (format[*i] == '.')
	{
		flag->ford = 1;
		*i += 1;
		if (format[*i] == '*')
		{
			*i += 1;
			prec = ft_itoa(va_arg(lst, int));
			if (ft_atoi(prec) < 0)
				return ((flag->salib = 1) == 1) ? NULL : NULL;
			return (prec);
		}
		prec = "0";
		while (ft_isdigit(format[*i]))
		{
			prec = addchar(prec, format[*i]);
			*i += 1;
		}
	}
	return (prec);
}

int		fillzero(const char *format, int *i)
{
	int zero;

	zero = 0;
	if (format[*i] == '0')
	{
		*i += 1;
		zero = 1;
	}
	return (zero);
}

int		fillminus(const char *format, int *i)
{
	int minus;

	minus = 0;
	while (format[*i] == '-')
	{
		*i += 1;
		minus = 1;
	}
	return (minus);
}

char	fillconv(const char *format, int *i)
{
	char conv;

	conv = 0;
	if (ft_strchr("cspdiuxX%", format[*i]))
	{
		conv = format[*i];
		*i += 1;
	}
	return (conv);
}
