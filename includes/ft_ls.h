/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 09:17:47 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/12 10:14:36 by mimeyer          ###   ########.fr       */
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
# include <errno.h>
# include <time.h>

typedef struct		s_dir
{
	char			*name;
	mode_t			mode;
	nlink_t			nlink;
	char			*uid;
	char			*gid;
	off_t			size;
	int				type;
	time_t			time;
	int				block;
	struct s_dir	*next;
}					t_dir;

int					check_flags(char c);
int					error_file(char *path);
int					error_permission(char *path);
int					check_errors(char *path, DIR *dr);

char				*convert_un(int uid);
char				*convert_gn(int gib);

t_dir				*set_list(struct dirent *de, char *path);

unsigned char		get_flags(int ac, char **av);

void				convert_time(char *str);
void				format_line(t_dir *list);
void				long_format(t_dir *list);
void				delete_list(t_dir **list);
void				print_recursion(char *path);
void				ft_ls(char *path, unsigned char flags);
void				print_blocks(t_dir *list, unsigned char flags);
void				print_list(t_dir *list, unsigned char flags);
void				print_normal(t_dir *list, unsigned char flags);
void				list_add(t_dir **alst, struct dirent *de, char *path);
void				recursion(t_dir *list, unsigned char flags, char *path);
void				print_output(t_dir *list, unsigned char flags, char *path);
void				basic_print(struct dirent *de, unsigned char flags,
						DIR *dr);
void				recursive_print(struct dirent *de, unsigned char flags,
						char *path);

// Sorting
void FrontBackSplit(t_dir* source, t_dir** frontRef, t_dir** backRef);
void MergeSort(t_dir** headRef, unsigned char flags);
t_dir* SortedMerge(t_dir* a, t_dir* b, unsigned char flags);

#endif
