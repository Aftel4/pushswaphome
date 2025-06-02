/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:52:32 by marvin            #+#    #+#             */
/*   Updated: 2025/04/16 16:52:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool is_valid_number(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!str[i])
        return (false);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (false);
        i++;
    }
    return (true);
}

static long ft_atol(char *str)
{
    long result;
    int sign;
    int i;

    result = 0;
    sign = 1;
    i = 0;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result * sign);
}
static bool has_duplicate(t_stack_node *stack, int n)
{
    t_stack_node *current;

    current = stack;
    while (current)
    {
        if (current->nbr == n)
            return (true);
        current = current->next 
    }
    return (false);
}
static t_stack_node *create_new_node(int value)
{
    t_stack_node *new_node;

    new_node = malloc(sizeof(t_stack_node));
    if (!new_node)
        return (NULL);
    new_node->nbr = value;
    new_node->index = 0;
    new_node->push_cost = 0;
    new_node->above_median = false;
    new_node->cheapest = false;
    new_node->target_node = NULL;
    new_node->next = NULL;
    new_node->prev = NULL;
    return (new_node);
}
static void append_node(t_stack_node **stack, t_stack_node *new_node)
{
    t_stack_node *current;

    if (!*stack)
    {
        *stack = new_node;
        return;
    }
    current = *stack;
    while (current->next)
        current = current->next;
    current->next = new_node;
    new_node->prev = current;
}
// Vérifie les limites INT et les doublons
static bool check_limits_and_duplicates(t_stack_node *stack_a, char *arg)
{
    long num;

    num = ft_atol(arg);
    if (num > INT_MAX || num < INT_MIN)
    {
        ft_putstr_fd("Error\n", 2);
        return (false);
    }
    if (has_duplicate(stack_a, (int)num))
    {
        ft_putstr_fd("Error\n", 2);
        return (false);
    }
    return (true);
}

// Traite un argument et l'ajoute à la stack si valide
static bool process_arg(t_stack_node **stack_a, char *arg)
{
    t_stack_node *new_node;
    long num;

    if (!is_valid_number(arg))
    {
        ft_putstr_fd("Error\n", 2);
        return (false);
    }
    if (!check_limits_and_duplicates(*stack_a, arg))
        return (false);
    num = ft_atol(arg);
    new_node = create_new_node((int)num);
    if (!new_node)
    {
        ft_putstr_fd("Error\n", 2);
        return (false);
    }
    append_node(stack_a, new_node);
    return (true);
}

// Fonction principale de parsing
bool init_stack_a(t_stack_node **stack_a, int argc, char **argv)
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (!process_arg(stack_a, argv[i]))
        {
            free_stack(stack_a);
            return (false);
        }
        i++;
    }
    return (true);
}
void free_stack(t_stack_node **stack)
{
    t_stack_node *current;
    t_stack_node *temp;

    if (!stack || !*stack)
        return;
    current = *stack;
    while (current)
    {
        temp = current->next;
        free(current);
        current = temp;
    }
    *stack = NULL;
}
