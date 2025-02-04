/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 00:03:55 by TakeshiKawa       #+#    #+#             */
/*   Updated: 2025/02/02 19:04:45 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_format(char format, va_list args);
int	ft_printchar(int num);
int	ft_printstr(char *str);

int	ft_printptr(char *ptr);
int	ft_putptr(uintptr_t num);
int	ft_ptrlen(uintptr_t num);

int	ft_puthex(unsigned int num, char format);
int	ft_hexlen(unsigned int num);
int	ft_printhex(unsigned int num, char format);

int	ft_printint(int num);
int	ft_putint(int num);
int	ft_intlen(int num);

int	ft_printuint(unsigned int num);
int	ft_putuint(unsigned int num);
int	ft_uintlen(unsigned int num);

#endif
