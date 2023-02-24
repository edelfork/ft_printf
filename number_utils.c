/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:23:16 by gimartin          #+#    #+#             */
/*   Updated: 2022/02/04 15:34:48 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_digits_num(long long n)
{
	int	result;

	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	result = 0;
	if (n < 0)
		result = 1;
	while (n)
	{
		result++;
		n /= 10;
	}
	return (result);
}

int	get_hex_digits_num(unsigned long n)
{
	int	result;

	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	result = 0;
	while (n)
	{
		result++;
		n /= 16;
	}
	return (result);
}

int	ft_isdigit(char ch)
{
	if ((ch >= '0') && (ch <= '9'))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (ft_isdigit(str[i]))
	{
		result = result * 10;
		result = result + str[i] - 48;
		i++;
	}
	return (result);
}
