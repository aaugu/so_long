/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:24:53 by aaugu             #+#    #+#             */
/*   Updated: 2023/01/27 12:23:00 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char  **map_parsing(char  *filename)
{
	char	**map;
	int		nb_line;

	nb_line = count_lines(filename);
	if (!nb_line)

	*map = (char *)malloc(sizeof(char *) * (nb_line + 1))
	if (!*map)
		return (0);
	*map[nb_line] = NULL;

}

int	count_lines(filename)
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
	while (line = get_next_line(fd))
		count++;
	close(fd);
	return (count);
}
