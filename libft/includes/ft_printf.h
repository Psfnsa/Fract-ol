/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 11:45:59 by mabanciu          #+#    #+#             */
/*   Updated: 2018/05/07 11:46:01 by mabanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <wchar.h>
# include <inttypes.h>

typedef struct		s_data
{
	int				minus;
	int				plus;
	int				space;
	int				diez;
	int				zero;
	int				width;
	int				precision;
	int				dot;
	int				hh;
	int				h;
	int				ll;
	int				l;
	int				j;
	int				z;
	int				contor;
	int				prefix;
}					t_data;

int					ft_printf(const char *format, ...);
int					print_string(char *format, va_list *arg);
int					print_specifier(char **format, va_list *arg, t_data *data);
void				init_data(t_data *data);
void				parse_flags(char **format, t_data *data);
void				parse_width(char **format, va_list *arg, t_data *data);
void				parse_length(char **format, t_data *data);
void				parse_precision(char **format, va_list *arg, t_data *data);
int					parse_specifiers(char **format, va_list *arg, t_data *data);
int					parse_specifiers2(char **format, va_list *arg,
											t_data *data);
int					parse_specifiers3(char **format, va_list *arg,
											t_data *data);
int					parse_specifiers4(char **format, va_list *arg,
											t_data *data);
int					widestr_handle(va_list *lst, t_data *f);
int					widestr_width(wchar_t *wstr, t_data *f);
int					widestr_precision(wchar_t *wstr, t_data *f);
int					wide_precision_len(wchar_t *wstr, t_data *f);
int					ft_putwidestr(wchar_t *wstr, int how_much);
int					ft_widestrlen(wchar_t *wstr);
int					widechar_handle(va_list *lst, t_data *f);
int					ft_charlen(wchar_t c);
void				ft_putwide(wchar_t c);
long long			extract_length(va_list *arg, t_data *data);
int					int_handle(va_list *arg, t_data *data);
char				*ft_itoa_long(long long int n);
char				*ft_itoa_ulong(unsigned long long int n, int base,
										int case01);
int					precision_len(char *str, t_data *data);
void				print_pad(int len, char c);
void				precision_print(char *str, t_data *data);
int					apply_flags(char *str, t_data *data, char *prefix);
unsigned long long	extract_ulength(va_list *arg, t_data *data);
int					unsigned_handle(va_list *arg, t_data *data);
int					hex_handle(va_list *arg, t_data *data, int case01);
int					precision_len(char *str, t_data *data);
int					string_handle(va_list *arg, t_data *data);
int					adress_handle(va_list *arg, t_data *data);
int					octal_handle(va_list *arg, t_data *data);
int					char_handle(va_list *arg, t_data *data);
int					n_handle(va_list *arg, t_data *data);
int					percent_handle(t_data *data);
int					undefined_handle(t_data *data, char c);
int					binary_handle(va_list *arg, t_data *data);

#endif
