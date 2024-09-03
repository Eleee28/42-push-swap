/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:52:34 by ejuarros          #+#    #+#             */
/*   Updated: 2024/03/20 09:14:17 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @details For each node of stack b find the gap where it should be inserted
 * in stack a and with the index of the limit number of the gap modify ra
 * variable accordingly (possitive nbr for ra and negative for rra). Add
 * one to moves to represent the push.
*/
void	ft_calc_moves_a(t_stack *a, t_stack *b)
{
	t_stack	*cp_a;
	int		size;

	size = ft_size(a);
	while (b)
	{
		cp_a = a;
		while (cp_a)
		{
			if (cp_a->next && ft_in_between(cp_a->num, cp_a->next->num, b->num))
			{
				if (ft_find_idx(a, cp_a->next->num) <= size / 2)
					b->ra = ft_find_idx(a, cp_a->next->num);
				else
					b->ra = (size - ft_find_idx(a, cp_a->next->num)) * -1;
				break ;
			}
			if (!cp_a->next)
				break ;
			cp_a = cp_a->next;
		}
		b->moves++;
		b = b->next;
	}
}

/**
 * @details For each node, if it is in the upper part it adds i number of
 * rb. If it is in the bottom part it adds size - i rrb (represented as a 
 * negative nbr in the rb field).
*/
void	ft_calc_moves_b(t_stack *b)
{
	int	size;
	int	i;

	size = ft_size(b);
	i = 0;
	while (b)
	{
		if (i <= size / 2)
			b->rb = i;
		else
			b->rb = (size - i) * -1;
		b = b->next;
		i++;
	}
}

/**
 * @details It also calculates the total number of movements.
*/
void	ft_adjust_moves(t_stack *b)
{
	b->rr = 0;
	b->rrr = 0;
	while (b)
	{
		while (b->ra < 0 && b->rb < 0)
		{
			b->ra++;
			b->rb++;
			b->rrr++;
		}
		while (b->ra > 0 && b->rb > 0)
		{
			b->ra--;
			b->rb--;
			b->rr++;
		}
		b->moves += abs(b->ra) + abs(b->rb) + b->rr + b->rrr;
		b = b->next;
	}
}
