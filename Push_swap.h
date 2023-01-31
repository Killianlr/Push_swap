/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:27:24 by kle-rest          #+#    #+#             */
/*   Updated: 2023/01/31 18:28:50 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	lst_a
{
	int data;
	struct lst_a	*next;
}l_a;

int	ft_strlentab(char ***tab);
int	ft_checkarg(char ***tab);
int	*convertarg(char ***tabchar);
char	***split_params(char ***tab, char **str, int ac);
int	checkarg(char *str);
void	ft_free(char ***tab);
int	checkint(int *tab, int t);
l_a	*split_list(int *tab);
void	print_list(l_a *start);
l_a	*sa(l_a **first);
void	ft_lstadd_back_ps(l_a **lst, l_a *new);
l_a *ft_lstnew_ps(int data);
l_a *rotate_list(l_a **first);

#endif