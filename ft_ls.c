/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 08:53:30 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/01 15:59:05 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_ls.h"

unsigned char		ft_flags(int ac, char **av)
{
	int				i;
	char			**str;
	unsigned char	flags;

	flags = 0;
	i = 1;
	while (i < ac)
	{
		str = &av[i];
		while (**str == 'l' || **str == 'a' || **str == 'R' ||
			**str == 'r' || **str == 't' || **str == ' ' || **str == '-')
		{
			if (**str == 'l')
				flags |= 1;
			if (**str == 'a')
				flags |= 2;
			if (**str == 'R')
				flags |= 4;
			if (**str == 'r')
				flags |= 8;
			if (**str == 't')
				flags |= 16;
			(*str)++;
		}
		i++;
	}
	return (flags);
}

int main(int ac, char **av)
{
	unsigned char flags;
	struct dirent *de;
    DIR *dr = opendir(".");

    flags = ft_flags(ac, av);

    if (dr == NULL)
    {
        printf("Could not open current directory");
        return 0;
    }
    while ((de = readdir(dr)) != NULL)
    	if (ac == 1)
    	{
    		if (de->d_name[0] != '.')
        		printf("%s\t", de->d_name);
        }
    	else
    		if	((flags & 2) && (!(flags & 1) && (!(flags & 4) 
    			&& (!(flags & 8)) && (!(flags & 16)))))
    			printf("%s\t", de->d_name);

    printf("\n");
    closedir(dr);
	return (0);
}
