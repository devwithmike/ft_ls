/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 09:12:44 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/29 15:04:13 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	initialize_blocks(t_blocks *blocks, int flags, int ac)
{
	blocks->flags = flags;
	blocks->total = 0;
	blocks->count = ac;
}

void	format_id(char *id)
{
	int len;
	int amount;

	amount = 10;
	len = ft_strlen(id);
	if (len == 0)
		amount--;
	ft_putstr(id);
	if (len < amount)
		while (len < amount)
		{
			ft_putchar(' ');
			len++;
		}
}
