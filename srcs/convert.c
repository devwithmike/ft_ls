/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:17:49 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/23 08:08:52 by mimeyer          ###   ########.fr       */
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

char	*convert_un(int uid, t_blocks *flags)
{
	struct passwd *pwd;

	pwd = getpwuid(uid);
	if ((pwd != NULL) && !(flags->flags & 64))
		return (ft_strdup(pwd->pw_name));
	return (ft_itoa(uid));
}

char	*convert_gn(int gib, t_blocks *flags)
{
	struct group *grp;

	grp = getgrgid(gib);
	if ((grp != NULL) && !(flags->flags & 64))
		return (ft_strdup(grp->gr_name));
	return (ft_itoa(gib));
}

void	print_time(char *str)
{
	int len;
	int i;

	i = 0;
	len = ft_strlen(str);
	ft_putchar(str[4]);
	ft_putchar(str[5]);
	ft_putchar(' ');
	while (i < 3)
	{
		ft_putchar(str[i]);
		i++;
	}
	i = 7;
	ft_putchar(' ');
	while (i < len)
	{
		ft_putchar(str[i]);
		i++;
	}
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
	print_time(ret);
}
