/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:05:59 by aantonin          #+#    #+#             */
/*   Updated: 2020/12/17 14:37:32 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static int		found_n(char *str)
{
	size_t		i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static int		gnl(char **new_line, int fd, int a)
{
	char	*buf;
	int		k;

	k = 0;
	while (k == 0 && a > 0)
	{
		if ((buf = malloc((BUFFER_SIZE + 1) * sizeof(char))) != NULL)
		{
			if ((a = read(fd, buf, BUFFER_SIZE)) > 0)
			{
				*(buf + a) = '\0';
				k = found_n(buf);
				if (!(*new_line = ft_strjoin_f(*new_line, buf)))
				{
					free(buf);
					return (-1);
				}
			}
			free(buf);
		}
		else
			return (-1);
	}
	return (a);
}

static int resalts(char **new_line, char **line, int a, int n)
{
	int i;
	int j;

	i = 0;
	while (i < n && (*new_line)[i] != '\n')
		i++;
	*line = malloc((i + 1) * sizeof(char));
	if (!*line)
		return (-1);
	j = 0;
	while (j < i)
	{
		(*line)[j] = (*new_line)[j];
		j++;
	}
	(*line)[j] = '\0';
	j++;
	while (j < n)
	{
		(*new_line)[j - i - 1] = (*new_line)[j];
		j++;
	}
	(*new_line)[j - i - 1] = '\0';
	return (a);
}

int				get_next_line(int fd, char **line)
{
	static char	*new_line;
	int			a;
	int			k;
	char		p[1];

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || read(fd, p, 0) < 0)
		return (-1);
	if (!new_line) 
	{
		if (!(new_line = malloc(sizeof(char))))
			return (-1);
		*new_line = '\0';
	}
	a = 1;
	k = found_n(new_line);
	(k == 0) ? 	a = gnl(&new_line, fd, a) : 0;
	if (a >= 0)
	{
		a = resalts(&new_line, line, a, ft_strlen(new_line));
		if ((new_line != NULL && a == 0 && k == 0) || a < 0)
			new_line = free_n(new_line);
		(a > 0) ? a = 1 : 0;	
	}
	return (a);
}
