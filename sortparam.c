/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortparam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:33:41 by kle-rest          #+#    #+#             */
/*   Updated: 2023/02/05 18:02:53 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ft_free(char ***tab)
{
	int	j;
	int	i;

	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			free(tab[j][i]);
			i++;
		}
		free(tab[j]);
		j++;
	}
	free(tab);
}

int	checkarg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		if (str[i] == '-' || str[i] == '+')
			i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			i++;
			if (str[i] == '\0' || str[i] == ' ')
				return (0);
		}
		return (1);
	}
	return (0);
}

char	***split_params(char ***tab, char **str, int ac)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (ac > 1)
	{
		tab[j] = ft_split(str[i], ' ');
		j++;
		i++;
		ac--;
	}
	//printtabchar(tab);
	if (ft_checkarg(tab) == 1)
	{
		ft_free(tab);
		return (NULL);
	}
	return (tab);
}

int	*convertarg(char ***tabchar)
{
	int	*tab;
	int	j;
	int	i;
	int	t;
	t_a	*start;

	j = 0;
	t = 0;
	tab = malloc(sizeof(int *) * (ft_strlentab(tabchar)));
	if (!tab)
		return (NULL);
	while (tabchar[j])
	{
		i = 0;
		while (tabchar[j][i])
		{
			tab[t] = ft_atoi(tabchar[j][i]);
			t++;
			i++;
		}
		j++;
	}
	ft_free(tabchar);
	if (checkint(tab, t) == 1)
		return (NULL);
	start = split_list(tab);
	//print_list(start);
	zero_rank(start);
	print_list(start);
	run_list_for_rank(start);
	printf("-------------\n");
	print_list(start);
	//printf("la mediane : %d\n", find_median(&start));
	//printf("--------------\n");
	//print_list(start);
	return (tab);
}

int	main(int ac, char **av)
{
	char	***tab;

	(void)ac;
	if (ac == 1)
		return (1);
	tab = malloc(sizeof(char ***) * ac);
	if (!tab)
		return (0);
	tab = split_params(tab, av, ac);
	if (!tab)
		return (1);
	convertarg(tab);
	return (0);
}
