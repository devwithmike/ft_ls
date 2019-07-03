/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:27:28 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/03 13:40:21 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		check_flags(char *str)
{
	if (*str == 'l')
		return 1;
	else if (*str == 'a')
		return 2;
	else if (*str == 'R')
		return 4;
	else if (*str == 'r')
		return 8;
	else if (*str == 't')
		return 16;
	return 0;
}

unsigned char	get_flags(int ac, char **av)
{
	int				i;
	char			*str;
	unsigned char	flags;

	flags = '\0';
	i = 1;
	while (i < ac)
	{
		str = ft_strdup(av[i]);
		if (*str == '-')
		{
			(str)++;
			while (*str == 'l' || *str == 'a' || *str == 'R' ||
			*str == 'r' || *str == 't')
			{
				flags |= check_flags(str);
				(str)++;
			}
		}
		i++;
	}
	return (flags);
}
