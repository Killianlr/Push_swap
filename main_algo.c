/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:58:26 by kle-rest          #+#    #+#             */
/*   Updated: 2023/03/31 13:25:31 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

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
	}
	return (str);
}

char	*littlesort(t_a **pile_a, t_a **pile_b, char *str)
{
	t_a	*tmpa;
	t_a	*tmpb;

	tmpa = (*pile_a)->next;
	tmpb = (*pile_b)->next;
	if ((*pile_a)->rank == tmpa->rank + 1)
		str = ft_strjoin_ps(str, swap_a(pile_a));
	if ((*pile_b)->rank == tmpb->rank - 1)
		str = ft_strjoin_ps(str, swap_b(pile_b));
	return (str);
}

char	*next(t_a **pile_a, t_a **pile_b, int stop, char *str)
{
	int	i;
	int	j;
	int	size;

	size = ft_lst_size(*pile_a) + ft_lst_size(*pile_b);
	if (size < 150 && ft_lst_size(*pile_a) > 2 && ft_lst_size(*pile_b) > 2)
		str = littlesort(pile_a, pile_b, str);
	i = caughtvalnext(*pile_a, stop);
	j = caughtvalprev(*pile_a, stop);
	if (i == ft_lst_size(*pile_a) || j == ft_lst_size(*pile_a))
		str = ft_strjoin_ps(str, push_list_b(pile_a, pile_b));
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
	return (str);
}

char	*algo(t_a **pile_a, t_a **pile_b, char *str, int interval)
{
	int	val;
	int	stop;
	int	size;

	size = ft_lst_size(*pile_a);
	val = 1;
	while (ft_lst_size(*pile_a) > 0)
	{
		stop = val + interval;
		while (val < stop)
		{
			if (ft_lst_size(*pile_a) == 1)
			{
				str = file_pile_a(pile_a, pile_b, str);
				break ;
			}
			else
				str = next(pile_a, pile_b, stop, str);
			val++;
		}
		if (check_rank_up(*pile_a) == 0 && ft_lst_size(*pile_b) == 1)
			break ;
	}
	str = ft_strjoin_ps(str, push_list_a(pile_a, pile_b));
	return (str);
}
