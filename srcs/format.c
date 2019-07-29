/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 09:48:27 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/29 11:04:09 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	format_nlink(t_dir *list)
{
	int len;
	int amount;

	amount = 5;
	len = ft_numlen(list->nlink);
	if (len == 0)
		amount--;
	ft_putnbr(list->nlink);
	if (len < amount)
		while (len < amount)
		{
			ft_putchar(' ');
			len++;
		}
}

void	format_size(t_dir *list)
{
	int len;
	int amount;

	amount = 8;
	len = ft_numlen(list->size);
	if (len == 0)
		amount--;
	ft_putnbr(list->size);
	if (len < amount)
		while (len < amount)
		{
			ft_putchar(' ');
			len++;
		}
}

void	format_permissions(t_dir *list)
{
	ft_putchar((list->mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((list->mode & S_IWUSR) ? 'w' : '-');
	if (list->mode & S_ISUID)
		ft_putchar((list->mode & S_IXUSR) ? 's' : 'S');
	else
		ft_putchar((list->mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((list->mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((list->mode & S_IWGRP) ? 'w' : '-');
	if (list->mode & S_ISGID)
		ft_putchar((list->mode & S_IXGRP) ? 's' : 'S');
	else
		ft_putchar((list->mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((list->mode & S_IROTH) ? 'r' : '-');
	ft_putchar((list->mode & S_IWOTH) ? 'w' : '-');
	if (list->mode & S_ISVTX)
		ft_putstr((list->mode & S_IXOTH) ? "t" : "T");
	else
		ft_putstr((list->mode & S_IXOTH) ? "x" : "-");
	format_acl(list);
}

void	format_long(t_dir *list)
{
	if (S_ISDIR(list->mode))
		ft_putchar('d');
	else if (S_ISLNK(list->mode))
		ft_putchar('l');
	else if (S_ISBLK(list->mode))
		ft_putchar('b');
	else if (S_ISCHR(list->mode))
		ft_putchar('c');
	else if (S_ISFIFO(list->mode))
		ft_putchar('p');
	else if (S_ISSOCK(list->mode))
		ft_putchar('s');
	else
		ft_putchar('-');
}

void	format_line(t_dir *list, char *path, int flags)
{
	format_long(list);
	format_permissions(list);
	format_nlink(list);
	format_id(list->uid);
	format_id(list->gid);
	format_size(list);
	convert_time(ctime(&list->time));
	ft_putstr(" ");
	add_colour(list, flags);
	if (S_ISLNK(list->mode))
		convert_nlink(path, list);
	if (list->next != NULL)
		ft_putchar('\n');
}
