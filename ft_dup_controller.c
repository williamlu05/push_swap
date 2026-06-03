
#include "push_swap.h"

int dup_controller(t_list *stack)
{
    t_list  *current;
    t_list  *checker;

    current = stack;
    while (current->next != stack)
    {
        checker = current->next;
        while (checker != stack)
        {
            if (checker->num == current->num)
            {
                printf("\nNumero repetido\n");
                return (1);
            }
            checker = checker->next;
        }
        current = current->next;
    }
    return (0);
}