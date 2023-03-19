/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:58:00 by kle-rest          #+#    #+#             */
/*   Updated: 2023/03/13 12:47:23 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	findmedprev(t_a *pile_a, int med)
{
	int	i;
	int j;
	t_a *tmp;

	i = 0;
	j = ft_lst_size(pile_a);
	tmp = pile_a;
	while (j > 0)
	{
		if (tmp->rank <= med)
			return (i);
		i++;
		j--;
		tmp = tmp->prev;
	}
	return (0);
}

int	findmednext(t_a *pile_a, int med)
{
	int	i;
	t_a *tmp;

	i = 0;
	tmp = pile_a;
	while (tmp->next)
	{
		if (tmp->rank <= med)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

char	*file_b(t_a **pile_a, t_a **pile_b, char *str, int med, int size)
{
	int	i;
	int j;
	
	while (size / 2 < ft_lst_size(*pile_a))
	{
		i = findmednext(*pile_a, med);
		j = findmedprev(*pile_a, med);
		// printf("i = %d, j = %d\n", i, j);
		// printf("lst_size = %d\n", ft_lst_size(*pile_a));
		// print_list_a(*pile_a);
		// print_list_b(*pile_b);
		if (i <= j)
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
	}
	return (str);
}

int	find_max_prev(t_a *pile_a, int size)
{
	int	i;
	int	j;
	t_a	*tmp;

	i = 0;
	j = ft_lst_size(pile_a);
	tmp = pile_a;
	while (j > 0)
	{
		if (tmp->rank == size)
			return (i);
		i++;
		j--;
		tmp = tmp->prev;
	}
	return (i);	
}

int	find_max_next(t_a *pile_a, int size)
{
	int	i;
	t_a	*tmp;

	i = 0;
	tmp = pile_a;
	while (tmp->next)
	{
		if (tmp->rank == size)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	find_min_next(t_a *pile_b)
{
	int	i;
	t_a	*tmp;

	i = 0;
	tmp = pile_b;
	while (tmp->next)
	{
		if (tmp->rank == 1)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	find_min_prev(t_a *pile_b)
{
	int	i;
	int	j;
	t_a	*tmp;

	i = 0;
	j = ft_lst_size(pile_b);
	tmp = pile_b;
	while (j > 0)
	{
		if (tmp->rank == 1)
			return (i);
		i++;
		j--;
		tmp = tmp->prev;
	}
	return (i);
}

char	*set_pointer_part2(t_a **pile_a, t_a **pile_b, char *str, int norp, int size)
{
	while (norp == 1)
	{
		if ((*pile_a)->rank != size)
			str = ft_strjoin_ps(str, rotate_list_a(pile_a));//next	
		if ((*pile_b)->rank != 1)
			str = ft_strjoin_ps(str, rotate_list_b(pile_b));
		if ((*pile_a)->rank == size && (*pile_b)->rank == 1)
			norp = 3;
	}
	while (norp == 2)
	{
		if ((*pile_a)->rank != size)
			str = ft_strjoin_ps(str, reverse_rotate_a(pile_a));
		if ((*pile_b)->rank != 1)
			str = ft_strjoin_ps(str, reverse_rotate_b(pile_b));
		if ((*pile_a)->rank == size && (*pile_b)->rank == 1)
			norp = 3;
	}
	return (str);
}

char	*set_pointer(t_a **pile_a, t_a **pile_b, char *str, int size)
{
	int	next;
	int	prev;
	int	diff1;
	int	diff2;
	(void)str;

	next = find_max_next(*pile_a, size);
	prev = find_max_prev(*pile_a, size);
	diff1 = prev - next;
	// printf("pour A : prev = %d, next = %d\n", prev, next);
	next = find_min_next(*pile_b);
	prev = find_min_prev(*pile_b);
	// printf("pour B : prev = %d, next = %d\n", prev, next);
	diff2 = prev - next;
	next = find_max_next(*pile_a, size) - find_min_next(*pile_b);
	if (next < 0)
		next = next * -1;
	prev = find_max_prev(*pile_a, size) - find_min_prev(*pile_b);
	if (prev < 0)
		prev = prev * -1;
	if (diff1 <= 0 && diff2 <= 0)
		return (set_pointer_part2(pile_a, pile_b, str, 2, size));
	else if (diff1 >= 0 && diff2 >= 0)
		return (set_pointer_part2(pile_a, pile_b, str, 1, size));
	else if (next < prev)
		return (set_pointer_part2(pile_a, pile_b, str, 1, size));
	else
		return (set_pointer_part2(pile_a, pile_b, str, 2, size));
	return (0);
}

char	*sort_next_p2(t_a **pile_a, t_a **pile_b, char *str)
{
	int	a;
	int	b;

	t_a *tmpa ;
	t_a *tmpb ;
	a = (*pile_a)->rank + 1;
	b = (*pile_b)->rank - 1;
	// print_list_a(*pile_a);
	// print_list_b(*pile_b);
	// printf("next_p2\n");
	while (ft_lst_size(*pile_a) > 0)
	{
		tmpa = (*pile_a)->next;
		tmpb = (*pile_b)->next;
		// printf("ici\n");
		if (tmpa->rank == a && tmpb->rank == b)
			break ;
		if (tmpa->rank != a)
			str = ft_strjoin_ps(str, swap_a(pile_a));
		if (tmpb->rank != b)
			str = ft_strjoin_ps(str, swap_b(pile_b));
		if (tmpa->rank != a)
			str = ft_strjoin_ps(str, rotate_list_a(pile_a));
		if (tmpb->rank != b)
			str = ft_strjoin_ps(str, rotate_list_b(pile_b));
	}
	return (str);
}

char	*sort_prev_p2(t_a **pile_a, t_a **pile_b, char *str)
{
	int	a;
	int	b;

	t_a *tmpa ;
	t_a *tmpb ;
	a = (*pile_a)->rank + 1;
	b = (*pile_b)->rank - 1;
	// printf("a = %d, b = %d\n", a, b);
	// print_list_a(*pile_a);
	// print_list_b(*pile_b);
	// printf("prev_p2\n");
	while (ft_lst_size(*pile_a) > 0)
	{
		tmpa = (*pile_a)->next;
		tmpb = (*pile_b)->next;
		// print_list_a(*pile_a);
		// print_list_b(*pile_b);
		if (tmpa->rank == a && tmpb->rank == b)
			break ;
		if (tmpa->rank != a)
			str = ft_strjoin_ps(str, reverse_rotate_a(pile_a));
		if (tmpb->rank != b)
			str = ft_strjoin_ps(str, reverse_rotate_b(pile_b));
		if (tmpa->rank != a)
			str = ft_strjoin_ps(str, swap_a(pile_a));
		if (tmpb->rank != b)
			str = ft_strjoin_ps(str, swap_b(pile_b));
	}
	return (str);
}

char	*opti2(t_a **pile_a, t_a **pile_b, char *str)
{
	int	anext;
	int	aprev;
	int	bnext;
	int	bprev;

	anext = find_next_a(*pile_a);
	aprev = find_prev_a(*pile_a);
	bnext = find_next_b(*pile_b);
	bprev = find_prev_b(*pile_b);
	anext += bnext;
	aprev += bprev;
	if (anext <= aprev)
		return (sort_next_p2(pile_a, pile_b, str));
	else
		return (sort_prev_p2(pile_a, pile_b, str));
}

char	*sort_next(t_a **pile_a, t_a **pile_b, char *str)
{
	int	a;
	int	b;

	a = (*pile_a)->rank - 1;
	b = (*pile_b)->rank + 1;
	// print_list_a(*pile_a);
	// print_list_b(*pile_b);
	// printf("a = %d, b = %d, rank a = %d, rank b = %d\n", a, b, (*pile_a)->rank, (*pile_b)->rank);
	while (ft_lst_size(*pile_a) > 0)
	{
		
		if ((*pile_a)->rank == a && (*pile_b)->rank == b)
			break ;
		if ((*pile_a)->rank != a)
			str = ft_strjoin_ps(str, rotate_list_a(pile_a));
		if ((*pile_b)->rank != b)
			str = ft_strjoin_ps(str, rotate_list_b(pile_b));
	}
	str = opti2(pile_a, pile_b, str);
	return (str);
}


char	*sort_prev(t_a **pile_a, t_a **pile_b, char *str)
{
	int	a;
	int	b;

	a = (*pile_a)->rank - 1;
	b = (*pile_b)->rank + 1;
	if (check_rank_up(*pile_a) == 0)
		a = (*pile_a)->rank;
	// print_list_a(*pile_a);
	// print_list_b(*pile_b);
	// printf("a = %d, b = %d\n", a, b);
	while (ft_lst_size(*pile_a) > 0)
	{
		// printf("ici\n");
		if ((*pile_a)->rank == a && (*pile_b)->rank == b)
			break ;
		if ((*pile_a)->rank != a)
			str = ft_strjoin_ps(str, reverse_rotate_a(pile_a));
		if ((*pile_b)->rank != b)
			str = ft_strjoin_ps(str, reverse_rotate_b(pile_b));
	}
	str = opti2(pile_a, pile_b, str);
	return (str);
}

char	*opti(t_a **pile_a, t_a **pile_b, char *str)
{
	int	anext;
	int	aprev;
	int	bnext;
	int	bprev;

	anext = find_next_a(*pile_a);
	aprev = find_prev_a(*pile_a);
	bnext = find_next_b(*pile_b);
	bprev = find_prev_b(*pile_b);
	anext += bnext;
	aprev += bprev;
	if (anext <= aprev)
		return (sort_next(pile_a, pile_b, str));
	else
		return (sort_prev(pile_a, pile_b, str));
}

char	*file_a(t_a **pile_a, t_a **pile_b, char *str)
{
	while (ft_lst_size(*pile_b) > 0)
		str = ft_strjoin_ps(str, push_list_a(pile_a, pile_b));
	return (str);
}

char	*new_algo_100(t_a **pile_a, t_a **pile_b, char *str)
{
	int	med;
	int	size;

	size = ft_lst_size(*pile_a);
	med = ft_lst_size(*pile_a) / 2;
	if (size % 2 == 1)
		med += 1;
	// printf("med = %d\n", med);
	str = file_b(pile_a, pile_b, str, med, size);
	str = set_pointer(pile_a, pile_b, str, size);
	// print_list_a(*pile_a);
	// print_list_b(*pile_b);
	// printf("GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG\n");
	// print_list_a(*pile_a);
	// print_list_b(*pile_b);
	while (ft_lst_size(*pile_a) > 0)
	{
		if (check_rank_up(*pile_a) == 0 && check_rank_down(*pile_b) == 0)
			break ;
		str = opti(pile_a, pile_b, str);
	}
	str = file_a(pile_a, pile_b, str);
	return (str);
}