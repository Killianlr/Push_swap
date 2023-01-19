/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:27:24 by kle-rest          #+#    #+#             */
/*   Updated: 2023/01/19 19:58:03 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	va_list
{
	int data;
	int rang;
	struct va_list	*next;
}va;

typedef struct	vb_list
{
	int data;
	int rang;
	struct vb_list *next;
}vb;

int	ft_strlentab(char ***tab);
int	ft_checkarg(char ***tab);
int	*convertarg(char ***tabchar, int ac);
char	***split_params(char ***tab, char **str, int ac);
int	checkarg(char *str);
void	ft_free(char ***tab);
int	checkint(int *tab, int t);


#endif