/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:24:53 by aaugu             #+#    #+#             */
/*   Updated: 2023/02/24 10:12:25 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**map_parsing(const char *filename)
{
	char	**map;
	char	*line;
	int		line_nb;
	int		fd;
	int		i;

	line_nb = count_lines(filename);
	if (!line_nb)
		return (0);
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
		if (!map[i] || map[i++] == 0)
			return (ft_freeall(map));
	}
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
		ft_printf("Error\nMap file is not readable\n");
		return (0);
	}
	while (get_next_line(fd))
		count++;
	close(fd);
	if (count == 0)
		ft_printf("Error\nMap empty");
	return (count);
}

char	**ft_freeall(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	ft_printf("Error\nMap invalid");
	return (NULL);
}
