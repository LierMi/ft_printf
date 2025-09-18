/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liemi <liemi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:13:59 by liemi             #+#    #+#             */
/*   Updated: 2025/09/18 20:09:47 by liemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_char(char c, int *count)
{
	if (*count == -1)
		return ;
	if (write(1, &c, 1) == -1)
	{
		*count = -1;
		return ;
	}
	(*count)++;
}

void	put_str(const char *s, int *count)
{
	if (*count == -1)
		return ;
	if (!s)
		s = "(null)";
	while (*s && *count != -1)
	{
		if (write(1, s, 1) == -1)
		{
			*count = -1;
			return ;
		}
		(*count)++;
		s++;
	}
}

static void	put_long(long n, int *count)
{
	char	c;

	if (*count == -1)
		return ;
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
		{
			*count = -1;
			return ;
		}
		(*count)++;
		n = -n;
	}
	if (n >= 10)
		put_long(n / 10, count);
	if (*count == -1)
		return ;
	c = (char)((n % 10) + '0');
	if (write(1, &c, 1) == -1)
	{
		*count = -1;
		return ;
	}
	(*count)++;
}

void	put_number(int n, int *count)
{
	if (*count == -1)
		return ;
	put_long((long)n, count);
}

void	put_unsigned(unsigned int n, int *count)
{
	char	c;

	if (*count == -1)
		return ;
	if (n >= 10)
		put_unsigned(n / 10, count);
	if (*count == -1)
		return ;
	c = (char)((n % 10) + '0');
	if (write(1, &c, 1) == -1)
	{
		*count = -1;
		return ;
	}
	(*count)++;
}
