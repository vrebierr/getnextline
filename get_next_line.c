/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrebierr <vrebierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 08:01:49 by vrebierr          #+#    #+#             */
/*   Updated: 2015/09/17 08:01:52 by vrebierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list		*ft_lstinit(void)
{
	t_list *result;

	result = (t_list *)malloc(sizeof(t_list));
	if (result)
	{
		result->first = NULL;
		result->last = NULL;
		result->len = 0;
		result->end = -1;
	}
	return (result);
}

void		ft_lstaddbuff(t_list *list, char *buff)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	if (tmp)
	{
		tmp->next = NULL;
		ft_strcpy(tmp->buff_content, buff);
		list->end = ft_strchr(tmp->buff_content, '\n') - tmp->buff_content;
		if (list->last)
		{
			tmp->prev = list->last;
			list->last->next = tmp;
			list->last = tmp;
		}
		else
		{
			tmp->prev = NULL;
			list->first = tmp;
			list->last = tmp;
		}
		list->len++;
	}
	ft_bzero(buff, BUFF_SIZE + 1);
}

void		ft_lstclear(t_list **list)
{
	t_node	*tmp;

	tmp = (*list)->first;
	while (tmp->next)
	{
		tmp = tmp->next;
		free(tmp->prev);
		tmp->prev = NULL;
	}
	(*list)->first = tmp;
	(*list)->len = 1;
	if ((*list)->end >= 0 && (*list)->end <= BUFF_SIZE)
		ft_strcpy(tmp->buff_content, tmp->buff_content + (*list)->end + 1);
	(*list)->end = ft_strchr(tmp->buff_content, '\n') - tmp->buff_content;
	if (ft_strlen(tmp->buff_content) == 0)
	{
		free((*list)->last);
		free(*list);
		*list = NULL;
	}
}

char		*ft_getline(t_list **list)
{
	char		*result;
	t_node		*tmp;
	int			i;

	result = (char *)malloc(sizeof(char) * (BUFF_SIZE * (*list)->len + 1));
	ft_bzero(result, BUFF_SIZE * (*list)->len + 1);
	tmp = (*list)->first;
	i = 0;
	while (tmp)
	{
		if (tmp->next)
			ft_strcat(result, tmp->buff_content);
		else
			result = ft_strncat(result, tmp->buff_content, (*list)->end);
		tmp = tmp->next;
		i++;
	}
	ft_lstclear(list);
	return (result);
}

int			get_next_line(int const fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	t_list static	*list = NULL;

	if (!line || !*line || fd < 0)
		return (-1);
	ft_bzero(buff, BUFF_SIZE + 1);
	(list == NULL) ? list = ft_lstinit() : NULL;
	if (list->end >= 0 && list->end <= BUFF_SIZE)
		EXEC(line, list);
	while (read(fd, &buff, BUFF_SIZE))
	{
		ft_lstaddbuff(list, buff);
		if (list->end >= 0 && list->end <= BUFF_SIZE)
			EXEC(line, list);
	}
	if (list->len > 0)
	{
		*line = ft_getline(&list);
		list = NULL;
	}
	return (0);
}
