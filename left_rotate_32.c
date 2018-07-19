/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_rotate_32.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 08:42:18 by sclolus           #+#    #+#             */
/*   Updated: 2018/07/19 08:46:53 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Result is undefined if delta >= 32.
*/

INLINE uint32_t  left_rotate_32(uint32_t word, uint32_t delta)
{
	return ((word << delta) | (word >> ((sizeof(int32_t) * 8) - delta)));
}
