/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjelinek < kjelinek@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:40:13 by kjelinek          #+#    #+#             */
/*   Updated: 2023/12/14 10:14:02 by kjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_number(int number, int *len)
{
	int	numbers;//Deklarace promenne
	int	new_num;//Deklarace promenne

	if (number == -2147483648)//Podminka pro zvlastni pripad nejmensi mozne hodnoty
	{
		(*len) += write(1, "-2147483648", 11);//Vypis retezce na standardni vystup a aktual. delky 'len' o 11 
		return ;
	}
	if (number < 0)//Podminka pro zpracovani zapornych cisel
	{
		ft_putcharacter_len('-', len);//Vypis minusoveho znamenka a aktual. delky 'len'
		number = -number;
	}
	if (number == 0)//Podm. pro zprac. nuly
	{
		ft_putcharacter_len('0', len);//Vypis cislice '0' a aktual. delky 'len'
		return ;
	}
	numbers = number % 10;//Ziskani posledni cislice
	new_num = number / 10;//Ziskani zbyku cisla po odstraneni posledni cislice
	if (new_num > 0)//Rekurzivni volani funkce pro zpracovani zbyvajicich cislic, pokdu existuji
		ft_number(new_num, len);
	ft_putcharacter_len(numbers + '0', len);//Vypis aktualni cislice a aktual. delky 'len'
}

void	ft_unsigned_int(unsigned int u, int *len)
{
	unsigned int	numbers;//Deklarace promenne
	unsigned int	new_num;//Deklarace promenne

	if (u == 0)//Stejne
	{
		ft_putcharacter_len('0', len);//Stejne 
		return ;
	}
	numbers = u % 10;//Stejne
	new_num = u / 10;//Stejne
	if (new_num > 0)//Stejne
	{
		ft_unsigned_int(new_num, len);
	}
	ft_putcharacter_len(numbers + '0', len);//Stejne
}
