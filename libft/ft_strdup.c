/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrebierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 20:51:14 by vrebierr          #+#    #+#             */
/*   Updated: 2015/03/17 20:51:14 by vrebierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1);
	result = (char *)malloc(sizeof(result) * (len + 1));
	if (result)
	{
		while (i < len)
		{
			result[i] = s1[i];
			i++;
		}
		result[i] = 0;
	}
	return (result);
}
