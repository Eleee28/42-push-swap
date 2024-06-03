/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:24:42 by ejuarros          #+#    #+#             */
/*   Updated: 2024/03/20 09:23:13 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_sorted(t_stack const *stack)
{
	int		sorted;
	t_stack	*tmp;

	sorted = 1;
	if (stack && stack)
		tmp = (t_stack *) stack;
	while (sorted && tmp && tmp->next)
	{
		if (tmp->num > (tmp->next)->num)
			sorted = 0;
		tmp = tmp->next;
	}
	return (sorted);
}
