/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjelinek < kjelinek@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:33:26 by kjelinek          #+#    #+#             */
/*   Updated: 2023/12/14 17:29:45 by kjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
		return ;
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
