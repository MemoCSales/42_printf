/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printunsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:58:25 by mcruz-sa          #+#    #+#             */
/*   Updated: 2023/12/30 13:11:38 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	intlen(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*itoa(unsigned int n)
{
	char	*num;
	int		len;

	len = intlen(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	printunsigned(unsigned int n)
{
	char	*num;
	int		i;

	i = 0;
	if (n == 0)
		i += write(1, "0", 1);
	else
	{
		num = itoa(n);
		i += printstring(num);
		free(num);
	}
	return (i);
}
