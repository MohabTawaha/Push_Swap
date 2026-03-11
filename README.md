*This activity has been created as part of the 42 curriculum by mal-tawa, abtaha.*

# PUSH_SWAP

## 📌 Description

We are study all of thing togother(on the same set)

**push_swap** is an algorithmic project from the 42 curriculum.  
The goal is to sort a list of integers using **two stacks (A and B)** and a limited set of allowed operations.

The challenge is not only to sort the numbers correctly, but to do so using the **minimum number of operations possible**.

The program receives a list of integers as arguments and outputs the sequence of operations needed to sort them.

---

## 🎯 Objectives

- Sort numbers in stack A in ascending order  
- Use stack B as auxiliary storage  
- Use only the allowed operations  
- Minimize the total number of operations  

---

## 🗂️ Allowed Operations

### Swap
- `sa` → Swap the first two elements of stack A  
- `sb` → Swap the first two elements of stack B  
- `ss` → `sa` and `sb` at the same time  

### Push
- `pa` → Push top element from B to A  
- `pb` → Push top element from A to B  

### Rotate
- `ra` → Shift up all elements of A by 1  
- `rb` → Shift up all elements of B by 1  
- `rr` → `ra` and `rb` at the same time  

### Reverse Rotate
- `rra` → Shift down all elements of A by 1  
- `rrb` → Shift down all elements of B by 1  
- `rrr` → `rra` and `rrb` at the same time  

---

## ⚙️ Instructions

### Compilation
```bash
make

or

make re

This will generate the executable:

push_swap
▶️ Usage
./push_swap 4 67 3 87 23

Example output:

pb
ra
sa
pa

Each line represents one operation applied to the stacks.
🤖 AI Usage

AI tools were used for:

Understanding algorithmic concepts like Radix Sort and Rotation Cost Optimization.

Debugging logical and memory-related issues.

Improving README structure, wording, and formatting

❗ Error Handling

The program prints:

Error

In the following cases:

Duplicate numbers

Non-numeric characters

Integer overflow

Empty input

Invalid formatting

🧪 Testing

Count moves for 100 reversed numbers:

./push_swap 100 99 98 ... 1 | wc -l

Random 500 numbers:

ARG=$(shuf -i 1-500 -n 500 | tr '\n' ' ')
./push_swap $ARG | wc -l
🏆 Performance Targets (42 Evaluation)
Numbers	Max Moves (Grade 5)
3	≤ 3
5	≤ 12
100	< 700
500	< 5500
🧠 Algorithm Explanation & Justification
1. Input Parsing and Indexing

All input numbers are:

Validated (numeric check, overflow check, duplicates)

Converted to integers

Assigned an index based on their sorted order

This allows working with small normalized values instead of large integers.

2. Small Sorting (≤ 5 numbers)

For small inputs, optimized hardcoded strategies are used:

3 numbers:
Direct comparison and minimal operations (sa, ra, rra) to reach sorted order.

5 numbers:
The two smallest values are pushed to stack B,
the remaining three are sorted in stack A,
then the two values are pushed back to A in correct order.

This approach is optimal and minimizes moves for small datasets.

3. Large Sorting (Radix Sort)

For large datasets, a binary radix sort is used based on the assigned indices.

Steps:

For each bit position (from least significant bit to most significant):

Iterate through stack A:

If bit = 0 → push to stack B

If bit = 1 → rotate stack A

Push all elements from stack B back to stack A

Repeat for the next bit

This guarantees:

Time complexity: O(n log n)

Predictable number of operations

Good performance for large inputs (100–500 numbers)

4. Rotation Cost Optimization

To minimize operations:

Each element’s position is evaluated

The cost of rotating stack A and stack B is calculated

The cheapest combination of rotations is chosen

This reduces unnecessary moves and improves overall efficiency.

42  Student
Project: push_swap
Login Name : mal-tawa, abtaha
Main Name : Mohab Tawaha, Abdalrahman Taha

