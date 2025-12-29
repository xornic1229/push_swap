/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 21:20:13 by jaialons          #+#    #+#             */
/*   Updated: 2025/12/26 21:20:28 by jaialons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void index_stack(t_stack *stack)
{
    int *arr;
    arr = malloc(sizeof(int) * stack->size);
    t_node *current;
    current = stack->head;
    int i;
    i = 0;
    while(current)
    {
        arr[i++] = current->elem;
        current = current->next;
    }
    bubble_sort(arr, stack->size);
    current = stack->head;
    while(current)
    {
        current->index = index_search(arr, stack->size, current->elem);
        current = current->next;
    }
    free(arr);
}

int *bubble_sort(int *arr, int n)
{
    int i = 0;
    int temp;
    while (i < n - 1)
    {
        int j = 0;
        while (j < n - i - 1)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
    return arr;
}

int index_search(int *arr, int n, int elem)
{
    int i;
    i = 0;
    while (i < n)
    {
        if (arr[i] == elem)
            return i;
        i++;
    }
    return -1;
}
