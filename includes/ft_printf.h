/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjelinek < kjelinek@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:33:08 by kjelinek          #+#    #+#             */
/*   Updated: 2023/12/14 17:27:43 by kjelinek         ###   ########.fr       */
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
void	ft_putcharacter_len(char c, int *len);

#endif
