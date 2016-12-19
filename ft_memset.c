/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:34:38 by sclolus           #+#    #+#             */
/*   Updated: 2016/11/07 19:04:55 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
  unsigned int	i;
  unsigned long	magicbit;

  i = 0;
  magicbit = c | c << 8 | c << 16 | c << 24 | (long)c << 32 | (long)c << 40 | (long)c << 48
    | (long)c << 56;
  while (i < len % 8)
    ((unsigned char*)b)[i++] = c;
  while (i < len)
    {
      *((unsigned long*)(b + i)) = magicbit;
      i += 8;
    }
  return (b);
}
