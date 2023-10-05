/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k <k@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 07:58:43 by k                 #+#    #+#             */
/*   Updated: 2023/10/05 15:00:24 by k                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_number(int number, int *len)
{
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
		return;
	}
	if (number < 0)
	{
		ft_putcharacter_len('-', len);
		number = -number;
	}
	if (number == 0)
	{
		ft_putcharacter_len('0', len);
		return;
	}
		int	numbers = number % 10;
		int	new_num = number / 10;
		
	if (new_num > 0)
    	{
			ft_number(new_num, len);
		}
    	ft_putcharacter_len(numbers + '0', len);
}
void	ft_pointer(size_t ptr, int *len)
{
	char	str[25];
	int		i;
	char	*base_char;

	base_char = "0123456789abcdef";
	i = 0;
	write(1, "0x", 2);
	(*len) += 2;
	if (ptr == 0)
	{
		ft_putcharacter_len('0', len);
		return ;
	}
	while (ptr != 0)
	{
		str[i] = base_char[ptr % 16];
		ptr = ptr / 16;
		i++;
	}
	while (i--)
	{
		ft_putcharacter_len(str[i], len);
	}
}

void	ft_hexadecimal(unsigned int x, int *len, char x_or_x)
{
	char	str[25];
	char	*base_char;
	int		i;

	if (x_or_x == 'X')
		base_char = "0123456789ABCDEF";
	else
		base_char = "0123456789abcdef";
	i = 0;
	if (x == 0)
	{
		ft_putcharacter_len('0', len);
		return;
	}
	while (x != 0)
	{
		str[i] = base_char[x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
		ft_putcharacter_len(str[i], len);
}

void	ft_unsigned_int(unsigned int u, int *len)
{
	if (u >= 10)
		ft_unsigned_int(u / 10, len);
		ft_putcharacter_len(u % 10 + '0', len);
}
