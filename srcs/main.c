/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:42:03 by elena             #+#    #+#             */
/*   Updated: 2024/03/20 10:35:20 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = ft_init(argc, argv);
	if (!a || ft_dup_number(a))
	{
		ft_clear(&a, free);
		ft_print_error();
	}
	if (!ft_is_sorted(a))
		ft_sort(&a);
	ft_clear(&a, free);
	return (0);
}

/*
void	print_stacks(t_stack const *a, t_stack const *b, char *msg)
{
	t_stack	*aux_a;
	t_stack	*aux_b;

	ft_printf("\n\n-> %s\n", msg);
	aux_a = (t_stack *) a;
	aux_b = (t_stack *) b;
	ft_printf("	Stack A							Stack B\n");
	while ((aux_a || aux_b))
	{
		if (aux_a)
		{
			ft_printf("% d [ra:% d] [rb:% d] [rr:% d] [rrr:% d] [m:% d]		",
			aux_a->num, aux_a->ra, aux_a->rb, aux_a->rr, aux_a->rrr,
			aux_a->moves);
			aux_a = aux_a->next;
		}
		else
			ft_printf("							");
		if (aux_b)
		{
			ft_printf("% d [ra:% d] [rb:% d] [rr:% d] [rrr:% d] [m:% d]\n",
			aux_b->num, aux_b->ra, aux_b->rb, aux_b->rr, aux_b->rrr,
			aux_b->moves);
			aux_b = aux_b->next;
		}
		else
			ft_printf("\n");
	}
	ft_printf("-------------- Exit print_stacks --------------\n\n");
}
*/