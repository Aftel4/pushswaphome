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
    while (current->nbr == n)
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
t_stack_node *parse_args(int argc, char **argv)
{
    t_stack_node *stack_a;
    int i;
    long num;

    stack_a = NULL;
    i = 1;  // Commencer à 1 car argv[0] est le nom du programme
    while (i < argc)
    {
        if (!is_valid_number(argv[i]))
        {
            // Gestion d'erreur - message + nettoyer la mémoire
            fprintf(stderr, "Error: Argument invalide '%s'\n", argv[i]);
            // TODO: Ajouter fonction pour libérer la stack existante
            return (NULL);
        }
        num = ft_atol(argv[i]);
        if (num > INT_MAX || num < INT_MIN)
        {
            fprintf(stderr, "Error: Nombre hors limites INT '%s'\n", argv[i]);
            // TODO: Ajouter fonction pour libérer la stack existante
            return (NULL);
        }
        if (has_duplicate(stack_a, (int)num))
        {
            fprintf(stderr, "Error: Doublon détecté '%s'\n", argv[i]);
            // TODO: Ajouter fonction pour libérer la stack existante
            return (NULL);
        }
        t_stack_node *new_node = create_new_node((int)num);
        if (!new_node)
        {
            fprintf(stderr, "Error: Échec d'allocation mémoire\n");
            // TODO: Ajouter fonction pour libérer la stack existante
            return (NULL);
        }
        append_node(&stack_a, new_node);
        
        i++;
    }
    return (stack_a);
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
int main(int argc, char **argv)
{
    t_stack_node *stack_a;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <nombre1> <nombre2> ...\n", argv[0]);
        return (1);
    }

    stack_a = parse_args(argc, argv);
    if (!stack_a)
    {
        // Une erreur s'est produite pendant le parsing
        return (1);
    }

    // À ce stade, stack_a contient tous les nombres correctement parsés
    // Tu peux maintenant continuer avec l'implémentation des commandes et de l'algorithme

    // N'oublie jamais de libérer la mémoire avant de quitter
    free_stack(&stack_a);
    return (0);
}
