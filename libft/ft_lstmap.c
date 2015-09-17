/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrebierr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 20:45:33 by vrebierr          #+#    #+#             */
/*   Updated: 2015/03/17 20:58:00 by vrebierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*tmp;

	tmp = lst;
	res = f(tmp);
	while (tmp->next != NULL)
	{
		res->next = f(tmp->next);
		tmp = tmp->next;
	}
	return (res);
}
