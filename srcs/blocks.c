/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 09:12:44 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/29 09:30:10 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	initialize_blocks(t_blocks *blocks, int flags, int ac)
{
	blocks->flags = flags;
	blocks->total = 0;
	blocks->count = ac;
}
