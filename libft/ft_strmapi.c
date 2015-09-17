/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrebierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 20:52:22 by vrebierr          #+#    #+#             */
/*   Updated: 2015/03/17 20:52:23 by vrebierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	res = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	i = 0;
	if (res != NULL)
	{
		while (s[i])
		{
			res[i] = f(i, s[i]);
			i++;
		}
	}
	res[i] = 0;
	return (res);
}
