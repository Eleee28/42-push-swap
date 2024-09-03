/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:09:10 by ejuarros          #+#    #+#             */
/*   Updated: 2024/03/21 08:02:37 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @details With three elements there are just six possible combinations of
 * numbers:
 * 		A	B	C	D	E	F
 * 		-	-	-	-	-	-
 * 		1	1	2	2	3	3
 * 		2	3	1	3	1	2
 * 		3	2	3	1	2	1
 * 
 *  - Case A: already ordered
 *  - Case B: movements -> ra, sa, rra. To identify: min(a) = a[0]
 *  - Case C: movements -> sa. To identify: a[0] > a[1]
 *  - Case D: movements -> rra. To identify: a[0] < a[1]
 *  - Case E: movements -> ra. To identify: max(a) = a[0] && min(a) = a[1]
 *  - Case F: movements -> sa rra. To identify: max(a) = a[0] && min(a) != a[1]
 * 
*/
void	ft_sort_three(t_stack **a)
{
	if (ft_find_min(*a) == (*a)->num)
	{
		rotate(a, NULL, 'a', 1);
		swap(a, NULL, 'a', 1);
		reverse_rotate(a, NULL, 'a', 1);
	}
	else if (ft_find_max(*a) == (*a)->num)
	{
		if (ft_find_min(*a) == (*a)->next->num)
			rotate(a, NULL, 'a', 1);
		else
		{
			swap(a, NULL, 'a', 1);
			reverse_rotate(a, NULL, 'a', 1);
		}
	}
	else
	{
		if ((*a)->num > (*a)->next->num)
			swap(a, NULL, 'a', 1);
		else
			reverse_rotate(a, NULL, 'a', 1);
	}
}

/**
 * @details The stack must not be ordered already.
 *  
 * If the size of the stack is 2 then just swap.
 * Otherwise, implement the algorithm to sort.
*/
void	ft_sort(t_stack **a)
{
	int	size;

	if (!ft_is_sorted(*a))
	{
		size = ft_size(*a);
		if (size == 2)
			swap(a, NULL, 'a', 1);
		else if (size == 3)
			ft_sort_three(a);
		else
			ft_sort_big(a);
	}
}

/**
 * @details Pushes elements into b until a has three elements. Sort a 
 * (3 elems) and order b choosing the cheapest element to move. Put 
 * the lowest elements at the top of a.
*/
void	ft_sort_big(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	while (ft_size(*a) > 3)
		push(a, &b, 'b', 1);
	if (!ft_is_sorted(*a))
		ft_sort_three(a);
	while (b && ft_size(b) > 0)
	{
		ft_init_moves(a, &b);
		ft_move_cheapest(a, &b);
	}
	if (!ft_is_sorted(*a))
		ft_place_head(a);
}

void	ft_place_head(t_stack **a)
{
	int	idx_min;
	int	size;

	idx_min = ft_find_idx(*a, ft_find_min(*a));
	size = ft_size(*a);
	while (idx_min && idx_min <= size / 2)
	{
		rotate(a, NULL, 'a', 1);
		idx_min--;
	}
	while (idx_min > size / 2 && idx_min < size)
	{
		reverse_rotate(a, NULL, 'a', 1);
		idx_min++;
	}
}
