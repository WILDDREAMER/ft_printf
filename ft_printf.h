/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozakkare <ozakkare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 21:00:02 by ozakkare          #+#    #+#             */
/*   Updated: 2019/12/02 10:04:17 by ozakkare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct	s_flag
{
	int			zero;
	int			minus;
	char		*width;
	char		*prec;
	char		conv;
	void		*arg;
	int			ford;
	int			salib;
	int			fors;
}				t_flag;

typedef	struct	s_args
{
	char		*dcm;
	int			wdt;
	int			b;
	int			n;
	int			prec;
	int			z;
	int			forzero;
	int			zeros;
}				t_args;

typedef	struct	s_arg
{
	char		c;
	int			wdt;
	int			b;
	char		*m;
	char		chartoprint;
}				t_arg;

int				ft_atoi(char *str);
long long		ft_atoiu(char *str);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
int				ft_strlen(const char *s);
int				ft_isdigit(int c);
void			ft_putstr(char *s);
char			*ft_substr(char const *s, int start, int len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_itoa(int n);
char			*ft_itoau(long long n);
char			*addchar(char *s1, char s2);
int				ft_putchar(char s, int l);
int				s(t_flag *flag);
int				u(t_flag *flag);
int				c(t_flag *flag);
int				xix(t_flag *flag);
int				di(t_flag *flag);
int				p(t_flag *flag);
char			*editstr(char *s1, int s, char s2, int l);
long long		convertu(long long n);
int				convert(int n);
char			*fill(int len, int n, char *p, int count);
int				whitespace(char c);
char			*fillwidth(const char *format, int *i,
va_list lst, t_flag *flag);
char			*fillprec(const char *format, int *i,
va_list lst, t_flag *flag);
int				fillzero(const char *format, int *i);
int				fillminus(const char *format, int *i);
char			fillconv(const char *format, int *i);
long long		negativeu(long long n);
char			*fillu(int len, long long n, char *p, int count);
int				ignore(const char *format, int *i);
void			initialise(t_flag *flag);
int				operations(t_flag *flag);
int				checkflags(const char *format, int *i, va_list lst);
int				ft_printf(const char *format, ...);
char			*hexadecimal(unsigned long long hex, char f);
void			flagg(t_flag *flag, const char *format,
int *i, va_list lst);

#endif
