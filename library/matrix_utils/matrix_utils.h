/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 08:30:49 by ejuarros          #+#    #+#             */
/*   Updated: 2024/03/06 08:17:07 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// add to lib strcmp
#ifndef MATRIX_UTILS_H
# define MATRIX_UTILS_H

# include <stdlib.h>

void	ft_free_matrix(char **str);
size_t	ft_len_matrix(char **str);
char	**ft_add_matrix(char **str, char *s);

#endif