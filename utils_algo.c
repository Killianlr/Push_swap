/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:56:40 by kle-rest          #+#    #+#             */
/*   Updated: 2023/03/07 14:33:20 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int		caughtmaxprev(t_a *pile_b)
{
	int	i;
	int	j;
	int	max;
	t_a *tmp;

	i = 0;
	tmp = pile_b;
	j = ft_lst_size(pile_b);
	max = ft_lst_size(pile_b);
	while (j > 0)
	{
		if (tmp->rank == max)
			return (i);
		i++;
		j--;
		tmp = tmp->prev;
	}
	return (i);
}

int		caughtmaxnext(t_a *pile_b)
{
	int	i;
	int	max;
	t_a *tmp;

	i = 0;
	tmp = pile_b;
	max = ft_lst_size(pile_b);
	while (tmp->next)
	{
		if (tmp->rank == max)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int		caughtvalnext(t_a *pile_a, int stop, int size)
{
	t_a	*tmp;
	int	i;

	i = 0;
	tmp = pile_a;
	while (tmp->next)
	{
		if (tmp->rank < stop && tmp->rank != size)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int		caughtvalprev(t_a *pile_a, int stop, int size)
{
	t_a	*tmp;
	int	i;
	int	j;

	i = 0;
	tmp = pile_a;
	j = ft_lst_size(pile_a);
	while (j > 0)
	{
		if (tmp->rank <= stop && tmp->rank != size)
			return (i);
		i++;
		j--;
		tmp = tmp->prev;
	}
	return (i);
}

char *split_push(t_a **pile_a, t_a **pile_b, char *str, int med)
{
	if (ft_lst_size(*pile_a) % 2 == 1)
		med += 1;
	while (ft_lst_size(*pile_b) < med)
	{
		if ((*pile_a)->rank <= med)
			str = ft_strjoin_ps(str, push_list_b(pile_a, pile_b));
		else if (med >= find_med(*pile_a, med))
			str = ft_strjoin_ps(str, rotate_list_a(pile_a));
		else if (med <= find_med(*pile_a, med))
			str = ft_strjoin_ps(str, reverse_rotate_a(pile_a));
	}
	return (str);
}
