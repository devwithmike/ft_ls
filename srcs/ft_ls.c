/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 08:53:30 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/23 10:14:37 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_ls.h"

void	recursion(t_dir *list, int flags, char *path)
{
	t_dir	*ptr;
	char	*s1;
	char	*s2;

	ptr = list;
	while (ptr != NULL)
	{
		if ((ptr->type == 4) && (ft_strcmp(ptr->name, ".") != 0)
		&& (ft_strcmp(ptr->name, "..") != 0))
		{
			if (!(flags & 2) && (ptr->name[0] == '.'))
			{
				ptr = ptr->next;
				continue ;
			}
			s1 = ft_strjoin(path[ft_strlen(path) - 1] != '/' ? "/" : "",
						ptr->name);
			s2 = ft_strjoin(path, s1);
			free(s1);
			ft_ls(s2, flags);
			free(s2);
		}
		ptr = ptr->next;
	}
}

void	check_sort(t_dir *initial, int flags)
{
	if (!(flags & 128))
		merge_sort(&initial, flags);
}

void	ft_ls(char *path, int flags)
{
	struct dirent	*de;
	t_dir			*initial;
	DIR				*dr;
	t_blocks		blocks;

	blocks.flags = flags;
	blocks.total = 0;
	initial = NULL;
	de = NULL;
	dr = opendir(path);
	if (check_errors(path, dr) == 1)
		return ;
	while ((de = readdir(dr)))
	{
		if (!initial)
			initial = set_list(de, path, &blocks);
		else
			list_add(&initial, de, path, &blocks);
	}
	closedir(dr);
	check_sort(initial, flags);
	print_output(initial, flags, path, &blocks);
	if (flags & 4)
		recursion(initial, flags, path);
	delete_list(&initial);
}

int		main(int ac, char **av)
{
	int		flags;
	int		check;
	char	*args[ac];
	int		j;

	check = 0;
	flags = get_flags(ac, av);
	if (ac == 1)
		ft_ls(".", flags);
	else
	{
		j = add_args(args, ac, av);
		check = execute_args(args, flags, j);
		if (check == 0)
			ft_ls(".", flags);
	}
	return (0);
}
