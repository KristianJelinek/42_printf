/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjelinek < kjelinek@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:40:13 by kjelinek          #+#    #+#             */
/*   Updated: 2023/12/14 15:07:49 by kjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_number(int number, int *len)
{
	int	numbers;
	int	new_num;

	if (number == -2147483648)
	{
		(*len) += write(1, "-2147483648", 11);
		return ;
	}
	if (number < 0)
	{
		ft_putcharacter_len('-', len);
		number = -number;
	}
	if (number == 0)
	{
		ft_putcharacter_len('0', len);
		return ;
	}
	numbers = number % 10;
	new_num = number / 10;
	if (new_num > 0)
		ft_number(new_num, len);
	ft_putcharacter_len(numbers + '0', len);
}

void	ft_unsigned_int(unsigned int u, int *len)
{
	unsigned int	numbers;
	unsigned int	new_num;

	if (u == 0)
	{
		ft_putcharacter_len('0', len);
		return ;
	}
	numbers = u % 10;
	new_num = u / 10;
	if (new_num > 0)
	{
		ft_unsigned_int(new_num, len);
	}
	ft_putcharacter_len(numbers + '0', len);
}
