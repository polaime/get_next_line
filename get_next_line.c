/* ************************************************************************** */
/*                                                     ..,,;;;,'..            */
/*                                                 .'cx0XNNWWWNXKOdl;.        */
/*   get_next_line.c                             .;xXWNKOkkOKNMMMMMMW0l.      */
/*                                              ,xNMXd,.   .cONMMMMMMMK;      */
/*   Par: polaime <pthibaud>                   .:0WMX:      :XMMNNMMMMM0,     */
/*                                             :KMMMk.      .lxdckMMMMWd.     */
/*   Cree: 2025/01/19 13:50:28                ,OMMMMK,          ,0MMMWO'      */
/*   Ameliore: 2025/01/19 14:42:13           .oWMMMMW0c.      .c0WMMWk,       */
/*                                           'OMMWXNWMWKkddodkKWMMWKo.        */
/*                                           'OMWk,,lx0XWWMMMMMWXOo'.         */
/*   https://github.com/polaime              .oKx'    .';:clllc;'.            */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t				i;
	char				*l;
	size_t				j;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s);
	if (len > j || (start + len) > j)
		len = j - start;
	l = (char *)malloc((len + 1) * sizeof (char));
	if (!l)
		return (NULL);
	i = 0;
	while (i != len && s[start + i] != '\0')
	{
		l[i] = s[start + i];
		i++;
	}
	l[i] = '\0';
	return (l);
}

static char	*get_line(const char *stash)
{
	int		i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	return (ft_substr(stash, 0, i + (stash[i] == '\n')));
}

static char	*save_stash(const char *stash)
{
	int		i;
	char	*tmp;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		++i;
	if (!stash[i])
		return (free((void *)stash), NULL);
	tmp = ft_substr(stash, i + (stash[i] == '\n'), -1);
	free((void *)stash);
	return (tmp);
}

static char	*read_line(char *stash, int fd)
{
	char	*buff;
	ssize_t	nb_read;

	nb_read = 1;
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (!ft_strrchr(stash, '\n') && nb_read != 0)
	{
		nb_read = read(fd, buff, BUFFER_SIZE);
		if (nb_read == -1)
		{
			free(stash);
			stash = NULL;
			break ;
		}
		buff[nb_read] = 0;
		stash = ft_strjoin(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char		*stash = NULL;
	char			*line;

	if (fd == -1 || fd > 2048)
		return (NULL);
	stash = read_line(stash, fd);
	if (!stash)
		return (NULL);
	line = get_line(stash);
	stash = save_stash(stash);
	return (line);
}
