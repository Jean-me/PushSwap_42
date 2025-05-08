/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:10:08 by mesasaki          #+#    #+#             */
/*   Updated: 2025/05/08 20:14:03 by mesasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

void	push_min_efficient(t_stack **a, t_stack **b)
{
	int		min_index;
	int		size;

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
	push_min_efficient(a, b); // まず回転数少なく最小を送る
	push_min_efficient(a, b); // 次にもう1つ
	sort_three(a);            // 中央の舞を整え
	if ((*b)->value < (*b)->next->value)
		sb(b);                // 小さい順に戻すために並び替え
	pa(a, b);
	pa(a, b);
}