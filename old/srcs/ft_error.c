/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:29:46 by ejuarros          #+#    #+#             */
/*   Updated: 2024/02/29 11:22:29 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/** 
 *  @details Some errors are non-integer numbers, numbers higher than a 
 *  natural number, duplicate numbers.
 * 
 *  Remember:
 * 		- fd = 0 --> Standard input
 * 		- fd = 1 --> Standard output
 * 		- fd = 2 --> Standard error output
 * 		- fd > 2 --> for opened files
*/
void	ft_print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
