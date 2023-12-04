/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjelinek < kjelinek@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:48:23 by k                 #+#    #+#             */
/*   Updated: 2023/12/04 08:35:59 by kjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putcharacter_len(char character, int *len)
{
	write(1, &character, 1);
	(*len)++;
}
void	ft_string(char *args, int *len)
{
	size_t	i;
	
	i = 0;
	if (!args)
	{
		write(1, "(null)", 6);
		(*len) += 6;
		return ;
	}
	while (args[i] != '\0')
	{
		ft_putcharacter_len(args[i], len);
		i++;
	}
}
