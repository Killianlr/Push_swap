/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_new_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:58:14 by kle-rest          #+#    #+#             */
/*   Updated: 2023/03/07 14:28:48 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	get_last_list(t_a *first)
{
	while(first->next)
		first = first->next;
	return (first->rank);
}

char	check_str_last(char	*str)
{
	int	i;

	if (!str)
		return (0);
	i = ft_strlen(str) - 1;
	return (str[i]);
}

char	*reverse_order(t_a **pile, char *str)
{
	int	i;

	i = ft_lst_size(*pile);
	if (i == 2)
		return (str = ft_strjoin_ps(str, swap_a(pile)));
	while (i > 0)
	{
		str = ft_strjoin_ps(str, swap_a(pile));
		i--;
		if (i > 0)
		{
			str = ft_strjoin_ps(str, reverse_rotate_a(pile));
			i--;
			if (i > 0)
			{
				str = ft_strjoin_ps(str, reverse_rotate_a(pile));
				i--;
			}
		}
	}
	return (str);
}

char	*sort_list_a(t_a **pile_a, t_a **pile_b, char *str)
{
	t_a	*first;
	t_a	*second;
	int	last;
	int	i;

	i = 0;
	first = *pile_a;
	second = first->next;
	last = get_last_list(first);
	if (check_rank_down(*pile_b) == 0 && find_rank_min(pile_a) == 1)
		return (push_list_b(pile_a, pile_b));
	// else if (first->rank < last)
	// 	return (rotate_list_a(pile_a));
	else if (first->rank > second->rank)
		return (swap_a(pile_a));
	else if (first->rank > last && check_str_last(str) != '6')
		return (reverse_rotate_a(pile_a));
	return (reverse_rotate_a(pile_a));
}

char	*sort_list_b(t_a **pile_a, t_a **pile_b, char *str)
{
	t_a	*first;
	t_a	*second;
	int	last;

	first = *pile_b;
	second = first->next;
	last = get_last_list(first);
	if (check_rank_up(*pile_a) == 0 && find_rank_max(pile_b) == 1)
		return (push_list_a(pile_a, pile_b));
	else if (first->rank < second->rank)
		return (swap_b(pile_b));
	else if (first->rank < last && check_str_last(str) != '7')
		return (reverse_rotate_b(pile_b));
	return (reverse_rotate_b(pile_b));
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

char	*algo(t_a **pile_a, t_a **pile_b, int med, char *str)
{
	str = split_push(pile_a, pile_b, str, med);
	while ((ft_lst_size(*pile_b) > 0) || (check_rank_up(*pile_a) > 0))
	{
		if (check_rank_down(*pile_a) == 0)
			str = reverse_order(pile_a, str);
		else if (check_rank_up(*pile_b) == 0)
			str = reverse_order(pile_b, str);
		else if ((check_rank_up(*pile_a) > 0 && ft_strlen(str) % 2 == 0)
			|| (check_rank_up(*pile_a) > 0 && check_rank_down(*pile_b) == 0))
			str = ft_strjoin_ps(str, sort_list_a(pile_a, pile_b, str));
		else if ((check_rank_down(*pile_b) > 0 && ft_strlen(str) % 2 == 1)
			|| (check_rank_down(*pile_b) > 0 && check_rank_up(*pile_a) == 0))
			str = ft_strjoin_ps(str, sort_list_b(pile_a, pile_b, str));
		else if (check_rank_down(*pile_b) == 0 && check_rank_up(*pile_a) == 0)
		{
			while (ft_lst_size(*pile_b) > 0)
				str = ft_strjoin_ps(str, push_list_a(pile_a, pile_b));
		}
	}
	return (str);
}
