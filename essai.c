
// int	find_median(t_a **pile)
// {
// 	int i;
// 	int j;
// 	t_a *first;
// 	t_a *compare;

// 	i = 0;
// 	j = 0;
// 	first = *pile;
// 	while (1 <= ft_lst_size(first))
// 	{
// 		compare = *pile;
// 		while (1 <= ft_lst_size(compare))
// 		{
// 			if (compare->data > first->data)
// 				i += 1; 
// 			else if (compare->data < first->data)
// 				j += 1;
// 			compare = compare->next;
// 		}
// 		if ((ft_lst_size(*pile) % 2) == 1 && j == i)
// 			return (first->data);
// 		else if ((ft_lst_size(*pile) % 2) == 0 && (j - i == 1 || j - i == -1))
// 			return (first->data);
// 		j = 0;
// 		i = 0;
// 		first = first->next;
// 	}
// 	return (0);
// }