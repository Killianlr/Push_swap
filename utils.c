/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:16:34 by kle-rest          #+#    #+#             */
/*   Updated: 2023/01/19 20:00:06 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	ft_strlentab(char ***tab)
{
	int i;
	int	j;
	int res;

	j = 0;
	res = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			i++;
			res++;
		}
		j++;
	}
	return (res);
}

int	ft_checkarg(char ***tab)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			if (checkarg(tab[j][i]) == 1)
			{
				write(2, "error\n", 7);
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	checkint(int *tab, int t)
{
	int	i;
	int j;

	i = 0;
	while (i < t)
	{
		//printf("%d\n", tab[i]);
		j = i + 1;
		if (tab[i] > 32767 || tab[i] < -32767)
		{
			write(2, "error int overload\n", 20);
			return (1);
		}
		while (j < t)
		{
			if (tab[i] == tab[j])
			{
				write(2, "error same value\n", 18);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}