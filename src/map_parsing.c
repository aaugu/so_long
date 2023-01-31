/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:24:53 by aaugu             #+#    #+#             */
/*   Updated: 2023/01/31 11:19:28 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**map_parsing(char *filename)
{
	char	**map;
	char	*line;
	int		nb_line;
	int		fd;
	int		i;

	nb_line = count_lines(filename);
	if (!nb_line)
		return (0);
	map = (char **)malloc(sizeof(char *) * (nb_line + 1));
	if (!map)
		return (NULL);
	fd = open(filename, O_RDONLY);
	i = 0;
	while (i < nb_line)
	{
		line = get_next_line(fd);
		map[i] = ft_strdup(line);
		if (!map[i] || map[i++] == 0)
			return (ft_freeall(map));
	}
	map[nb_line] = NULL;
	return (map);
}

int	count_lines(char *filename)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error, map file is not readable\n");
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
