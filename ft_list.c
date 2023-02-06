/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:27:02 by kle-rest          #+#    #+#             */
/*   Updated: 2023/02/06 18:08:58 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	swap(t_a **first)
{
	t_a	*temp;
	t_a	*second;

	// if (!first || !(*first)->next)
	// 	return (NULL);
	second = (*first)->next;
	temp = second->next;
	second->next = *first;
	(*first)->next = temp;
	*first = second;
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

t_a	*push_list(t_a **first_a, t_a **first_b)
{
	t_a	*tmp;

	if (!first_a || !first_b)
		return (NULL);
	tmp = *first_a;
	*first_a = (*first_a)->next;
	tmp->next = *first_b;
	return (tmp);
}

// int	main(void)
// {
// 	t_a *pile_a;
// 	t_a *pile_b;
// 	int i;
// 	int j;
// 	t_a *save_a;
// 	t_a *save_b;

// 	i = 5;
// 	j = 80;
// 	pile_a = ft_lstnew_ps(i);
// 	pile_b = ft_lstnew_ps(j);
// 	save_a = pile_a;
// 	save_b = pile_b;
// 	while (i > 0)
// 	{
// 		j--;
// 		i--;
// 		ft_lstadd_back_ps(&pile_a, ft_lstnew_ps(i));
// 		ft_lstadd_back_ps(&pile_b, ft_lstnew_ps(j));
// 	}
// 	print_list(save_a);
// 	printf("------------\n");
// 	print_list(save_b);
// 	save_b = push_list(&save_a, &save_b);
// 	printf("------------\n");
// 	print_list(save_a);
// 	printf("------------\n");
// 	print_list(save_b);
// }
