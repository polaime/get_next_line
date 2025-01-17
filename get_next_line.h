/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthibaud <pthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:29:10 by pthibaud          #+#    #+#             */
/*   Updated: 2025/01/09 17:18:45 by pthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
int		bool_n(char *str);
void	*ft_calloc(size_t num, size_t size);
char	*ft_strrchr(const char *str, int c);

#endif
