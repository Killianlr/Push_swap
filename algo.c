/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:23:52 by kle-rest          #+#    #+#             */
/*   Updated: 2023/02/04 17:21:42 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int find_median(t_a **pile)
{
	int i;
	int j;
	t_a *first;
	t_a *compare;

	i = 0;
	j = 0;
	first = *pile;
	while (first->next)
	{
		compare = first;
		printf("first %d\n", first->data);
		while (compare->next)
		{
		printf("compare %d\n", compare->data);
			if (compare->data > first->data)
				i += 1; 
			else if (compare->data < first->data)
				j += 1;
			compare = compare->next;
		// printf("i = %d; ", i);
		// printf("j = %d; ", j);
		}
		if (j == i) // la mediane
			return (first->data);
		else if (j - i == 1 || j - i == -1)
			return (first->data);
		j = 0;
		i = 0;
		first = first->next;
	}
	return (0);
}