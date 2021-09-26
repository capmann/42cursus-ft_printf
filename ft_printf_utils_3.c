/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarteau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:54:18 by cmarteau          #+#    #+#             */
/*   Updated: 2020/06/30 23:50:01 by cmarteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_search(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}

char	*ft_startrek(int star)
{
	char	*two;
	int		yo;
	int		j;
	int		a;

	j = 0;
	yo = star;
	if (!(two = malloc(sizeof(char) * (ft_nblen(yo) + 1))))
		return (0);
	if (yo < 0)
	{
		two[0] = '-';
		yo = yo * (-1);
	}
	while (yo > 9)
	{
		two[ft_nblen(star) - j - 1] = yo % 10 + 48;
		yo /= 10;
		star /= 10;
		j++;
	}
	a = (star < 0) ? 1 : 0;
	two[a] = yo + 48;
	two[j + 1 + a] = '\0';
	return (two);
}

char	*ft_star(char *flags, int star)
{
	int		i;
	int		k;
	char	*one;
	char	*three;
	char	*four;

	i = 0;
	while (flags[i] != '*')
		i++;
	one = ft_substr(flags, 0, i);
	k = i + 1;
	while (flags[k])
		k++;
	four = ft_substr(flags, i + 1, k - 1);
	three = (i == 0) ? ft_strcpy(ft_startrek(star))
	: ft_strcat(one, ft_startrek(star));
	free(flags);
	if (i == 0)
		free(one);
	if (four[1])
		return (ft_strcat(three, four));
	free(four);
	return (three);
}

char	*ft_check_star(char *flags2, char *flags3)
{
	if (ft_search(flags2, '*') >= 0)
		return (flags3);
	else
		return (flags2);
}
