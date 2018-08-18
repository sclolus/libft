/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_rotate_32.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 08:45:25 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/18 04:05:02 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Result is undefined if delta >= 32.
*/

uint32_t	right_rotate_32(uint32_t word, uint32_t delta)
{
	return ((word >> delta) | (word << ((sizeof(int32_t) * 8) - delta)));
}
