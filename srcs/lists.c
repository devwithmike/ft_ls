/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 12:09:38 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/23 10:15:40 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_dir	*set_list(struct dirent *de, char *path, t_blocks *blocks)
{
	t_dir		*new;
	struct stat	sb;
	char		*tmp;
	char		*tmp_path;

	if (!(new = (t_dir *)malloc(sizeof(*new))))
		return (NULL);
	tmp_path = ft_strjoin(path, path[ft_strlen(path) - 1] != '/' ? "/" : "");
	tmp = ft_strjoin(tmp_path, de->d_name);
	lstat(tmp, &sb);
	new->name = ft_strdup(de->d_name);
	new->nlink = sb.st_nlink;
	new->uid = convert_un(sb.st_uid, blocks);
	new->gid = convert_gn(sb.st_gid, blocks);
	new->size = sb.st_size;
	new->type = de->d_type;
	new->mode = sb.st_mode;
	new->time = sb.st_mtime;
	new->next = NULL;
	set_blocks(sb.st_blocks, blocks, new->name);
	free(tmp_path);
	free(tmp);
	return (new);
}

void	delete_list(t_dir **list)
{
	t_dir *current;
	t_dir *next;

	current = *list;
	while (current)
	{
		next = current->next;
		free(current->name);
		free(current->uid);
		free(current->gid);
		free(current);
		current = next;
	}
	*list = NULL;
}

void	list_add(t_dir **alst, struct dirent *de, char *path, t_blocks *blocks)
{
	t_dir	*new;
	t_dir	*tail;

	tail = *alst;
	new = set_list(de, path, blocks);
	if (*alst == NULL)
		(*alst)->next = new;
	else
	{
		while (tail->next != NULL)
			tail = tail->next;
		tail->next = new;
	}
}
