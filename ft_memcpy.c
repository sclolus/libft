/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:02:41 by sclolus           #+#    #+#             */
/*   Updated: 2016/11/04 16:42:26 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
  unsigned long	*longword_ptr;
  unsigned int	i;

  i = 0;
  while (i < n)
    {
      ((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
      i++;
    }
  longword_ptr = (unsigned long*)(src + i);
  while (i < n)
    {
      *((unsigned long*)(dst + i)) = *longword_ptr++;
      i += 8;
    }
  return (dst);
}
