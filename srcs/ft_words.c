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

void ft_putcharacter_len(char c, int *len)
{
    // Výpis jednoho znaku na standardní výstup
    write(1, &c, 1);
    
    // Aktualizace délky vytvořeného textu
    (*len)++;
}

void ft_string(char *args, int *len)
{
    size_t i;

    // Inicializace indexu pro postupné procházení řetězce
    i = 0;

    // Zvláštní případ pro NULL řetězec
    if (!args)
    {
        write(1, "(null)", 6);
        (*len) += 6;
        return;
    }

    // Postupné procházení řetězce
    while (args[i] != '\0')
    {
        // Volání funkce pro výpis jednoho znaku a aktualizace délky
        ft_putcharacter_len(args[i], len);
        i++;
    }
}
