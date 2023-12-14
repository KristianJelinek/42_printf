/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjelinek < kjelinek@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:33:48 by kjelinek          #+#    #+#             */
/*   Updated: 2023/12/14 15:56:16 by kjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	g_hex[] = "0123456789abcdef";

void	ft_putpointer(size_t ptr, int *len)
{
	char	str[25];
	int		i;

	i = 0;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		*len += 5;
		return ;
	}
	while (ptr != 0)
	{
		str[i++] = g_hex[ptr % 16];
		ptr /= 16;
	}
	write(1, "0x", 2);
	*len += 2;
	while (i--)
		ft_putcharacter_len(str[i], len);
}

void	ft_pointer(size_t ptr, int *len)
{
	ft_putpointer(ptr, len);
}
