/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 20:00:32 by ashari            #+#    #+#             */
/*   Updated: 2019/04/17 22:21:06 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/header.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	t_lst	*t;
	int		fd;

	fd = open(av[1], O_RDONLY);
	t = map_reader(fd, &t);
	int i;
	printf("%p\n", t);
	while (t)
	{
		i = 0;
		while ((t->map)[i])
		{
			printf("%s\n", (t->map)[i]);
			i++;
		}
		t = t->next;
	}
	close(fd);
}
