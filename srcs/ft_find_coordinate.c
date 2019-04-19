/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_coordinate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 20:57:36 by ashari            #+#    #+#             */
/*   Updated: 2019/04/19 14:11:47 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**		Return place, which we searched
*/

static	int		where_the_nearest(char *tetr, int *last, int *last_coord)
{
	int			nearest;
	int			i;
	int			step;

	nearest = 4;
	i = -1;
	while (++i < 19)
	{
		step = -1;
		while (++step < 4)
		{
			if ((i % 10) != 4 && (i % 10) != 9 && tetr[i] == '#')
				(step < nearest) ? nearest = step : 0;
			if (tetr[i] == '#')
			{
				*last_coord = step;
				*last = i;
			}
			i++;
		}
	}
	return (nearest);
}

static	int		where_the_farest(char *tetr)
{
	int			nearest;
	int			i;
	int			step;

	nearest = 0;
	i = -1;
	while (++i < 19)
	{
		step = -1;
		while (++step < 4)
		{
			if ((i % 10) != 4 && (i % 10) != 9 && tetr[i] == '#')
				(step > nearest) ? nearest = step : 0;
			i++;
		}
	}
	return (nearest);
}

static	int		give_me_your_size(char *tetr)
{
	int			h;
	int			flag;
	int			i;
	int			step;

	h = 0;
	step = -1;
	i = -1;
	while (++i < 19)
	{
		flag = 0;
		step = -1;
		while (++step < 4)
		{
			if ((i % 10) != 4 && (i % 10) != 9 && tetr[i] == '#' && flag == 0)
			{
				flag = 1;
				h++;
			}
			i++;
		}
	}
	return (h);
}

static int		get_width(char *tetr)
{
	int i;
	int max_i;

	i = -1;
	max_i = -1;
	while (++i < 19)
		if (tetr[i] == '#' && max_i % 5 < i % 5)
			max_i = i;
	return (max_i);
}

int				ft_find_coordinate(char *tetr, int *h, int *w)
{
	int			nearest;
	int			last_coord;
	int			last;
	int			coord;

	nearest = where_the_nearest(tetr, &last, &last_coord);
	*h = give_me_your_size(tetr);
	coord = last - (last_coord - nearest) - (*h - 1) * 5;
	*w = get_width(tetr) % 5 - coord % 5 + 1;
	return (coord);
}
