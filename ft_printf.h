/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcruz-sa <mcruz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:43:28 by mcruz-sa          #+#    #+#             */
/*   Updated: 2023/12/30 15:07:44 by mcruz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

# define UPPERHEXABASE "0123456789ABCDEF"
# define LOWERHEXABASE "0123456789abcdef"

int	ft_printf(const char *format, ...);
int	printchar(char c);
int	printstring(char *s);
int	printdecimal(int n);
int	printunsigned(unsigned int n);
int	printhexa(unsigned long long n, const char *format);

#endif