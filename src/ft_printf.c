/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:30:55 by pstrohal          #+#    #+#             */
/*   Updated: 2024/04/24 16:31:15 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_count_list	check_write_arg(char chr, t_count_list plist)
{
	char	c;

	if (chr == '%')
		plist = ft_write (&chr, 1, plist);
	else if (chr == 'c')
	{
		c = (char)(va_arg(plist.arg, int));
		plist = ft_write (&c, 1, plist);
	}
	else if (chr == 's')
		plist = ft_printstr(plist);
	else if (chr == 'p')
		plist = ft_print_adress_in_hex(plist);
	else if (chr == 'd' || chr == 'i')
		plist = ft_printint(plist);
	else if (chr == 'u')
		plist = ft_print_base(plist, chr, 10);
	else if (chr == 'x' || chr == 'X')
		plist = ft_print_base(plist, chr, 16);
	return (plist);
}

int	ft_printf(const char *str, ...)
{
	t_count_list	plist;

	va_start(plist.arg, str);
	plist.count = 0;
	plist.error = 0;
	plist.hexarr = "0123456789abcdef\0";
	while (*str && plist.error == 0)
	{
		if (*str == '%')
		{
			plist = check_write_arg(*(str++ + 1), plist);
			if (plist.error < 0)
				return (-1);
		}
		else
			plist = ft_write(str, 1, plist);
		str++;
	}
	va_end(plist.arg);
	if (!(plist.error == 0))
		return (plist.error);
	return (plist.count);
}

// int	main(void)
// {
// 	int				p;
// 	char			*f;
// 	unsigned int	h;

// 	p = 65;
// 	f = "-1";
// 	h = 6843512;
// 	printf("%d\n", ft_printf(" NULL %s NULL ", NULL));
// 	   printf("%d\n", printf(" NULL %s NULL ", NULL));
// }