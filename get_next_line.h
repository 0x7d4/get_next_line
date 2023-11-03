/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 23:05:40 by mmomeni           #+#    #+#             */
/*   Updated: 2023/07/20 12:37:54 by mmomeni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	char			content;
	struct s_node	*next;
}					t_node_;

typedef struct s_queue
{
	t_node_			*first;
	t_node_			*last;
	int				size;
}					t_queue;

t_node_				*enqueue(t_queue *queue, char content);
char				dequeue(t_queue *queue);
char				*queue_to_line(t_queue *queue);
t_node_				*node_new(char content);

char				*get_next_line(int fd);

#endif