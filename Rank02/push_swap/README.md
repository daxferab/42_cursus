# 🔄 Push Swap - 42 School Project

Welcome to **Push Swap**! 🎉 This is one of the most challenging projects from **Rank 2** at 42 School. The goal is to sort a stack of integers using only two stacks and a limited set of operations, with the fewest possible moves. This project teaches algorithm optimization, data structures, and efficiency analysis.

The challenge is to sort integers using only **push**, **swap**, **rotate**, and **reverse rotate** operations! 🚀

---

### 📂 Project Structure

push_swap/
├── include/push_swap.h    # Header file (.h)  
├── src/                   # Source files (.c)  
│   ├── main.c             # Main program logic  
│   ├── parse.c            # Argument parsing & validation  
│   ├── sort.c             # Main sorting logic  
│   ├── sort_to_five.c     # Optimized sorting for ≤5 elements  
│   ├── ksort.c            # K-sort algorithm implementation  
│   ├── lst_utils.c        # Linked list utilities  
│   ├── utils.c            # General utility functions  
│   ├── exceptions.c       # Error handling  
│   └── sortopt/           # Stack operations  
│       ├── swap.c         # Swap operations (sa, sb, ss)  
│       ├── push.c         # Push operations (pa, pb)  
│       ├── rotate.c       # Rotate operations (ra, rb, rr)  
│       └── reverse_rotate.c # Reverse rotate (rra, rrb, rrr)  
├── obj/                   # Object files directory  
├── libft/                 # Libft library  
├── .gitignore  
├── Makefile               # Makefile to compile the project  
└── README.md              # This file  

---

### 📜 Available Operations

#### 🔄 Stack Operations
- **`sa`** - Swap the first 2 elements of stack A
- **`sb`** - Swap the first 2 elements of stack B  
- **`ss`** - `sa` and `sb` at the same time
- **`pa`** - Push top element of stack B to stack A
- **`pb`** - Push top element of stack A to stack B
- **`ra`** - Rotate stack A (first element becomes last)
- **`rb`** - Rotate stack B (first element becomes last)
- **`rr`** - `ra` and `rb` at the same time
- **`rra`** - Reverse rotate stack A (last element becomes first)
- **`rrb`** - Reverse rotate stack B (last element becomes first)
- **`rrr`** - `rra` and `rrb` at the same time

---

### 🧠 Algorithm Strategy

#### 🎯 Adaptive Sorting Approach
The program uses different algorithms based on the number of elements:

1. **≤ 3 elements**: Hardcoded optimal solutions
2. **4-5 elements**: Optimized brute-force approach  
3. **> 5 elements**: K-sort algorithm (modified radix sort)

#### 🔧 Core Functions

##### **Parsing & Validation**
- **`parse(int argc, char **argv, t_num **stack_a)`**: Parses arguments and builds stack A
- **`addtolist(t_num **stack_a, char *num)`**: Adds valid numbers to the stack
- **`index_list(t_num **stack_a)`**: Assigns indices for sorting optimization

##### **Sorting Logic**
- **`sort(t_num **stack_a, t_num **stack_b)`**: Main sorting dispatcher
- **`sort_two(t_num **stack_a)`**: Optimized 2-element sort
- **`sort_three(t_num **stack_a)`**: Optimized 3-element sort  
- **`sort_five(t_num **stack_a, t_num **stack_b)`**: Optimized ≤5 element sort
- **`ksort_first()` & `ksort_second()`**: K-sort algorithm implementation

##### **Stack Operations**
- **`swap(t_num **stack, char *movement)`**: Swap top two elements
- **`push(t_num **stack_1, t_num **stack_2, char *movement)`**: Move element between stacks
- **`rotate(t_num **stack, char *movement)`**: Rotate stack upward
- **`rev_rotate(t_num **stack, char *movement)`**: Rotate stack downward

##### **Utility Functions**
- **`sorted(t_num *stack_a)`**: Check if stack is sorted
- **`lstsize(t_num *lst)`**: Get stack size
- **`repeated(t_num *stack_a)`**: Check for duplicate values

---

## 🛠️ How to Use

### 📦 Compilation

To compile the program, run:

```bash
make
```

This will generate the `push_swap` executable.

### 🧩 Usage

The program takes integers as arguments:

```bash
./push_swap [numbers...]
```

### 💡 Usage Examples

#### Basic Examples
```bash
# Sort 3 numbers
./push_swap 3 1 2
# Output: sa

# Sort 5 numbers  
./push_swap 5 4 3 2 1
# Output: pb pb ra pb ra sa pa pa pa

# Sort random numbers
./push_swap 42 21 7 84 15 33
```

#### Advanced Testing
```bash
# Test with 100 random numbers
ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' '); ./push_swap $ARG

# Count operations
./push_swap 4 67 3 87 23 | wc -l

# Test with duplicates (should show "Error")
./push_swap 1 2 3 2

# Test with invalid input
./push_swap 1 2 abc 4
```

---

## 🎯 Performance Goals

### 📊 Operation Count Targets

- **3 elements**: ≤ 3 operations
- **5 elements**: ≤ 12 operations  
- **100 elements**: ≤ 700 operations (5 points), ≤ 900 (4 points), ≤ 1100 (3 points)
- **500 elements**: ≤ 5500 operations (5 points), ≤ 7000 (4 points), ≤ 8500 (3 points)

### 🏆 Optimization Techniques

1. **Indexing**: Convert values to indices for faster comparison
2. **K-sort**: Divide and conquer approach for large datasets
3. **Hardcoded small cases**: Optimal solutions for ≤5 elements
4. **Move cost analysis**: Choose operations that minimize total moves

---

## ✅ Project Requirements

- ✅ Sort integers using only the allowed operations
- ✅ Handle any number of integers (within reason)
- ✅ Minimize the number of operations
- ✅ Handle edge cases (duplicates, invalid input, empty input)
- ✅ No memory leaks
- ✅ Error handling with "Error" message
- ✅ Operations printed to stdout, one per line

---

## 🔧 Algorithm Deep Dive

### K-Sort Algorithm
The K-sort algorithm divides the numbers into chunks and processes them:

1. **Phase 1**: Push elements to stack B in chunks based on index ranges
2. **Phase 2**: Push elements back to stack A in sorted order
3. **Optimization**: Use rotation to minimize operations

### Small Number Optimization
- **2 numbers**: 1 operation maximum (`sa`)
- **3 numbers**: Hardcoded decision tree (≤3 operations)
- **4-5 numbers**: Optimized approach using both stacks

---

## 🚨 Error Handling

The program handles various error conditions:

- **Invalid arguments**: Non-numeric values, overflows
- **Duplicates**: Same number appears twice
- **Empty input**: No arguments provided
- **Out of range**: Numbers outside INT_MIN to INT_MAX

All errors result in "Error" printed to stderr and program exit.

---

## 🧪 Testing & Validation

### Manual Testing
```bash
# Test sorting correctness
./push_swap 3 1 4 1 5 | ./checker 3 1 4 1 5

# Test operation count
./push_swap $(shuf -i 1-100 -n 100) | wc -l
```

### Automated Testing
```bash
# Generate and test multiple cases
for i in {1..100}; do
    ARG=$(shuf -i 1-500 -n 100 | tr '\n' ' ')
    MOVES=$(./push_swap $ARG | wc -l)
    echo "Test $i: $MOVES moves"
done
```

---

## 💡 Key Learning Objectives

- **Algorithm Design**: Creating efficient sorting algorithms with constraints
- **Data Structures**: Mastering linked lists and stack operations
- **Optimization**: Minimizing operations through smart algorithm choice
- **Complexity Analysis**: Understanding time and space complexity
- **Edge Case Handling**: Robust input validation and error management
- **Performance Tuning**: Achieving target operation counts

---

## 🚀 Advanced Features

### Bonus: Checker Program
The project can include a checker program that validates the sorting operations:

```bash
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
# Output: OK or KO
```

### Visualization
Consider creating a visualizer to see the sorting process in action!

---

## 🔍 Debugging Tips

1. **Print stack states**: Add debug prints to see stack contents
2. **Count operations**: Track operation count during development
3. **Test edge cases**: Empty input, single element, already sorted
4. **Memory check**: Use valgrind to detect memory leaks
5. **Performance profiling**: Measure operation counts for different sizes

---

*Made with ❤️ at 42 Madrid*