/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liemi <liemi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:46:43 by liemi             #+#    #+#             */
/*   Updated: 2025/09/17 21:50:56 by liemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# if defined(__linux__)
#  define NULLPTR "(nil)"
#  define NULLPTR_LEN 5
# elif defined(__APPLE__)
#  define NULLPTR "0x0"
#  define NULLPTR_LEN 3
# endif

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *fmt, ...);
void	put_char(char c, int *count);
void	put_str(const char *s, int *count);
void	put_number(int n, int *count);
void	put_unsigned(unsigned int n, int *count);
void	ft_handle_format(char c, va_list *args, int *count);
void	put_hex(unsigned int n, int uppercase, int *count);
void	put_hex_long(unsigned long long n, int *count);
void	put_pointer(void *ptr, int *count);

#endif
