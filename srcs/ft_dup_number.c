/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:10:16 by elena             #+#    #+#             */
/*   Updated: 2024/03/20 09:15:08 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_dup_number(t_stack const *stack)
{
	t_stack	*aux;
	t_stack	*aux2;

	aux = (t_stack *) stack;
	while (aux)
	{
		aux2 = aux->next;
		while (aux2)
		{
			if (aux->num == aux2->num)
				return (1);
			aux2 = aux2->next;
		}
		aux = aux->next;
	}
	return (0);
}
