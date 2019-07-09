/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:57:58 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/09 15:57:43 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int	check_errors(char *path)
{
	if (errno == 20)
	{
		ft_putstr(path);
		return (1);
	}
	if (errno == 13)
	{
		ft_putstr("ft_ls: ");
		if (path[ft_strlen(path) - 1] != '/')
			ft_putstr(path);
		ft_putstr(": Permission denied\n");
		return (1);
	}
	return (0);
}
