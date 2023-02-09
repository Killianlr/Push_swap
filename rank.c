/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:30:23 by kle-rest          #+#    #+#             */
/*   Updated: 2023/02/09 10:46:00 by kle-rest         ###   ########.fr       */
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
	int	rank;
	t_a	*list;
	t_a	*run;

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
