/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:19:06 by kle-rest          #+#    #+#             */
/*   Updated: 2023/02/11 18:22:36 by kle-rest         ###   ########.fr       */
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

char	*sort_list_a(t_a **pile, char *str)
{
	//int	med;
	t_a	*first;
	t_a	*second;
	int	last;

	//med = ft_lst_size(*pile) / 2;
	first = *pile;
	second = first->next;
	last = get_last_list(first);
	if (first->rank > second->rank)
		return (swap_a(pile));
	else if (first->rank > last && check_str_last(str) != '6')
		return (reverse_rotate_a(pile));
	return (rotate_list_a(pile));


	// if (first->rank > second->rank && last < second->rank)
	// 	return (swap_a(pile));
	// else if (med < check_rank_up(*pile))
	// 	return (rotate_list_a(pile));
	// else if (med >= check_rank_up(*pile))
	// 	return (reverse_rotate_a(pile));
	// else
	// 	return ("a");
}

char	*sort_list_b(t_a **pile, char *str)
{
	// int	med;
	t_a	*first;
	t_a	*second;
	int	last;

	// med = ft_lst_size(*pile) / 2;
	first = *pile;
	second = first->next;
	last = get_last_list(first);
	// printf("ici\n");
	printf("str = %s\n", str);
	if (first->rank < second->rank)
		return (swap_b(pile));
	else if (first->rank < last && check_str_last(str) != '7')
		return (reverse_rotate_b(pile));
	return (rotate_list_b(pile));


	// else if (med < check_rank_down(*pile))
	// 	return (rotate_list_b(pile));
	// else if (med >= check_rank_down(*pile))
	// 	return (reverse_rotate_b(pile));
	// else
	// 	return ("b");
}

char *split_push(t_a **pile_a, t_a **pile_b, char *str, int med)
{
	if (ft_lst_size(*pile_a) % 2 == 1)
		med += 1;
	while (ft_lst_size(*pile_a) > med)
	{
		printf("ici\n");
		printf("lst size pile_a %d med %d", ft_lst_size(*pile_a), med);
		if ((*pile_a)->rank <= med)
			str = ft_strjoin_ps(str, push_list_b(pile_a, pile_b));
		else if (med >= find_med(*pile_a, med))
			str = ft_strjoin_ps(str, rotate_list_a(pile_a));
		else if (med <= find_med(*pile_a, med))
			str = ft_strjoin_ps(str, reverse_rotate_a(pile_a));
		//printf("ici\n");
	}
	return (str);
}

void	algo(t_a **pile_a, t_a **pile_b, int med, char *str)
{
	int	i;

	i = 0;
	//printf("med = %d\n", med);
	str = split_push(pile_a, pile_b, str, med);
	// str = ft_strjoin_ps(str, split_push(pile_a, pile_b, str, med));
	printf("str = %s\n", str);
	print_list(*pile_a);
	print_list(*pile_b);
	while ((ft_lst_size(*pile_b) > 0) || (check_rank_up(*pile_a) > 0))
	{
		print_list(*pile_a);
		print_list(*pile_b);
		// printf("str = %s\n", str);
		if ((check_rank_up(*pile_a) > 0 && ft_strlen(str) % 2 == 0)
			|| (check_rank_up(*pile_a) > 0 && check_rank_down(*pile_b) == 0))
			str = ft_strjoin_ps(str, sort_list_a(pile_a, str));
		// printf("ici\n");
		if ((check_rank_down(*pile_b) > 0 && ft_strlen(str) % 2 == 1)
			|| (check_rank_down(*pile_b) > 0 && check_rank_up(*pile_a) == 0))
			str = ft_strjoin_ps(str, sort_list_b(pile_b, str));
		if (check_rank_down(*pile_b) == 0 && check_rank_up(*pile_a) == 0)
		{
			while (ft_lst_size(*pile_b) > 0)
				str = ft_strjoin_ps(str, push_list_a(pile_a, pile_b));
		}
	}
	// print_list(*pile_a);
	// print_list(*pile_b);
	print_instruction(str, 0);
	free(str);
}
