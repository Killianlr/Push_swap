// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   new_algo.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/02/09 16:19:06 by kle-rest          #+#    #+#             */
// /*   Updated: 2023/02/14 16:36:03 by kle-rest         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "Push_swap.h"

// int	get_last_list(t_a *first)
// {
// 	while(first->next)
// 		first = first->next;
// 	return (first->rank);
// }

// char	check_str_last(char	*str)
// {
// 	int	i;

// 	if (!str)
// 		return (0);
// 	i = ft_strlen(str) - 1;
// 	return (str[i]);
// }

// char	*reverse_order(t_a **pile, char *str)
// {
// 	int	i;

// 	i = ft_lst_size(*pile);
// 	if (i == 2)
// 		return (str = ft_strjoin_ps(str, swap_a(pile)));
// 	while (i > 0)
// 	{
// 		str = ft_strjoin_ps(str, swap_a(pile));
// 		i--;
// 		if (i > 0)
// 		{
// 			str = ft_strjoin_ps(str, reverse_rotate_a(pile));
// 			i--;
// 			if (i > 0)
// 			{
// 				str = ft_strjoin_ps(str, reverse_rotate_a(pile));
// 				i--;
// 			}
// 		}
// 	}
// 	return (str);
// }

// char	*sort_list_a(t_a **pile, char *str)
// {
// 	t_a	*first;
// 	t_a	*second;
// 	int	last;
// 	int	i;

// 	i = 0;
// 	first = *pile;
// 	second = first->next;
// 	last = get_last_list(first);
// 	if (first->rank > second->rank)
// 		return (swap_a(pile));
// 	else if (first->rank > last && check_str_last(str) != '6')
// 		return (reverse_rotate_a(pile));
// 	return (rotate_list_a(pile));
// }

// char	*sort_list_b(t_a **pile, char *str)
// {
// 	// int	med;
// 	t_a	*first;
// 	t_a	*second;
// 	int	last;

// 	// med = ft_lst_size(*pile) / 2;
// 	first = *pile;
// 	second = first->next;
// 	last = get_last_list(first);
// 	print_list_b(*pile);
// 	if (first->rank < second->rank)
// 		return (swap_b(pile));
// 	else if (first->rank < last && check_str_last(str) != '7')
// 		return (reverse_rotate_b(pile));
// 	return (rotate_list_b(pile));
// }

// char *split_push(t_a **pile_a, t_a **pile_b, char *str, int med)
// {
// 	if (ft_lst_size(*pile_a) % 2 == 1)
// 		med += 1;
// 	while (ft_lst_size(*pile_b) < med)
// 	{
// 		if ((*pile_a)->rank <= med)
// 			str = ft_strjoin_ps(str, push_list_b(pile_a, pile_b));
// 		else if (med >= find_med(*pile_a, med))
// 			str = ft_strjoin_ps(str, rotate_list_a(pile_a));
// 		else if (med <= find_med(*pile_a, med))
// 			str = ft_strjoin_ps(str, reverse_rotate_a(pile_a));
// 	}
// 	print_list_a(*pile_a), print_list_b(*pile_b);
// 	// printf("str = %s\n", str);
// 	return (str);
// }

// void	algo(t_a **pile_a, t_a **pile_b, int med, char *str)
// {
// 	str = split_push(pile_a, pile_b, str, med);
// 	if (ft_lst_size(*pile_a) == 3)
// 		str = ft_strjoin_ps(str, algo_3(pile_a));
// 	else if (ft_lst_size(*pile_b) == 3)
// 		str = ft_strjoin_ps(str, reverse_algo_3(pile_b));
// 	while ((ft_lst_size(*pile_b) > 0) || (check_rank_up(*pile_a) > 0))
// 	{
// 		if (check_rank_down(*pile_a) == 0)
// 			str = ft_strjoin(str, reverse_order(pile_a, str));
// 		else if (check_rank_up(*pile_b) == 0)
// 			str = ft_strjoin(str, reverse_order(pile_b, str));
// 		else if ((check_rank_up(*pile_a) > 0 && ft_strlen(str) % 2 == 0)
// 			|| (check_rank_up(*pile_a) > 0 && check_rank_down(*pile_b) == 0))
// 			str = ft_strjoin_ps(str, sort_list_a(pile_a, str));
// 		else if ((check_rank_down(*pile_b) > 0 && ft_strlen(str) % 2 == 1)
// 			|| (check_rank_down(*pile_b) > 0 && check_rank_up(*pile_a) == 0))
// 			str = ft_strjoin_ps(str, sort_list_b(pile_b, str));
// 		else if (check_rank_down(*pile_b) == 0 && check_rank_up(*pile_a) == 0)
// 		{
// 			while (ft_lst_size(*pile_b) > 0)
// 				str = ft_strjoin_ps(str, push_list_a(pile_a, pile_b));
// 		}
// 	}
// 	print_instruction(str, 0);
// 	free(str);
// }
