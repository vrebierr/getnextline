/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrebierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 20:54:02 by vrebierr          #+#    #+#             */
/*   Updated: 2015/03/17 21:00:52 by vrebierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_splitmalloc(char const *s, char c)
{
	unsigned int	i;
	int				cpt;
	char			**res;

	i = 0;
	cpt = 0;
	while (s[i])
	{
		if (s[i] == c)
			cpt++;
		i++;
	}
	res = (char **)malloc((sizeof(char *) * (cpt + 1)));
	return (res);
}

void	ft_init(int *i, int *x)
{
	*i = 0;
	*x = 0;
}

char	**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		x;
	size_t	len;

	ft_init(&i, &x);
	res = ft_splitmalloc(s, c);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == 0)
			break ;
		len = 0;
		while (s[i + len] != c && s[i + len] != 0)
			len++;
		res[x] = ft_strsub(s, i, len);
		x++;
		i += len;
	}
	res[x] = 0;
	return (res);
}
