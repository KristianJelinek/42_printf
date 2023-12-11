/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjelinek < kjelinek@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:05:57 by k                 #+#    #+#             */
/*   Updated: 2023/12/04 08:35:42 by kjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void ft_printf_check(char s, va_list *args, int *len, int *i)
{
    // Rozpoznání formátovacího specifikátoru a volání odpovídající funkce pro zpracování
    if (s == 's')
        ft_string(va_arg(*args, char *), len);
    else if (s == 'd' || s == 'i')
        ft_number(va_arg(*args, int), len);
    else if (s == 'u')
        ft_unsigned_int(va_arg(*args, unsigned int), len);
    else if (s == 'x')
        ft_hexadecimal(va_arg(*args, unsigned int), len, 'x');
    else if (s == 'X')
        ft_hexadecimal(va_arg(*args, unsigned int), len, 'X');
    else if (s == 'p')
        ft_pointer(va_arg(*args, size_t), len);
    else if (s == 'c')
        ft_putcharacter_len(va_arg(*args, int), len);
    else if (s == '%')
        ft_putcharacter_len('%', len);
    else
        (*i)--;
}

int ft_printf(const char *string, ...)
{
    va_list args;
    int i;
    int len;

    // Inicializace indexu i a délky výstupu
    i = 0;
    len = 0;

    // Inicializace proměnné argumentů
    va_start(args, string);

    // Zpracování řetězce formátu
    while (string[i] != '\0')
    {
        if (string[i] == '%')
        {
            i++; // Přeskočení znaku '%'
            ft_printf_check(string[i], &args, &len, &i); // Zpracování formátovacího specifikátoru
            i++; // Přeskočení zpracovaného specifikátoru
        }
        else
        {
            ft_putcharacter_len((char)string[i], &len); // Výpis běžného znaku
            i++; // Přeskočení běžného znaku
        }
    }

    // Ukončení práce s proměnnými argumenty
    va_end(args);

    // Vrácení celkové délky vytvořeného textu
    return (len);
}
