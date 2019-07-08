/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 08:53:30 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/08 08:50:59 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_ls.h"

void	recursion(struct dirent *de, unsigned char flags, char *path)
{
	DIR *dr;

	if (flags & 4)
	{
		dr = opendir(path);
		while ((de = readdir(dr)))
			if ((de->d_type == 4) && (ft_strcmp(de->d_name, ".") != 0)
			&& (ft_strcmp(de->d_name, "..") != 0))
				ft_ls(ft_strjoin(path, ft_strjoin("/", de->d_name)), flags);
		closedir(dr);
	}
}

void	ft_ls(char *path, unsigned char flags)
{
	struct dirent *de;
	t_dir *initial;
	DIR *dr;

	initial = NULL;
	de = NULL;
	dr = opendir(path);
	if (check_errors(path) == 1)
		return ;
	while ((de = readdir(dr)))
	{
		if (!initial)
			initial = set_list(de->d_name);
		else
			list_add(&initial, de->d_name);
	}
	closedir(dr);
	print_list(initial, flags);
	recursion(de, flags, path);
	delete_list(&initial);
}

int		main(int ac, char **av)
{
	unsigned char	flags;
	int				i;

	i = 1;
	flags = get_flags(ac, av);
	if ((ac == 1) || ((ac == 2) && flags))
		ft_ls(".", flags);
	else
		while (i < ac)
		{
			if (av[i][0] != '-')
				ft_ls(av[i], flags);
			i++;
		}
	ft_putchar('\n');
	return (0);
}
