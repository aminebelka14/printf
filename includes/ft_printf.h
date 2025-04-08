/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambelkac <ambelkac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:19:43 by ambelkac          #+#    #+#             */
/*   Updated: 2020/08/20 18:17:32 by ambelkac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct		s_var {
	void				*p;
	char				*s;
	long unsigned int	u;
	long int			d;
	int					c;
}					t_var;

typedef struct		s_form {
	int				isprec;
	int				precval;
	int				iszero;
	int				zeroval;
	int				isdash;
	int				dashval;
	int				iswidth;
	int				widthval;
}					t_form;

typedef struct		s_param {
	char			*format;
	t_var			*var;
	t_form			*form;
	char			conv;
	int				dispd;
	int				precdoublezero;
	int				isspace;
	struct s_param	*next;
}					t_param;

typedef struct		s_pars_str {
	t_param			*first;
	int				i;
	int				efflen;
}					t_pars_str;

int					ft_printf(const char *str, ...);

char				*ft_substr_free(char *s,
unsigned int start, size_t len, int ifree);
size_t				ft_strlen(const char *str);
char				*ft_strncat(char *dest, char *src, unsigned int nb);
char				*cncat(char *str1, char *str2, int free1, int free2);
char				*ft_strdup_free(char *src, int ifree);

int					form_parsing(t_form *form, char *str, va_list ap);
int					flag_parsing(t_param *current, char const *str, int i);
int					check_string(t_param **param, char const *str, va_list ap);
int					is_flag_correct(char const *str);

int					is_in_set(char c, char const *set);
int					ft_isdigit(int c);
int					is_number(char const *str, int i);

int					display_params(t_param *param, const char *str);
void				display_s(t_param *param);
void				display_d(t_param *param);
void				display_x(t_param *param);
void				display_bigx(t_param *param);
void				display_p(t_param *param);
void				display_u(t_param *param);
void				display_c(t_param *param);

int					display_precision(t_param *param);
int					display_width(t_param *param, int pre);
int					display_dash(t_param *param);
int					display_0(t_param *param);

t_var				*link_args(va_list ap, const char *str);

t_pars_str			*allocate_pars_str(t_param *first);
t_param				*allocate_next_elem(t_param **current);
t_param				*allocate_param(void);
void				free_param(t_param *param);
int					free_param_list(t_param **list, int rval);

int					var_len(t_param *param);
int					nbrlen(long int snbr,
long unsigned int unbr, char type, int count);

void				ft_putnbr_fd(long int nb, int fd);
void				ft_putnbr_base(long int nb, char *base);
void				ft_putunbr_fd(unsigned int nb, int fd);
int					ft_atoi(const char *str);
char				*strmalloc(char *src);

int					zero_dash_repetition(char const *str, int i);
int					get_dash_value(va_list ap);

#endif
