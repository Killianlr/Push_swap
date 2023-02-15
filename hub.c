/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:45:17 by kle-rest          #+#    #+#             */
/*   Updated: 2023/02/15 17:17:08 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	hub(long int *tab, int i)
{
	char	*str;
	t_a		*pile_a;
	t_a		*pile_b;
	// int		med;

	str = ft_calloc_ps(1, sizeof(char));
	pile_b = NULL;
	pile_a = split_list(tab, i);
	zero_rank(pile_a);
	run_list_for_rank(pile_a);
	add_prev_list(&pile_a);
	print_list_prev(pile_a);
	// med = ft_lst_size(pile_a) / 2;
	// if (check_rank_up(pile_a) == 0)
	// 	return (write(1, "trop facile\n", 13));
	// if (ft_lst_size(pile_a) < 4)
	// 	str = algo_3(&pile_a, str);
	// else if (ft_lst_size(pile_a) == 5)
	// 	str = algo_5(&pile_a, &pile_b, str);
	// else if (ft_lst_size(pile_a) == 6)
	// 	str = algo_6(&pile_a, &pile_b, med, str);
	// else
	// 	str = algo(&pile_a, &pile_b, med, str);
	print_list_a(pile_a);
	// printf("str = %s\n", str);
	// print_instruction(str, 0);
	// free(str);
	// ft_free_list(pile_a);
	// printf("%s\n", sort_list_a(&pile_a, str));
	// print_list(pile_a);
	// printf("%s\n", sort_list_a(&pile_a, str));
	// print_list(pile_a);
	// printf("%s\n", sort_list_a(&pile_a, str));
	/////////////// print_list(pile_a);
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

