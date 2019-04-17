/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:01:04 by ashari            #+#    #+#             */
/*   Updated: 2019/04/17 18:03:42 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/header.h"

static int	is_map_valid(char *buff)
{
	int			i;
	int			res;
	int			count;

	i = 0;
	count = 0;
	while (buff[i])
		if ((buff[i] == '.' || buff[i] == '#')
		|| (buff[i] == '\n' && (i % 10 == 9 || i % 10 == 4 || i == 20)))
		{
			if (buff[i] == '#')
			{
				if (count == 0)
					res = i;
				count++;
			}
			i++;
		}
		else
			return (-1);
	if (count != 4 || i != 21)
		return (-1);
	return (res);
}

static	char	**last_map_reader(char *buff)
{
	char	*tmp;
	int		res;

	res = 0;
	buff[20] = '\0';
	if ((res = is_map_valid(buff)) >= 0)
	{
		tmp = ft_strndup(buff, 20);
		if (is_tetramino_valid(&tmp, res))
			return (ft_strsplit(tmp));
		else
			return (NULL);
	}
	else
		return (NULL);
}

t_list		**map_reader(int fd, t_lst **tetramino)
{
	int		res;
	char	*tetramino_tmp;
	char	*tmp;
	char	**map;
	char	*buff;

	while ((res = read(fd, buff, 21)) > 20)
	{
		buff[res] = '\0';
		if ((res = is_map_valid(buff)) >= 0)
		{
			tmp = ft_strndup(buff, 20);
			if (is_tetramino_valid(tmp, res))
			{
				if (!(tetramino_tmp =
				ft_list_pushback(tetramino, ft_strsplit(tmp))))
					return (ft_list_del(tetramino) && ft_strdel(tmp));
			}
			else
				return (NULL);
		}
		else
			return (NULL);
	}
	if (res == 20)
		if (!(tetramino_tmp =
		ft_list_pushback(tetramino, last_map_reader(buff))))
			return (ft_list_del(tetramino) && ft_strdel(tmp));
	if (res == -1)
		return (NULL);
	return (tetramino);
}
