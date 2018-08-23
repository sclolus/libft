/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_va_arg_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 19:57:33 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/23 04:50:28 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		*ft_signed_cast(void *value, t_conversion *arg)
{
	if (arg->modifier == MOD_L)
		return ((void *)(uint64_t)value);
	else if (arg->modifier == MOD_LL)
		return ((void *)(uint64_t)value);
	else if (arg->modifier == MOD_H)
		return ((void *)(uint64_t)(int16_t)value);
	else if (arg->modifier == MOD_HH)
		return ((void *)(uint64_t)(char)value);
	else
		return ((void *)(uint64_t)(int32_t)value);
}

static void		*ft_unsigned_cast(void *value
										, t_conversion *arg)
{
	if (arg->modifier == MOD_L)
		return ((void *)(uint64_t)(uint64_t)value);
	else if (arg->modifier == MOD_LL)
		return ((void *)(uint64_t)(int64_t)value);
	else if (arg->modifier == MOD_H)
		return ((void *)(uint64_t)(uint16_t)value);
	else if (arg->modifier == MOD_HH)
		return ((void *)(uint64_t)(uint8_t)value);
	else
		return ((void *)(uint64_t)(uint32_t)value);
}

static void		*argument_cast(void *value, t_conversion *arg)
{
	if (ft_strchr("Ddi", arg->conversion))
		return (ft_signed_cast(value, arg));
	else if (ft_strchr("xXou", arg->conversion))
		return (ft_unsigned_cast(value, arg));
	return (value);
}

void			get_va_arg_value(va_list *v_arg, t_conversion *conversion)
{
	void	*value;

	value = va_arg(*v_arg, void *);
	conversion->value = argument_cast(value, conversion);
}
