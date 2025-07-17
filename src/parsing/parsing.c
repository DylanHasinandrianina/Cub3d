/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasinan <shasinan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:13:01 by shasinan          #+#    #+#             */
/*   Updated: 2025/07/17 14:07:02 by shasinan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	exit_with_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

void	check_file(int ac, char **av)
{
	int		len;
	int		fd;
	char	buffer[1];

	if (ac != 2)
	{
		ft_putstr_fd("Error\nbad arguments\n", 2);
		exit(1);
	}
	len = ft_strlen(av[1]);
	if (len < 4 || ft_strcmp(".cub", av[1] + len - 4) != 0)
		exit_with_error("Error\nwrong extension (expected: .cub)\n");
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit_with_error("Error\ncannot open the file\n");
	if (read(fd, buffer, 1) == 0)
	{
		close(fd);
		exit_with_error("Error\nnothing in the file\n");
	}
	close(fd);
}

static int	count_file_lines(int fd)
{
	int		count;
	char	*line;

	count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		count++;
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static char	**read_file_to_array(char **av)
{
	int		fd;
	int		nbr_line;
	int		i;
	char	**content;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (NULL);
	nbr_line = count_file_lines(fd);
	content = malloc(sizeof(char *) * (nbr_line + 1));
	if (!content)
		return (NULL);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (free(content), NULL);
	i = 0;
	while (i < nbr_line)
	{
		content[i] = get_next_line(fd);
		if (!content[i])
			return (free_partial_lines(content, i), close(fd), NULL);
		i++;
	}
	content[i] = NULL;
	return (get_next_line(-1), close(fd), content);
}

int	parsing(int ac, char **av, t_game *game)
{
	char	**file_content;

	(void)ac;
	file_content = read_file_to_array(av);
	if (!file_content)
		return (0);
	if (check_error(file_content, game))
	{
		free_split(file_content);
		return (0);
	}
	return (1);
}

/*What the parsing does:

    Checks the file format

        Ensures the file has a .cub extension.

        Opens the file and reads its content line by line.

    Extracts and validates required data

        Textures: NO, SO, WE, EA paths for wall textures.

        Colors: Floor (F) and Ceiling (C) colors in RGB format.

        Map: The 2D map layout made of characters like 1, 0, and P.

    Validates map integrity

        Ensures the map is enclosed by walls (1).

        Checks that there's only one player starting position.

        Ensures no invalid characters exist.

    Fills the game structure (t_game)

        Stores textures, colors, and map data into the t_game struct*/
