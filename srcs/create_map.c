/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cortiz <cortiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 08:06:19 by cortiz            #+#    #+#             */
/*   Updated: 2023/03/03 13:27:34 by cortiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_width(const char *str)
{
	int	i;
	int	total_word;

	total_word = 0;
	i = 0;
	while (str[i])
	{
		while (ft_is_whitespace(str[i]))
			i++;
		if (str[i] != '\0')
			total_word++;
		while (ft_is_whitespace(str[i]) == 0 && str[i])
			i++;
	}
	return (total_word);
}

int	get_height(char *file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	return (i);
}

int	get_width(char *file)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(file, O_RDONLY, 0);
	line = get_next_line(fd);
	width = count_width(line);
	free(line);
	close(fd);
	return (width);
}

void	fill_map(int *map_line, char *line)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_split(line, ' ');
	while (tmp[i])
	{
		map_line[i] = ft_atoi(tmp[i]);
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

void	create_map(t_map *map, char *file)
{
	int		i;
	int		fd;
	char	*line;

	map->height = get_height(file);
	map->width = get_width(file);
	map->matrix = malloc(sizeof(int *) * (map->height + 1));
	i = -1;
	while (++i <= map->height)
		map->matrix[i] = malloc(sizeof(int) * (map->width + 1));
	fd = open(file, O_RDONLY, 0);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		fill_map(map->matrix[i], line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map->matrix[i] = NULL;
	free(line);
	close(fd);
}
