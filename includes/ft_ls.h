/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 09:17:47 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/26 09:28:50 by mimeyer          ###   ########.fr       */
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
# include <sys/acl.h>
# include <sys/xattr.h>
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
	char			*path;
	int				block;
	struct s_dir	*next;
}					t_dir;

typedef struct		s_blocks
{
	int				total;
	int	flags;
}					t_blocks;


void	format_acl(t_dir *ptr);
void	format_name(t_dir *ptr, int flags);

int					check_flags(char c);
void	format_normal(t_dir *ptr, int flags);

int					isdir(const char *path);
void				files_args(char **args, int flags);
int					error_file(char *path);
int					error_permission(char *path);
int					check_errors(char *path, DIR *dr);
int					execute_args(char **args, int flags, int ac);

int				add_args(char **args, int ac, char **av);
void				sort_args(char **args, int ac);

char				*convert_un(int uid, t_blocks *flags);
char				*convert_gn(int gib, t_blocks *flags);

void	set_blocks(int block, t_blocks *total, char *name);

t_dir	*set_list(struct dirent *de, char *path, t_blocks *blocks);

int		get_flags(int ac, char **av);
int	execute_flags(char **av, int i, int j, int flags);

void				print_time(char *str);
void				convert_time(char *str);
void				format_nlink(t_dir *list);
void				format_size(t_dir *list);
void				convert_nlink(char *path, t_dir *list);
void				format_line(t_dir *list, char *path, int flags);
void				format_long(t_dir *list);
void				format_permissions(t_dir *list);
void				delete_list(t_dir **list);
void				print_recursion(char *path);
void				ft_ls(char *path, int flags);
void	print_blocks(t_blocks *blocks);
void				print_list(t_dir *list, int flags, char *path);
void				print_normal(t_dir *list, int flags);
void	list_add(t_dir **alst, struct dirent *de, char *path, t_blocks *blocks);
void				recursion(t_dir *list, int flags, char *path);
void	print_output(t_dir *list, int flags, char *path, t_blocks *blocks);
void				basic_print(struct dirent *de, int flags,
						DIR *dr);
void				recursive_print(struct dirent *de, int flags,
						char *path);

void				front_back_sort(t_dir* source, t_dir** frontRef, t_dir** backRef);
void				merge_sort(t_dir** headRef, int flags);
t_dir				*sorted_merge(t_dir* a, t_dir* b, int flags);

#endif
