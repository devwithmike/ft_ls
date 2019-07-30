/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 09:17:47 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/30 10:22:35 by mimeyer          ###   ########.fr       */
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
	time_t			nano;
	char			*path;
	struct s_dir	*next;
}					t_dir;

typedef struct		s_blocks
{
	int				total;
	int				flags;
	int				count;
}					t_blocks;

void				sort_args(char **args, int ac);
int					add_args(char **args, int ac, char **av);
void				files_args(char **args, int flags, int ac);
int					execute_args(char **args, int flags, int ac);

int					bg_colour(t_dir *list);
void				add_colour(t_dir *list, int flags);

void				convert_nlink(char *path, t_dir *list);
char				*convert_un(int uid, t_blocks *flags);
char				*convert_gn(int gib, t_blocks *flags);
void				print_time(char *str);
void				convert_time(char *str);

int					error_file(char *path);
int					error_permission(char *path);
int					check_errors(char *path, DIR *dr);

void				initialize_blocks(t_blocks *blocks, int flags, int ac);
void				format_id(char *id);
void				sort_nano_ascii(int flags, t_dir *a, t_dir *b,
						t_dir **result);

void				incorrect_flags(char c);
int					check_flags(char c);
int					execute_flags(char **av, int i, int j, int flags);
int					get_flags(int ac, char **av);

void				format_nlink(t_dir *list);
void				format_size(t_dir *list);
void				format_permissions(t_dir *list);
void				format_long(t_dir *list);
void				format_line(t_dir *list, char *path, int flags);

void				recursion(t_dir *list, int flags, char *path, int ac);
void				ft_ls(char *path, int flags, int ac);

t_dir				*set_list(struct dirent *de, char *path, t_blocks *blocks);
void				delete_list(t_dir **list);
void				list_add(t_dir **alst, struct dirent *de, char *path,
						t_blocks *blocks);
void				rev_lst(t_dir **head);

void				print_blocks(t_blocks *blocks);
void				print_list(t_dir *list, int flags, char *path);
void				print_normal(t_dir *list, int flags);
void				print_recursion(char *path, t_blocks *blocks);
void				print_output(t_dir *list, int flags, char *path,
						t_blocks *blocks);

t_dir				*sorted_merge(t_dir *a, t_dir *b, int flags);
t_dir				*sorted_merge_t(t_dir *a, t_dir *b, int flags);
void				merge_sort(t_dir **head_ref, int flags);
void				front_back_sort(t_dir *source, t_dir **front_ref,
						t_dir **back_ref);
void				check_nano(int flags, t_dir *a, t_dir *b, t_dir **result);

void				format_acl(t_dir *ptr);
void				format_name(t_dir *ptr, int flags);
void				format_normal(t_dir *ptr, int flags);
int					isdir(const char *path);
void				set_blocks(int block, t_blocks *total, char *name);

#endif
