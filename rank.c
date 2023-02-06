/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:30:23 by kle-rest          #+#    #+#             */
/*   Updated: 2023/02/06 16:32:49 by kle-rest         ###   ########.fr       */
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

t_a	*ft_lstnew_ps(int data)
{
	t_a	*new;

	new = NULL;
	new = (t_a *)malloc(sizeof(t_a));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back_ps(t_a **lst, t_a *new)
{
	t_a	*temp;

	if (!lst)
		return ;
	temp = *lst;
	if (!temp)
	{
		*lst = new;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}
