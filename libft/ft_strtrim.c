/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrebierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 20:54:33 by vrebierr          #+#    #+#             */
/*   Updated: 2015/03/17 20:54:34 by vrebierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	size_t			len;
	char			*res;
	unsigned int	i;

	i = 0;
	while (ft_isspace(s[i]))
		i++;
	res = ft_strsub(s, i, ft_strlen(s));
	len = ft_strlen(res) - 1;
	while (ft_isspace(res[len]))
		len--;
	res = ft_strsub(res, 0, len + 1);
	return (res);
}
