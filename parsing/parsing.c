/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:04:21 by tmilcent          #+#    #+#             */
/*   Updated: 2023/01/22 19:09:26 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
		if (line[i] == '"' && c % 2 == 0)
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
		if (line[i] == '\'' && c % 2 == 0)
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

/*
	Get the node type of a char* 
	- the different possibility node type are listed in the enum "e_node_type"
*/
enum e_node_type	get_node_type(char *args)
{
	if (!args || ft_strlen(args) == 0)
		return (0);
	if (ft_strcmp(args, "|") == 0)
		return (PIPE);
	else if (ft_strcmp(args, "&&") == 0)
		return (AND);
	else if (ft_strcmp(args, "||") == 0)
		return (OR);
	else if (ft_strlen(args) >= 2 && args[0] == '<' && args[1] == '<')
		return (REDIRECT_2_INPUT);
	else if (ft_strlen(args) >= 2 && args[0] == '>' && args[1] == '>')
		return (REDIRECT_2_OUTPUT);
	else if (args[0] == '<')
		return (REDIRECT_INPUT);
	else if (args[0] == '>')
		return (REDIRECT_OUTPUT);
	else
		return (COMMAND);
}

/*
	Get line as a tab of node
*/
t_node	**get_line_as_nodes(char **line_as_tab)
{
	int		tab_size;
	t_node	**line_as_nodes;

	tab_size = 0;
	while (line_as_tab[tab_size] != 0)
		tab_size++;
	line_as_nodes = malloc(sizeof(*line_as_nodes) * (tab_size + 1));
	line_as_nodes[tab_size] = 0;
	while (--tab_size >= 0)
	{
		line_as_nodes[tab_size] = create_node();
		line_as_nodes[tab_size]->type = get_node_type(line_as_tab[tab_size]);
		line_as_nodes[tab_size]->arg = ft_strdup(line_as_tab[tab_size]);
	}
	return (line_as_nodes);
}

/*
	Line parsing
*/
t_node	**parse_line(char *line)
{
	char	**line_split;
	t_node	**line_as_nodes;

	line_split = ft_split(line, ' ');
	line_as_nodes = get_line_as_nodes(line_split);
	free(line_split);
	return (line_as_nodes);
}
