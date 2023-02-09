/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:27:24 by kle-rest          #+#    #+#             */
/*   Updated: 2023/02/09 13:14:50 by kle-rest         ###   ########.fr       */
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
	int				rank;
	struct lst_a	*next;
}t_a;

int		ft_strlentab(char ***tab);
int		ft_checkarg(char ***tab);
int		convertarg(char ***tabchar);
char	***split_arg(char ***tab, char **str, int ac);
int		checkarg(char *str);
void	ft_free(char ***tab);
int		checkint(long int *tab, int t);
t_a		*split_list(long int *tab, int j);
void	print_list(t_a *start);
char	*swap_a(t_a **first);
char	*swap_b(t_a **first);
void	ft_lstadd_back_ps(t_a **lst, t_a *new);
t_a		*ft_lstnew_ps(int data);
char	*rotate_list_a(t_a **first);
char	*rotate_list_b(t_a **first);
char	*reverse_rotate_a(t_a **first);
char	*reverse_rotate_b(t_a **first);
char	*push_list_b(t_a **pile_a, t_a **pile_b);
char	*push_list_a(t_a **pile_a, t_a **pile_b);
int		ft_lst_size(t_a *lst);
char	*push_list_b(t_a **pile_a, t_a **pile_b);
void	zero_rank(t_a *pile);
void	run_list_for_rank(t_a *pile);
void	allow_rank(int mem, t_a *pile, int rank);
void	hub(long int *tab, int i);
void	*ft_calloc_ps(int nmemb, int size);
char	*ft_strjoin_ps(char *s1, char *s2);
void	print_instruction(char *str, int i);
void	print_instruction2(char *str, int i);
void	algo_3(t_a **pile);
void	algo_5(t_a **pile_a, t_a **pile_b);
int		ft_checksizeint(char ***tab, int i);
long int	ft_atoi_ps(const char *nptr);
void	algo_5end(t_a **pile_a, t_a **pile_b, char *str);
void	ft_free_list(t_a *pile_a);

#endif