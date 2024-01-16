/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:41:56 by mcruz-sa          #+#    #+#             */
/*   Updated: 2023/12/30 15:03:36 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_placeholders(const char *format, va_list args)
{
	int	i;

	i = 0;
	if (*format == 'c')
		i += printchar(va_arg(args, int));
	else if (*format == 's')
		i += printstring(va_arg(args, char *));
	else if (*format == 'd' || *format == 'i')
		i += printdecimal(va_arg(args, int));
	else if (*format == 'u')
		i += printunsigned(va_arg(args, unsigned int));
	else if (*format == 'X' || *format == 'x')
		i += printhexa(va_arg(args, unsigned int), format);
	else if (*format == 'p')
	{
		i += printstring("0x");
		i += printhexa(va_arg(args, unsigned long long), format);
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	int		i;

	i = 0;
	ch = (char) c;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == ch)
		return ((char *) &s[i]);
	return (NULL);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;

	va_start (args, format);
	i = 0;
	while (*format)
	{
		if (*format == '%' && ft_strchr("cspdiuxX", *(++format)))
			i += ft_placeholders(format, args);
		else if (*format == '%')
			i += printchar('%');
		else
			i = i + printchar(*format);
		format++;
	}
	va_end(args);
	return (i);
}
