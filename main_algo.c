// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main_algo.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/03/01 09:58:26 by kle-rest          #+#    #+#             */
// /*   Updated: 2023/03/03 14:16:37 by kle-rest         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "Push_swap.h"

// int		nearupmednext(t_a *pile_a, int med)
// {
// 	t_a	*tmp;
// 	int	i;

// 	i = 0;
// 	tmp = pile_a;
// 	while (tmp->next)
// 	{
// 		if (tmp->rank < med)
// 			return (i);
// 		i++;
// 		tmp = tmp->next;
// 	}
// 	return (i);
// }

// int		nearupmedprev(t_a *pile_a, int med)
// {
// 	t_a	*tmp;
// 	int	i;

// 	i = 0;
// 	tmp = pile_a;
// 	while (tmp->prev)
// 	{
// 		if (tmp->rank <= med)
// 			return (i);
// 		i++;
// 		tmp = tmp->prev;
// 	}
// 	return (i);
// }

// char	*algo100(t_a **pile_a, t_a **pile_b, char *str, int med)
// {
// 	int	i;
// 	int	j;
// 	int	val;
// 	int	stop;

// 	// print_list_a(*pile_a);
// 	// print_list_b(*pile_b);
// 	while (check_rank_up(pile_a) > 0)
// 	{
// 		i = nearupmednext(*pile_a, med);
// 		printf("i = %d\n", i);
// 		j = nearupmedprev(*pile_a, med);
// 		printf("j = %d\n", j);
// 		if (i < j || i == j)
// 		{
// 			printf("next\n");
// 			while (i--)
// 				str = ft_strjoin_ps(str, rotate_list_a(pile_a));
// 			str = ft_strjoin_ps(str, push_list_b(pile_a, pile_b));
// 			// print_list_a(*pile_a);
// 			// print_list_prev(*pile_a);
// 			// printf("--------B------\n");
// 			// print_list_b(*pile_b);
// 			// print_list_prev(*pile_b);
// 			// printf("-------A-------\n");
// 		}
// 		else
// 		{
// 			while (j--)
// 			{
// 				str = ft_strjoin_ps(str, reverse_rotate_a(pile_a));
// 				print_list_a(*pile_a);
// 			}
// 			str = ft_strjoin_ps(str, push_list_b(pile_a, pile_b));
// 			// print_list_a(*pile_a);
// 			// print_list_prev(*pile_a);
// 			// printf("-------B-------\n");
// 			// print_list_b(*pile_b);
// 			// print_list_prev(*pile_b);
// 			// printf("-------A-------\n");
// 		}
// 		// if (ft_lst_size(pile_b) > 2)
// 		// 	str = ft_strjoin_ps(str, preliminaire_check_b(pile_b));
// 	}
// 	return (str);
// }

// char	*swap_a(t_a **first)
// {
// 	t_a	*temp;
// 	t_a	*second;
// 	t_a *tmp;

// 	if (!first || !(*first)->next)
// 		return (NULL);
// 	tmp = (*first);
// 	second = (*first)->next;
// 	temp = second->next;
// 	(*first)->prev = second;
// 	second->next = *first;
// 	(*first)->next = temp;
// 	while (tmp->next)
// 		tmp = tmp->next;
// 	second->prev = tmp;
// 	*first = second;
// 	printf("sa\n");
// 	return ("1");
// }