/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:23:58 by gimartin          #+#    #+#             */
/*   Updated: 2022/02/04 15:35:17 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	preprint_integer(int num, int symbols_to_print, t_flag *flag)
{
	if (num < 0 && (flag->zero && !flag->point))
		ft_putchar('-', flag);
	if (flag->width && !flag->minus)
		print_spaces(flag->width - symbols_to_print, flag);
	if (num < 0 && (!flag->zero && flag->point))
		ft_putchar('-', flag);
	if (flag->plus && num >= 0)
		ft_putchar('+', flag);
	if (flag->space && num >= 0 && !flag->plus)
		ft_putchar(' ', flag);
	if (flag->accuracy > get_digits_num(num))
		print_zeroes(flag->accuracy - get_digits_num(num), flag);
}

char	*print_integer(char *s, int num, t_flag *flag)
{
	int	symbols_to_print;

	symbols_to_print = get_digits_num(num);
	if (((flag->plus || flag->space) && num >= 0) || num < 0)
		symbols_to_print++;
	if (num < 0 && flag->accuracy >= symbols_to_print)
		symbols_to_print = flag->accuracy + 1;
	if (flag->accuracy > symbols_to_print)
		symbols_to_print = flag->accuracy;
	if (flag->point && flag->accuracy == 0 && num == 0)
		symbols_to_print = 0;
	preprint_integer(num, symbols_to_print, flag);
	ft_putnbr(num, flag);
	if (flag->width && flag->minus)
		print_spaces(flag->width - symbols_to_print, flag);
	return (++s);
}

char	*print_unsigned(char *s, va_list args, t_flag *flag)
{
	unsigned int	num;
	int				symbols_to_print;

	num = va_arg(args, unsigned int);
	symbols_to_print = get_digits_num(num);
	if (flag->plus || flag->space)
		symbols_to_print++;
	if (flag->accuracy > symbols_to_print)
		symbols_to_print = flag->accuracy;
	if (flag->point && flag->accuracy == 0 && num == 0)
		symbols_to_print = 0;
	if (flag->width && !flag->minus)
		print_spaces(flag->width - symbols_to_print, flag);
	if (flag->plus)
		ft_putchar('+', flag);
	if (flag->space && !flag->plus)
		ft_putchar(' ', flag);
	if (flag->accuracy > get_digits_num(num))
		print_zeroes(flag->accuracy - get_digits_num(num), flag);
	ft_putnbr(num, flag);
	if (flag->width && flag->minus)
		print_spaces(flag->width - symbols_to_print, flag);
	s++;
	return (s);
}

int	print_orig_string(char *s, size_t size, t_flag *flag)
{
	size_t	i;

	i = 0;
	while (s[i] && i < size)
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == '%')
			{
				ft_putchar('%', flag);
				i++;
			}
		}
		else
			ft_putchar(s[i], flag);
		i++;
	}
	return (0);
}
