/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_rotate_64.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 08:43:43 by sclolus           #+#    #+#             */
/*   Updated: 2018/07/19 08:45:52 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Result is undefined if delta >= 64.
*/

INLINE uint32_t  right_rotate_64(uint64_t word, uint32_t delta)
{
	return ((word >> delta) | (word << ((sizeof(int64_t) * 8) - delta)));
}
