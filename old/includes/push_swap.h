/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:54:34 by elena             #+#    #+#             */
/*   Updated: 2024/06/28 09:18:01 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>

# ifndef NUL
#  define NUL 0
# endif

# include "../library/library.h"

/** @struct s_stack
 * 
 *  @brief node of a stack
 * 
 *  @param num number
 * 
 *  @param next pointer to the next node
 * 
 *  -- MOVEMENTS --
 *  @param ra ra (+) & rra (-)
 *  @param rb rb (+) & rrb (-)
 *  @param rr rr
 *  @param rrr rrr
 *  @param moves total number of movements
*/
typedef struct s_stack
{
	long			num;
	struct s_stack	*next;
	int				ra;
	int				rb;
	int				rr;
	int				rrr;
	int				moves;
}					t_stack;

// ------------------ Rules (movements) ------------------

/** @brief Swaps the first two elements of the stack
 * 
 *  @param a stack a
 *  @param b stack b
 *  @param c stack to swap (s for both)
 *  @param w write enable
*/
void	swap(t_stack **a, t_stack **b, int c, int w);

/** @brief Pushes the first element of one stack into another
 * 
 *  @param a stack a
 *  @param b stack b
 *  @param c stack to push into
 *  @param w writ enable
*/
void	push(t_stack **a, t_stack **b, int c, int w);

/** @brief Rotates (move up) the elements of the stack
 * 
 *  @param a stack a
 *  @param b stack b
 *  @param c stack to rotate (r for both)
 *  @param w write enable
*/
void	rotate(t_stack **a, t_stack **b, int c, int w);

/** @brief Reverse rotates (move down) the elements of the stack
 * 
 *  @param a stack a
 *  @param b stack b
 *  @param c stack to reverse rotate (r for both)
 *  @param w write enable
*/
void	reverse_rotate(t_stack **a, t_stack **b, int c, int w);

// ------------------ main.c ------------------

/** @brief Displays on the console the current state of the stacks
 * 
 *  @param a stack a
 *  @param b stack b
*/
void	print_stacks(t_stack const *a, t_stack const *b, char *msg);

// ------------------ ft_init.c ------------------

/** @brief Initializes the stack a with the arguments passed
 * 
 *  @param argc number of arguments passed
 *  @param argv arguments passed
 * 
 *  @return stack a
*/
t_stack	*ft_init(int argc, char **argv);

// ------------------ ft_error.c ------------------

/** @brief Prints "Error\\n" to the standard error output */
void	ft_print_error(void);

// ------------------ list_utils.c ------------------

/**  @brief Adds a node at the end of the list
 * 
 * 	@param lst double pointer to the list
 * 	@param new node to add to the list
*/
void	ft_add_back(t_stack **stack, t_stack *new);

/** @brief Finds the last node of the list
 * 
 * 	@param lst pointer to the list
 * 
 * 	@return last node of the list
*/
t_stack	*ft_last(t_stack *stack);

/** @brief Creates a new nod
 * 
 * 	@param content pointer to the content
 * 
 * 	@return new node
*/
t_stack	*ft_new(int content);

/** @brief Counts the number of nodes of a list
 * 
 * 	@param lst pointer to the list
 * 	@return number of nodes of the list
*/
int		ft_size(t_stack *stack);

// ------------------ list_utils2.c ------------------

/** @brief Deletes and frees a node and all the consecutive ones
 *
 * 	@param lst double pointer to the list
 * 	@param new pointer to a delete function
*/
void	ft_clear(t_stack **stack, void (*del)(void *));

/** @brief Frees the memory of the content and its node
 * 
 * 	@param lst double pointer to the list
 * 	@param new pointer to a delete function
*/
void	ft_delone(t_stack *stack, void (*del)(void *));

// ------------------ ft_sort.c ------------------

/** @brief Sorts a stack
 * 
 *  @param a stack to sort
*/
void	ft_sort(t_stack **a);

/** @brief Sorts a stack of three elements
 * 
 *  @attention Check stack is not ordered
 * 
 *  @param a stack to sort
*/
void	ft_sort_three(t_stack **a);

/** @brief Sorts a stack of more than three elements
 * 
 * @param a stack to sort
*/
void	ft_sort_big(t_stack **a);

/** @brief Places the lowest element at the top of the stack
 * 
 * @param a stack a
*/
void	ft_place_head(t_stack **a);

// ------------------ ft_is_sorted.c ------------------

/** @brief Checks whether a stack is sorted
 * 
 *  @param stack stack to check
 * 
 *  @retval 1 if it is sorted
 *  @retval 0 otherwise
*/
int		ft_is_sorted(t_stack const *stack);

// ------------------ ft_find.c ------------------

/** @brief Finds the minimum number in the stack
 * 
 *  @param stack stack to search
 * 
 *  @return minimum value
*/
int		ft_find_min(t_stack const *stack);

/** @brief Finds the maximum number in the stack
 * 
 *  @param stack stack to search
 * 
 *  @return maximum value
*/
int		ft_find_max(t_stack const *stack);

/** @brief Finds the index of a number in the stack
 * 
 *  @param stack stack
 *  @param num number to search
 * 
 *  @return index of the number
*/
int		ft_find_idx(t_stack const *stack, int num);

// ------------------ ft_dup_number.c ------------------

/** @brief Checks if there are duplicate numbers in the stack
 * 
 *  @param stack stack to check
 * 
 *  @retval 0 if there are no duplicates
 *  @retval 1 if there are duplicates
*/
int		ft_dup_number(t_stack const *stack);

// ------------------ ft_sort_big.c ------------------

/** @brief Initializes the movement fields to order the stack
 * 
 * @param a stack a
 * @param b stack b
*/
void	ft_init_moves(t_stack **a, t_stack **b);

/** @brief Moves the cheapest element from stack b to stack a
 * 
 *  @param a stack a
 *  @param b stack b
*/
void	ft_move_cheapest(t_stack **a, t_stack **b);

// ------------------ utils.c ------------------

/** @brief Absolute value of a number
 * 
 * @param n number
 * 
 * @return absolute value of n
*/
int		abs(int n);

/** @brief Checks if a number is between two others
 * 
 * @param lim1 limit of the interval
 * @param lim2 limit of the interval
 * @param n number to check
 * 
 * @retval 1 if it is in the interval
 * @retval 0 otherwise
*/
int		ft_in_between(int lim1, int lim2, int n);

/** @brief Sets all the movement variables to zero
 * 
 * @param stack stack to set to zero
*/
void	ft_set_zero(t_stack *stack);

// ------------------ ft_calc_moves.c ------------------

/** @brief Calculates the movements to insert an element in stack a in its
 * 	correct position
 * 
 * @param a stack a
 * @param b stack b
*/
void	ft_calc_moves_a(t_stack *a, t_stack *b);

/** @brief Calculates the movements to put an element in stack b in the first
 *  position
 * 
 * @param b stack b
*/
void	ft_calc_moves_b(t_stack *b);

/** @brief Adjusts the movements to use rr and rrr
 * 
 * @param b stack b
*/
void	ft_adjust_moves(t_stack *b);

#endif