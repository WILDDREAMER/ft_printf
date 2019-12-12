/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:10:55 by ozakkare          #+#    #+#             */
/*   Updated: 2019/12/01 12:10:22 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_substr(char const *s, int start, int len)
{
	char	*p;
	int		i;
	int		starts;

	if (!s)
		return (NULL);
	if (s[0] == '\0' || start > ft_strlen(s))
	{
		if (!(p = malloc(1 * sizeof(char))))
			return (0);
		p[0] = '\0';
		return (p);
	}
	if (!(p = malloc((len + 1) * sizeof(char))))
		return (0);
	i = 0;
	starts = start;
	while (start < len + starts && s[start])
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}

char		*editstr(char *s1, int s, char s2, int l)
{
	char	*p;
	int		i;
	int		j;
	int		len;

	len = (int)ft_strlen(s1);
	if (s1 == NULL)
		return (ft_strdup(&s2));
	if (!(p = malloc((ft_strlen(s1) + l) * sizeof(char))))
		return (0);
	i = -1;
	j = s;
	while (++i < s)
		p[i] = s1[i];
	l += i;
	while (i < l)
		p[i++] = s2;
	while (j < len)
		p[i++] = s1[j++];
	p[i] = '\0';
	return (p);
}

char		*addchar(char *s1, char s2)
{
	char	*p;
	int		i;

	if (s1 == NULL)
		return (ft_strdup(&s2));
	if (!(p = malloc((ft_strlen(s1) + 2) * sizeof(char))))
		return (0);
	i = -1;
	while (++i < (int)ft_strlen(s1))
		p[i] = s1[i];
	p[i++] = s2;
	p[i] = '\0';
	return (p);
}

void		ft_putstr(char *s)
{
	if (s != 0)
		while (*s)
			write(1, s++, 1);
}

int			ft_putchar(char s, int l)
{
	int r;

	r = l;
	while (l--)
		write(1, &s, 1);
	return (r);
}
