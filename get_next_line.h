/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrebierr <vrebierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 08:01:37 by vrebierr          #+#    #+#             */
/*   Updated: 2015/09/17 08:01:40 by vrebierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 42
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# define EXEC(line, list) ({*line = ft_getline(&list); return (1);})

typedef struct		s_node
{
	char			buff_content[BUFF_SIZE + 1];
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct		s_dlist
{
	int				len;
	long int		end;
	struct s_node	*first;
	struct s_node	*last;
}					t_dlist;

int					get_next_line(int const fd, char **line);

#endif
