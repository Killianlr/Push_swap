/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:30:23 by kle-rest          #+#    #+#             */
/*   Updated: 2023/02/05 18:30:56 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	zero_rank(t_a *pile)
{
	while (1 <= ft_lst_size(pile))
	{
		pile->rank = 0;
		pile = pile->next;
	}
}

void	allow_rank(int mem, t_a *pile, int rank)
{
	while (1 <= ft_lst_size(pile))
	{
		if (mem == pile->data)
			pile->rank = rank;
		pile = pile->next;
	}
}

void	run_list_for_rank(t_a *pile)
{
	int	mem;
	int rank;
	t_a *list;
	t_a *run;

	rank = 0;
	list = pile;
	while (1 <= ft_lst_size(list))
	{
		run = pile;
		mem = __INT_MAX__;
		while (1 <= ft_lst_size(run))
		{
			if (mem > run->data && run->rank == 0)
				mem = run->data;
			run = run->next;
		}
		rank += 1;
		allow_rank(mem, pile, rank);
		list = list->next;
	}
}

int	find_median(t_a **pile)
{
	int i;
	int j;
	t_a *first;
	t_a *compare;

	i = 0;
	j = 0;
	first = *pile;
	while (1 <= ft_lst_size(first))
	{
		compare = *pile;
		while (1 <= ft_lst_size(compare))
		{
			if (compare->data > first->data)
				i += 1; 
			else if (compare->data < first->data)
				j += 1;
			compare = compare->next;
		}
		if ((ft_lst_size(*pile) % 2) == 1 && j == i)
			return (first->data);
		else if ((ft_lst_size(*pile) % 2) == 0 && (j - i == 1 || j - i == -1))
			return (first->data);
		j = 0;
		i = 0;
		first = first->next;
	}
	return (0);
}