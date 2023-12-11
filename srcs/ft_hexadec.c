/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjelinek < kjelinek@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:33:26 by kjelinek          #+#    #+#             */
/*   Updated: 2023/12/10 14:33:28 by kjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_hexadecimal(unsigned int x, int *len, char x_or_x)
{
	char	str[25];//Deklarace promenne
	char	*base_char;//Deklarace promenne
	int		i;//Deklarace promenne

	if (x_or_x == 'X')//Nastaveni pole hodnoty x_or_x. Pokud x_or_x je 'X' pouzijeme velka pismena jinak mala
		base_char = "0123456789ABCDEF";
	else
		base_char = "0123456789abcdef";
	i = 0;//Inicializace proměnné 'i' na 0 pro pozdější použití jako index pole
	if (x == 0)//Podmínka pro zvláštní případ, kdy je vstupní číslo x rovno 0. V tomto případě se vytiskne '0' a funkce končí.
	{
		ft_putcharacter_len('0', len);
		return ;
	}
	while (x != 0)//Cyklus, který převede číslo x na hexadecimální reprezentaci.
	{
		str[i] = base_char[x % 16];//str[i] = base_char[x % 16]; Získání hexadecimální číslice pro aktuální zbytek při dělení x 16. Tato číslice se uloží do pole str.
		x = x / 16;//x = x / 16;: Získání další části čísla pro další iteraci cyklu.
		i++;//i++;: Inkrementace indexu pole str pro uložení další hexadecimální číslice.
	}
	while (i--)//Cyklus pro výpis hexadecimální reprezentace zpětně od poslední číslice.
		ft_putcharacter_len(str[i], len);//ft_putcharacter_len(str[i], len);: Volání jiné funkce (ft_putcharacter_len), která vytiskne aktuální číslici hexadecimální reprezentace a aktualizuje délku výstupu.
}
