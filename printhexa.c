/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:00:20 by mcruz-sa          #+#    #+#             */
/*   Updated: 2023/12/30 15:01:53 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printhexa(unsigned long long n, const char *format)
{
	unsigned long long		num;
	char					*hexabase;
	int						i;

	num = n;
	i = 0;
	hexabase = NULL;
	if (*format == 'x' || *format == 'p')
		hexabase = LOWERHEXABASE;
	else if (*format == 'X')
		hexabase = UPPERHEXABASE;
	if (num >= 16)
		i += printhexa(num / 16, format);
	printchar(hexabase[num % 16]);
	return (i + 1);
}
