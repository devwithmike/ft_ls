/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 08:53:30 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/03 12:14:06 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_ls.h"

void	ft_ls(char *path, unsigned char flags)
{
	struct dirent *de;

	DIR *dr = opendir(path);
	while ((de = readdir(dr)) != NULL)
		if (!flags)
		{
			if (de->d_name[0] != '.')
			{
				ft_putstr(de->d_name);
				ft_putchar('\t');
			}
		}
    	else
		{
    		ft_putstr(de->d_name);
    		ft_putchar('\t');
    	}
}

int main (int ac, char **av)
{
	unsigned char flags;
	int i;

	i = 1;
	flags = get_flags(ac, av);
	if (flags & 2)
		ft_putstr("-a");
	/*if (ac == 1)
		ft_ls(".", flags);
	else
		while (i < ac)
		{
			if (av[i][0] != '-')
				ft_ls(av[i],flags);
			i++;
		}*/
	ft_putchar('\n');
	return (0);
}
