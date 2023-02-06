/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:16:34 by kle-rest          #+#    #+#             */
/*   Updated: 2023/02/06 16:55:16 by kle-rest         ###   ########.fr       */
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

int	checkint(int *tab, int t)
{
	int	i;
	int	j;

	i = 0;
	while (i < t)
	{
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

t_a	*split_list(int *tab)
{
	t_a	*start;
	t_a	*next;
	int	i;

	i = 0;
	start = NULL;
	next = NULL;
	start = ft_lstnew_ps(tab[i]);
	if (!start)
		return (NULL);
	while (tab[++i])
	{
		next = ft_lstnew_ps(tab[i]);
		if (!next)
			return (NULL);
		ft_lstadd_back_ps(&start, next);
	}
	free(tab);
	return (start);
}

int	ft_lst_size(t_a *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

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
