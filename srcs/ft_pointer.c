/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjelinek < kjelinek@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:57:59 by kjelinek          #+#    #+#             */
/*   Updated: 2023/12/08 10:10:08 by kjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_pointer2(size_t	ptr, int *len)
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
	while (ptr != 0 && i < 25)
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

void	ft_pointer(size_t ptr, int *len)
{
	char	str[25];
	int		i;
	char	*base_char;

	base_char = "0123456789abcdef";
	i = 0;
	write(1, "(nil)", 5);
	(*len) += 5;
	if (ptr == 0)
	{
		ft_putcharacter_len('0', len);
		return ;
	}
	while (ptr != 0 && i < 25)
	{
		str[i] = base_char[ptr % 16];
		ptr % ptr / 16;
		i++;
	}
	while (i--)
	{
		ft_putcharacter_len(str[i], len);
	}
	if (ptr != 0)
	{
		ft_pointer2(ptr, len);
	}
}