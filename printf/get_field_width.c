/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_field_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:41:10 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/22 17:42:00 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint64_t	get_field_width(const char *str, t_conversion *conversion)
{
	uint64_t	i;

	conversion->field_width = ft_atollu(str);
	i = 0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	return (i);
}
