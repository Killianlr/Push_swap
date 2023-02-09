/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:23:52 by kle-rest          #+#    #+#             */
/*   Updated: 2023/02/08 13:52:55 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	print_instruction2(char *str, int i)
{
	if (str[i] == '1')
		write(1, "sa\n", 3);
	else if (str[i] == '2')
		write(1, "sb\n", 3);
	else if (str[i] == '4')
		write(1, "pa\n", 3);
	else if (str[i] == '5')
		write(1, "pb\n", 3);
	else if (str[i] == '6')
		write(1, "ra\n", 3);
	else if (str[i] == '7')
		write(1, "rb\n", 3);
	else if (str[i] == '9')
		write(1, "rra\n", 4);
	else if (str[i] == '0')
		write(1, "rrb\n", 4);
}

void	print_instruction(char *str, int i)
{
	while (str[i] != '\0')
	{
		if ((str[i] == '1' && str[i + 1] == '2')
			|| (str[i] == '2' && str[i + 1] == '1'))
		{
			write(1, "ss\n", 3);
			i++;
		}
		else if ((str[i] == '6' && str[i + 1] == '7')
			|| (str[i] == '7' && str[i + 1] == '6'))
		{
			write(1, "rr\n", 4);
			i++;
		}
		else if ((str[i] == '9' && str[i + 1] == '0')
			|| (str[i] == '0' && str[i + 1] == '9'))
		{
			write(1, "rrr\n", 4);
			i++;
		}
		else
			print_instruction2(str, i);
		i++;
	}
}

// int	main(void)
// {
// 	char	*str;
// 	int		i;

// 	i = 0;
// 	str = "125665948230150990364567";
// 	print_instruction(str, i);
// 	return (0);
// }
