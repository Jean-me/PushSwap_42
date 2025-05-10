/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:10:08 by mesasaki          #+#    #+#             */
/*   Updated: 2025/05/10 14:41:13 by mesasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

void	push_min_efficient(t_stack **a, t_stack **b)
{
	int	min_index;
	int	size;

	min_index = find_min_index(*a);
	size = stack_size(*a);
	if (min_index <= size / 2)
	{
		while (min_index-- > 0)
			ra(a);
	}
	else
	{
		while (min_index++ < size)
			rra(a);
	}
	pb(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	push_min_efficient(a, b);
	push_min_efficient(a, b);
	sort_three(a);
	if ((*b)->value < (*b)->next->value)
		sb(b);
	pa(a, b);
	pa(a, b);
}

void	sort_four(t_stack **a, t_stack **b)
{
	int	min_index;

	min_index = find_min_index(*a);
	if (min_index == 1)
		ra(a);
	else if (min_index == 2)
	{
		ra(a);
		ra(a);
	}
	else if (min_index == 3)
		rra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}
