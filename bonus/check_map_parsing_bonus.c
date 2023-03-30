/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_parsing_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:37:39 by aaugu             #+#    #+#             */
/*   Updated: 2023/03/30 11:42:40 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int		count_lines(const char *filename);
char	**fill_map(const char *filename, int line_nb);

char	**map_parsing(const char *filename)
{
	char	**map;
	int		line_nb;

	line_nb = count_lines(filename);
	if (!line_nb)
		return (NULL);
	map = fill_map(filename, line_nb);
	if (!map)
		return (NULL);
	return (map);
}

int	count_lines(const char *filename)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nMap file is not readable. Try again\n");
		return (0);
	}
	line = NULL;
	while (TRUE)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		count++;
	}
	close(fd);
	if (count == 0)
		ft_printf("Error\nMap empty. Try again\n");
	return (count);
}

char	**fill_map(const char *filename, int line_nb)
{
	int		i;
	int		fd;
	char	*line;
	char	**map;

	map = (char **)malloc(sizeof(char *) * (line_nb + 1));
	if (!map)
		return (NULL);
	map[line_nb] = NULL;
	fd = open(filename, O_RDONLY);
	i = 0;
	while (i < line_nb)
	{
		line = get_next_line(fd);
		map[i] = ft_substr(line, 0, ft_strlen(line) - 1);
		free(line);
		if (!map[i])
		{
			ft_strs_free(map, line_nb);
			return (NULL);
		}
		i++;
	}
	close(fd);
	return (map);
}
