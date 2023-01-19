/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:31:07 by kle-rest          #+#    #+#             */
/*   Updated: 2022/11/24 09:27:26 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*sm;

	i = 0;
	sm = malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!sm)
		return (0);
	while (s[i])
	{
		sm[i] = s[i];
		i++;
	}
	sm[i] = '\0';
	return (sm);
}

