/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_rotate_32.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 08:42:18 by sclolus           #+#    #+#             */
/*   Updated: 2018/07/19 08:47:21 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Result is undefined if delta >= 64.
*/

INLINE uint32_t  left_rotate_64(uint64_t word, uint32_t delta)
{
	return ((word << delta) | (word >> ((sizeof(int64_t) * 8) - delta)));
}
