/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:58:26 by kle-rest          #+#    #+#             */
/*   Updated: 2023/03/07 12:21:13 by kle-rest         ###   ########.fr       */
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
		// print_list_prev(pile_a);
		if (tmp->rank <= stop && tmp->rank != size)
			return (i);
		i++;
		j--;
		tmp = tmp->prev;
	}
	return (i);
}

char	*file_pile_a(t_a **pile_a, t_a **pile_b, char *str)
{
	int	i;
	int	j;

	while (ft_lst_size(*pile_b) > 1)
	{
		i = caughtmaxnext(*pile_b);
		j = caughtmaxprev(*pile_b);
		if (i < j || i == j)
		{
			while (i--)
				str = ft_strjoin_ps(str, rotate_list_b(pile_b));
			str = ft_strjoin_ps(str, push_list_a(pile_a, pile_b));
		}
		else
		{
			while (j--)
				str = ft_strjoin_ps(str, reverse_rotate_b(pile_b));
			str = ft_strjoin_ps(str, push_list_a(pile_a, pile_b));
		}
		print_list_b(*pile_b);
	}
	printf("ici\n");
	return (str);
}

char	*algo100(t_a **pile_a, t_a **pile_b, char *str)
{
	int	i;
	int	j;
	int	val;
	int	stop;
	int size;

	size = ft_lst_size(*pile_a);
	val = 0;
	while (ft_lst_size(*pile_a) > 0)
	{
		stop = val + 10;
		while (val < size && val <= stop)
		{
			i = caughtvalnext(*pile_a, stop, size);
			j = caughtvalprev(*pile_a, stop, size);
			if (ft_lst_size(*pile_a) == 1)
			{
				str = file_pile_a(pile_a, pile_b, str);
				break ;
			}
			else if (i < j || i == j)
			{
				while (i--)
					str = ft_strjoin_ps(str, rotate_list_a(pile_a));
				str = ft_strjoin_ps(str, push_list_b(pile_a, pile_b));
			}
			else
			{
				while (j--)
					str = ft_strjoin_ps(str, reverse_rotate_a(pile_a));
				str = ft_strjoin_ps(str, push_list_b(pile_a, pile_b));
			}
			val++;
		}
		if (check_rank_up(*pile_a) == 0 && ft_lst_size(*pile_b) == 1)
			break ;
	}
	print_list_a(*pile_a);
	str = ft_strjoin_ps(str, push_list_a(pile_a, pile_b));
	return (str);
}