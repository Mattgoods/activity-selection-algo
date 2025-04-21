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

## Performance Analysis & Visualization

This project includes scripts to automate performance measurement and visualize results:

### 1. Collecting Performance Data

A shell script is provided to run the algorithm for various input sizes and record running time and peak memory usage.

**To use:**
```sh
cd src
chmod +x collect_performance.sh
./collect_performance.sh
```
This will generate a `performance_results.csv` file with the results.

### 2. Plotting Results

A Python script is provided to plot running time and memory usage versus input size.

**To use:**
```sh
pip3 install matplotlib pandas numpy
python3 plot_performance.py
```
This will display and save two plots:
- `running_time_vs_input_size.png`
- `peak_memory_vs_input_size.png`

These graphs help you compare empirical performance with theoretical expectations.

## File Structure
- `src/activity_selection.cpp` — Main source code file

## License
This project is provided for educational purposes.
