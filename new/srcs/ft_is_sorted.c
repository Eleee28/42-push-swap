/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:24:42 by ejuarros          #+#    #+#             */
/*   Updated: 2024/09/02 09:03:51 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_sorted(t_stack const *stack)
{
	int		sorted;
	t_stack	*tmp;

	sorted = 1;
	if (stack)
		tmp = (t_stack *) stack;
	while (sorted && stack && tmp && tmp->next)
	{
		if (tmp->num > (tmp->next)->num)
			sorted = 0;
		tmp = tmp->next;
	}
	return (sorted);
}
