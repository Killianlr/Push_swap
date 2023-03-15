/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:16:34 by kle-rest          #+#    #+#             */
/*   Updated: 2023/03/14 14:03:17 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	*ft_calloc_ps(int nmemb, int size)
{
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	if (!nmemb || !size)
		return (malloc(0));
	if (nmemb > 4294967295 / size)
		return (0);
	str = malloc(size * nmemb);
	if (!str)
	{
		free(str);
		return (NULL);
	}
	while (i < size * nmemb)
	{
		str[i] = 0;
		i++;
	}
	return ((void *)str);
}

char	*ft_strjoin_ps(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*len;

	i = -1;
	j = 0;
	if (!s1)
		s1 = ft_calloc(sizeof(char), 1);
	if (!s1 || !s2)
		return (NULL);
	len = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!len)
		return (NULL);
	while (s1[++i])
		len[i] = s1[i];
	while (s2[j])
		len[i++] = s2[j++];
	len[i] = '\0';
	free(s1);
	return (len);
}

long int	ft_atoi_ps(const char *nptr)
{
	int			i;
	long int	s;
	long int	nb;

	nb = 0;
	i = 0;
	s = 1;
	while ((nptr[i] == ' ') || (nptr[i] >= 7 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s = s * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb *= 10;
		nb += nptr[i] - 48;
		i++;
	}
	return (s * nb);
}

int	find_rank_max(t_a **pile)
{
	int	comp;
	int	i;
	t_a	*tmp;

	i = 1;
	comp = (*pile)->rank;
	tmp = *pile;
	while (tmp->next)
	{
		if (tmp->rank > comp)
			i = 0;
		tmp = tmp->next;
	}
	if (tmp->rank > comp)
		i = 0;
	return (i);
}

int	find_rank_min(t_a **pile)
{
	int	comp;
	int	i;
	t_a	*tmp;

	i = 1;
	comp = (*pile)->rank;
	tmp = *pile;
	while (tmp->next)
	{
		if (tmp->rank < comp)
			i = 0;
		tmp = tmp->next;
	}
	if (tmp->rank < comp)
		i = 0;
	return (i);
}
