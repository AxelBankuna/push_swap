/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abukasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:49:30 by abukasa           #+#    #+#             */
/*   Updated: 2019/01/12 17:03:51 by abukasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

struct					s_stack_a
{
	int					val;
	struct s_stack_a	*next;
	struct s_stack_a	*prev;
	int					rank_a;
	int					rank_b;
	int					rank;
	int					direction_a;
	int					direction_b;
}						*head_a;

struct					s_stack_b
{
	int					val;
	struct s_stack_b	*next;
	struct s_stack_b	*prev;
}						*head_b;

struct					s_stack_check
{
	long					val;
	struct s_stack_check	*next;
	struct s_stack_check	*prev;
};

struct					s_sorted
{
	int					val;
	int					place;
	struct s_sorted		*next;
	struct s_sorted		*prev;
}						*head_s;
struct s_sorted			*t1_s;
struct s_sorted			*t2_s;

struct					s_info
{
	int					largest_a_pos;
	int					largest_a;
	int					smallest_a_pos;
	int					smallest_a;
	int					largest_b_pos;
	int					largest_b;
	int					smallest_b;
	int					count_b;
	int					pos_b;
	int					direction;
	int					ready_dir;
	int					print;
}						allinfo;

struct					s_commands
{
	char				*cmd;
	struct s_commands	*next;
}						*head;

struct s_stack_a		*load_a(struct s_stack_a *head_a, int nbr);
struct s_stack_b		*load_b(struct s_stack_b *head_b, int nbr);
struct s_stack_a		*receive_and_load(struct s_stack_a *head_a, char *av);
int						asc(int a, int b);
struct s_sorted			*load_s(struct s_sorted *head_s, int nbr);
struct s_sorted			*r_and_l_s(struct s_sorted *head_s, char *av);
struct s_sorted			*arrange_s(struct s_sorted *head_s);
int						checkdup(struct s_sorted *head_s);
int						count_a(struct s_stack_a *head_a);
int						count_b(struct s_stack_b *head_b);
void					sa(struct s_stack_a **head_a);
void					sb(struct s_stack_b **head_b);
void					ra(struct s_stack_a **head_a);
void					rb(struct s_stack_b **head_b);
void					ss(struct s_stack_a **head_a,
		struct s_stack_b **head_b);
void					rr(struct s_stack_a **head_a,
		struct s_stack_b **head_b);
void					rra(struct s_stack_a **head_a);
void					rrb(struct s_stack_b **head_b);
void					rrr(struct s_stack_a **head_a,
		struct s_stack_b **head_b);
struct s_stack_b		*pb(struct s_stack_a **head_a,
		struct s_stack_b *head_b);
struct s_stack_a		*pa(struct s_stack_a *head_a,
		struct s_stack_b **head_b);
struct s_stack_a		*a_load(struct s_stack_a *head_a, int x);
struct s_stack_a		*createnode_a(int x);
struct s_stack_b		*createcode_b(int x);
struct s_stack_a		*remove_a(struct s_stack_a *head_a);
struct s_stack_b		*remove_b(struct s_stack_b *head_b);
void					twonumbers(struct s_stack_a **head_a);
void					three(struct s_stack_a **head_a,
		struct s_info allinfo);
void					five(struct s_stack_a **head_a,
		struct s_stack_b **head_b,
		struct s_sorted *head_s);
void					lots(struct s_stack_a **head_a,
		struct s_stack_b **head_b);
void					sort(struct s_stack_a **head_a,
		struct s_stack_b **head_b,
		struct s_info allinfo);
int						checked(struct s_stack_a **top_a,
		struct s_sorted **top);
struct s_stack_b		*revolver(struct s_stack_a **top_a,
		struct s_stack_b **top_b);
struct s_info			largest_a(struct s_stack_a *head_a,
		struct s_info allinfo);
struct s_info			smallest_a(struct s_stack_a *head_a,
		struct s_info allinfo);
void					ready_b(struct s_stack_b **top_b);
int						largest_val(struct s_stack_a **top);
void					smallest_b(struct s_stack_b **top);
int						largest_b(struct s_stack_b **top);
int						*ready_b_(struct s_stack_b **top_b,
		int total, int holder,
		int *ret);
void					rank_a(struct s_stack_a **head);
void					rank_b(struct s_stack_a *temp,
		struct s_stack_b **head);
void					rank(struct s_stack_a **head_a,
		struct s_stack_b **head_b);
struct s_stack_a		*select_a(struct s_stack_a **head);
struct s_stack_a		*move_a(struct s_stack_a **head_a,
		struct s_stack_b **head_b);
void					check(struct s_commands **head,
		struct s_stack_a **head_a,
		struct s_stack_b **head_b);
int						cleanmain(char **av);
int						ordered(struct s_stack_a *head_a);
void					five(struct s_stack_a **head_a,
		struct s_stack_b **head_b, struct s_sorted *head_s);
void					five_(struct s_stack_a **head_a,
		struct s_stack_b **head_b, int i);
void					rev1(struct s_stack_b **head_b);
void					rev2(struct s_stack_b **head_b);
void					rev3(struct s_stack_a *head_a,
		struct s_stack_b **head_b);
void					rrr_a(struct s_stack_a **head_a);
void					rrr_b(struct s_stack_b **head_b);
void					rr_a(struct s_stack_a **head_a);
void					rr_b(struct s_stack_b **head_b);
void					move_a_ext(struct s_stack_a *temp_a,
		struct s_stack_a **head_a, struct s_stack_b **head_b);
void					freenode_a(struct s_stack_a **head);
void					freenode_s(struct s_sorted **head);
void					freecmd(struct s_commands **head);
int						check_max(char *str);
void					movefree(struct s_stack_a **temp,
		struct s_stack_a *head_a, char *num_str);
char					*ft_join(char const *s1, char const *s2);
char					*onestring(char **av);
void					insert(struct s_stack_a **head_a,
		struct s_sorted **head_s, char **av);
int						insert_(struct s_stack_a **head_a,
		struct s_sorted **head_s, char **av);
#endif
