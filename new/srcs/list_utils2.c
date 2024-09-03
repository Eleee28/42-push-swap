/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:16:02 by elena             #+#    #+#             */
/*   Updated: 2024/03/20 10:29:28 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * 	@details If the list does not exist the function has no effect. At the 
 *  end, the pointer to the list must be NULL.
*/
void	ft_clear(t_stack **stack, void (*del)(void *))
{
	t_stack	*aux;

	while (*stack)
	{
		aux = *stack;
		*stack = (*stack)->next;
		ft_delone(aux, del);
	}
}

/**
 * @details	The memory of 'next' must not be freed.
*/
void	ft_delone(t_stack *stack, void (*del)(void *))
{
	if (stack && del)
	{
		free(stack);
	}
}
