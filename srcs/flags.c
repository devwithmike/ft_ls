/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:27:28 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/29 15:09:04 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	incorrect_flags(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putstr("\nusage: ./ft_ls [-AGRalnprt1] [file ...]\n");
}

int		check_flags(char c)
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
	if (c == 'f')
		return (128);
	if (c == 'p')
		return (256);
	if (c == 'G')
		return (512);
	if (c == 'A')
		return (1024);
	return (2048);
}

int		execute_flags(char **av, int i, int j, int flags)
{
	while (av[i][j])
	{
		flags |= check_flags(av[i][j]);
		if (flags & 2048)
		{
			incorrect_flags(av[i][j]);
			exit(1);
		}
		j++;
	}
	if (((flags & 128) || (flags & 1024)) && !(flags & 2))
		flags += 2;
	if (flags & 128)
	{
		flags -= 1;
		flags -= 16;
	}
	return (flags);
}

int		get_flags(int ac, char **av)
{
	int	i;
	int	j;
	int	flags;

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
