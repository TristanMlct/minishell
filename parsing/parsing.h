/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:04:30 by tmilcent          #+#    #+#             */
/*   Updated: 2023/01/18 22:06:08 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdlib.h>

int		count_unescaped_singlequote(char *line);
int		count_unescaped_doublequote(char *line);
char	*sanitize_line(char *line);

#endif