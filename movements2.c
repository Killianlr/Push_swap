/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:55:54 by kle-rest          #+#    #+#             */
/*   Updated: 2023/03/19 12:11:53 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

char	*reverse_rotate_b(t_a **first)
{
	t_a	*second;
	t_a	*newfirst;

	if (!first)
		return (NULL);
	second = *first;
	while (2 < ft_lst_size(*first))
		*first = (*first)->next;
	newfirst = (*first)->next;
	(*first)->next = NULL;
	newfirst->next = second;
	*first = newfirst;
	add_prev_list(first);
	return ("0");
}

char	*push_list_b(t_a **pile_a, t_a **pile_b)
{
	t_a	*first_b;
	t_a	*first_a;
	t_a	*last;

	if (!*pile_a)
		return (NULL);
	first_a = (*pile_a)->next;
	last = *pile_a;
	while (last->next)
		last = last->next;
	first_a->prev = last;
	first_b = *pile_a;
	first_b->next = *pile_b;
	*pile_a = first_a;
	*pile_b = first_b;
	add_prev_list(pile_b);
	add_prev_list(pile_a);
	return ("5");
}

char	*push_list_a(t_a **pile_a, t_a **pile_b)
{
	t_a	*first_b;
	t_a	*first_a;

	if (!*pile_b)
		return (NULL);
	first_a = (*pile_b)->next;
	first_b = *pile_b;
	first_b->next = *pile_a;
	*pile_b = first_a;
	*pile_a = first_b;
	add_prev_list(pile_a);
	if (!*pile_b)
		return ("4");
	else
		add_prev_list(pile_b);
	return ("4");
}
