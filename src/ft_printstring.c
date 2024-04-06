/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:03:28 by pstrohal          #+#    #+#             */
/*   Updated: 2024/03/22 19:29:22 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_count_list	ft_printstr(t_count_list plist)
{
	char	*str;

	str = va_arg(plist.arg, char *);
	if (!str)
	{
		plist = ft_write("(null)", 6, plist);
		return (plist);
	}
	while (*str && plist.error == 0)
	{
		plist = ft_write (str, 1, plist);
		str++;
	}
	return (plist);
}
