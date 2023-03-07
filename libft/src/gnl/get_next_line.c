/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:24:40 by mhug              #+#    #+#             */
/*   Updated: 2022/11/25 11:30:15 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	get_content(int fd, char **content, int *c_len)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return ;
	if (ft_index_of(*content, '\n') != -1)
		return (free_strs(&buffer, 0));
	read_bytes = 1;
	while (read_bytes)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free_strs(&buffer, 0));
		buffer[read_bytes] = '\0';
		*content = ft_strnjoin(*content, buffer, *c_len, read_bytes);
		if (!*content)
			return (free_strs(&buffer, 0));
		*c_len += read_bytes;
		if (ft_index_of(buffer, '\n') != -1)
			break ;
	}
	return (free_strs(&buffer, 0));
}

char	*get_residual_content(char *content, int c_len, int l_len)
{
	char	*residual;
	int		i;
	int		len;

	len = c_len - l_len;
	residual = malloc(sizeof(char) * (len + 1));
	if (!residual)
		return (free_strs(&content, 0), NULL);
	i = -1;
	while (++i < len)
		residual[i] = content[l_len + i];
	residual[len] = '\0';
	return (free_strs(&content, 0), residual);
}

char	*get_line_from_content(char *content, int c_len, int *l_len)
{
	char	*line;
	int		i_breakline;
	int		i;

	i_breakline = ft_index_of(content, '\n');
	if (i_breakline != -1)
		*l_len = i_breakline + 1;
	else
		*l_len = c_len;
	line = (char *)malloc(sizeof(char) * (*l_len + 1));
	if (!line)
		return (NULL);
	i = -1;
	while (++i < *l_len)
		line[i] = content[i];
	line[*l_len] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*content = NULL;
	int			content_len;
	int			line_len;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	line_len = 0;
	if (!content)
		content_len = 0;
	else
		content_len = ft_strlen(content);
	get_content(fd, &content, &content_len);
	if (content && *content != '\0')
		line = get_line_from_content(content, content_len, &line_len);
	content = get_residual_content(content, content_len, line_len);
	if ((content && !line) || *line == '\0')
		return (free_strs(&content, &line), NULL);
	return (line);
}
