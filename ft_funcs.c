/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 18:46:13 by ozakkare          #+#    #+#             */
/*   Updated: 2019/12/01 12:04:07 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		argscount(char *desc)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (desc[i])
	{
		if (desc[i] == '%' && desc[i + 1] != '%' && desc[i + 1])
			count++;
		i++;
	}
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char*)s);
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char*)s);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lens1;
	int		lens2;
	char	*p;
	int		i;
	int		j;

	if (s2 == 0)
		return (0);
	if (s1 == NULL)
		return (ft_strdup(s2));
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!(p = malloc((lens1 + lens2 + 1) * sizeof(char))))
		return (0);
	i = -1;
	while (++i < lens1)
		p[i] = s1[i];
	j = 0;
	while (i < (lens1 + lens2))
		p[i++] = s2[j++];
	p[i] = '\0';
	return (p);
}

int		ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s;
	int		len;
	int		i;

	len = 0;
	while (s1[len])
		len++;
	len++;
	s = malloc(len * sizeof(char));
	if (s == 0)
		return (0);
	i = -1;
	while (s1[++i])
		s[i] = s1[i];
	s[i] = '\0';
	return (s);
}
