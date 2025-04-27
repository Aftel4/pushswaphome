/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:28:23 by marvin            #+#    #+#             */
/*   Updated: 2025/04/17 17:28:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_stack_node **stack_a, bool print)
{
    t_stack_node    *first;
    t_stack_node    *second;
    int             temp;

    if (!stack_a || !(*stack_a) || !(*stack_a)->next)
        return;
    
    first = *stack_a;
    second = first->next;
    temp = first->nbr;
    first->nbr = second->nbr;
    second->nbr = temp;
    temp = first->index;
    first->index = second->index;
    second->index = temp;
    if (print)
        write(1, "sa\n", 3);
}
void    sb(t_stack_node **stack_b, bool print)
{
    t_stack_node    *first;
    t_stack_node    *second;
    int             temp;

    if (!stack_b || !(*stack_b) || !(*stack_b)->next)
        return;
    
    first = *stack_b;
    second = first->next;
    temp = first->nbr;
    first->nbr = second->nbr;
    second->nbr = temp;
    temp = first->index;
    first->index = second->index;
    second->index = temp;
    if (print)
        write(1, "sb\n", 3);
}
void    ss(t_stack_node **stack_a, t_stack_node **stack_b, bool print)
{
    sa(stack_a, false);
    sb(stack_b, false);
    
    if (print)
        write(1, "ss\n", 3);
}