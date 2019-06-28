/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 08:53:30 by mimeyer           #+#    #+#             */
/*   Updated: 2019/06/28 10:54:10 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_ls.h"

int main(void)
{
	struct dirent *de;
    DIR *dr = opendir(".");

    if (dr == NULL)
    {
        printf("Could not open current directory" );
        return 0;
    }
    while ((de = readdir(dr)) != NULL)
    	if (de->d_name[0] != '.')
        	printf("%s\t", de->d_name);
    printf("\n");
    closedir(dr);
	return (0);
}
