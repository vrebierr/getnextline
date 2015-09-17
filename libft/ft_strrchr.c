/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrebierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 20:53:53 by vrebierr          #+#    #+#             */
/*   Updated: 2015/03/17 20:53:53 by vrebierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	unsigned char	*tmp_s;
	unsigned char	tmp_c;

	i = ft_strlen(s) - 1;
	tmp_s = (unsigned char *)s;
	tmp_c = (unsigned char)c;
	if (c == 0)
		return ((char *)&tmp_s[i + 1]);
	while (tmp_s[i])
	{
		if (tmp_s[i] == tmp_c)
			return ((char *)&tmp_s[i]);
		i--;
	}
	return (NULL);
}
