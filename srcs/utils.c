/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 10:52:19 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/19 10:10:34 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	set_blocks(int block, t_blocks *total, char *name)
{
	if (total->flags & 2)
		total->total += block;
	else
	{
		if (ft_strncmp(name, ".", 1) != 0)
			total->total += block;
	}
}
