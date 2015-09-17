/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrebierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 20:52:16 by vrebierr          #+#    #+#             */
/*   Updated: 2015/03/17 20:52:17 by vrebierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	int		i;

	res = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	i = 0;
	if (res != NULL)
	{
		while (s[i])
		{
			res[i] = f(s[i]);
			i++;
		}
	}
	res[i] = 0;
	return (res);
}
