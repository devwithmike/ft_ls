/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:48:22 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/10 09:13:45 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	print_list(t_dir *list, unsigned char flags)
{
	t_dir *ptr;

	ptr = list;
	while (ptr != NULL)
	{
		if (flags & 2)
		{
			printf("%hu\t%s\t%s\t%lld\t%s\n", ptr->nlink, ptr->uid, ptr->gid,
					ptr->size, ptr->name);
			ptr = ptr->next;
		}
		else
		{
			if (ptr->name[0] != '.')
			{
				printf("%hu\t%s\t%s\t%lld\t%s\n", ptr->nlink, ptr->uid,
						ptr->gid, ptr->size, ptr->name);
			}
			ptr = ptr->next;
		}
	}
}

void	print_normal(t_dir *list, unsigned char flags)
{
	t_dir *ptr;

	ptr = list;
	while (ptr != NULL)
	{
		if (flags & 2)
		{
			ft_putstr(ptr->name);
			ft_putstr("\t\t");
			ptr = ptr->next;
		}
		else
		{
			if (ptr->name[0] != '.')
			{
				ft_putstr(ptr->name);
				ft_putstr("\t\t");
			}
			ptr = ptr->next;
		}
	}
}

void	print_recursion(char *path)
{
	if ((ft_strcmp(path, "./") != 0) && (ft_strcmp(path, ".") != 0))
	{
		ft_putstr("\n\n");
		ft_putstr(path);
		ft_putstr(":\n");
	}
}

void	print_output(t_dir *list, unsigned char flags, char *path)
{
	if (flags & 1)
	{
		if (flags & 4)
			print_recursion(path);
		print_list(list, flags);
	}
	else
	{
		if (flags & 4)
			print_recursion(path);
		print_normal(list, flags);
	}
}