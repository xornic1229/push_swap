def push(stack_from, stack_to):
    if stack_from:
        stack_to.insert(0, stack_from.pop(0))

def rotate(stack):
    if stack:
        first = stack.pop(0)
        stack.append(first)

def reverse_rotate(stack):
    if stack:
        last = stack.pop()
        stack.insert(0, last)

def is_sorted(stack):
    return all(stack[i] <= stack[i+1] for i in range(len(stack)-1))

# Pila inicial A (top = índice 0)
stack_a = [23, 45, 1657, 33242321345, 4253, 235436, 2345, 2536, 254, 253567, 6332]
stack_b = []

# Lista de instrucciones
instructions = [
    "pb", "ra", "ra", "ra", "pb", "pb", "pb", "ra", "pb", "ra", "ra", "pa", "pa", "pa", "pa", "pa",
    "ra", "pb", "ra", "ra", "pb", "pb", "ra", "ra", "pb", "pb", "ra", "pa", "pa", "pa", "pa", "pa",
    "pb", "ra", "ra", "pb", "ra", "ra", "ra", "pb", "pb", "ra", "ra", "pa", "pa", "pa", "pa",
    "ra", "ra", "ra", "ra", "ra", "ra", "pb", "ra", "pb", "ra", "pb", "pa", "pa", "pa"
]

for instr in instructions:
    if instr == "pa":
        push(stack_b, stack_a)
    elif instr == "pb":
        push(stack_a, stack_b)
    elif instr == "ra":
        rotate(stack_a)
    elif instr == "rb":
        rotate(stack_b)
    elif instr == "rra":
        reverse_rotate(stack_a)
    elif instr == "rrb":
        reverse_rotate(stack_b)
    else:
        print(f"Instrucción desconocida: {instr}")

print("Pila A final:", stack_a)
print("Pila B final:", stack_b)
print("¿Está ordenada la pila A?", is_sorted(stack_a))
