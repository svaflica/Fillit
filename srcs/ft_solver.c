/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:10:07 by djeanna           #+#    #+#             */
/*   Updated: 2019/04/21 12:33:38 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

static	int		ft_solution_map_size(int n)
{
	return (ft_sqrt(n));
}

static void		fill_by_zero(long long *map, int size)
{
	while (--size >= 0)
		map[size] = 0;
}

int				ft_solver(t_lst *tetramino)
{
	int				size;
	long long		map[11];
	int				solve;

	fill_by_zero(map, 11);
	size = ft_solution_map_size(ft_list_size(tetramino) * 4);
	solve = 0;
	while (!solve)
	{
		solve = ft_try_to_solve(tetramino, map, size);
		if (!solve)
		{
			fill_by_zero(map, size);
			size++;
		}
	}
	return (ft_print_map(tetramino, size));
}
