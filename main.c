/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:42:25 by mesasaki          #+#    #+#             */
/*   Updated: 2025/05/02 18:48:41 by mesasaki         ###   ########.fr       */
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
	mask = (bool *)malloc(sizeof (bool) * num);
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
	free (mask);
	return (id_arr);
}

void	push_and_sort(t_stack **a, t_stack **b, int n)
{
	if (n > 3)
		radix_sort(a, b);
	else if (n > 2)
		sort_three(a);
	else
		sort_two(a);
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

int	main(int argc, char **argv)
{
	t_stack			*a;
	t_stack			*b;
	unsigned int	*id_arr;
	int				*arr;
	int				n;

	n = argc - 1;
	a = NULL;
	b = NULL;
	if (argc < 2)
		return (write(2, "Error\n", 6), 1);
	arr = malloc(sizeof(int) * n);
	id_arr = malloc(sizeof(unsigned int) * n);
	if (!arr || !id_arr)
		return (write(2, "Error\n", 6), 1);
	if (parse_and_store(arr, argv, argc))
		return (write(2, "Error\n", 6), 1);
	if (compare_n(arr, n))
		return (write(2, "Error\n", 6), 1);
	rank_compress(arr, id_arr, n);
	make_node(&a, id_arr, n);
	push_and_sort(&a, &b, n);
	bury_all(arr, id_arr, a, b);
}
