/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:38:45 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/04 13:07:22 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	basic_print(struct dirent *de, unsigned char flags, DIR *dr)
{
	while ((de = readdir(dr)))
		if (!(flags & 2))
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
	closedir(dr);
}

void	recursive_print(struct dirent *de, unsigned char flags, char *path)
{
    ft_putstr("\n\n");
	ft_putstr(path);
	ft_putchar('/');
	ft_putstr(de->d_name);
	ft_putstr(":\n");
	ft_ls(ft_strjoin(path, ft_strjoin("/", de->d_name)), flags);
}