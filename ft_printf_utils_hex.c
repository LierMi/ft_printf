/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liemi <liemi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:24:48 by liemi             #+#    #+#             */
/*   Updated: 2025/09/18 20:14:55 by liemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_hex_rec(unsigned int n, const char *base, int *count)
{
	char	c;

	if (*count == -1)
		return ;
	if (n >= 16)
	{
		put_hex_rec(n / 16, base, count);
		if (*count == -1)
			return ;
	}
	c = base[n % 16];
	if (write(1, &c, 1) == -1)
	{
		*count = -1;
		return ;
	}
	(*count)++;
}

void	put_hex(unsigned int n, int uppercase, int *count)
{
	const char	*base;

	if (*count == -1)
		return ;
	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	put_hex_rec(n, base, count);
}

static void	put_hex_long_rec(unsigned long long n, const char *base, int *count)
{
	char	c;

	if (*count == -1)
		return ;
	if (n >= 16)
	{
		put_hex_long_rec(n / 16, base, count);
		if (*count == -1)
			return ;
	}
	c = base[n % 16];
	if (write(1, &c, 1) == -1)
	{
		*count = -1;
		return ;
	}
	(*count)++;
}

void	put_hex_long(unsigned long long n, int *count)
{
	if (*count == -1)
		return ;
	put_hex_long_rec(n, "0123456789abcdef", count);
}

void	put_pointer(void *ptr, int *count)
{
	if (*count == -1)
		return ;
	if (!ptr)
	{
		if (write(1, NULLPTR, NULLPTR_LEN) == -1)
		{
			*count = -1;
			return ;
		}
		*count += NULLPTR_LEN;
		return ;
	}
	put_str("0x", count);
	if (*count == -1)
		return ;
	put_hex_long((unsigned long long)ptr, count);
}
