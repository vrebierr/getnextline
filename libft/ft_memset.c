/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrebierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 20:59:23 by vrebierr          #+#    #+#             */
/*   Updated: 2015/03/17 20:59:23 by vrebierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	tmp;
	unsigned char	*s;

	tmp = c;
	i = 0;
	s = b;
	while (i < len)
	{
		s[i] = tmp;
		i++;
	}
	return (b);
}
