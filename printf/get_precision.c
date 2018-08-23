/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:21:43 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/22 17:53:23 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint64_t	get_precision(const char *str, t_conversion *conversion)
{
	uint64_t	i;

	if (*str != '.')
	{
		conversion->precision = 0;
		return (0);
	}
	str++;
	conversion->precision = ft_atollu(str);
	i = 0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	return (i + 1);
}
