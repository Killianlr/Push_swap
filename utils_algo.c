/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:56:40 by kle-rest          #+#    #+#             */
/*   Updated: 2023/03/19 14:03:18 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	caughtmaxprev(t_a *pile_b)
{
	int	i;
	int	j;
	int	max;
	t_a	*tmp;

	i = 0;
	tmp = pile_b;
	j = ft_lst_size(pile_b);
	max = ft_lst_size(pile_b);
	while (j > 0)
	{
		if (tmp->rank == max)
			return (i);
		i++;
		j--;
		tmp = tmp->prev;
	}
	return (i);
}

int	caughtmaxnext(t_a *pile_b)
{
	int	i;
	int	max;
	t_a	*tmp;

	i = 0;
	tmp = pile_b;
	max = ft_lst_size(pile_b);
	while (tmp->next)
	{
		if (tmp->rank == max)
			return (i);
		i++;
		tmp = tmp->next;
	}
	if (tmp->rank == max)
		return (i);
	return (i);
}

int	find_rank_max(t_a *pile_a)
{
	t_a	*tmp;
	int	max;

	max = 0;
	tmp = pile_a;
	while (tmp->next)
	{
		if (max < tmp->rank)
			max = tmp->rank;
		tmp = tmp->next;
	}
	if (max < tmp->rank)
		max = tmp->rank;
	return (max);
}

int	caughtvalnext(t_a *pile_a, int stop)
{
	t_a	*tmp;
	int	i;
	int	j;
	int	max;

	i = 0;
	tmp = pile_a;
	j = ft_lst_size(pile_a);
	max = find_rank_max(pile_a);
	while (j > 0)
	{
		if (tmp->rank < stop && tmp->rank != max)
			return (i);
		i++;
		j--;
		tmp = tmp->next;
	}
	return (i);
}

int	caughtvalprev(t_a *pile_a, int stop)
{
	t_a	*tmp;
	int	i;
	int	j;
	int	max;

	i = 0;
	tmp = pile_a;
	j = ft_lst_size(pile_a);
	max = find_rank_max(pile_a);
	while (j > 0)
	{
		if (tmp->rank <= stop && tmp->rank != max)
			return (i);
		i++;
		j--;
		tmp = tmp->prev;
	}
	return (i);
}
