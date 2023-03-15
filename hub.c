/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:45:17 by kle-rest          #+#    #+#             */
/*   Updated: 2023/03/15 15:43:04 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

t_a	*ft_copie(int rank)
{
	t_a	*copie;

	copie = NULL;
	copie = (t_a *)malloc(sizeof(t_a));
	if (!copie)
		return (NULL);
	copie->rank = rank;
	copie->next = NULL;
	copie->prev = NULL;
	return (copie);
}

char	*hub2(t_a **pile_a, t_a **pile_b, int k)
{
	t_a		*copie;
	t_a		*tmp;
	t_a 	*next;
	char	*str;
	char	*mem;
	int		j;

	j = 0;
	mem = NULL;
	while (j < k && j < 60) //25 - 60 
	{
		str = ft_calloc_ps(1, sizeof(char));
		tmp = *pile_a;
		copie = ft_copie(tmp->rank);
		tmp = tmp->next;
		while (k--)
		{
			next = ft_copie(tmp->rank);
			ft_lstadd_back_ps(&copie, next);
			tmp = tmp->next;
		}
		k = ft_lst_size(*pile_a) - 1;
		add_prev_list(&copie);
		// print_list_a(copie);
		str = algo100(&copie, pile_b, str, j);
		// print_list_a(copie);
		printf(" j = %d size str = %zu\n", j, ft_strlen(str));
		if ((!mem) || ft_strlen(str) < ft_strlen(mem))
		{
			if (mem)
				free(mem);
			mem = str;
		}
		else
			free(str);
		j++;
		ft_free_list(copie);
	}
	printf("size mem = %zu\n", ft_strlen(mem));
	return (mem);
}

int	hub(long int *tab, int i)
{
	char	*str;
	int		k;
	t_a		*pile_a;
	t_a		*pile_b;

	str = ft_calloc_ps(1, sizeof(char));
	pile_b = NULL;
	pile_a = split_list(tab, i);
	k = ft_lst_size(pile_a) - 1;
	zero_rank(pile_a);
	run_list_for_rank(pile_a);
	add_prev_list(&pile_a);
	if (check_rank_up(pile_a) == 0)
		return (write(1, "trop facile\n", 13));
	if (ft_lst_size(pile_a) < 4)
		str = algo_3(&pile_a, str);
	else if (ft_lst_size(pile_a) == 5)
		str = algo_5(&pile_a, &pile_b, str);
	else
	{
		free(str);
		str = hub2(&pile_a, &pile_b, k);
	}
	// str = algo_5(&copie, &pile_b, str);
	// print_list_a(pile_a);
	// else if (ft_lst_size(pile_a) < 101)
	// 	print_list_a(ft_copie(pile_a));
	// {			
	// 	while (k < 60)
	// 	{
	// 		copie = ft_copie(pile_a);
	// 		pile_b = NULL;
	// 		str = algo100(&cop_a, &pile_b, str, k);
	// 		if (!mem || (mem && ft_strlen(mem) > ft_strlen(str)))
	// 		{
	// 			mem = malloc(ft_strlen(str) + 1);
	// 			size = ft_strlen(str);
	// 			for (int i = 0; i <= size; i++)
	// 				mem[i] = str[i];
	// 			str = ft_calloc_ps(1, sizeof(char));
	// 		}
	// 		k++;
	// 		free(str);
	// 	}
	// 	str = mem;
	// }
	// else if (ft_lst_size(pile_a) < 501)
	// 	str = algo100(&pile_a, &pile_b, str, 40);
	// // str = new_algo_100(&pile_a, &pile_b, str);
	// // print_list_a(cop_a);
	// // print_list_b(pile_b);
	// print_instruction(str, 0);
	// printf("size pile = %d\n", ft_lst_size(pile_a));
	free(str);
	ft_free_list(pile_a);
	return (0);
}
 