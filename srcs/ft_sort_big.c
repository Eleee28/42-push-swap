/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:11:03 by ejuarros          #+#    #+#             */
/*   Updated: 2024/03/21 08:01:49 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_init_moves(t_stack **a, t_stack **b)
{
	t_stack	*cp_b;

	ft_set_zero(*b);
	cp_b = *b;
	ft_calc_moves_b(cp_b);
	cp_b = *b;
	ft_calc_moves_a(*a, cp_b);
	cp_b = *b;
	ft_adjust_moves(cp_b);
}

/** @brief Finds the number with less cost to move
 * 
 * @param b stack b
 * 
 *  @return node of the cheapest number to move
*/
static t_stack	*ft_find_cheapest(t_stack *b)
{
	int		cost;
	t_stack	*cp_b;
	t_stack	*min;

	cost = INT_MAX;
	min = NULL;
	cp_b = b;
	while (cp_b && cost > 1)
	{
		if (cp_b->moves < cost)
		{
			cost = cp_b->moves;
			min = cp_b;
		}
		cp_b = cp_b->next;
	}
	return (min);
}

/** @brief Rotates stack a according to the movements information
 * 
 * @param a stack a
 * @param b stack b
 * @param min cheapest node of stack b
 * 
 * @return void
*/
static void	rotate_stack_a(t_stack **a, t_stack **b, t_stack *min)
{
	while (min->ra != 0)
	{
		if (min->ra > 0)
		{
			rotate(a, b, 'a', 1);
			min->ra--;
		}
		else
		{
			reverse_rotate(a, b, 'a', 1);
			min->ra++;
		}
		min->moves--;
	}
}

/** @brief Rotates stack b according to the movements information
 * 
 * @param a stack a
 * @param b stack b
 * @param min cheapest node of stack b
 * 
 * @return void
*/
static void	rotate_stack_b(t_stack **a, t_stack **b, t_stack *min)
{
	while (min->rb)
	{
		if (min->rb > 0)
		{
			rotate(a, b, 'b', 1);
			min->rb--;
		}
		else
		{
			reverse_rotate(a, b, 'b', 1);
			min->rb++;
		}
		min->moves--;
	}
}

/** 
 * @details Applies in order rr, rrr, ra, rb, pa
*/
void	ft_move_cheapest(t_stack **a, t_stack **b)
{
	t_stack	*min;

	min = ft_find_cheapest(*b);
	while (min->rr)
	{
		rotate(a, b, 'r', 1);
		min->rr--;
		min->moves--;
	}
	while (min->rrr)
	{
		reverse_rotate(a, b, 'r', 1);
		min->rrr--;
		min->moves--;
	}
	rotate_stack_a(a, b, min);
	rotate_stack_b(a, b, min);
	push(a, b, 'a', 1);
}
