/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjelinek < kjelinek@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:57:59 by kjelinek          #+#    #+#             */
/*   Updated: 2023/12/14 11:08:58 by kjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_pointer2(size_t ptr, int *len)
{
	char str[25] = {0};  // Inicializace pole na nulové hodnoty
	int i = 0;
	char *base_char = "0123456789abcdef";
	// Speciální případ pro nulu
	if (ptr == 0)
	{
		ft_putcharacter_len('0', len);
		return ;
	}
	// Převod na hexadecimální reprezentaci
	while (ptr != 0 && i < 24)
	{
		str[i] = base_char[ptr % 16];
		ptr /= 16;
		i++;
	}
	// Výpis hexadecimální reprezentace
	while (i--)
		ft_putcharacter_len(str[i], len);
}

void	ft_pointer(size_t ptr, int *len)
{
	char str[25] = {0};  // Inicializace pole na nulové hodnoty
	int i = 0;
	char *base_char = "0123456789abcdef";
	// Speciální případ pro nulový ukazatel
	if (!ptr)
	{
		write(1, "(nil)", 5);
		*len += 5;
		return ;
	}
	// Převod na hexadecimální reprezentaci
	while (ptr != 0 && i < 24)
	{
		str[i++] = base_char[ptr % 16];
		ptr /= 16;
	}
	// Výpis hexadecimální reprezentace
	while (i--)
	{
		ft_putcharacter_len(str[i], len);
	}
}

int main() {
    size_t test_ptr = 12345; // Změňte na libovolnou testovací hodnotu
    int length = 0;

    ft_pointer(test_ptr, &length);
    printf("\nDélka výstupu: %d\n", length);

    return 0;
}
