/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 16:33:00 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/23 05:43:09 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int64_t		get_conversion(const char *str,
						va_list *v_arg,
						t_conversion *conversion)
{
	uint64_t	i;

	if (*str != '%')
		return (-1);
	i = 1;
	while (str[i])
	{
		if (get_conversion_flag(str + i, conversion) != 1)
			break ;
		i++;
	}
	i += get_field_width(str + i, conversion);
	i += get_precision(str + i, conversion);
	i += get_length_modifier(str + i, conversion);
	if (-1 == get_conversion_type(str + i, conversion))
		return (-1);
	i++;
	get_va_arg_value(v_arg, conversion);
	return ((int64_t)i);
}
