/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:11:11 by pstrohal          #+#    #+#             */
/*   Updated: 2024/03/26 11:09:22 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_count_list	ft_printint(t_count_list plist)
{
	int				n;

	n = va_arg(plist.arg, int);
	if (n < -2147483648 || n > 2147483647)
		return (plist);
	if (n == -2147483648)
	{
		plist = ft_write("-2147483648", 11, plist);
		return (plist);
	}
	if (n < 0)
	{
		plist = ft_write("-", 1, plist);
		n *= -1;
	}
	plist = ft_printnbr(n, plist);
	return (plist);
}

t_count_list	ft_printnbr(int n, t_count_list plist)
{
	unsigned int	rem;
	char			temp[sizeof(char) * 13];
	int				i;

	rem = 0;
	i = 0;
	if (!n)
		plist = ft_write("0", 1, plist);
	while (n > 0 && plist.error == 0)
	{
		rem = n - (n / 10) * 10;
		n /= 10;
		temp[i++] = plist.hexarr[rem];
	}
	temp[i--] = '\0';
	while (i >= 0 && plist.error == 0)
	{
		plist = ft_write(&temp[i--], 1, plist);
	}
	return (plist);
}
