/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:17:49 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/15 13:37:45 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	convert_nlink(char *path, t_dir *list)
{
	char	buf[1025];
	char	*tmp;
	char	*full;

	ft_bzero(buf, 1025);
	tmp = ft_strjoin(path, "/");
	full = ft_strjoin(tmp, list->name);
	readlink(full, buf, 1024);
	ft_putstr(" -> ");
	ft_putstr(buf);
	free(tmp);
	free(full);
}

char	*convert_un(int uid)
{
	struct passwd *pwd;

	pwd = getpwuid(uid);
	if (pwd != NULL)
		return (ft_strdup(pwd->pw_name));
	return (ft_itoa(uid));
}

char	*convert_gn(int gib)
{
	struct group *grp;

	grp = getgrgid(gib);
	if (grp != NULL)
		return (ft_strdup(grp->gr_name));
	return (ft_itoa(gib));
}

void	convert_time(char *str)
{
	char	ret[14];
	int		i;
	int		j;

	j = 0;
	i = 4;
	ft_strcpy(ret, "000  0 00:00 ");
	while (i < 16)
	{
		ret[j] = str[i];
		j++;
		i++;
	}
	ft_putstr(ret);
}
