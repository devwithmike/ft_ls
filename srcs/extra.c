/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 09:12:44 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/30 10:23:45 by mimeyer          ###   ########.fr       */
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

void	sort_nano_ascii(int flags, t_dir *a, t_dir *b, t_dir **result)
{
	if (!(flags & 8) && (ft_strcmp(a->name, b->name)) < 0)
	{
		*result = a;
		(*result)->next = sorted_merge_t(a->next, b, flags);
	}
	else if ((flags & 8) && (ft_strcmp(a->name, b->name)) > 0)
	{
		*result = a;
		(*result)->next = sorted_merge_t(a->next, b, flags);
	}
	else
	{
		*result = b;
		(*result)->next = sorted_merge_t(a, b->next, flags);
	}
}
