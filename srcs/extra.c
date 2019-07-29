/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 09:12:44 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/29 10:57:57 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	initialize_blocks(t_blocks *blocks, int flags, int ac)
{
	blocks->flags = flags;
	blocks->total = 0;
	blocks->count = ac;
}

void	format_uid(t_dir *list)
{
	int len;
	int amount;

	amount = 14;
	len = ft_strlen(list->uid);
	if (len == 0)
		amount--;
	ft_putstr(list->uid);
	if (len < amount)
		while (len < amount)
		{
			ft_putchar(' ');
			len++;
		}
}

void	format_gid(t_dir *list)
{
	int len;
	int amount;

	amount = 14;
	len = ft_strlen(list->gid);
	if (len == 0)
		amount--;
	ft_putstr(list->gid);
	if (len < amount)
		while (len < amount)
		{
			ft_putchar(' ');
			len++;
		}
}