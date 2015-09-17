/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrebierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 20:43:44 by vrebierr          #+#    #+#             */
/*   Updated: 2015/03/17 20:43:45 by vrebierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_getlen(int n)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	else if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_atoi_str(int len, int n)
{
	int		i;
	char	*res;

	i = 0;
	res = ft_strnew(len);
	if (res != NULL)
	{
		if (n < 0)
		{
			res[i] = '-';
			i++;
			n *= -1;
		}
		while (i < len)
		{
			res[i] = n % 10 + 48;
			n /= 10;
			i++;
		}
		res[i] = 0;
	}
	return (res);
}

char	*ft_reverse(char *s)
{
	char	tmp;
	size_t	len;
	size_t	i;

	len = ft_strlen(s) - 1;
	i = 0;
	if (s[0] == '-')
		i++;
	while (i < len)
	{
		tmp = s[i];
		s[i] = s[len];
		s[len] = tmp;
		i++;
		len--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;

	if (n == -2147483648)
		return ("-2147483648");
	len = ft_getlen(n);
	res = ft_atoi_str(len, n);
	res = ft_reverse(res);
	return (res);
}
