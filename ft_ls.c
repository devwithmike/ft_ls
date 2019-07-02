/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 08:53:30 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/02 16:04:32 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_ls.h"

unsigned char		get_flags(int ac, char **av)
{
	int				i;
	char			**str;
	unsigned char	flags;

	flags = 0;
	i = 1;
	while (i < ac)
	{
		str = &av[i];
		if (**str == '-')
		{
			(*str)++;
			while (**str == 'l' || **str == 'a' || **str == 'R' ||
			**str == 'r' || **str == 't')
			{
				if (**str == 'l')
					flags |= 1;
				else if (**str == 'a')
					flags |= 2;
				else if (**str == 'R')
					flags |= 4;
				else if (**str == 'r')
					flags |= 8;
				else if (**str == 't')
					flags |= 16;
				(*str)++;
			}
		}
		i++;
	}
	return (flags);
}

int main (int ac, char **av)
{
	unsigned char flags;
	char **str = NULL;
	int i;

	i = 2;
	flags = get_flags(ac, av);
	while (i < ac)
	{
		str = &av[i];
		if (**str == '-')
			(*str)++;
		else
		{
			printf("%s\n", *str);
			(*str)++;
		}
		i++;
	}
	return (0);
}
