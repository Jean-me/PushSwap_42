/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 14:53:36 by mesasaki          #+#    #+#             */
/*   Updated: 2025/05/10 14:54:19 by mesasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

void	push_and_sort(t_stack **a, t_stack **b, int n)
{
	if (n > 5)
		radix_sort(a, b);
	else if (n > 4)
		sort_five(a, b);
	else if (n > 3)
		sort_four(a, b);
	else if (n > 2)
		sort_three(a);
	else if (n > 1)
		sort_two(a);
}
