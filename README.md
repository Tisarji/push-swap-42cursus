# Push_Swap

## Introduction
The Push_Swap project is a highly efficient sorting algorithm developed to sort data using two stacks. It employs a variety of techniques optimized for different data set sizes, including a special case handling for fully descending orders.

## Features
- Handles a variety of data set sizes with different sorting algorithms.
- Special optimization for fully descending order datasets.
- Stack operations include push, swap, rotate, and reverse rotate.

## Algorithms
- `algorithm_small`: Optimized for small datasets.
- `algorithm_medium`: Used for medium-sized datasets.
- `algorithm_large`: Handles larger datasets with an optimized approach.
- `butterfly_split`: For very large datasets, employing a comprehensive sorting strategy.
- `sort_descending`: Special case optimization for fully descending datasets.

## Conceptual Diagram for push_swap

![DALL·E 2024-01-22 00 51 14 - Create a conceptual diagram for a software project named 'push_swap'  The diagram should include the following elements___1  Main Function (Central No](https://github.com/Tisarji/Push-Swap/assets/48820052/c04306a5-7c2a-4cdb-9844-fd3cc5be39bb)

## Main Function (Central Node)
- **Label**: `main`
- **Description**: The entry point of the program. It handles initial argument parsing and directs the flow of the program.
- **Connected to**: `ft_check_arg`, `sort_stack`, `freeall`

## Argument Parsing
- **Label**: `ft_check_arg`
- **Description**: Parses command-line arguments and initializes stack `a`.
- **Connected to**: `main`

## Sorting Decision Logic
- **Label**: `sort_stack`
- **Description**: Decides which sorting algorithm to use based on the size and order of the dataset.
- **Connected to**: `main`, `algorithm_small`, `algorithm_medium`, `algorithm_large`, `butterfly_split`, `sort_descending`

## Sorting Algorithms
- **Labels**: `algorithm_small`, `algorithm_medium`, `algorithm_large`, `butterfly_split`
- **Description**: Implements specific sorting logic.
- **Connected to/from**: `sort_stack`

## Special Case Sorting
- **Label**: `sort_descending`
- **Description**: Handles the special case of a fully descending dataset.
- **Connected to/from**: `sort_stack`

## Utility Functions
- **Labels**: `ft_push`, `ft_rotate`, `ft_swap`, `utils`
- **Description**: Perform basic stack operations and checks.
- **Connected to**: Sorting algorithm nodes where they are used.

## Cleanup
- **Label**: `freeall`
- **Description**: Frees allocated memory.
- **Connected to**: `main`

## Diagram Structure
- The diagram should be structured with `main` in the center.
- Arrows should indicate the flow of control or data.
- Each node (function or module) should be clearly labeled.
- Group sorting algorithms and utility functions for clarity.



## Installation
To install and run the Push_Swap project:
1. Clone the repository:
   ```git clone [repository link] ```
2. Compile the program:
   ```make```

## Usage
To use the Push_Swap program:
Example: ```./push_swap 2 1 3 6 5 8```


## Code Structure
- `push_swap.c`: The main entry point of the program.
- Sorting algorithm files (`algorithm_small.c`, `algorithm_medium.c`, etc.).
- Utility functions (`ft_push.c`, `ft_rotate.c`, `ft_swap.c`, etc.).
- Stack manipulation and checking (`utils.c`).

## Contributing
Contributions to the Push_Swap project are welcome. Please ensure to follow the project's code style and contribute meaningful and optimized code.

## License

## Authors
- Tisarji
