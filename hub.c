/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:45:17 by kle-rest          #+#    #+#             */
/*   Updated: 2023/04/11 10:44:35 by kle-rest         ###   ########.fr       */
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

char	*hub4(t_a **copie, char *str, char *mem, int j)
{
	t_a	*pile_b;

	pile_b = NULL;
	add_prev_list(copie);
	str = algo(copie, &pile_b, str, j);
	if ((!mem) || ft_strlen(str) < ft_strlen(mem))
	{
		if (mem)
			free(mem);
		mem = str;
	}
	else
		free(str);
	ft_free_list(*copie);
	return (mem);
}

char	*hub3(t_a **pile_a, int k, int j, int l)
{
	t_a		*copie;
	t_a		*tmp;
	t_a		*next;
	char	*str;
	char	*mem;

	mem = NULL;
	while (j < k && j < l)
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
		mem = hub4(&copie, str, mem, j);
		j++;
	}
	return (mem);
}

char	*hub2(t_a **pile_a, char *str, int k)
{
	t_a	*pile_b;

	pile_b = NULL;
	if (ft_lst_size(*pile_a) < 4)
		str = algo_3(pile_a, str);
	else if (ft_lst_size(*pile_a) == 5)
		str = algo_5(pile_a, &pile_b, str);
	else if (ft_lst_size(*pile_a) < 151)
	{
		free(str);
		str = hub3(pile_a, k, 2, 50);
	}
	else
	{
		free(str);
		str = hub3(pile_a, k, 38, 43);
	}
	return (str);
}

int	hub(long int *tab, int i)
{
	char	*str;
	int		k;
	t_a		*pile_a;

	str = ft_calloc_ps(1, sizeof(char));
	pile_a = split_list(tab, i);
	k = ft_lst_size(pile_a) - 1;
	zero_rank(pile_a);
	run_list_for_rank(pile_a);
	add_prev_list(&pile_a);
	if (check_rank_up(pile_a) == 0)
	{
		ft_free_list(pile_a);
		free(str);
		return (0);
	}
	else
		str = hub2(&pile_a, str, k);
	print_instruction(str, 0);
	free(str);
	ft_free_list(pile_a);
	return (0);
}
