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
2. Partition: all elements of stack A with values less than the pivot are pushed to stack B, all elements of stack B with values greater than the pivot are pushed to stack A.
3. Stack A is sorted recursively.
4. Stack B is sorted recursively.

The base case of the recursion is a stack with size 3 or less. These stacks are sorted with another function.<br>
The resulting list of operations is then optimized – redundant sets of operations are removed.<br>

## **Base case – stacks with size 3 or less**
<br>

### **Stack A**

For stacks with size 1, we do nothing.<br>
For stacks with size 2, we swap elements if the first element is greater than the second.<br>
For stacks with size 3 or more, there are six possible cases of how the first three numbers are arranged in a stack:<br>

1. 1 2 3 – do nothing.
2. 1 3 2 – if stack A contains exactly 3 elements, we rotate it (it becomes 3 2 1), swap the first two elements again (it becomes 2 3 1), and then reverse rotate it (it becomes 1 2 3), else we do nothing.
3. 2 1 3 – if stack A contains exactly 3 elements, we swap the first two elements at the top of it, else we do nothing.
4. 2 3 1 – if stack A contains exactly 3 elements, we reverse rotate it, else we rotate it (it becomes 3 1 ... 2), swap the first two elements at the top of it (it becomes 1 3 ... 2), reverse rotate it (it becomes 2 1 3 ... ) and then swap the first two elements again (it becomes 1 2 3 ... ).
5. 3 1 2 – if stack A contains exactly 3 elements, we rotate it, else we swap the first two elements at the top of it (it becomes 1 3 2 ... ), rotate it (it becomes 3 2 ... 1), swap the first two elements again (it becomes 2 3 ... 1) and then reverse rotate it (it becomes 1 2 3 ... ).
6. 3 2 1 – if stack A contains exactly 3 elements, we swap the first two elements at the top of it (it becomes 2 3 1) and then reverse rotate it (it becomes 1 2 3), else we swap the first two elements at the top of it (it becomes 2 3 1 ...), rotate it (it becomes 3 1 ... 2), swap the first two elements again (it becomes 1 3 ... 2), reverse rotate it (it becomes 2 1 3 ... ) and then swap the first two elements again (it becomes 1 2 3 ... ).

### **Stack B**

For stacks with size 1, we push the only element to stack A.<br>
For stacks with size 2, we swap elements if the first element is lesser than the second and then push both elements to stack A.<br>
For stacks with size 3, there are six possible cases of how the first three numbers are arranged in a stack:<br>

1. 1 2 3 – if stack B contains exactly 3 elements, we swap the first two elements at the top of it (it becomes 2 1 3), reverse rotate it (it becomes 3 2 1) and then push all elements to stack A, else we rotate it (it becomes 2 3 ... 1), swap the first two elements at the top of it (it becomes 3 2 ... 1), push the first two elements at the top of it to stack A, reverse rotate it (it becomes 1 ... ) and then push the first element at the top of is to stack A.
2. 1 3 2 – 
3. 2 1 3 –
4. 2 3 1 –
5. 3 1 2 –
6. 3 2 1 – if stack B contains exactly 3 elements, we push them all to stack A, else we do nothing.

## **Optimization**

<br>
Source of `test.sh` – https://github.com/ksnow-be/push_swap_checker
