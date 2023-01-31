/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:27:02 by kle-rest          #+#    #+#             */
/*   Updated: 2023/01/31 18:29:21 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

l_a *ft_lstnew_ps(int data)
{
	l_a *new;

	new = NULL;
	new = (l_a*)malloc(sizeof(l_a));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back_ps(l_a **lst, l_a *new)
{
	l_a *temp;

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

l_a	*sa(l_a **first)
{
	l_a *temp;
	l_a *second;

	if (!first || !(*first)->next)
		return (NULL);
	second = (*first)->next;
	temp = second->next;
	second->next = *first;
	(*first)->next = temp;
	return (second);	
}

l_a *rotate_list(l_a **first)
{
	l_a *tmp;
	l_a *newfirst;

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

