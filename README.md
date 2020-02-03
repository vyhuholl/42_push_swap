Another School 21 project. **checker** – a program to check whether a given sequence of numbers (stored in stack A) is sorted in ascending order after executing a given list of operations. **push_swap** – a program to find the smallest list of operations to sort a given sequence of numbers (stored in stack A) in ascending order. Avaliable operations are:<br>

* **sa**, **sb**, **ss** – swap the first 2 elements at the top of stack A, stack B, or both;
* **pa**, **pb** – push the top element of stack A to stock B or vice versa;
* **ra**, **rb**, **rr** – rotate stack A, stack B or both by 1;
* **rra**, **rrb**, **rrr** – reverse rotate stack A, stack B or both by 1;

For more detailed explanation please read `push_swap.en.pdf`.<br>
# **Sorting algorithm**
## **Quicksort**
<br>
I implemented a quicksort algorithm:<br><br>

1. Pivot element is selected.
2. Partition: all elements of stack A with values less than the pivot are pushed to stack B, all elements of stack B with values greater than the pivot are pushed to stack A.
3. Stack A is sorted recursively.
4. Stack B is sorted recursively.

The base case of the recursion is a stack with size 3 or less. These stacks are sorted with another function.<br>
The resulting list of operations is then optimized – redundant sets of operations are removed.<br>
## **Base case – stacks with size 3 or less**
There are six possible cases of how three numbers are arranged in a stack:

1. 1 2 3 – do nothing.
2. 1 3 2 –
3. 2 1 3 –
4. 2 3 1 –
5. 3 1 2 –
6. 3 2 1 –

<br>

## **Optimization**
<br>
Source of `test.sh` – https://github.com/ksnow-be/push_swap_checker
