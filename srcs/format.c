/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 09:48:27 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/12 10:35:54 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	long_format(t_dir *list)
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

void	format_line(t_dir *list)
{
	long_format(list);
	ft_putstr((list->mode & S_IRUSR) ? "r" : "-");
	ft_putstr((list->mode & S_IWUSR) ? "w" : "-");
	ft_putstr((list->mode & S_IXUSR) ? "x" : "-");
	ft_putstr((list->mode & S_IRGRP) ? "r" : "-");
	ft_putstr((list->mode & S_IWGRP) ? "w" : "-");
	ft_putstr((list->mode & S_IXGRP) ? "x" : "-");
	ft_putstr((list->mode & S_IROTH) ? "r" : "-");
	ft_putstr((list->mode & S_IWOTH) ? "w" : "-");
	ft_putstr((list->mode & S_IXOTH) ? "x  " : "-  ");
	ft_putnbr(list->nlink);
	ft_putchar('\t');
	ft_putstr(list->uid);
	ft_putstr("  ");
	ft_putstr(list->gid);
	ft_putstr("  ");
	ft_putnbr(list->size);
	ft_putstr("\t");
	convert_time(ctime(&list->time));
	ft_putstr(" ");
	if (list->next != NULL)
		ft_putendl(list->name);
	else
		ft_putstr(list->name);
}
