/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 23:09:54 by mmomeni           #+#    #+#             */
/*   Updated: 2023/07/20 12:44:17 by mmomeni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	nn_index(t_queue *queue)
{
	t_node_	*tmp;
	int		i;

	if (!queue->size)
		return (queue->size);
	tmp = queue->first;
	i = 0;
	while (tmp)
	{
		if (tmp->content == '\n')
			return (i + 1);
		tmp = tmp->next;
		i++;
	}
	return (queue->size);
}

t_node_	*node_new(char content)
{
	t_node_	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

t_node_	*enqueue(t_queue *queue, char content)
{
	t_node_	*node;

	node = node_new(content);
	if (!node)
		return (NULL);
	node->next = NULL;
	if (!queue->size)
		queue->first = node;
	else
		queue->last->next = node;
	queue->last = node;
	queue->size++;
	return (node);
}

char	dequeue(t_queue *queue)
{
	t_node_	*tmp;
	char	c;

	if (!queue->size)
		return ('\0');
	tmp = queue->first;
	c = tmp->content;
	queue->first = tmp->next;
	free(tmp);
	queue->size--;
	return (c);
}

char	*queue_to_line(t_queue *queue)
{
	char	*line;
	int		i;
	int		nn;

	if (!queue->size)
		return (NULL);
	nn = nn_index(queue);
	line = malloc((nn + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (i < nn)
		line[i++] = dequeue(queue);
	line[i] = '\0';
	return (line);
}
