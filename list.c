/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:44:05 by kle-rest          #+#    #+#             */
/*   Updated: 2023/02/15 17:20:43 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ft_free_list(t_a *pile_a)
{
	t_a	*tmp;
	t_a *first;

	if (!pile_a)
		return ;
	first = pile_a;
	while (first)
	{
		tmp = first;
		first = first->next;
		free(tmp);
	}
}

int	ft_lst_size(t_a *lst)
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

t_a	*ft_lstnew_ps(int data)
{
	t_a	*new;

	new = NULL;
	new = (t_a *)malloc(sizeof(t_a));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
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

void	add_prev_list(t_a **lst)
{
	t_a	*tmp1;
	t_a *tmp2;

	tmp1 = *lst;
	tmp2 = *lst;
	while (tmp2->next)
	{
		tmp2 = tmp2->next;
		tmp2->prev = tmp1;
		tmp1 = tmp1->next;
	}
	printf("ici\n");
	//tmp2->next = *lst;
	//tmp2 = tmp2->next;
	//tmp2->prev = tmp1;
	(*lst)->prev = tmp2;
}

t_a	*split_list(long *tab, int j)
{
	t_a	*start;
	t_a	*next;
	int	i;

	i = 1;
	start = NULL;
	next = NULL;
	start = ft_lstnew_ps(tab[0]);
	if (!start)
		return (NULL);
	while (j--)
	{
		next = ft_lstnew_ps(tab[i]);
		if (!next)
			return (NULL);
		ft_lstadd_back_ps(&start, next);
		i++;
	}
	free(tab);
	return (start);
}
