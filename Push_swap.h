/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:27:24 by kle-rest          #+#    #+#             */
/*   Updated: 2023/03/19 14:29:04 by kle-rest         ###   ########.fr       */
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
	struct lst_a	*prev;
}t_a;

int			ft_strlentab(char ***tab);
int			ft_checkarg(char ***tab);
int			checkarg(char *str);
int			checkint(long int *tab, int t);
int			ft_checksizeint(char ***tab, int i);
void		ft_free_list(t_a *pile_a);
void		*ft_calloc_ps(int nmemb, int size);
char		*ft_strjoin_ps(char *s1, char *s2);
long int	ft_atoi_ps(const char *nptr);
int			caughtmaxprev(t_a *pile_b);
int			caughtmaxnext(t_a *pile_b);
int			caughtvalnext(t_a *pile_a, int stop);
int			caughtvalprev(t_a *pile_a, int stop);
int			find_med(t_a *pile, int med);
void		zero_rank(t_a *pile);
void		allow_rank(int mem, t_a *pile, int rank);
void		run_list_for_rank(t_a *pile);
int			check_rank_up(t_a *pile_a);
int			check_rank_down(t_a *pile_b);
void		print_instruction(char *str, int i);
char		*swap_a(t_a **first);
char		*swap_b(t_a **first);
char		*rotate_list_a(t_a **first);
char		*rotate_list_b(t_a **first);
char		*reverse_rotate_a(t_a **first);
char		*reverse_rotate_b(t_a **first);
char		*push_list_b(t_a **pile_a, t_a **pile_b);
char		*push_list_a(t_a **pile_a, t_a **pile_b);
char		*algo_3(t_a **pile, char *str);
char		*algo_5(t_a **pile_a, t_a **pile_b, char *str);
char		*algo(t_a **pile_a, t_a **pile_b, char *str, int interval);
t_a			*split_list(long *tab, int j);
void		add_prev_list(t_a **lst);
void		ft_lstadd_back_ps(t_a **lst, t_a *new);
t_a			*ft_lstnew_ps(int data);
int			ft_lst_size(t_a *lst);
int			hub(long int *tab, int i);

#endif