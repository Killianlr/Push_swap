/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:27:24 by kle-rest          #+#    #+#             */
/*   Updated: 2023/02/04 17:10:27 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct lst_a
{
	int				data;
	struct lst_a	*next;
}t_a;

int		ft_strlentab(char ***tab);
int		ft_checkarg(char ***tab);
int		*convertarg(char ***tabchar);
char	***split_params(char ***tab, char **str, int ac);
int		checkarg(char *str);
void	ft_free(char ***tab);
int		checkint(int *tab, int t);
t_a		*split_list(int *tab);
void	print_list(t_a *start);
t_a		*swap(t_a **first);
void	ft_lstadd_back_ps(t_a **lst, t_a *new);
t_a		*ft_lstnew_ps(int data);
t_a		*rotate_list(t_a **first);
t_a		*reverse_rotate(t_a **first);
int		ft_lst_size(t_a *lst);
t_a		*push_list(t_a **first_a, t_a **first_b);
int		find_median(t_a **pile);

#endif