/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:57:58 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/29 15:44:10 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int	error_file(char *path)
{
	if (errno == 20)
	{
		ft_putstr(path);
		return (1);
	}
	return (0);
}

int	error_permission(char *path)
{
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

int	check_errors(char *path, DIR *dr)
{
	if (!dr)
	{
		if (error_file(path) == 1)
			return (1);
		else
		{
			if (error_permission(path) == 1)
				return (1);
			ft_putstr("ft_ls: ");
			ft_putstr(path);
			ft_putstr(": No such file or directory\n");
			return (1);
		}
	}
	return (0);
}
