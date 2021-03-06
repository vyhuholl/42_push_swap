Another School 21 project. **checker** – a program to check whether a given sequence of numbers (stored in stack A) is sorted in ascending order after executing a given list of operations. **push_swap** – a program to find the smallest list of operations to sort a given sequence of numbers (stored in stack A) in ascending order. Avaliable operations are:<br>

* **sa**, **sb**, **ss** – swap the first 2 elements at the top of stack A, stack B, or both;
* **pa**, **pb** – push the top element of stack A to stock B or vice versa;
* **ra**, **rb**, **rr** – rotate stack A, stack B or both by 1;
* **rra**, **rrb**, **rrr** – reverse rotate stack A, stack B or both by 1;

For more detailed explanation please read `push_swap.en.pdf`.<br><br>

# **Sorting algorithm**

## **Quicksort**
<br>
I implemented a quicksort algorithm:<br><br>

1. Pivot element is selected.
2. Partition: all elements of stack A with values less than the pivot are pushed to stack B, all elements of stack B with values greater than the pivot are pushed to stack A (via push and rotate operations).
3. Stack A is sorted recursively.
4. Stack B is sorted recursively.

The base case of the recursion is a stack with size 3 or less. These stacks are sorted with another function.<br>
The resulting list of operations is then optimized – redundant sets of operations are removed or combined to a single operation.<br>

## **Base case – stacks with size 3 or less**
<br>

### **Stack A**

For stacks with size 1, we do nothing.<br>
For stacks with size 2, we swap elements if the first element is greater than the second.<br>
For stacks with size 3 or more, there are six possible cases of how the first three numbers are arranged in a stack:<br>

1. 1 2 3 – do nothing.
2. 1 3 2 – reverse rotate stack A (it becomes 2 1 3) and then swap the first two elements at the top of it (it becomes 1 2 3).
3. 2 1 3 – swap the first two elements at the top of stack A (it becomes 1 2 3).
4. 2 3 1 – reverse rotate stack A (it becomes 1 2 3).
5. 3 1 2 – rotate stack A (it becomes 1 2 3).
6. 3 2 1 – swap the first two elements at the top of stack A (it becomes 2 3 1) and then reverse rotate it (it becomes 1 2 3).

### **Stack B**

For stacks with size 1, we do nothing.<br>
For stacks with size 2, we swap elements if the first element is lesser than the second.<br>
For stacks with size 3, there are six possible cases of how the first three numbers are arranged in a stack:<br>

1. 1 2 3 – swap the first two elements at the top of stack B (it becomes 2 1 3), and then reverse rotate it (it becomes 3 2 1).
2. 1 3 2 – rotate stack B (it becomes 3 2 1).
3. 2 1 3 – reverse rotate stack B (it becomes 3 2 1).
4. 2 3 1 – swap the first two elements at the top of stack B (it becomes 3 2 1).
5. 3 1 2 – reverse rotate stack B (it becomes 2 3 1), and then swap the first two elements at the top of it (it becomes 3 2 1).
6. 3 2 1 – do nothing.

## **Optimization**

These sets of operations are removed:

1. **sa** + **sa** (or **sb** + **sb**)
2. **ra** + **rra** (or **rb** + **rrb**)
3. **rra** + **ra** (or **rrb** + **rb**)
4. **pa** + **pb** (or **pb** + **pa**)

These sets of operations are combined to a single operation:

1. **sa** + **sb** = **ss**
2. **ra** + **rb** = **rr**
3. **rra** + **rrb** = **rrr**

<br>
Source of `test.sh` – https://github.com/ksnow-be/push_swap_checker
