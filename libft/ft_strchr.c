/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrebierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 20:50:08 by vrebierr          #+#    #+#             */
/*   Updated: 2015/03/17 20:59:46 by vrebierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*tmp_s;
	unsigned char	tmp_c;

	i = 0;
	tmp_s = (unsigned char *)s;
	tmp_c = (unsigned char)c;
	while (tmp_s[i])
	{
		if (tmp_s[i] == tmp_c)
			return ((char *)&tmp_s[i]);
		i++;
	}
	if (c == 0)
		return ((char *)&tmp_s[i]);
	return (NULL);
}
