/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:38:05 by kle-rest          #+#    #+#             */
/*   Updated: 2022/12/16 13:38:13 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_reverse(char *nb, int c)
{
	char temp;
	int i;

	i = 0;
	while (i < c / 2)
	{
		temp = nb[i];
		nb[i] = nb[c - i - 1];
		nb[c - i - 1] = temp;
		i++;
	}
	return (nb);
}
