/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthibaud <pthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:29:18 by pthibaud          #+#    #+#             */
/*   Updated: 2025/01/09 17:21:48 by pthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t num, size_t size)
{
	void		*l;
	size_t		i;

	i = 0;
	i--;
	if (size != 0 && i / size < num)
		return (NULL);
	i = 0;
	l = malloc(num * size);
	if (l == NULL)
		return (NULL);
	while (i < num * size)
	{
		((unsigned char *)l)[i] = 0;
		i++;
	}
	return (l);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	return (free(s1), str);
}

int	bool_n(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strrchr(const char *str, int c)
{
	const char			*r;
	unsigned char		uc;

	if (!str)
		return (NULL);
	uc = (unsigned char)c;
	r = NULL;
	while (*str != '\0')
	{
		if ((unsigned char)*str == uc)
			r = str;
		str++;
	}
	if (uc == '\0')
		return ((char *)str);
	return ((char *)r);
}
