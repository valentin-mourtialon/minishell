/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:02:32 by sel-maar          #+#    #+#             */
/*   Updated: 2023/01/04 14:34:22 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*mem_line;
	char		*line;
	int			ret;
	char		*buff;

	ret = 1;
	if (BUFFER_SIZE < 1 || fd < 0 || fd >= FOPEN_MAX)
		return (NULL);
	while (!ft_strchr(mem_line, '\n') && ret != 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret < 0)
			return (free(buff), NULL);
		buff[ret] = 0;
		mem_line = ft_strjoin(mem_line, buff);
		if (!mem_line)
			return (NULL);
	}
	line = ft_cutline1(mem_line);
	mem_line = ft_cutline2(mem_line);
	return (line);
}
/*
int	main()
{
	int	i = 1;
	int	fd;
	char *line;
	fd = open("test.fdf", O_RDONLY);

	while (i < 10)
	{
		line = get_next_line(fd);
		printf("%d-%s", i, line);
		i++;
		free(line);
	}
	close(fd);
	return (0);
}*/
