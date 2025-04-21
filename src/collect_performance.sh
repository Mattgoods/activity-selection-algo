#!/bin/bash
# Script to run activity_selection for various input sizes and collect timing/memory data

# Path to the compiled C++ program
EXEC=./activity_selection

# Output CSV file
OUTFILE=performance_results.csv

# Input sizes to test
declare -a SIZES=(1000 2000 5000 10000 20000 40000 80000)

# Write CSV header
echo "input_size,running_time_ms,peak_memory_kb" > $OUTFILE

for N in "${SIZES[@]}"; do
    # Run the program and capture output
    OUTPUT=$($EXEC --random $N)
    # Extract relevant lines
    SIZE=$(echo "$OUTPUT" | grep "Input size:" | awk '{print $3}')
    TIME=$(echo "$OUTPUT" | grep "Running time" | awk '{print $4}')
    MEM=$(echo "$OUTPUT" | grep "Peak memory" | awk '{print $5}')
    # Write to CSV
    echo "$SIZE,$TIME,$MEM" >> $OUTFILE
done
