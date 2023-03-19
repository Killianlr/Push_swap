/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo356.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:36:01 by kle-rest          #+#    #+#             */
/*   Updated: 2023/03/19 11:17:10 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

char	*algo_3(t_a **pile, char *str)
{
	t_a		*tmp;

	tmp = *pile;
	tmp = tmp->next;
	if (tmp->rank == 3 && (*pile)->rank == 1)
		str = ft_strjoin_ps(str, swap_a(pile));
	if (tmp->rank == 3 && (*pile)->rank == 2)
		str = ft_strjoin_ps(str, reverse_rotate_a(pile));
	if ((*pile)->rank == 3)
	{
		str = ft_strjoin_ps(str, rotate_list_a(pile));
		if ((*pile)->rank == 2)
			str = ft_strjoin_ps(str, swap_a(pile));
	}
	if ((*pile)->rank == 2)
	{
		str = ft_strjoin_ps(str, swap_a(pile));
		if ((*pile)->rank == 3)
			str = ft_strjoin_ps(str, rotate_list_a(pile));
	}
	return (str);
}

char	*algo_5end(t_a **pile_a, t_a **pile_b, char *str)
{
	t_a	*tmp;

	tmp = (*pile_b)->next;
	if ((*pile_b)->rank == 1 && tmp->rank == 2)
	{
		str = ft_strjoin_ps(str, swap_b(pile_b));
		str = ft_strjoin_ps(str, reverse_rotate_b(pile_b));
	}
	if ((*pile_b)->rank == 2 && tmp->rank == 3)
		str = ft_strjoin_ps(str, swap_b(pile_b));
	if ((*pile_b)->rank == 2 && tmp->rank == 1)
		str = ft_strjoin_ps(str, reverse_rotate_b(pile_b));
	if ((*pile_b)->rank == 1 && tmp->rank == 3)
		str = ft_strjoin_ps(str, rotate_list_b(pile_b));
	while (ft_lst_size(*pile_b) > 0)
		str = ft_strjoin_ps(str, push_list_a(pile_a, pile_b));
	while ((*pile_a)->rank != 1)
		str = ft_strjoin_ps(str, rotate_list_a(pile_a));
	return (str);
}

char	*algo_5(t_a **pile_a, t_a **pile_b, char *str)
{
	t_a		*tmp;

	while (ft_lst_size(*pile_a) > 2)
	{
		if ((*pile_a)->rank < 4)
			str = ft_strjoin_ps(str, push_list_b(pile_a, pile_b));
		else
			str = ft_strjoin_ps(str, rotate_list_a(pile_a));
	}
	if ((*pile_a)->rank == 5)
		str = ft_strjoin_ps(str, swap_a(pile_a));
	tmp = *pile_b;
	tmp = tmp->next;
	if ((*pile_b)->rank == 1 && tmp->rank == 3)
		str = ft_strjoin_ps(str, rotate_list_b(pile_b));
	if ((*pile_b)->rank == 3 && tmp->rank == 1)
		str = ft_strjoin_ps(str, swap_b(pile_b));
	str = algo_5end(pile_a, pile_b, str);
	return (str);
}
