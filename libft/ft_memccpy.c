/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrebierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 20:46:58 by vrebierr          #+#    #+#             */
/*   Updated: 2015/03/17 21:20:15 by vrebierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;
	unsigned char	tmp_c;
	size_t			i;

	tmp_src = (unsigned char *)src;
	tmp_dst = (unsigned char *)dst;
	tmp_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		tmp_dst[i] = tmp_src[i];
		if (tmp_dst[i] == tmp_c)
			return (&((char *)dst)[i + 1]);
		i++;
	}
	return (NULL);
}
