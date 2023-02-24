/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:21:33 by gimartin          #+#    #+#             */
/*   Updated: 2022/02/04 15:34:07 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_flags_from_star(t_flag *flag, va_list args)
{
	if (!flag->point)
	{
		flag->width = va_arg(args, int);
		if (flag->width < 0)
		{
			flag->minus = 1;
			flag->width = -flag->width;
		}
	}
	else
	{
		flag->accuracy = va_arg(args, int);
		if (flag->accuracy < 0)
		{
			flag->point = 0;
			flag->accuracy = 0;
		}
	}
}

void	parse_flags(char *s, t_flag *flag)
{
	if (*s == '-')
		flag->minus = 1;
	if (*s == '.')
		flag->point = 1;
	if (*s == '#')
		flag->hash = 1;
	if (*s == ' ')
		flag->space = 1;
	if (*s == '+')
		flag->plus = 1;
	if (*s == '0')
		flag->zero = 1;
}

char	*get_flags(char *s, t_flag *flag, va_list args)
{
	while (!ft_strchr(VALID_KEYS, *s))
	{
		parse_flags(s, flag);
		if (*s == '*')
			get_flags_from_star(flag, args);
		if (ft_isdigit(*s) && flag->point)
			flag->accuracy = ft_atoi(s);
		else if (ft_isdigit(*s))
			flag->width = ft_atoi(s);
		while (ft_isdigit(*s) && ft_isdigit(*(s + 1)))
			s++;
		s++;
	}
	if (flag->minus || flag->point)
		flag->zero = 0;
	flag->type = *s;
	return (s);
}

char	*parse_arg(char *s, va_list args, t_flag *flag)
{
	if (*s == 'c')
		return (print_char(s, args, flag));
	else if (*s == 's')
		return (print_string(s, va_arg(args, char *), flag));
	else if (*s == 'd' || *s == 'i')
		return (print_integer(s, va_arg(args, int), flag));
	else if (*s == 'u')
		return (print_unsigned(s, args, flag));
	else if (*s == 'p')
		return (print_pointer(s, args, flag));
	else if (*s == 'x' || *s == 'X')
		return (print_hex(s, args, flag));
	else if (*s == '%')
		return (print_string(s, "%", flag));
	return (s);
}

char	*get_next_arg(char *s)
{
	while (*s)
	{
		if (*s == '%' && *(s + 1) != '%')
		{
			s++;
			return (s);
		}
		if (*s == '%')
			s++;
		s++;
	}
	return (s);
}
