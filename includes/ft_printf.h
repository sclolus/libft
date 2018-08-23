/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 16:06:35 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/23 05:49:20 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <stdio.h>
# include <assert.h>

# define SUPPORTED_CONVERSIONS (sizeof(PRINTF_CONVERSION_FLAGS) - 1)
# define PRINTF_CONVERSION_FLAGS "diouxXcspn%"
# define SUPPORTED_FLAGS_NBR 5

int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);

typedef struct	s_conversion_flags
{
	uint8_t		sharp : 1;
	uint8_t		zero_pad : 1;
	uint8_t		negative : 1;
	uint8_t		space : 1;
	uint8_t		plus : 1;
	uint8_t		pad : 3;
}				t_conversion_flags;

# define MODIFIER_HH "hh"
# define MODIFIER_H "h"
# define MODIFIER_L "l"
# define MODIFIER_LL "ll"

typedef enum	e_len_modifier
{
	MOD_HH = 0,
	MOD_H,
	MOD_L,
	MOD_LL,
	SUPPORTED_LEN_MODIFIERS,
	NO_MODIFIER = SUPPORTED_LEN_MODIFIERS,
}				t_len_modifier;

typedef struct	s_conversion
{
	void				*value;
	uint64_t			field_width;
	uint64_t			precision;
	t_len_modifier		modifier;
	t_conversion_flags	flags;
	char				conversion;
	uint8_t				pad[2];
}				t_conversion;

typedef struct	s_convertor
{
	uint64_t	(*convertor)(t_conversion *conversion);
	char		id;
	uint8_t		pad[7];
}				t_convertor;

typedef struct	s_printf_info
{
	uint64_t	printed_chars;
	int			printing_fd;
	uint8_t		pad[4];
}				t_printf_info;

extern t_printf_info	g_printf_info;

uint64_t		process_conversion(va_list *v_arg,
							const char *format,
							uint64_t index);
void			print_conversion(t_conversion *conversion);

uint64_t		get_field_width(const char *str, t_conversion *conversion);
int64_t			get_conversion(const char *str,
						va_list *v_arg,
						t_conversion *conversion);

typedef void	(*t_f_flags_parsing_callback)(t_conversion *conversion);

int32_t			get_conversion_flag(const char *str, t_conversion *conversion);
void			sharp_flag_callback(t_conversion *conversion);
void			zero_pad_flag_callback(t_conversion *conversion);
void			negative_flag_callback(t_conversion *conversion);
void			space_flag_callback(t_conversion *conversion);
void			plus_flag_callback(t_conversion *conversion);

uint64_t		get_precision(const char *str, t_conversion *conversion);
uint64_t		get_length_modifier(const char *str, t_conversion *conversion);
int32_t			get_conversion_type(const char *str, t_conversion *conversion);
void			get_va_arg_value(va_list *v_arg, t_conversion *conversion);

/*
** Field width handling
*/

uint64_t		print_left_padding(t_conversion *conversion, uint64_t len);

/*
** Conversion functions
*/

# define SMALL_HEX_BASE "0123456789abcdef"
# define HEX_BASE "0123456789ABCDEF"
# define OCTAL_BASE "01234567"

uint64_t		conversion_signed_decimal(t_conversion *conversion);
uint64_t		conversion_unsigned_decimal(t_conversion *conversion);
uint64_t		conversion_small_hex(t_conversion *conversion);
uint64_t		conversion_capital_hex(t_conversion *conversion);
uint64_t		conversion_octal(t_conversion *conversion);
uint64_t		conversion_char(t_conversion *conversion);
uint64_t		conversion_string(t_conversion *conversion);
uint64_t		conversion_pointer(t_conversion *conversion);
uint64_t		conversion_printed_chars(t_conversion *conversion);
uint64_t		conversion_modulo(t_conversion *conversion);
#endif
