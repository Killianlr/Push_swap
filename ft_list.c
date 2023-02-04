/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:27:02 by kle-rest          #+#    #+#             */
/*   Updated: 2023/02/02 16:39:33 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

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

t_a	*swap(t_a **first)
{
	t_a	*temp;
	t_a	*second;

	if (!first || !(*first)->next)
		return (NULL);
	second = (*first)->next;
	temp = second->next;
	second->next = *first;
	(*first)->next = temp;
	return (second);
}

t_a	*rotate_list(t_a **first)
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
	return (newfirst);
}

t_a	*reverse_rotate(t_a **first)
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
	return (newfirst);
}
