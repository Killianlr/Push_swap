/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:45:17 by kle-rest          #+#    #+#             */
/*   Updated: 2023/02/09 12:51:49 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	hub(long int *tab, int i)
{
	t_a		*pile_a;
	t_a		*pile_b;

	pile_b = NULL;
	pile_a = split_list(tab, i);
	zero_rank(pile_a);
	run_list_for_rank(pile_a);
	if (ft_lst_size(pile_a) < 4)
		algo_3(&pile_a);
	else if (ft_lst_size(pile_a) < 6)
		algo_5(&pile_a, &pile_b);
	print_list(pile_a);
	// printf("%s\n", swap_a(&pile_a));
	// printf("------------\n");
	// printf("%s\n", rotate_list_a(&pile_a));
	// print_list(pile_a);
	// printf("------------\n");
	// printf("%s\n", reverse_rotate_a(&pile_a));
	// print_list(pile_a);
	// printf("------------\n");
	// printf("%s\n", push_list_b(&pile_a, &pile_b));
	// printf("==============A================\n");
	// print_list(pile_a);
	// printf("==============B================\n");
	// print_list(pile_b);
	// printf("%s\n", push_list_b(&pile_a, &pile_b));
	// printf("==============A================\n");
	// print_list(pile_a);
	// printf("==============B================\n");
	// print_list(pile_b);
	// printf("%s\n", push_list_a(&pile_a, &pile_b));
	// printf("==============A================\n");
	// print_list(pile_a);
	// printf("==============B================\n");
	// print_list(pile_b);





	// if (ft_lst_size(pile_a) < 4)
	// 	algo_3(&pile_a);
	// if (ft_lst_size(pile_a) < 9)
	// 	algo_8(pile_a);
}
