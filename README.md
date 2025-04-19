# Activity Selection Problem - Greedy Algorithm (C++)

## Overview
This project provides a modular and well-documented C++ implementation of the greedy algorithm to solve the Activity Selection Problem. The program reads a list of activities (with start and finish times) from user input and outputs the maximum set of non-overlapping activities.

## How to Build and Run

### Prerequisites
- A C++ compiler (e.g., `g++`)
- Any operating system (Windows, macOS, Linux)

### Steps
1. **Open a Terminal or Command Prompt** and navigate to the project directory.
2. **Compile the code**:
   ```sh
   g++ -std=c++11 -O2 -o activity_selection activity_selection.cpp
   ```
3. **Run the program**:
   ```sh
   ./activity_selection
   ```
   - On Windows, use `activity_selection.exe` instead of `./activity_selection`.

## Usage
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

## Performance Evaluation
- You can test the program with varying input sizes to evaluate performance.
- For large input sets, you may redirect input from a file:
  ```sh
  ./activity_selection < input.txt
  ```
  - On Windows, use `activity_selection.exe < input.txt`.

## File Structure
- `src/activity_selection.cpp` — Main source code file

## License
This project is provided for educational purposes.
