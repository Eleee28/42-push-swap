/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:45:25 by ejuarros          #+#    #+#             */
/*   Updated: 2024/03/19 09:55:24 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/** 
 * 	@details If the list does not exist the function has no effect.
*/
void	ft_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (stack)
	{
		if (*stack)
		{
			last = ft_last(*stack);
			last->next = new;
		}
		else
			*stack = new;
	}
}

/** 
 * 	@details If the list does not exist the function has no effect.
*/
t_stack	*ft_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/** 
 * 	@details The content of the node is initialized with content and next 
 *  with NULL.
*/
t_stack	*ft_new(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NUL);
	ft_bzero(new, sizeof(t_stack));
	new->next = NULL;
	new->num = content;
	return (new);
}

int	ft_size(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}
