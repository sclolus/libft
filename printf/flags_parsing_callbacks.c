/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_parsing_callbacks.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:12:05 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/22 17:12:58 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	sharp_flag_callback(t_conversion *conversion)
{
	conversion->flags.sharp = 1;
}

void	zero_pad_flag_callback(t_conversion *conversion)
{
	if (conversion->flags.negative)
		conversion->flags.zero_pad = 0;
	else
		conversion->flags.zero_pad = 1;
}

void	negative_flag_callback(t_conversion *conversion)
{
	conversion->flags.negative = 1;
	conversion->flags.zero_pad = 0;
}

void	space_flag_callback(t_conversion *conversion)
{
	if (conversion->flags.plus)
		conversion->flags.space = 0;
	else
		conversion->flags.space = 1;
}

void	plus_flag_callback(t_conversion *conversion)
{
	conversion->flags.plus = 1;
	conversion->flags.space = 0;
}
