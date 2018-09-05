/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarjane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 05:12:09 by cfarjane          #+#    #+#             */
/*   Updated: 2018/09/04 12:25:41 by cfarjane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include <stdint.h>
# include "./libft.h"
# include <stdio.h>

/*
** _________________________
**| 1 |  2 | 3 |  4 | 5 | 6 |
**| l | ll | h | hh | j | z |  length
** -------------------------
** ________________________________________
**|    0   |    1    |   2   |  3  |   4   |
**|  d i D | o O u U | x X p | c C |  s S  |  conv
** ----------------------------------------
** _________________________________________________________
**| % | #+-0sp | digit | .digit | hlhhlljz | diDoOuUxXpsScC |
**| % | option | width | precis |  length  |   conversion   |  printf
** ---------------------------------------------------------
**
** 0xxxxxxx -> < 0x7F
** 110xxxxx  10xxxxxx -> < 0x7FF
** 1110xxxx  10xxxxxx  10xxxxxx -> < 0xFFFF
** 11110xxx  10xxxxxx  10xxxxxx  10xxxxxx -> < 0x10FFFF
*/

typedef struct		s_flags
{
	int				pre;
	int				width;
	int				zero;
	int				hash;
	int				space;
	int				plus;
	int				minus;
	int				length;
	int				len;
	int				ret;
	int				plus_c;
	int				neg;
	char			*x;
	char			*bigx;
	int				cheat;
	char			*tmp;
	int				spe;
}					t_flags;

/*
** permet le return des octets écrits
*/
typedef struct		s_ret
{
	size_t			written;
}					t_ret;

/*
** Checks
*/
void				check_precision(char **format, t_flags *flag);
void				check_width(char **format, t_flags *flag);
void				check_flags(char **format, t_flags *flag);
void				check_length(char **format, t_flags *flag);
int					ft_isconv(char c);
int					ft_isflag(char c);
int					ft_islength(char c);

/*
** Conversions
*/
int					ft_cconv(char *format, va_list ap, t_flags *flag);
uintmax_t			ft_hexaconv(char *format, va_list ap, t_flags *flag);
int					ft_sconv(char *format, va_list ap, t_flags *flag);
unsigned long long	ft_ouconv(char *format, va_list ap, t_flags *flag);

/*
** Prints
*/
int					ft_print_unsigned(unsigned long long n, int base, int maj);
int					ft_final_print(char **format, va_list ap);
int					print_conversion(char *fmt, va_list ap, t_flags *flag);
int					ft_printf(const char *format, ...);
int					ft_print_hexa(char *fmt, va_list ap, t_flags *flag);
int					ft_print_octal(char *fmt, va_list ap, t_flags *flag);
int					ft_print_decimal(char *format, va_list ap, t_flags *flag);

/*
** Options
*/
int					print_zero_decimal(char *s, t_flags *f, int ret, char *fmt);
int					print_zero_char(t_flags *flag, int ret);
int					width_prec_decimal(t_flags *f, char *s, char *fmt, int n);
int					width_char(t_flags *flag, int ret);
int					print_minus(char *s, t_flags *f, int ret, char *fmt);
int					print_minus_char(char c, t_flags *flag, int ret);
int					minus_str(t_flags *flag, char *str, int ret);
int					minus_wstr(t_flags *flag, wchar_t *wstr, int ret);
int					width_prec_wstr(t_flags *flag, wchar_t *wstr, int ret);
int					cheat_width_wstr(t_flags *f, int len, wchar_t *w, int ret);
int					wwdpc_next(t_flags *flag, wchar_t *wstr, int ret);

#endif
