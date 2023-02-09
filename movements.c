/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:27:02 by kle-rest          #+#    #+#             */
/*   Updated: 2023/02/09 10:46:31 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

char	*swap_a(t_a **first)
{
	t_a	*temp;
	t_a	*second;

	if (!first || !(*first)->next)
		return (NULL);
	second = (*first)->next;
	temp = second->next;
	second->next = *first;
	(*first)->next = temp;
	*first = second;
	return ("1");
}

char	*swap_b(t_a **first)
{
	t_a	*temp;
	t_a	*second;

	if (!first || !(*first)->next)
		return (NULL);
	second = (*first)->next;
	temp = second->next;
	second->next = *first;
	(*first)->next = temp;
	*first = second;
	return ("2");
}

char	*rotate_list_a(t_a **first)
{
	t_a	*tmp;
	t_a	*newfirst;

	if (!first)
		return (NULL);
	tmp = *first;
	newfirst = (*first)->next;
	while ((*first)->next)
		*first = (*first)->next;
	tmp->next = NULL;
	(*first)->next = tmp;
	*first = newfirst;
	return ("6");
}

char	*rotate_list_b(t_a **first)
{
	t_a	*tmp;
	t_a	*newfirst;

	if (!first)
		return (NULL);
	tmp = *first;
	newfirst = (*first)->next;
	while ((*first)->next)
		*first = (*first)->next;
	tmp->next = NULL;
	(*first)->next = tmp;
	*first = newfirst;
	return ("7");
}

char	*reverse_rotate_a(t_a **first)
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
	return ("9");
}
