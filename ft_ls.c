/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 08:53:30 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/03 09:50:53 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_ls.h"

int				check_flags(char **str)
{
	if (**str == 'l')
		return 1;
	else if (**str == 'a')
		return 2;
	else if (**str == 'R')
		return 4;
	else if (**str == 'r')
		return 8;
	else if (**str == 't')
		return 16;
	return 0;
}

unsigned char	get_flags(int ac, char **av)
{
	int				i;
	char			**str;
	unsigned char	flags;

	flags = '\0';
	i = 0;
	while (++i < ac)
	{
		str = &av[i];
		if (**str == '-')
		{
			(*str)++;
			while (**str == 'l' || **str == 'a' || **str == 'R' ||
			**str == 'r' || **str == 't')
			{
				flags |= check_flags(str);
				(*str)++;
			}
		}
	}
	return (flags);
}

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

	i = 0;
	flags = get_flags(ac, av);
	if (ac == 1)
		ft_ls(".", flags);
	else
		while (++i < ac)
		{
			ft_ls(av[i],flags);
		}
	ft_putchar('\n');
	return (0);
}
