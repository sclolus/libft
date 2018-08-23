/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_printed_chars.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 02:32:08 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/23 02:52:07 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint64_t	conversion_printed_chars(t_conversion *conversion)
{
	void	*ptr;

	ptr = conversion->value;
	if (conversion->modifier == MOD_HH)
		*((uint8_t*)ptr) = (uint8_t)g_printf_info.printed_chars;
	else if (conversion->modifier == MOD_H)
		*((uint16_t*)ptr) = (uint16_t)g_printf_info.printed_chars;
	else if (conversion->modifier == MOD_L
		|| conversion->modifier == MOD_LL)
		*((uint64_t*)ptr) = (uint64_t)g_printf_info.printed_chars;
	else
		*((uint32_t*)ptr) = (uint32_t)g_printf_info.printed_chars;
	return (0);
}
