/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:23:39 by gimartin          #+#    #+#             */
/*   Updated: 2022/02/04 15:35:03 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_spaces(int n, t_flag *flag)
{
	while (n > 0)
	{
		if (flag->zero)
			ft_putchar('0', flag);
		else
			ft_putchar(' ', flag);
		n--;
	}
}

void	print_zeroes(int n, t_flag *flag)
{
	while (n > 0)
	{
		ft_putchar('0', flag);
		n--;
	}
}

char	*print_char(char *s, va_list args, t_flag *flag)
{
	char	ch;

	ch = va_arg(args, int);
	if (flag->width && !flag->minus)
	{
		print_spaces(flag->width - 1, flag);
		ft_putchar(ch, flag);
	}
	else if (flag->width && flag->minus)
	{
		ft_putchar(ch, flag);
		print_spaces(flag->width - 1, flag);
	}
	else
		ft_putchar(ch, flag);
	s++;
	return (s);
}

char	*print_string(char *s, char *arg, t_flag *flag)
{
	int	len;

	len = ft_strlen(arg);
	if (arg == NULL)
		len = 6;
	if (flag->point && flag->accuracy < len)
		len = flag->accuracy;
	if (flag->width && !flag->minus)
		print_spaces(flag->width - len, flag);
	if (arg != NULL)
		ft_putstr(arg, flag);
	else
		ft_putstr("(null)", flag);
	if (flag->width && flag->minus)
		print_spaces(flag->width - len, flag);
	s++;
	return (s);
}
