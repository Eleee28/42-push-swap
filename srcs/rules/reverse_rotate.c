/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:33:26 by elena             #+#    #+#             */
/*   Updated: 2024/03/21 07:59:54 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/** @brief Reverse rotates the elements of the stack
 * 
 * @param stack stack to reverse rotate
 * 
 * @return void
*/
static void	reverse_rotate_stack(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prev;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

/**
 * @details character c can take three values:
 * 		- 'a' to reverse rotate stack a
 * 		- 'b' to reverse rotate stack b 
 * 		- 'r' to reverse rotate both stacks
 * 
 * character w c take to values:
 * 		- '1' to write 
 * 		- '0' otherwise
*/
void	reverse_rotate(t_stack **a, t_stack **b, int c, int w)
{
	if (c == 'a')
		reverse_rotate_stack(a);
	else if (c == 'b')
		reverse_rotate_stack(b);
	else if (c == 'r')
	{
		reverse_rotate_stack(a);
		reverse_rotate_stack(b);
	}
	if ((c == 'a' || c == 'b' || c == 'r') && w == 1)
		ft_printf("rr%c\n", c);
}
