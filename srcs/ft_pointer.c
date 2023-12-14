/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjelinek < kjelinek@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:57:59 by kjelinek          #+#    #+#             */
/*   Updated: 2023/12/14 09:23:23 by kjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void ft_pointer2(size_t ptr, int *len)
{
    char	str[25];
    int		i;
    char	*base_char;

    // Pole znaků pro reprezentaci hexadecimálních číslic
    base_char = "0123456789abcdef";
    // Inicializace indexu pro pole znaků
    i = 0;
    // Výpis "0x" a aktualizace délky
    write(1, "0x", 2);
    (*len) += 2;
    // Zvláštní případ pro nulu
    if (ptr == 0)
    {
        ft_putcharacter_len('0', len);
        return;
    }
    // Převod na hexadecimální reprezentaci
    while (ptr != 0 && i < 25)
    {
        str[i] = base_char[ptr % 16]; // Získání hexadecimální číslice
        ptr = ptr / 16; // Získání další části čísla
        i++;
    }
    // Výpis hexadecimální reprezentace
    while (i--)
    {
        ft_putcharacter_len(str[i], len); // Výpis aktuální číslice a aktualizace délky
    }
}

void ft_pointer(size_t ptr, int *len)
{
    char str[25];
    int i;
    char *base_char;
    // Pole znaků pro reprezentaci hexadecimálních číslic
    base_char = "0123456789abcdef";
    // Inicializace indexu pro pole znaků
    i = 0;
    // Výpis "(nil)" a aktualizace délky
    write(1, "(nil)", 5);
    *len += 5;
    // Zvláštní případ pro nulový ukazatel
    if (!ptr)
        return (ft_putcharacter_len('0', len));
    // Převod na hexadecimální reprezentaci
    while (ptr != 0 && i < 25)
    {
        str[i++] = base_char[ptr % 16]; // Získání hexadecimální číslice
        ptr /= 16; // Získání další části čísla
    }
    // Výpis hexadecimální reprezentace
    while (i--)
        ft_putcharacter_len(str[i], len); // Výpis aktuální číslice a aktualizace délky
    // Pokud zbyly další číslice, zavoláme druhou funkci pro další převod
    if (ptr != 0)
        ft_pointer2(ptr, len);
}
