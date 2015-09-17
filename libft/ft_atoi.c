/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrebierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 20:38:42 by vrebierr          #+#    #+#             */
/*   Updated: 2015/03/17 20:38:44 by vrebierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

char	*ft_trimwhitespace(const char *s)
{
	while (*s == ' '
		|| *s == '\r'
		|| *s == '\n'
		|| *s == '\v'
		|| *s == '\t'
		|| *s == '\f')
		s++;
	return ((char *)s);
}

int		ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	str = ft_trimwhitespace(str);
	if (str[i] == '+' || str[i] == '-')
	{
		sign = (str[i] == '-') ? -1 : 1;
		i++;
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (result * sign);
		result = (str[i] - 48) + result * 10;
		i++;
	}
	return (result * sign);
}
