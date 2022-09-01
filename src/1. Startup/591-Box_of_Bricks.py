# Move minimal #of bricks to get even stacks

### INPUT
# first number of stacks
# height of the stacks
# terminated by 0

### OUTPUT
# Set #n
# The minimum number of moves is k.


# construct list
# get how high the stacks should be
# remove any stack smaller, since we don't need to move from them
counter = 1
num_walls = int(input())
while num_walls != 0:
    num_moves = 0
    stack_array = [int(x) for x in input().split(" ")]
    stack_height = int(sum(stack_array) / num_walls)
    stack_array = [stack for stack in stack_array if stack > stack_height]
    for stack in stack_array:
        num_moves += stack - stack_height

    # Print output
    print(f"Set #{counter}")
    print(f"The minimum number of moves is {num_moves}.\n")

    counter += 1
    num_walls = int(input())

### Each is O(n)