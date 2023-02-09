/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:19:06 by kle-rest          #+#    #+#             */
/*   Updated: 2023/02/09 18:44:09 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	get_last_list(t_a *first)
{
	while(first->next)
		first = first->next;
	return (first->rank);
}

int	check_str_a_b(char	*str)
{
	int	i;

	if (!str)
		return (0);
	i = ft_strlen(str) - 1;
	// printf("str = %s, str[i] = %c\n", str, str[i]);
	if (str[i] == 'a')
		return (1);
	else if (str[i] == 'b')
		return (0);
	else
		return (0);
}

char	*sort_list_a(t_a **pile)
{
	int	med;
	t_a	*first;
	t_a	*second;
	int	last;

	med = ft_lst_size(*pile) / 2;
	first = *pile;
	second = first->next;
	last = get_last_list(first);
	if (first->rank > second->rank)
		return (swap_a(pile));
	else if (med < check_rank_up(*pile))
		return (rotate_list_a(pile));
	// else if (med >= check_rank_up(*pile))
	// 	return (reverse_rotate_a(pile));
	else
		return ("a");
}

char	*sort_list_b(t_a **pile)
{
	int	med;
	t_a	*first;
	t_a	*second;
	int	last;

	med = ft_lst_size(*pile) / 2;
	first = *pile;
	second = first->next;
	last = get_last_list(first);
	printf("ici\n");
	if (first->rank < second->rank)
		return (swap_b(pile));
	else if (med < check_rank_down(*pile))
		return (rotate_list_b(pile));
	// else if (med >= check_rank_down(*pile))
	// 	return (reverse_rotate_b(pile));
	else
		return ("b");
}

void	algo(t_a **pile_a, t_a **pile_b, int med, char *str)
{
	int	i;

	i = 0;
	while (i <= med)
	{
		str = ft_strjoin_ps(str, push_list_b(pile_a, pile_b));
		i++;
	}
	while ((ft_lst_size(*pile_b) > 0) || (check_rank_up(*pile_a) > 0))
	{
		print_list(*pile_a);
		// print_list(*pile_b);
		// printf("str = %s\n", str);
		if ((check_rank_up(*pile_a) > 0 && check_str_a_b(str) == 0)
			|| (check_rank_up(*pile_a) > 0 && check_rank_down(*pile_b) == 0))
			str = ft_strjoin_ps(str, sort_list_a(pile_a));
		// printf("ici\n");
		if ((check_rank_down(*pile_b) > 0 && check_str_a_b(str) == 1)
			|| (check_rank_down(*pile_b) > 0 && check_rank_up(*pile_a) == 0))
			str = ft_strjoin_ps(str, sort_list_b(pile_b));
		if (check_rank_down(*pile_b) == 0 && check_rank_up(*pile_a) == 0)
		{
			while (ft_lst_size(*pile_b) > 0)
				str = ft_strjoin_ps(str, push_list_a(pile_a, pile_b));
		}
	}
	print_instruction(str, 0);
	free(str);
}
