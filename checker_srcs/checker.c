/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:51:56 by ejuarros          #+#    #+#             */
/*   Updated: 2024/03/21 08:00:35 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include <string.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = ft_init(argc, argv);
	b = NULL;
	if (!a || ft_dup_number(a))
	{
		ft_clear(&a, free);
		ft_print_error();
	}
	execute(&a, &b);
	check(a, b);
	return (0);
}

void	execute(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		perform_move(a, b, line);
		free(line);
		line = get_next_line(0);
	}
	free(line);
}

void	perform_move(t_stack **a, t_stack **b, char *line)
{
	if (ft_strncmp(line, "sa\n", ft_strlen(line)) == 0)
		swap(a, b, 'a', 0);
	else if (ft_strncmp(line, "sb\n", ft_strlen(line)) == 0)
		swap(a, b, 'b', 0);
	else if (ft_strncmp(line, "ss\n", ft_strlen(line)) == 0)
		swap(a, b, 's', 0);
	else if (ft_strncmp(line, "pa\n", ft_strlen(line)) == 0)
		push(a, b, 'a', 0);
	else if (ft_strncmp(line, "pb\n", ft_strlen(line)) == 0)
		push(a, b, 'b', 0);
	else
		perform_move2(a, b, line);
}

void	perform_move2(t_stack **a, t_stack **b, char *line)
{
	if (ft_strncmp(line, "ra\n", ft_strlen(line)) == 0)
		rotate(a, b, 'a', 0);
	else if (ft_strncmp(line, "rb\n", ft_strlen(line)) == 0)
		rotate(a, b, 'b', 0);
	else if (ft_strncmp(line, "rr\n", ft_strlen(line)) == 0)
		rotate(a, b, 'r', 0);
	else if (ft_strncmp(line, "rra\n", ft_strlen(line)) == 0)
		reverse_rotate(a, b, 'a', 0);
	else if (ft_strncmp(line, "rrb\n", ft_strlen(line)) == 0)
		reverse_rotate(a, b, 'b', 0);
	else if (ft_strncmp(line, "rrr\n", ft_strlen(line)) == 0)
		reverse_rotate(a, b, 'r', 0);
	else
	{
		free(line);
		ft_clear(a, free);
		ft_clear(b, free);
		ft_print_error();
	}
}

void	check(t_stack *a, t_stack *b)
{
	if (ft_is_sorted(a) && !b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (a)
		ft_clear(&a, free);
	if (b)
		ft_clear(&b, free);
}
