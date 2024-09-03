/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elena <elena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:35:41 by elena             #+#    #+#             */
/*   Updated: 2024/03/20 14:37:31 by elena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

void	execute(t_stack **a, t_stack **b);
void	perform_move(t_stack **a, t_stack **b, char *line);
void	perform_move2(t_stack **a, t_stack **b, char *line);
void	check(t_stack *a, t_stack *b);

#endif