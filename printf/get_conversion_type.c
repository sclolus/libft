/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conversion_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:42:40 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/22 17:46:23 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int32_t	get_conversion_type(const char *str, t_conversion *conversion)
{
	if (ft_strchr(PRINTF_CONVERSION_FLAGS, *str))
	{
		conversion->conversion = *str;
		return (0);
	}
	return (-1);
}
