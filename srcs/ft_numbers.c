/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k <k@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 07:58:43 by k                 #+#    #+#             */
/*   Updated: 2023/10/01 17:32:57 by k                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_number(int number, int *len)
{
	if ( number == -2147483648)
	{
		write(1, "-2147483648", 11);
			(len) += 11;
			return ;
	}
	if (number < 0)
	{
		ft_putcharacter_len('-', len);
		ft_number(number * -1, len);
	}
	else
	{
		if (number > 9)
		{
			ft_number(number / 10, len);
			ft_putcharacter_len(number % 10 + '0', len);
		}
	}
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

