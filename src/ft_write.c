/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:49:40 by pstrohal          #+#    #+#             */
/*   Updated: 2024/03/22 19:29:34 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_count_list	ft_write(const void *buf, size_t nbyte, t_count_list plist)
{
	int	t;

	t = write(1, buf, nbyte);
	if (t < 0)
		plist.error = -1;
	plist.count += t;
	return (plist);
}
