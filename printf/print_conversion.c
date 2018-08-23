/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 20:09:15 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/23 04:52:36 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline void	print_conversion(t_conversion *conversion)
{
	static const t_convertor	convertors[11] = {
		{conversion_signed_decimal, 'd', {0}},
		{conversion_signed_decimal, 'i', {0}},
		{conversion_octal, 'o', {0}},
		{conversion_unsigned_decimal, 'u', {0}},
		{conversion_small_hex, 'x', {0}},
		{conversion_capital_hex, 'X', {0}},
		{conversion_char, 'c', {0}},
		{conversion_string, 's', {0}},
		{conversion_pointer, 'p', {0}},
		{conversion_printed_chars, 'n', {0}},
		{conversion_modulo, '%', {0}},
	};
	uint32_t					i;

	i = 0;
	while (i < sizeof(convertors) / sizeof(*convertors))
	{
		if (conversion->conversion == convertors[i].id)
			g_printf_info.printed_chars += convertors[i].convertor(conversion);
		i++;
	}
}
