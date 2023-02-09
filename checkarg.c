/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkarg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:56:14 by kle-rest          #+#    #+#             */
/*   Updated: 2023/02/09 11:41:24 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	ft_strlentab(char ***tab)
{
	int	i;
	int	j;
	int	res;

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
	int	i;
	int	j;

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

int	checkint(long int *tab, int t)
{
	int	i;
	int	j;

	i = 0;
	while (i < t)
	{
		j = i + 1;
		if (tab[i] > 2147483647 || tab[i] < -2147483648)
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

int	ft_checksizeint(char ***tab, int i)
{
	int	j;
	int	u;
	int	size;

	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			u = 0;
			size = 0;
			while (tab[i][j][u])
			{
				if ((tab[i][j][u] == '-') || (tab[i][j][u] == '+'))
					size++;
				u++;
			}
			if ((u - size) > 10)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
