/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:48:22 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/26 09:29:58 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	print_blocks(t_blocks *blocks)
{
	ft_putstr("total ");
	ft_putnbr(blocks->total);
	ft_putchar('\n');
}

void	print_list(t_dir *list, int flags, char *path)
{
	t_dir *ptr;

	ptr = list;
	while (ptr != NULL)
	{
		if ((flags & 2) && (flags & 1024))
		{
			if ((ft_strcmp(ptr->name, ".") != 0) &&
			(ft_strcmp(ptr->name, "..") != 0))
				format_line(ptr, path, flags);
		}
		else if ((flags & 2) && !(flags & 1024))
			format_line(ptr, path, flags);
		else
		{
			if (ft_strncmp(ptr->name, ".", 1) != 0)
				format_line(ptr, path, flags);
		}
		ptr = ptr->next;
	}
	ft_putchar('\n');
}

void	print_normal(t_dir *list, int flags)
{
	t_dir *ptr;

	ptr = list;
	while (ptr != NULL)
	{
		if ((flags & 2) && (flags & 1024))
		{
			if ((ft_strcmp(ptr->name, ".") != 0) &&
			(ft_strcmp(ptr->name, "..") != 0))
				format_normal(ptr, flags);
		}
		else if ((flags & 2) && !(flags & 1024))
			format_normal(ptr, flags);
		else
		{
			if (ptr->name[0] != '.')
				format_normal(ptr, flags);
		}
		ptr = ptr->next;
	}
	if (!(flags & 8))
		ft_putchar('\n');
}

void	print_recursion(char *path)
{
	if ((ft_strcmp(path, "./") != 0) && (ft_strcmp(path, ".") != 0)
		&& (ft_strcmp(path, "..") != 0))
	{
		ft_putstr("\n");
		ft_putstr(path);
		ft_putstr(":\n");
	}
}

void	print_output(t_dir *list, int flags,
					char *path, t_blocks *blocks)
{
	if (flags & 1 || flags & 64)
	{
		if (flags & 4)
			print_recursion(path);
		print_blocks(blocks);
		print_list(list, flags, path);
	}
	else
	{
		if (flags & 4)
			print_recursion(path);
		print_normal(list, flags);
	}
}
