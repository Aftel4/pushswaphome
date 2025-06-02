/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:25:36 by marvin            #+#    #+#             */
/*   Updated: 2025/04/17 17:25:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

/* STRUCTURES */

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

/* PARSING ET INITIALISATION */
bool			is_valid_number(char *str);
long			ft_atol(char *str);
bool			has_duplicate(t_stack_node *stack, int n);
t_stack_node	*create_new_node(int value);
void			append_node(t_stack_node **stack, t_stack_node *new_node);
bool			check_limits_and_duplicates(t_stack_node *stack_a, char *arg);
bool			process_arg(t_stack_node **stack_a, char *arg);
bool			init_stack_a(t_stack_node **stack_a, int argc, char **argv);
void			current_index(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			prep_for_push(t_stack_node **s, t_stack_node *n, char c);
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);

/* OPÉRATIONS DE BASE */
void			sa(t_stack_node **stack_a, bool print);
void			sb(t_stack_node **stack_b, bool print);
void			ss(t_stack_node **stack_a, t_stack_node **stack_b, bool print);
void			pa(t_stack_node **stack_a, t_stack_node **stack_b, bool print);
void			pb(t_stack_node **stack_a, t_stack_node **stack_b, bool print);
void			ra(t_stack_node **stack_a, bool print);
void			rb(t_stack_node **stack_b, bool print);
void			rr(t_stack_node **stack_a, t_stack_node **stack_b, bool print);
void			rra(t_stack_node **stack_a, bool print);
void			rrb(t_stack_node **stack_b, bool print);
void			rrr(t_stack_node **stack_a, t_stack_node **stack_b, bool print);


/* ALGORITHME */
void			set_index(t_stack_node *stack);
void			set_target_nodes(t_stack_node *stack_a, t_stack_node *stack_b);
void			set_position(t_stack_node *stack);
void			set_push_cost(t_stack_node *stack_a, t_stack_node *stack_b);
void			set_cheapest(t_stack_node *stack);
void			do_cheapest_move(t_stack_node **stack_a, t_stack_node **stack_b);
void			sort_three(t_stack_node **stack);
void			sort(t_stack_node **stack_a, t_stack_node **stack_b);

/* FONCTIONS UTILITAIRES */
void			ft_putstr_fd(char *s, int fd);
int				stack_size(t_stack_node *stack);
bool			is_sorted(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
void			free_stack(t_stack_node **stack);
int				stack_len(t_stack_node *stack)
bool			stack_sorted(t_stack_node *stack);

#endif