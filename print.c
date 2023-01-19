/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:38:49 by kle-rest          #+#    #+#             */
/*   Updated: 2023/01/19 19:54:37 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	printtabchar(char ***tab)
{
	int i;
	int j;

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
	int i;

	i = 0;
	while (j > 0)
	{
		printf("int = %d\n", tab[i]);
		i++;
		j--;
	}
}