/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:22:44 by gimartin          #+#    #+#             */
/*   Updated: 2022/02/04 15:22:49 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define VALID_KEYS "cspdiuxX%"
# define BASE_LOWER "0123456789abcdef"
# define BASE_UPPER "0123456789ABCDEF"

typedef struct s_flag
{
	char	type;
	int		counter;
	int		minus;
	int		zero;
	int		point;
	int		accuracy;
	int		hash;
	int		space;
	int		plus;
	int		width;
	int		uppercase;
}	t_flag;

int		ft_printf(const char *str, ...);

char	*get_next_arg(char *s);
char	*parse_arg(char *s, va_list args, t_flag *flag);
char	*get_flags(char *s, t_flag *flag, va_list args);
void	parse_flags(char *s, t_flag *flag);
void	get_flags_from_star(t_flag *flag, va_list args);

int		ft_strlen(const char *str);
void	ft_putchar(char ch, t_flag *flag);
void	ft_putstr(char *str, t_flag *flag);
int		ft_putnbr(long long n, t_flag *flag);
char	*ft_strchr(const char *s, int ch);
int		ft_isdigit(char ch);
int		ft_atoi(const char *str);

char	*print_char(char *s, va_list args, t_flag *flag);
char	*print_string(char *s, char *arg, t_flag *flag);
void	preprint_integer(int num, int symbols_to_print, t_flag *flag);
char	*print_integer(char *s, int num, t_flag *flag);
char	*print_unsigned(char *s, va_list args, t_flag *flag);
int		print_orig_string(char *s, size_t size, t_flag *flag);

void	putnbr_pointer(unsigned long num, t_flag *flag);
int		putnbr_hex(char ch, long long num, t_flag *flag);
char	*print_pointer(char *s, va_list args, t_flag *flag);
void	preprint_hex(char *s, long long num, int symb_to_print, t_flag *flag);
char	*print_hex(char *s, va_list args, t_flag *flag);
void	print_spaces(int n, t_flag *flag);
void	print_zeroes(int n, t_flag *flag);

int		get_digits_num(long long n);
int		get_hex_digits_num(unsigned long n);

#endif
