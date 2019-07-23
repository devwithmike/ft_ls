/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:27:28 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/23 08:18:56 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			incorrect_flags(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putstr("\nusage: ./ft_ls [-alRrt1] [file ...]\n");
}

int				check_flags(char c)
{
	if (c == 'l')
		return (1);
	if (c == 'a')
		return (2);
	if (c == 'R')
		return (4);
	if (c == 'r')
		return (8);
	if (c == 't')
		return (16);
	if (c == '1')
		return (32);
	if (c == 'n')
		return (64);
	return (128);
}

unsigned char	execute_flags(char **av, int i, int j, unsigned char flags)
{
	while (av[i][j])
	{
		flags += check_flags(av[i][j]);
		if (flags & 128)
		{
			incorrect_flags(av[i][j]);
			exit(1);
		}
		j++;
	}
	return (flags);
}

unsigned char	get_flags(int ac, char **av)
{
	int				i;
	int				j;
	unsigned char	flags;

	flags = ' ';
	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j++] == '-')
		{
			if ((av[i][j] == '-') && (av[i][j + 1] != '-'))
				break ;
			flags = execute_flags(av, i, j, flags);
		}
		else
			break ;
		i++;
	}
	return (flags);
}
