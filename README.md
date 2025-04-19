# Activity Selection Problem - Greedy Algorithm (C++)

## Overview
This project provides a modular and well-documented C++ implementation of the greedy algorithm to solve the Activity Selection Problem. The program can read a list of activities (with start and finish times) from user input or generate random activities for experimental analysis. It outputs the maximum set of non-overlapping activities and reports running time and peak memory usage.

## How to Build and Run

### Prerequisites
- A C++ compiler (e.g., `g++`)
- Any operating system (Windows, macOS, Linux)

### Steps
1. **Open a Terminal** and navigate to the project directory.
2. **Compile the code**:
   ```sh
   g++ -std=c++11 -O2 -o activity_selection src/activity_selection.cpp
   ```
3. **Run the program**:
   - For manual input:
     ```sh
     ./activity_selection
     ```
   - For experimental analysis with random input of size N (e.g., 1000):
     ```sh
     ./activity_selection --random 1000
     ```

## Usage

### Manual Input
1. When prompted, enter the number of activities.
2. For each activity, enter the start and finish times separated by a space.
   - Example input for 3 activities:
     ```
     3
     1 4
     3 5
     0 6
     ```
3. The program will output the selected (non-overlapping) activities.

### Experimental Analysis
- Use the `--random N` option to generate N random activities.
- The program will output:
  - The selected activities
  - Input size
  - Running time (milliseconds)
  - Peak memory usage (KB)

## Performance Evaluation
- Run the program with increasing values of N to observe how running time and memory usage scale.
- Example:
  ```sh
  ./activity_selection --random 10000
  ```

## File Structure
- `src/activity_selection.cpp` — Main source code file

## License
This project is provided for educational purposes.
