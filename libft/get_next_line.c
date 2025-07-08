/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shasinan <shasinan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:16:51 by shasinan          #+#    #+#             */
/*   Updated: 2025/07/07 17:02:58 by shasinan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*read_from_file(int fd)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		free(buffer);
		return ((char *)-1);
	}
	if (bytes_read == 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	return (buffer);
}

char	*join_buffer(char *big_buf, char *read_buf)
{
	char	*new_big_buf;

	if (!big_buf)
	{
		new_big_buf = ft_strdup(read_buf);
		if (!new_big_buf)
			return (free(read_buf), NULL);
		return (new_big_buf);
	}
	new_big_buf = ft_strjoin(big_buf, read_buf);
	if (!new_big_buf)
		return (NULL);
	free(big_buf);
	return (new_big_buf);
}

char	*extract_line(char *big_buf)
{
	char	*line_extracted;
	int		i;

	line_extracted = NULL;
	i = 0;
	while (big_buf[i] && big_buf[i] != '\n')
		i++;
	if (big_buf[i] == '\0')
		line_extracted = ft_strdup(big_buf);
	else if (big_buf[i] == '\n')
		line_extracted = ft_substr(big_buf, 0, i + 1);
	if (!line_extracted)
		return (NULL);
	return (line_extracted);
}

char	*update_big_buf(char *big_buf)
{
	char	*big_buf_updated;
	int		i;

	i = 0;
	while (big_buf[i] && big_buf[i] != '\n')
		i++;
	if (big_buf[i] == '\0')
	{
		free(big_buf);
		return (NULL);
	}
	big_buf_updated = ft_substr(big_buf, i + 1, ft_strlen(big_buf) - i - 1);
	if (!big_buf_updated)
		return (NULL);
	free(big_buf);
	return (big_buf_updated);
}

char	*get_next_line(int fd)
{
	static char	*big_buf;
	char		*line;
	char		*read_buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!big_buf || !ft_strchr(big_buf, '\n'))
	{
		read_buf = read_from_file(fd);
		if (read_buf == (char *)-1)
			return (free(big_buf), big_buf = NULL, NULL);
		if (!read_buf)
			break ;
		big_buf = join_buffer(big_buf, read_buf);
		if (!big_buf)
			return (free(big_buf), NULL);
		free(read_buf);
	}
	if (!big_buf || big_buf[0] == '\0')
		return (free(big_buf), big_buf = NULL, NULL);
	line = extract_line(big_buf);
	big_buf = update_big_buf(big_buf);
	return (line);
}
