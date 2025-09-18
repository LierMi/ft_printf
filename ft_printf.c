/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liemi <liemi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:57:15 by liemi             #+#    #+#             */
/*   Updated: 2025/09/18 20:11:12 by liemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_percent(int *count)
{
	put_char('%', count);
}

void	ft_handle_format(char c, va_list *args, int *count)
{
	if (*count == -1)
		return ;
	if (c == 'd' || c == 'i')
		put_number(va_arg(*args, int), count);
	else if (c == 'c')
		put_char((char)va_arg(*args, int), count);
	else if (c == 's')
		put_str(va_arg(*args, char *), count);
	else if (c == '%')
		put_percent(count);
	else if (c == 'u')
		put_unsigned(va_arg(*args, unsigned int), count);
	else if (c == 'x')
		put_hex(va_arg(*args, unsigned int), 0, count);
	else if (c == 'X')
		put_hex(va_arg(*args, unsigned int), 1, count);
	else if (c == 'p')
		put_pointer(va_arg(*args, void *), count);
}

int	ft_printf(const char *fmt, ...)
{
	int		count;
	int		i;
	va_list	ap;

	va_start(ap, fmt);
	i = 0;
	count = 0;
	while (fmt && fmt[i] && count != -1)
	{
		if (fmt[i] == '%' && fmt[i + 1])
		{
			ft_handle_format(fmt[i + 1], &ap, &count);
			i += 2;
			continue ;
		}
		put_char(fmt[i], &count);
		i++;
	}
	va_end(ap);
	return (count);
}
