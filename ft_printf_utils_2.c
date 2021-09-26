/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarteau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:54:18 by cmarteau          #+#    #+#             */
/*   Updated: 2020/07/01 00:07:55 by cmarteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_atoi(char *str)
{
	unsigned int res;
	unsigned int i;
	unsigned int k;

	res = 0;
	i = 0;
	k = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == 45 && str[i + 1] != 43)
	{
		k = -1;
		i++;
	}
	if (str[i] == 43)
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	free(str);
	return (res * k);
}

int		ft_atoi_plus(char *str, int i)
{
	char	*res;
	int		d;

	d = 0;
	while (str[i] == '-' || str[i] == '0' || str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		i++;
		d++;
	}
	res = ft_substr(str, i - d, d);
	return (ft_atoi(res));
}

char	*ft_strcpy(char *str)
{
	char	*dest;
	int		i;

	i = 0;
	if (!(dest = malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (0);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = 0;
	free(str);
	return (dest);
}

char	*ft_strcat(char *src, char *dst)
{
	int		i;
	char	*cat;
	int		src_len;
	int		dst_len;

	i = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (!(cat = malloc(sizeof(char) * (src_len + dst_len + 1))))
		return (0);
	while (src[i])
	{
		cat[i] = src[i];
		i++;
	}
	i = 0;
	while (dst[i])
	{
		cat[src_len + i] = dst[i];
		i++;
	}
	cat[src_len + i] = '\0';
	free(src);
	free(dst);
	return (cat);
}
