/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:27:28 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/17 15:48:18 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			incorrect_flags(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putstr("\nusage: ft_ls [-alRrt] [file ...]\n");
}

int				check_flags(char c)
{
	if (c == 'l')
		return (1);
	else if (c == 'a')
		return (2);
	else if (c == 'R')
		return (4);
	else if (c == 'r')
		return (8);
	else if (c == 't')
		return (16);
	else
		return (128);
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
			while (av[i][j])
			{
				flags += check_flags(av[i][j]);
				if (flags & 128)
				{
					incorrect_flags(av[i][j]);
					return ('\0');
				}
				j++;
			}
		}
		else
			break ;
		i++;
	}
	return (flags);
}


// unsigned char	get_flags(int ac, char **av)
// {
// 	int				i;
// 	int				j;
// 	unsigned char	flags;

// 	flags = '\0';
// 	i = 1;
// 	while (i < ac)
// 	{
// 		j = 0;
// 		if (av[i][j++] == '-')
// 		{
// 			if (av[i][j] == '-')
// 				break ;
// 			while (av[i][j] == 'l' || av[i][j] == 'a' || av[i][j] == 'R' ||
// 			av[i][j] == 'r' || av[i][j] == 't')
// 			{
// 				flags |= check_flags(av[i][j]);
// 				j++;
// 			}
// 		}
// 		else
// 			break ;
// 		i++;
// 	}
// 	return (flags);
// }
