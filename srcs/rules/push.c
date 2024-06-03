/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:25:42 by elena             #+#    #+#             */
/*   Updated: 2024/03/21 07:59:49 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/** @brief Pushes the first element of src into dest
 * 
 * @param src source stack
 * @param dest destination stack
 * 
 * @return void
*/
static void	push_stack(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = *dest;
	*dest = *src;
	*src = (*src)->next;
	(*dest)->next = tmp;
}

/**
 * @details character c can take two values:
 * 		- 'a' to push into stack a
 * 		- 'b' to push into stack b 
 * 
 * character w c take to values:
 * 		- '1' to write 
 * 		- '0' otherwise
*/
void	push(t_stack **a, t_stack **b, int c, int w)
{
	if (c == 'a')
		push_stack(b, a);
	else if (c == 'b')
		push_stack(a, b);
	if ((c == 'a' || c == 'b') && w == 1)
		ft_printf("p%c\n", c);
}
