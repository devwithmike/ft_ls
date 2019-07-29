/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 10:52:19 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/29 14:43:00 by mimeyer          ###   ########.fr       */
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

int		isdir(const char *path)
{
	struct stat	s;

	stat(path, &s);
	return (S_ISDIR(s.st_mode));
}

void	format_normal(t_dir *ptr, int flags)
{
	add_colour(ptr, flags);
	if (ptr->next != NULL)
		ft_putstr("\n");
}

void	format_acl(t_dir *ptr)
{
	acl_t	acl;

	if ((listxattr(ptr->path, 0, 0, XATTR_NOFOLLOW) > 0))
	{
		ft_putstr("@  ");
		return ;
	}
	if ((acl = acl_get_link_np(ptr->path, ACL_TYPE_EXTENDED)))
	{
		free(acl);
		ft_putstr("+  ");
		return ;
	}
	free(acl);
	ft_putstr("   ");
}

void	format_name(t_dir *ptr, int flags)
{
	ft_putstr(ptr->name);
	if (flags & 256)
		if (isdir(ptr->path))
			ft_putchar('/');
}
