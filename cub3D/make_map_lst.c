/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonin <aantonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 10:43:49 by aantonin          #+#    #+#             */
/*   Updated: 2021/03/05 16:12:03 by aantonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

char	**make_map(t_list **head, int size)
{
	char	**map;
	int		i;
	t_list	*tmp;

	tmp = *head;
	map = (char**)malloc((size + 1) * sizeof(char*));
	i = 0;
	while (tmp)
	{
		map[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	return (map);
}

void	checking_map_errors2(char **map, int n, int i)
{
	char	flag;
	int		j;
	char	*v;
	char	*nsew;

	v = "012 NSEW";
	nsew = "NSEW";
	flag = 0;
	while (i < n)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (ft_memchr(v, map[i][j], 8) == NULL)
				error_exit(1);
			if (ft_memchr(nsew, map[i][j], 4))
			{
				if (flag == 1)
					error_exit(2);
				flag = 1;
			}
			j++;
		}
		i++;
	}
}

void	checking_map_errors(char **map, int n, int flag)
{
	int			i;
	char		**map_new;
	int			k;
	t_params	params;

	i = 0;
	while (map[i][0] != '1' && map[i][0] != ' ')
		i++;
	check_repeat(map, i - 1);
	params = read_before(map, i - 1);
	checking_map_errors2(map, n, i);
	map_new = (char**)malloc((n - i + 2) * sizeof(char*));
	k = 0;
	while (k + i < n)
	{
		map_new[k] = ft_strdup(map[k + i]);
		k++;
	}
	check_new_map(map_new, k - 1);
	i = count_sprite(map_new, k - 1);
	params.spr_coun = i;
	if (i > 0)
		params.spr_mas = write_down_sprite(map_new, n, i);
	draw_map(map_new, k, params, flag);
}

void	read_file(int flag, int fd)
{
	t_list	*head;
	char	*line;
	char	**map;
	int		i;

	head = NULL;
	line = NULL;
	while (get_next_line(fd, &line))
	{
		ft_lstadd_back(&head, ft_lstnew(line));
	}
	ft_lstadd_back(&head, ft_lstnew(line));
	i = ft_lstsize(head);
	if (i < 3)
		error_exit(1);
	map = make_map(&head, i);
	checking_map_errors(map, i, flag);
	exit(0);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	s[1];
	int		flag;

	if (argc <= 1 || argc > 3)
		error_exit(0);
	flag = 0;
	if (argc == 3)
		(ft_strncmp(argv[2], "--save", 7) == 0) ? flag = 1 : error_exit(0);
	i = ft_strlen(argv[1]);
	if (argv[1][i - 1] != 'b' || argv[1][i - 2] != 'u' ||\
	argv[1][i - 3] != 'c' || argv[1][i - 4] != '.')
		error_exit(4);
	fd = open(argv[1], O_RDONLY);
	if ((i = read(fd, s, 0)) < 0)
		error_exit(1);
	read_file(flag, fd);
	return (0);
}
