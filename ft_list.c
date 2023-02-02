/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:27:02 by kle-rest          #+#    #+#             */
/*   Updated: 2023/02/02 13:57:02 by kle-rest         ###   ########.fr       */
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

l_a	*swap(l_a **first)
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

int	ft_lst_size(l_a *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

l_a	*reverse_rotate(l_a **first)
{
	l_a *second;
	l_a *newfirst;
	
	if (!first)
		return (NULL);
	second = *first;
	while (2 < ft_lst_size(*first))
	{
		*first = (*first)->next;
		printf("lst size : %d\n", ft_lst_size(*first));
	}
	newfirst = (*first)->next;
	(*first)->next = NULL;
	newfirst->next = second;
	return (newfirst);
}

