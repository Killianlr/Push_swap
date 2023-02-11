/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:45:17 by kle-rest          #+#    #+#             */
/*   Updated: 2023/02/11 18:18:12 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	hub(long int *tab, int i)
{
	char	*str;
	t_a		*pile_a;
	t_a		*pile_b;
	int		med;

	str = ft_calloc_ps(1, sizeof(char));
	pile_b = NULL;
	pile_a = split_list(tab, i);
	zero_rank(pile_a);
	run_list_for_rank(pile_a);
	med = ft_lst_size(pile_a) / 2;
	if (check_rank_up(pile_a) == 0)
		return (write(1, "trop facile\n", 13));
	algo(&pile_a, &pile_b, med, str);
	print_list(pile_a);
	// printf("%s\n", sort_list_a(&pile_a, str));
	// print_list(pile_a);
	// printf("%s\n", sort_list_a(&pile_a, str));
	// print_list(pile_a);
	// printf("%s\n", sort_list_a(&pile_a, str));
	// print_list(pile_a);
	// printf("%s\n", sort_list_a(&pile_a, str));
	// print_list(pile_a);
	// printf("%s\n", sort_list_a(&pile_a, str));
	// print_list(pile_a);
	// if (ft_lst_size(pile_a) < 4)
	// 	algo_3(&pile_a);
	// else if (ft_lst_size(pile_a) < 6)
	// 	algo_5(&pile_a, &pile_b);
	// print_list(pile_a);
	// ft_free_list(pile_a);
	// ft_free_list(pile_b);
	return (0);
}

