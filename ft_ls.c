/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 08:53:30 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/01 15:19:56 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_ls.h"

unsigned char		ft_flags(char **av, int ac)
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
	/*struct dirent *de;
    DIR *dr = opendir(".");

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
    		if (ft_strcmp(av[1], "-a") == 0)
    			printf("%s\t", de->d_name);

    printf("\n");
    closedir(dr);*/

    unsigned char flags;

    flags = ft_flags(av, ac);

	if (flags & 1)
		printf("Flag l is a go\n");
	if (flags & 2)
		printf("Flag a is a go\n");
	if (flags & 4)
		printf("Flag R is a go\n");
	if (flags & 8)
		printf("Flag r is a go\n");
	if (flags & 16)
		printf("Flag t is a go\n");

	return (0);
}
