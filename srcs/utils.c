/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:44:20 by ejuarros          #+#    #+#             */
/*   Updated: 2024/03/20 10:43:50 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

/**
 * @details There are three possible cases:
 * 	- (8, -1), n = 9 --> it is in the interval (lim1 > lim2 && n > lims)
 * 	- (8, -1), n = -20 --> it is in the interval (lim1 > lim2 && n < lims)
 * 	- (3, 5), n = 4 --> usual and intuitive case
 * 
 * (Take into account I am considering my stack to be circular!)
*/
int	ft_in_between(int lim1, int lim2, int n)
{
	if (lim1 > lim2)
		return ((n > lim2 && n > lim1) || (n < lim2 && n < lim1));
	else
		return (n < lim2 && n > lim1);
}

void	ft_set_zero(t_stack *stack)
{
	t_stack	*cp;

	cp = stack;
	while (cp)
	{
		cp->ra = 0;
		cp->rb = 0;
		cp->rr = 0;
		cp->rrr = 0;
		cp->moves = 0;
		cp = cp->next;
	}
}
