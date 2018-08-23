/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conversion_flag.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:11:22 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/23 05:00:04 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int32_t	get_conversion_flag(const char *str, t_conversion *conversion)
{
	static const char						flags[SUPPORTED_FLAGS_NBR] = {
		'#', '0', '-', ' ', '+',
	};
	static const t_f_flags_parsing_callback	callbacks[SUPPORTED_FLAGS_NBR] = {
		sharp_flag_callback, zero_pad_flag_callback, negative_flag_callback,
		space_flag_callback, plus_flag_callback,
	};
	uint32_t								i;

	if (!*str)
		return (-1);
	i = 0;
	while (i < SUPPORTED_FLAGS_NBR)
	{
		if (flags[i] == *str)
		{
			callbacks[i](conversion);
			return (1);
		}
		i++;
	}
	return (0);
}
