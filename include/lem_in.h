/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 15:24:56 by arive-de          #+#    #+#             */
/*   Updated: 2017/09/12 16:03:44 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/libft.h"
# include <stdio.h>

typedef struct				s_list_tube
{
	struct s_list_li		*addr;
	struct s_list_tube		*next;
}							t_list_tube;
typedef struct				s_list_li
{
	char					*name;
	int						x;
	int						y;
	int						start;
	int						end;
	int						seen;
	t_list_tube				*link;
	struct s_list_li		*next;
}							t_list_li;
typedef struct				s_output
{
	struct s_output			*orig;
	char					*name;
	struct s_output			*next;
}							t_output;
typedef struct				s_queue
{
	struct s_queue			*prev;
	t_list_li				*room;
	struct s_queue			*next;
}							t_queue;
typedef struct				s_lem
{
	int						nb_fmi;
	int						nb_line;
	int						nb_room;
	int						aff;
	int						start;
	int						x;
	int						y;
	int						sx;
	int						sy;
	int						end;
	char					*line;
	char					**tab;
	char					**tab2;
	char					*name;
	char					**name_s;
	char					*start_n;
	int						flag;
	int						flag_t;
	t_list_li				*lst;
	t_list_li				*cur;
	t_list_tube				*tub;
	t_output				*out;
	t_queue					*que;
}							t_lem;
t_list_li					*create_maillon_li(t_lem *env);
t_list_tube					*create_maillon_tub(t_list_li *tmp);
t_queue						*create_maillon_queue(t_queue *cur,
													t_list_li *addr);
t_output					*create_maillon_output(char *str);
void						print_lst(t_lem *env);
void						add_maillon_end(t_list_li **begin_list,
													t_list_li *data);
void						add_maillon_end2(t_list_tube **begin_list,
													t_list_tube *data);
void						add_maillon_end3(t_queue **begin_list,
													t_queue *data);
void						add_maillon_beg(t_output **begin_list,
													t_output *data);
void						get(t_lem *env);
void						freedom(t_lem *env);
t_output					*last(t_output *tmp);
int							lst_count(t_lem *env);
void						printer(t_lem *env, t_output *tmp);
void						add_orig(t_lem *env);
void						error();
void						del(t_lem *env);
int							checker(t_lem *env);
int							tube(t_lem *env, char *str);
int							is_fmi(t_lem *env, char *str);
int							salle(t_lem *env, char *str);
int							comment(t_lem *env, char *str);
int							parser(t_lem *env, char *str);
int							solver(t_lem *env);
t_list_li					*init_solver(t_lem *env);
#endif
