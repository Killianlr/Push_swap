/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder_opti.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:31:32 by kle-rest          #+#    #+#             */
/*   Updated: 2023/03/11 16:37:59 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	find_next_a(t_a *pile_a)
{
	t_a *tmp;
	int	i;

	tmp = pile_a;
	i = 0;
	while (tmp->next)
	{
		if (tmp->rank == pile_a->rank - 1)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	find_prev_a(t_a *pile_a)
{
	t_a *tmp;
	int	i;
	int	j;

	tmp = pile_a;
	i = 0;
	j = ft_lst_size(pile_a);
	while (j > 0)
	{
		if (tmp->rank == pile_a->rank - 1)
			return (i);
		i++;
		j--;
		tmp = tmp->prev;
	}
	return (i);
}

int	find_next_b(t_a *pile_b)
{
	t_a *tmp;
	int	i;

	tmp = pile_b;
	i = 0;
	while (tmp->next)
	{
		if (tmp->rank == pile_b->rank + 1)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	find_prev_b(t_a *pile_b)
{
	t_a *tmp;
	int	i;
	int	j;

	tmp = pile_b;
	i = 0;
	j = ft_lst_size(pile_b);
	while (j > 0)
	{
		if (tmp->rank == pile_b->rank + 1)
			return (i);
		i++;
		j--;
		tmp = tmp->prev;
	}
	return (i);
}