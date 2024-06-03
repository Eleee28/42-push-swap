/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:11:54 by elena             #+#    #+#             */
/*   Updated: 2024/03/21 08:00:01 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/** @brief Swaps the first two elements of the stack
 * 
 * @param stack stack to swap
 * 
 * @return void
*/
static void	swap_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

/**
 * @details character c can take three values:
 * 		- 'a' to swap stack a
 * 		- 'b' to swap stack b 
 * 		- 's' to swap both stacks
 * 
 * character w c take to values:
 * 		- '1' to write 
 * 		- '0' otherwise
*/
void	swap(t_stack **a, t_stack **b, int c, int w)
{
	if (c == 'a')
		swap_stack(a);
	else if (c == 'b')
		swap_stack(b);
	else if (c == 's')
	{
		swap_stack(a);
		swap_stack(b);
	}
	if ((c == 'a' || c == 'b' || c == 's') && w == 1)
		ft_printf("s%c\n", c);
}
