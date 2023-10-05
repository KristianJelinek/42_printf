/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k <k@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:40:18 by k                 #+#    #+#             */
/*   Updated: 2023/10/05 15:02:34 by k                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>


void	ft_putcharacter_len(char character, int *len);
void	ft_string(char *args, int *len);
void	ft_number(int number, int *len);
void	ft_hexadecimal(unsigned int x, int *len, char x_or_x);
void	ft_unsigned_int(unsigned int u, int *len);
void	ft_pointer(size_t pointer, int *len);
int		ft_printf(const char *string, ...);

#endif