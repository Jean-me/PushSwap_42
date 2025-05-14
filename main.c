/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:42:25 by mesasaki          #+#    #+#             */
/*   Updated: 2025/05/14 19:51:43 by mesasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

unsigned int	*rank_compress(int *arr, unsigned int *id_arr, int num)
{
	bool	*mask;
	int		i;
	int		id;

	i = 0;
	mask = (bool *)malloc(sizeof(bool) * num);
	if (mask == NULL)
		return (NULL);
	while (i < num)
	{
		mask[i] = false;
		i++;
	}
	i = 0;
	while (i < num)
	{
		id = find_min_id(arr, mask, num);
		id_arr[id] = i;
		mask[id] = true;
		i++;
	}
	free(mask);
	return (id_arr);
}

int	parse_and_store(int *arr, char **argv, int argc)
{
	int	i;
	int	c;

	i = 1;
	c = 0;
	while (i < argc)
	{
		if (is_number(argv[i]) == NOT_NUMBER || over_int(argv[i]) == NOT_NUMBER)
			return (NOT_NUMBER);
		arr[c] = ft_atoi(argv[i]);
		i++;
		c++;
	}
	return (0);
}

void	make_node(t_stack **a, unsigned int *id_arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		add_node(a, id_arr[i]);
		i++;
	}
}

int	init_validate(int argc, char **argv, int **arr, unsigned int **id_arr)
{
	int	n;

	n = argc - 1;
	*arr = (int *)malloc(sizeof(int) * n);
	*id_arr = (unsigned int *)malloc(sizeof(unsigned int) * n);
	if (!(*arr) || !(*id_arr) || parse_and_store(*arr, argv, argc)
		|| compare_n(*arr, n))
	{
		bury_array(*arr, *id_arr);
		return (write(2, "Error\n", 6), 2);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack			*a;
	t_stack			*b;
	unsigned int	*id_arr;
	int				*arr;

	a = NULL;
	b = NULL;
	if (argc - 1 > 1)
	{
		if (init_validate(argc, argv, &arr, &id_arr) != 0)
			return (2);
		if (!is_sorted(arr, argc - 1))
		{
			bury_array(arr, id_arr);
			return (0);
		}
		rank_compress(arr, id_arr, argc - 1);
		make_node(&a, id_arr, argc - 1);
		push_and_sort(&a, &b, argc - 1);
		bury_all(arr, id_arr, a, b);
	}
	else if (argc - 1 == 1 && (is_number(argv[1]) == NOT_NUMBER
			|| over_int(argv[1]) == NOT_NUMBER))
		return (write(2, "Error\n", 6), 2);
	return (0);
}
