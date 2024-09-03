/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:30:05 by elena             #+#    #+#             */
/*   Updated: 2024/03/21 07:59:57 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/** @brief Rotates the elements of the stack
 * 
 * @param stack stack to rotate
 * 
 * @return void
*/
static void	rotate_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = ft_last(*stack);
	(*stack)->next = tmp;
	*stack = tmp->next;
	tmp->next = NULL;
}

/**
 * @details character c can take three values:
 * 		- 'a' to rotate stack a
 * 		- 'b' to rotate stack b 
 * 		- 'r' to rotate both stacks
 * 
 * character w c take to values:
 * 		- '1' to write 
 * 		- '0' otherwise
*/
void	rotate(t_stack **a, t_stack **b, int c, int w)
{
	if (c == 'a')
		rotate_stack(a);
	else if (c == 'b')
		rotate_stack(b);
	else if (c == 'r')
	{
		rotate_stack(a);
		rotate_stack(b);
	}
	if ((c == 'a' || c == 'b' || c == 'r') && w == 1)
		ft_printf("r%c\n", c);
}
