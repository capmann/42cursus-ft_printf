/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarteau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:34:25 by cmarteau          #+#    #+#             */
/*   Updated: 2020/07/04 01:06:22 by cmarteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFTPRINTF_H
# define FT_LIBFTPRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

# define HEXAUP "0123456789ABCDEF"
# define HEXA "0123456789abcdef"

typedef struct		s_argu
{
	int				i;
	char			c;
	char			*s;
	unsigned int	u;
	unsigned long	l;
	void			*p;
}					t_argu;

int					ft_strlen(char *s);
int					ft_nblen(long n);
int					ft_nblen_u(unsigned int n);
int					ft_nblen_xx(unsigned long n, char c);
int					ft_putchar(char c, int i);
int					ft_putstr(char *s, int d);
int					ft_putnbr(long n);
int					ft_putnbr_u(unsigned int n);
int					ft_putnbr_xx(unsigned long n, char c);
int					ft_itoahex(unsigned long n, char a);
char				*ft_substr(const char *s, int start, size_t len);
int					ft_atoi(char *str);
int					ft_atoi_plus(char *str, int i);
int					ft_search(char *str, char c);
int					ft_checkflags_strunc(char *str, t_argu arg);
int					ft_flags_parsing(char *flags);
int					ft_printf(const char *format, ...);
char				*ft_star(char *flags, int star);
char				*ft_strcpy(char *str);
char				*ft_check_star(char *flags2, char *flags3);
char				*ft_strcat(char	*src, char *dst);
int					ft_convert_s(t_argu arg, char c, char *flags, int sc);
int					ft_convert_i(t_argu arg, char *flags, int sc);
int					ft_convert_u(t_argu arg, char *flags, int sc);
int					ft_convert_x(t_argu arg, char c, char *flags, int sc);
int					ft_flags_i(char *str, t_argu arg, int sc);
int					ft_flags_u(char *str, t_argu arg, int sc);
int					ft_flags_p(char *str, t_argu arg, int sc);
int					ft_flags_xx(char *str, t_argu arg, int sc);
int					ft_flags_s(char *str, t_argu arg, int sc, char c);
int					ft_rightflags_i(char *str, t_argu arg, int sc);
int					ft_rightflags_u(char *str, t_argu arg, int sc);
int					ft_rightflags_xx(char *str, t_argu arg, char c, int sc);
int					ft_rightflags_s(char *str, t_argu arg, int sc, char c);
int					ft_test2(char format);
char				*ft_flagsait(va_list *ap, char *flags);
int					ft_test(char format, char *flags);
int					ft_format(char format, t_argu arg, char *flags, int sc);
t_argu				ft_function(va_list *ap, char format);
int					ft_yo(char *flags);
int					ft_zero(char *flags);
int					ft_minus(char *flags);
int					ft_width(char *flags);
int					ft_preci(char *flags);
int					ft_count(const char *format, int i, va_list *ap);
int					ft_ion(const char *format, int i);
void				ft_init(t_argu *arg);

#endif
