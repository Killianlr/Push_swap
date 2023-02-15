/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:38:49 by kle-rest          #+#    #+#             */
/*   Updated: 2023/02/15 17:21:26 by kle-rest         ###   ########.fr       */
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

void	print_list_a(t_a *start)
{
	if (!start)
		return ;
	printf("-------A-------\n");
	while (start->next)
	{
		printf("--- rank %d ---\n", start->rank);
		start = start->next;
	}
	printf("--- rank %d ---\n", start->rank);
	printf("-------A-------\n");
}

void	print_list_b(t_a *start)
{
	if (!start)
		return ;
	printf("=======B=======\n");
	while (start->next)
	{
		printf("=== rank %d ===\n", start->rank);
		start = start->next;
	}
	printf("=== rank %d ===\n", start->rank);
	printf("=======B=======\n");
}

void	print_list_prev(t_a *start)
{
	int	i;

	i = ft_lst_size(start);
	if (!start)
		return ;
	printf("-------prev-------\n");
	while (i > 0)
	{
		printf("--- rank %d ---\n", start->rank);
		start = start->prev;
		i--;
	}
	printf("-------prev-------\n");
}