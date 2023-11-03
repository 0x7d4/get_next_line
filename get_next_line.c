/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmomeni <mmomeni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 23:04:51 by mmomeni           #+#    #+#             */
/*   Updated: 2023/11/03 15:58:37 by mmomeni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*reset_queue(t_queue *queue)
{
	t_node_	*tmp;

	while (queue->first)
	{
		tmp = queue->first->next;
		free(queue->first);
		queue->first = tmp;
	}
	*queue = (t_queue){.first = 0, .last = 0, .size = 0};
	return (NULL);
}

char	*ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
		if (s[i++] == c)
			return (&s[i]);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_queue	queue;
	char			buf[BUFFER_SIZE + 1];
	int				fb;
	int				i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (1)
	{
		fb = read(fd, buf, BUFFER_SIZE);
		if (fb == -1)
			return (reset_queue(&queue));
		buf[fb] = 0;
		i = 0;
		while (i < fb)
			if (!enqueue(&queue, buf[i++]))
				return (NULL);
		if (!fb || ft_strchr(buf, '\n'))
			break ;
	}
	return (queue_to_line(&queue));
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int		fd;

// 	fd = open("test.txt", O_RDONLY);
// 	// fd = STDIN_FILENO;
// 	printf("[%s]\n", get_next_line(fd));
// 	// char c = 0;
// 	// int fb = read(fd, &c, 1);
// 	// printf("fb now: %d and char: %c\n", fb, c);
// 	// printf("should be null: [%s]\n", get_next_line(fd));
// 	printf("[%s]\n", get_next_line(fd));
// 	printf("[%s]\n", get_next_line(fd));
// 	printf("[%s]\n", get_next_line(fd));
// 	printf("[%s]\n", get_next_line(fd));
// 	printf("[%s]\n", get_next_line(fd));
// }
