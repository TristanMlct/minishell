/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:41:35 by mhug              #+#    #+#             */
/*   Updated: 2022/11/30 15:59:23 by mhug             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

int		ft_index_of(char *str, char c);
void	free_strs(char **s1, char **s2);
char	*ft_strnjoin(char *s1, char *s2, int s1_len, int s2_len);
char	*get_next_line(int fd);

#endif
