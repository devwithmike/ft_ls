/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 09:17:47 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/08 15:08:42 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <stdio.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>

typedef struct		s_dir
{
	char			*name;
	nlink_t			nlink;
	char			*uid;
	char			*gid;
	off_t			size;
	struct s_dir	*next;
}					t_dir;

int					check_flags(char *str);
int					check_errors(char *path);
t_dir				*set_list(const char *name);
void				delete_list(t_dir **list);
void				list_add(t_dir **alst, const char *name);
//void				print_list(t_dir *list, unsigned char flags);
void				basic_print(struct dirent *de, unsigned char flags,
						DIR *dr);
void				recursive_print(struct dirent *de, unsigned char flags,
						char *path);
unsigned char		get_flags(int ac, char **av);
void				ft_ls(char *path, unsigned char flags);
void				recursion(struct dirent *de, unsigned char flags,
						char *path);
char				*convert_un(int uid);
char				*convert_gn(int gib);
void	print_list(t_dir *list, unsigned char flags);
void	print_normal(t_dir *list, unsigned char flags);
void	print_output(t_dir *list, unsigned char flags);


// Sorting
void FrontBackSplit(t_dir* source, t_dir** frontRef, t_dir** backRef);
void MergeSort(t_dir** headRef, unsigned char flags);
t_dir* SortedMerge(t_dir* a, t_dir* b, unsigned char flags);


#endif
