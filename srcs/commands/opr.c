/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:30:01 by marvin            #+#    #+#             */
/*   Updated: 2025/04/25 17:30:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void    ra(t_stack_node **stack_a, bool print)
{
    t_stack_node *first;
    t_stack_node *last;

    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return;

    first = *stack_a;
    last = *stack_a;

    while (last->next)
        last = last->next;
    *stack_a = first->next;
    (*stack_a)->prev = NULL;

    last->next = first;
    first->prev = last;
    first->next = NULL;

    if (print)
        write(1, "ra\n", 3);
}

void    rb(t_stack_node **stack_b, bool print)
{
    t_stack_node *first;
    t_stack_node *last;

    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return;

    first = *stack_b;
    last = *stack_b;

    while (last->next)
        last = last->next;
    *stack_b = first->next;
    (*stack_b)->prev = NULL;

    last->next = first;
    first->prev = last;
    first->next = NULL;

    if (print)
        write(1, "rb\n", 3);
}
void    rr(t_stack_node **stack_a, t_stack_node **stack_b, bool print)
{
    ra(stack_a, false);
    rb(stack_b, false);
    
    if (print)
        write(1, "rr\n", 3);
}
void    rra(t_stack_node **stack_a, bool print)
{
    t_stack_node *last;

    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return;

    last = *stack_a;
    while (last->next)
        last = last->next;

    last->prev->next = NULL;
    last->next = *stack_a;
    (*stack_a)->prev = last;
    last->prev = NULL;
    *stack_a = last;

    if (print)
        write(1, "rra\n", 4);
}
void    rrb(t_stack_node **stack_b, bool print)
{
    t_stack_node *last;

    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return;

    last = *stack_b;
    while (last->next)
        last = last->next;

    last->prev->next = NULL;
    last->next = *stack_b;
    (*stack_b)->prev = last;
    last->prev = NULL;
    *stack_b = last;

    if (print)
        write(1, "rrb\n", 4);
}

void    rrr(t_stack_node **stack_a, t_stack_node **stack_b, bool print)
{
    rra(stack_a, false);
    rrb(stack_b, false);
    
    if (print)
        write(1, "rrr\n", 4);
}