/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:04:21 by tmilcent          #+#    #+#             */
/*   Updated: 2023/01/18 22:05:55 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*
	TODO(Tristan) : to be remove when libft will be include
*/
int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
	Count the number on single quote that matter (not between double quote).
*/
int	count_unescaped_singlequote(char *line)
{
	int	i;
	int	c;
	int	in_double_quote;

	i = -1;
	c = 0;
	in_double_quote = 0;
	while (line[++i])
	{
		if (line[i] == '"')
			in_double_quote = (in_double_quote + 1) % 2;
		if (line[i] == '\'')
		{
			if (!in_double_quote)
				c++;
		}
	}
	return (c);
}

/*
	Count the number on double quote that matter (not between single quote).
*/
int	count_unescaped_doublequote(char *line)
{
	int	i;
	int	c;
	int	in_single_quote;

	i = -1;
	c = 0;
	in_single_quote = 0;
	while (line[++i])
	{
		if (line[i] == '\'')
			in_single_quote = (in_single_quote + 1) % 2;
		if (line[i] == '"')
		{
			if (!in_single_quote)
				c++;
		}
	}
	return (c);
}

/*
	Remove single and double quote that prevent the interpretation of metachars
*/
char	*sanitize_line(char *line)
{
	char	*sanitized_line;
	int		new_line_size;
	int		i;
	int		j;

	new_line_size = ft_strlen(line)
		- count_unescaped_singlequote(line) - count_unescaped_doublequote(line);
	sanitized_line = malloc(sizeof(char) * (new_line_size + 1));
	sanitized_line[new_line_size] = '\0';
	i = -1;
	j = -1;
	while (line[++i])
	{
		if (line[i] == '"')
			while (line[++i] != '"')
				sanitized_line[++j] = line[i];
		else if (line[i] == '\'')
			while (line[++i] != '\'')
				sanitized_line[++j] = line[i];
		else
			sanitized_line[++j] = line[i];
	}
	return (sanitized_line);
}
