/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:18:42 by ejuarros          #+#    #+#             */
/*   Updated: 2024/09/02 11:41:13 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/** @brief modified atoi function to check for errors
 * 
 *  @details If any errors occur, turn the error flag to true.
 * 
 *  @param nptr string to convert to integer
 *  @param error error flag
 * 
 *  @return integer
*/
static int	ft_atoi_v2(const char *nptr, int *error)
{
	long int	num;
	int			sign;

	num = 0;
	sign = 1;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n'
		|| *nptr == '\v' || *nptr == '\r' || *nptr == '\f')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (!ft_isdigit(*(nptr + 1)))
			*error = 1;
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (nptr && *nptr)
	{
		if (!ft_isdigit(*nptr))
			*error = 1;
		num = num * 10 + (*(nptr++) - '0');
	}
	if ((num * sign) > INT_MAX || (num * sign) < INT_MIN)
		*error = 1;
	return (num * sign);
}

static void	parse_loop(char **input, t_stack **a)
{
	int	i;
	int	error;
	int	num;

	i = 0;
	while (input && input[i])
	{
		error = 0;
		num = ft_atoi_v2(input[i], &error);
		if (error == 1)
		{
			ft_free_matrix(input);
			ft_clear(a, free);
			ft_print_error();
		}
		ft_add_back(a, ft_new(num));
		i++;
	}
}

/** @brief parses the input
 * 
 *  @details Split the string using ' ' as separator and add nodes to the
 *  list with the result of applying atoi.
 * 
 * 	If there occurs an error in the execution of the atoi, free all the 
 *  memory and print the error message.
 * 
 *  Free the result from the split at the end. 
 * 
 *  @param argv string to parse
 *  @param a stack to add the parsed input
 * 
 *  @return void
*/
static void	ft_parse_input(char *argv, t_stack **a)
{
	char	**input;

	input = ft_split(argv, ' ');
	if (!input || !input[0])
	{
		if (input)
			free(input);
		ft_print_error();
	}
	parse_loop(input, a);
	ft_free_matrix(input);
}

/**
 * @details If the are less than 2 arguments (only the executable file
 * called), return control to the user.
 * Otherwise, parse the input.
*/
t_stack	*ft_init(int argc, char **argv)
{
	t_stack	*a;
	int		i;

	a = NULL;
	if (argc < 2)
		exit(0);
	else
	{
		i = 1;
		while (i < argc)
		{
			ft_parse_input(argv[i], &a);
			i++;
		}
	}
	return (a);
}
