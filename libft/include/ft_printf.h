/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:48:36 by nivergne          #+#    #+#             */
/*   Updated: 2019/06/20 07:23:22 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <wchar.h>

# define BUFF_SIZE		64
# define UC				unsigned char
# define US				unsigned short

# define RED			"\033[38;2;255;0;0m"
# define GREEN			"\033[38;2;0;255;0m"
# define YELLOW			"\033[38;2;255;255;0m"
# define BLUE			"\033[38;2;0;0;255m"
# define MAGENTA		"\033[38;2;255;0;128m"
# define CYAN			"\033[38;2;0;255;255m"
# define PINK			"\033[38;2;255;0;255m"
# define TURQUOISE		"\033[38;2;0;255;191m"
# define ORANGE			"\033[38;2;255;128;0m"
# define LIGHT_PURPLE	"\033[38;2;191;0;255m"
# define PURPLE			"\033[38;2;128;0;255m"
# define WHITE			"\033[38;2;255;255;255m"
# define BLACK			"\033[38;2;0;0;0m"
# define RESET			"\033[0m"

# define BRED			"\033[48;2;255;0;0m"
# define BGREEN			"\033[48;2;0;255;0m"
# define BYELLOW		"\033[48;2;255;255;0m"
# define BBLUE			"\033[48;2;0;0;255m"
# define BMAGENTA		"\033[48;2;255;0;128m"
# define BCYAN			"\033[48;2;0;255;255m"
# define BPINK			"\033[48;2;255;0;255m"
# define BTURQUOISE		"\033[48;2;0;255;191m"
# define BORANGE		"\033[48;2;255;128;0m"
# define BLIGHT_PURPLE	"\033[48;2;191;0;255m"
# define BPURPLE		"\033[48;2;128;0;255m"
# define BWHITE			"\033[48;2;255;255;255m"
# define BBLACK			"\033[48;2;0;0;0m"

typedef struct			s_info
{
	int					zero;
	int					plus;
	int					minus;
	int					space;
	int					hashtag;
	int					percent;
	int					width;
	int					accuracy;
	int					type;
	int					conversion;
	int					neg;
	int					llmin;
	int					fnull;
	int					init;
	int					ret;
	int					index;
	char				buff[BUFF_SIZE];
}						t_info;

void					ft_bzero(void *s, size_t n);
void					*ft_memset(void *b, int c, size_t len);
void					*ft_memalloc(size_t size);
void					ft_putchar(char c);
void					ft_putstr(char const *s);
void					ft_putnbr(int n);
size_t					ft_strlen(const char *s);
int						ft_atoi(const char *str);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strcpy(char *dest, const char *src);

void					ft_addfloat(va_list ap, t_info *o);
int						width_size_float(t_info *o,
						unsigned long long cast_ap);
void					ft_put_float(t_info *o, unsigned long long left,
						long double cast_ap, int flag);
void					ft_mantis(t_info *o, long double cast_ap, int flag,
						unsigned long long left);
void					ft_padding(t_info *o);
void					ft_merge_float(t_info *o, unsigned long long left,
						long double cast_ap, int size);

int						t_info_init(t_info *o, int i);
int						check_type(char c, t_info *o);
int						ft_accuracy(t_info *o);

unsigned long long		res_size(unsigned long long value, int base);
char					*fill_base(int base, int l);
char					*conv(unsigned long long value, int base, int l);
unsigned long long		itooct(unsigned long long nb);

void					ft_addpercent(va_list ap, t_info *o);

void					ft_addchar(va_list ap, t_info *o);
void					ft_addwchar(va_list ap, t_info *o);
void					ft_putwchar(wchar_t c, t_info *o);
void					addwidth_wchar(wchar_t c, int nb, t_info *o);
void					ft_color(va_list ap, t_info *options);

void					ft_addstr(va_list ap, t_info *o);
void					ft_strchar(char *cast_ap, t_info *o);
void					ft_strwchar(char *tmp, t_info *o);
void					print_ls(wchar_t *str, t_info *o);

void					ft_addaddr(va_list ap, t_info *o);

void					ft_nbr(va_list ap, t_info *o);
void					ft_nbrsign(t_info *o);
void					ft_addnbr(long long cast_ap, t_info *o);
void					ft_addnbr_core(long long nb, t_info *o);

void					ft_uns(va_list ap, t_info *o);
void					ft_adduns(long long cast_ap, t_info *o);
void					ft_adduns_core(unsigned long long nb,
						t_info *o, int base);

void					ft_oct(va_list ap, t_info *o);
void					ft_addoct(unsigned long long cast_ap, t_info *o);
void					oct_for_null(t_info *o);

void					ft_hex(va_list ap, t_info *o);
void					ft_addhexmin(char *cast_ap, t_info *o);
void					ft_addhexmaj(char *cast_ap, t_info *o);
void					hex_for_null(t_info *o);

void					ft_addbin(va_list ap, t_info *o);

void					addwidth_char(int nb, t_info *o);
void					addwidth_string(int nb, char *cast_ap, t_info *o);
void					char_null(int cast_ap, t_info *o);
char					*string_for_null(char *cast);

int						width_size_diou(t_info *o, long long cast_ap,
						int base);
int						width_size_x(t_info *o, char *cast_ap);
int						width_size_o(t_info *o, unsigned long long cast_ap);
void					width_for_null(t_info *o);
int						width_bin(t_info *o);

int						check_flag(char c, t_info *o);
int						check_width(char c, t_info *o);
int						check_accuracy_one(char c, t_info *o);
int						check_accuracy_two(char c, t_info *o);
int						check_conversion(char c, t_info *o);

void					(*g_funptr[13])(va_list ap, t_info *o);
void					addbuff(char *str, t_info *o);
int						parse_str(char *buff, t_info *o);
int						append_to_buff(char c, int print, t_info *o);
int						ft_printf(char *buff, ...);

#endif
