/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:45:17 by kle-rest          #+#    #+#             */
/*   Updated: 2023/02/06 18:03:18 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	hub(int *tab)
{
	t_a		*pile;

	pile = split_list(tab);
	zero_rank(pile);
	run_list_for_rank(pile);
	print_list(pile);
	printf("%d\n", ft_lst_size(pile));
	// swap(&pile);
	// printf("------------\n");
	// print_list(pile);
	// if (ft_lst_size(pile) < 4)
	// 	algo_3(&pile);
	// if (ft_lst_size(pile) < 9)
	// 	algo_8(pile);
}

// void	algo_3(t_a **pile)
// {
// 	t_a *tmp;

// 	tmp = pile;
// 	if (tmp->rank == 3)
		
// }
