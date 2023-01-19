/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:16:34 by kle-rest          #+#    #+#             */
/*   Updated: 2023/01/19 16:38:34 by kle-rest         ###   ########.fr       */
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
	printf("malloc = %d\n", res);
	return (res);
}