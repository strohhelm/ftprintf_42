/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:06:16 by pstrohal          #+#    #+#             */
/*   Updated: 2024/03/23 13:00:34 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_counterlist
{
	int		count;
	int		error;
	va_list	arg;
	char	*hexarr;
}	t_count_list;

int				ft_printf(const char*str, ...);
t_count_list	ft_print_adress_in_hex(t_count_list plist);
t_count_list	ft_print_base(t_count_list plist, char u, int base);
t_count_list	ft_printstr(t_count_list plist);
t_count_list	ft_printint(t_count_list plist);
t_count_list	ft_write(const void *buf, size_t nbyte, t_count_list plist);
t_count_list	ft_printnbr(int n, t_count_list plist);

#endif