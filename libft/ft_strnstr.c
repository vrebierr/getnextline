/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrebierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 20:53:37 by vrebierr          #+#    #+#             */
/*   Updated: 2015/03/17 20:53:38 by vrebierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	if (s2[0] == 0)
		return ((char *)s1);
	while (s1[i] && i < n)
	{
		if (s1[i] == s2[y])
		{
			y++;
			if (s2[y] == 0)
				return ((char *)&s1[i - y + 1]);
		}
		i++;
	}
	return (NULL);
}
