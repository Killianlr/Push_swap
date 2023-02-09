/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:38:49 by kle-rest          #+#    #+#             */
/*   Updated: 2023/02/08 13:17:57 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	printtabchar(char ***tab)
{
	int	i;
	int	j;

	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			printf("string = %s\n", tab[j][i]);
			i++;
		}
		j++;
	}
}

void	printtabint(int *tab, int j)
{
	int	i;

	i = 0;
	while (j > 0)
	{
		printf("int = %d\n", tab[i]);
		i++;
		j--;
	}
}

void	print_list(t_a *start)
{
	if (!start)
		return ;
	while (start->next)
	{
		printf("data %d || rank %d\n", start->data, start->rank);
		start = start->next;
	}
	printf("data %d || rank %d\n", start->data, start->rank);
}
