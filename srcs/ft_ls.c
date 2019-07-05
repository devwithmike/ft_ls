/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 08:53:30 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/05 09:52:46 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_ls.h"

t_dir	*set_list(const char *name)
{
	t_dir *new;

	if (!(new = (t_dir *)malloc(sizeof(*new))))
		return (NULL);
	if (!(new->name = (char *)malloc(ft_strlen(name))))
	{
		free(new);
		return (NULL);
	}
	new->name = ft_strdup(name);
	new->next = NULL;
	return (new);
}

void	list_add(t_dir **alst, const char *name)
{
	t_dir *new;

	new = set_list(name);
	new->next = *alst;
	*alst = new;
}

void	print_list(t_dir *list)
{
	t_dir *ptr;
	ptr = list;
	while (ptr != NULL)
	{
		ft_putstr(ptr->name);
		ft_putchar('\t');
		ptr = ptr->next;
	}
}

void	ft_ls(char *path, unsigned char flags)
{
	struct dirent *de;
	t_dir *initial;

	initial = NULL;

	(void)flags;

	de = NULL;
	DIR *dr = opendir(path);
	if (check_errors(path) == 1)
		return;
	while((de = readdir(dr)))
	{
		if (!initial)
			initial = set_list(de->d_name);
		else
			list_add(&initial, de->d_name);
	}
	closedir(dr);
	print_list(initial);
	
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

int main (int ac, char **av)
{
	unsigned char flags;
	int i;

	i = 1;
	flags = get_flags(ac, av);
	if ((ac == 1) || ((ac == 2) && flags))
		ft_ls(".", flags);
	else
		while (i < ac)
		{
			if (av[i][0] != '-')
				ft_ls(av[i],flags);
			i++;
		}
	ft_putchar('\n');
	return (0);
}
