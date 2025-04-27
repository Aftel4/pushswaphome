/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:33:40 by marvin            #+#    #+#             */
/*   Updated: 2025/04/25 21:33:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack_node *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

t_stack_node	*find_last(t_stack_node *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

bool	stack_sorted(t_stack_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack_node	*find_min(t_stack_node *stack)
{
	long			smallest;
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	smallest = LONG_MAX;
	min_node = NULL;
	while (stack)
	{
		if (stack->nbr < smallest)
		{
			smallest = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack_node	*find_max(t_stack_node *stack)
{
	long			largest;
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	largest = LONG_MIN;
	max_node = NULL;
	while (stack)
	{
		if (stack->nbr > largest)
		{
			largest = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
