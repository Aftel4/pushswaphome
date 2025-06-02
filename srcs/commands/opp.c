/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:13:09 by marvin            #+#    #+#             */
/*   Updated: 2025/04/24 19:13:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void    pa(t_stack_node **stack_a, t_stack_node **stack_b, bool print)
{
    t_stack_node *tempb;

    if(!stack_b || !*stack_b)
        return;
    tempb = *stack_b;
    *stack_b = tempb->next;
    if(*stack_b)
        (*stack_b)->prev = NULL;
    tempb->next = *stack_a;
    tempb->prev = NULL;
    if(*stack_a)
        (*stack_a)->prev = tempb;
    *stack_a = tempb;
    if (print)
        write(1, "pa\n", 3);
}
void    pb(t_stack_node **stack_a, t_stack_node **stack_b, bool print)
{
    t_stack_node *tempa;

    if(!stack_a || !*stack_a)
        return;
    tempa = *stack_a;
    *stack_a = tempa->next;
    if(*stack_a)
        (*stack_a)->prev = NULL;
    tempa->next = *stack_b;
    tempa->prev = NULL;
    if(*stack_b)
        (*stack_b)->prev = tempa;
    *stack_b = tempa;
    if (print)
        write(1, "pb\n", 3);
}
