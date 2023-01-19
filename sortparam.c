/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortparam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:33:41 by kle-rest          #+#    #+#             */
/*   Updated: 2023/01/19 17:58:02 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ft_free(char ***tab)
{
	int	j;
	int	i;
	int l;

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

char ***split_params(char ***tab, char **str, int ac)
{
	int	i;
	int	j;
	int	l;

	l = 0;
	i = 1;
	j = 0;
	while (ac > 1)
	{
		tab[j] = ft_split(str[i], ' ');
		j++;
		i++;
		ac--;
	}
	tab[j] = '\0';
	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			//printf("%s\n", tab[j][i]);
			if (checkarg(tab[j][i]) == 1)
			{
				write(2, "error\n", 7);
				return NULL;
			}
			i++;
		}
		j++;
	}
	return (tab);
}

int *convertarg(char ***tabchar, int ac)
{
	int *tab;
	int j;
	int i;
	int t;

	j = 0;
	t = 0;
	tab = malloc(sizeof(int*) * (ft_strlentab(tabchar)));
	if (!tab)
		return NULL;
	while (tabchar[j])
	{
		i = 0;
		while(tabchar[j][i])
		{
			tab[t] = ft_atoi(tabchar[j][i]);
			t++;
			i++;
		}
		j++;
	}
	t = 0;
	while (tab[t])
	{
		printf("%d\n", tab[t]);
		t++;
	}
	//free(tab);
	return (tab);
}

int	main(int ac, char **av)
{
	(void)ac;
	char ***tab;
	int	i;
	int	j;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char***) * ac);
	if (!tab)
		return (0);
	tab = split_params(tab, av, ac);
	if (!tab)
		return (1);
	//printf("ok\n");
	convertarg(tab, ac);
	ft_free(tab);
	return (0);
}