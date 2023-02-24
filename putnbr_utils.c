/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:24:12 by gimartin          #+#    #+#             */
/*   Updated: 2022/02/04 15:35:30 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putnbr_pointer(unsigned long num, t_flag *flag)
{
	char	result[18];
	int		i;

	i = 1;
	while (num)
	{
		result[i] = BASE_LOWER[num % 16];
		num = num / 16;
		i++;
	}
	i--;
	if (i)
		ft_putstr("0x", flag);
	while (i)
	{
		ft_putchar(result[i], flag);
		i--;
	}
}

int	putnbr_hex(char ch, long long num, t_flag *flag)
{
	char	result[18];
	int		i;

	if (flag->point && flag->accuracy == 0 && num == 0)
		return (0);
	i = 1;
	if (num == 0)
		ft_putchar('0', flag);
	while (num)
	{
		if (ch == 'x')
			result[i] = BASE_LOWER[num % 16];
		else
			result[i] = BASE_UPPER[num % 16];
		num = num / 16;
		i++;
	}
	i--;
	while (i)
	{
		ft_putchar(result[i], flag);
		i--;
	}
	return (0);
}

char	*print_pointer(char *s, va_list args, t_flag *flag)
{
	void	*pointer;
	int		symbols_to_print;

	pointer = va_arg(args, void *);
	symbols_to_print = get_hex_digits_num((unsigned long)pointer);
	if (flag->plus || flag->space)
		symbols_to_print++;
	if (flag->accuracy > symbols_to_print)
		symbols_to_print = flag->accuracy;
	if (flag->width && !flag->minus)
		print_spaces(flag->width - symbols_to_print - 2, flag);
	if (pointer == 0)
		ft_putstr("0x0", flag);
	else
		putnbr_pointer((unsigned long)pointer, flag);
	if (flag->width && flag->minus)
		print_spaces(flag->width - symbols_to_print - 2, flag);
	s++;
	return (s);
}

void	preprint_hex(char *s, long long num, int symb_to_print, t_flag *flag)
{
	if (num < 0 && (flag->zero || flag->point))
		ft_putchar('-', flag);
	if (flag->width && !flag->minus)
		print_spaces(flag->width - symb_to_print, flag);
	if (flag->plus && num >= 0)
		ft_putchar('+', flag);
	if (flag->space && num >= 0 && !flag->plus)
		ft_putchar(' ', flag);
	if (flag->accuracy > get_hex_digits_num(num))
		print_zeroes(flag->accuracy - get_hex_digits_num(num), flag);
	if (flag->hash && num != 0)
	{
		if (*s == 'x')
			ft_putstr("0x", flag);
		else
			ft_putstr("0X", flag);
	}
}

char	*print_hex(char *s, va_list args, t_flag *flag)
{
	long long	num;
	int			symbols_to_print;

	num = (long long)va_arg(args, unsigned int);
	symbols_to_print = get_hex_digits_num(num);
	if (((flag->plus || flag->space) && num >= 0) || num < 0)
		symbols_to_print++;
	if (flag->accuracy > symbols_to_print)
		symbols_to_print = flag->accuracy;
	if (num < 0 && flag->accuracy >= symbols_to_print)
		symbols_to_print = flag->accuracy + 1;
	if (flag->point && flag->accuracy == 0 && num == 0)
		symbols_to_print = 0;
	preprint_hex(s, num, symbols_to_print, flag);
	putnbr_hex(*s, num, flag);
	if (flag->width && flag->minus)
		print_spaces(flag->width - symbols_to_print, flag);
	return (++s);
}
