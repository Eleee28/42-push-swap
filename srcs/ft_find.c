/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:10:47 by elena             #+#    #+#             */
/*   Updated: 2024/03/20 09:17:19 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_find_min(t_stack const *stack)
{
	int		min;
	t_stack	*tmp;

	tmp = (t_stack *)stack;
	min = tmp->num;
	while (tmp)
	{
		if (tmp->num < min)
			min = tmp->num;
		tmp = tmp->next;
	}
	return (min);
}

int	ft_find_max(t_stack const *stack)
{
	int		max;
	t_stack	*tmp;

	tmp = (t_stack *)stack;
	max = tmp->num;
	while (tmp)
	{
		if (tmp->num > max)
			max = tmp->num;
		tmp = tmp->next;
	}
	return (max);
}

int	ft_find_idx(t_stack const *stack, int num)
{
	int		idx;
	t_stack	*tmp;

	tmp = (t_stack *)stack;
	idx = 0;
	while (tmp && tmp->num != num)
	{
		idx++;
		tmp = tmp->next;
	}
	return (idx);
}
