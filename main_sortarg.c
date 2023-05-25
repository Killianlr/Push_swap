/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sortarg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:33:41 by kle-rest          #+#    #+#             */
/*   Updated: 2023/04/11 10:33:51 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ft_free(char ***tab)
{
	int	j;
	int	i;

	j = 0;
	while (tab && tab[j])
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
	int	e;

	i = 0;
	e = 0;
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

char	***split_arg(char ***tab, char **str, int ac)
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
	tab[j] = NULL;
	if (ft_checkarg(tab) == 1)
	{
		ft_free(tab);
		return (NULL);
	}
	if (ft_checksizeint(tab, 0) == 1)
	{
		ft_free(tab);
		write(2, "Error\n", 7);
		return (NULL);
	}
	return (tab);
}

int	convertarg(char ***tabchar)
{
	long int	*tab;
	int			j;
	int			i;
	int			t;

	j = 0;
	t = 0;
	tab = malloc(sizeof(int *) * (ft_strlentab(tabchar)));
	if (!tab)
		return (1);
	while (tabchar && tabchar[j])
	{
		i = 0;
		while (tabchar[j][i])
			tab[t++] = ft_atoi_ps(tabchar[j][i++]);
		j++;
	}
	if (checkint(tab, t) == 1)
		return (1);
	hub(tab, (ft_strlentab(tabchar) - 1));
	return (0);
}

int	main(int ac, char **av)
{
	char	***tab;

	tab = NULL;
	(void)ac;
	if (ac == 1)
		return (1);
	if (check_is_empty(av[1]) == 1)
		return (1);
	tab = malloc(sizeof(char **) * ac);
	if (!tab)
		return (0);
	tab = split_arg(tab, av, ac);
	if (!tab)
		return (1);
	if (convertarg(tab) == 1)
		return (1);
	ft_free(tab);
	return (0);
}
