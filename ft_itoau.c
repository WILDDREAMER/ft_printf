/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoau.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:17:45 by ozakkare          #+#    #+#             */
/*   Updated: 2019/11/22 02:48:29 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long		negativeu(long long n)
{
	if (n < 0)
		return (1);
	return (0);
}

long long		convertu(long long n)
{
	if (negativeu(n))
		return (n * -1);
	return (n);
}

char			*fillu(int len, long long n, char *p, int count)
{
	int				i;
	long long		nb;
	int				zero;

	i = 0;
	nb = (long long)convertu(n);
	if (negativeu(n))
		p[i++] = '-';
	while (len--)
	{
		p[i++] = (char)((nb / count) + 48);
		if ((nb % count) != 0 || (count / 10) != 0)
		{
			nb %= count;
			count /= 10;
			if (((nb) / (count)) > nb)
				p[i] = '0';
		}
	}
	zero = 0;
	if (negativeu(n))
		zero++;
	p[i - zero] = '\0';
	return (p);
}

char			*ft_itoau(long long n)
{
	long long		nb;
	int				count;
	int				len;
	char			*p;

	nb = convertu(n);
	count = 1;
	len = 1 + negativeu(n);
	while (nb >= 10)
	{
		nb /= 10;
		count *= 10;
		len++;
	}
	if (!(p = malloc(len + 1 * sizeof(char))))
		return (0);
	return (fillu(len, n, p, count));
}

void			flagg(t_flag *flag, const char *format, int *i, va_list lst)
{
	char *m;

	m = "%";
	flag->minus = fillminus(format, i);
	flag->zero = fillzero(format, i);
	flag->width = fillwidth(format, i, lst, flag);
	flag->prec = fillprec(format, i, lst, flag);
	flag->conv = fillconv(format, i);
	if ((flag->conv) == '%')
		flag->arg = m;
	else
		flag->arg = va_arg(lst, void *);
	if (flag->conv == 's' && ft_atoi(flag->prec) < 0)
		flag->prec = NULL;
}
