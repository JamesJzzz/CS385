#!/bin/bash

file=inversioncounter.cpp
MAXTIME="8.000"

if [ ! -f "$file" ]; then
    echo -e "Error: File '$file' not found.\nTest failed."
    exit 1
fi

num_right=0
total=0
line="________________________________________________________________________"
compiler=
interpreter=
language=
extension=${file##*.}
if [ "$extension" = "py" ]; then
    if [ ! -z "$PYTHON_PATH" ]; then
        interpreter=$(which python.exe)
    else
        interpreter=$(which python3.2)
    fi
    command="$interpreter $file"
    echo -e "Testing $file\n"
elif [ "$extension" = "java" ]; then
    language="java"
    command="java ${file%.java}"
    echo -n "Compiling $file..."
    javac $file
    echo -e "done\n"
elif [ "$extension" = "c" ] || [ "$extension" = "cpp" ]; then
    language="c"
    command="./${file%.*}"
    echo -n "Compiling $file..."
    results=$(make 2>&1)
    if [ $? -ne 0 ]; then
        echo -e "\n$results"
        exit 1
    fi
    echo -e "done\n"
fi

run_test_args() {
    (( ++total ))
    echo -n "Running test $total..."
    expected=$3
    local ismac=0
    date --version >/dev/null 2>&1
    if [ $? -ne 0 ]; then
       ismac=1
    fi
    local start=0
    if (( ismac )); then
        start=$(python -c 'import time; print time.time()')
    else
        start=$(date +%s.%N)
    fi
    received=$(echo -e $2 | $command $1 2>&1 | tr -d '\r')
    local end=$(date +%s.%N)
    if (( ismac )); then
        end=$(python -c 'import time; print time.time()')
    else
        end=$(date +%s.%N)
    fi
    local elapsed=$(echo "scale=3; $end - $start" | bc | awk '{printf "%.3f", $0}') 
    if [ "$expected" != "$received" ]; then
        echo -e "failure\n\nExpected$line\n$expected\n"
        echo -e "Received$line\n$received\n"
    else
        result=$(echo $elapsed $MAXTIME | awk '{if ($1 > $2) print 1; else print 0}')
        if [ "$result" -eq 1 ]; then
            echo -e "failure\nTest timed out at $elapsed seconds. Maximum time allowed is $MAXTIME seconds.\n"
        else
            echo "success [$elapsed seconds]"
            (( ++num_right ))
        fi
    fi
}

# TODO - Make sure your code can handle these cases.
run_test_args "" "x 1 2 3" "Enter sequence of integers, each followed by a space: Error: Non-integer value 'x' received at index 0."
run_test_args "" "1 2 x 3" "Enter sequence of integers, each followed by a space: Error: Non-integer value 'x' received at index 2."
run_test_args "lots of args" "" "Usage: ./inversioncounter [slow]"
run_test_args "average" "" "Error: Unrecognized option 'average'."
run_test_args "" "" "Enter sequence of integers, each followed by a space: Error: Sequence of integers not received."
run_test_args "" "  " "Enter sequence of integers, each followed by a space: Error: Sequence of integers not received."

# TODO - write some tests that use the 'slow' approach. Here is one example.
# You are allowed up to 8 seconds to count inversions on up to 100,000 values.
run_test_args "slow" "2 1" "Enter sequence of integers, each followed by a space: Number of inversions: 1"
run_test_args "slow" "2 5 6 1 7 9" "Enter sequence of integers, each followed by a space: Number of inversions: 3"
run_test_args "slow" "5 3 4 2 1" "Enter sequence of integers, each followed by a space: Number of inversions: 9"
run_test_args "slow" "9 4 3 1 6 7" "Enter sequence of integers, each followed by a space: Number of inversions: 8"
run_test_args "slow" "2 5 6 1 9 7" "Enter sequence of integers, each followed by a space: Number of inversions: 4"
run_test_args "slow" "9 1 3 4 6" "Enter sequence of integers, each followed by a space: Number of inversions: 4"
run_test_args "slow" "1 2 3 4 5 6 7 8 9" "Enter sequence of integers, each followed by a space: Number of inversions: 0"
run_test_args "slow" "1 2 4 8 16 32" "Enter sequence of integers, each followed by a space: Number of inversions: 0"
run_test_args "slow" "5 4 3 2 1" "Enter sequence of integers, each followed by a space: Number of inversions: 10"
run_test_args "slow" "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25" "Enter sequence of integers, each followed by a space: Number of inversions: 0"
run_test_args "slow" "10 9 8 7 6 5 4 3 2 1" "Enter sequence of integers, each followed by a space: Number of inversions: 45"
run_test_args "slow" "1 1 1 1" "Enter sequence of integers, each followed by a space: Number of inversions: 0"
run_test_args "slow" "1 0 1 2" "Enter sequence of integers, each followed by a space: Number of inversions: 1"
run_test_args "slow" "1 0 0" "Enter sequence of integers, each followed by a space: Number of inversions: 2"
run_test_args "slow" "1 1 0 0" "Enter sequence of integers, each followed by a space: Number of inversions: 4"
run_test_args "slow" "3 1 0 1 2 9" "Enter sequence of integers, each followed by a space: Number of inversions: 5"
run_test_args "slow" "1" "Enter sequence of integers, each followed by a space: Number of inversions: 0"
# END slow tests

MAXTIME="1.250"

# TODO - write some tests that use the 'fast' approach. Here is one example.
# You are allowed up to 1.25 seconds to count inversions on up to 100,000 values.
run_test_args "" "2 1" "Enter sequence of integers, each followed by a space: Number of inversions: 1"
run_test_args "" "2 5 6 1 7 9" "Enter sequence of integers, each followed by a space: Number of inversions: 3"
run_test_args "" "5 3 4 2 1" "Enter sequence of integers, each followed by a space: Number of inversions: 9"
run_test_args "" "9 4 3 1 6 7" "Enter sequence of integers, each followed by a space: Number of inversions: 8"
run_test_args "" "2 5 6 1 9 7" "Enter sequence of integers, each followed by a space: Number of inversions: 4"
run_test_args "" "9 1 3 4 6" "Enter sequence of integers, each followed by a space: Number of inversions: 4"
run_test_args "" "1 2 3 4 5 6 7 8 9" "Enter sequence of integers, each followed by a space: Number of inversions: 0"
run_test_args "" "1 2 4 8 16 32" "Enter sequence of integers, each followed by a space: Number of inversions: 0"
run_test_args "" "5 4 3 2 1" "Enter sequence of integers, each followed by a space: Number of inversions: 10"
run_test_args "" "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25" "Enter sequence of integers, each followed by a space: Number of inversions: 0"
run_test_args "" "10 9 8 7 6 5 4 3 2 1" "Enter sequence of integers, each followed by a space: Number of inversions: 45"
run_test_args "" "1 1 1 1" "Enter sequence of integers, each followed by a space: Number of inversions: 0"
run_test_args "" "1 0 1 2" "Enter sequence of integers, each followed by a space: Number of inversions: 1"
run_test_args "" "1 0 0" "Enter sequence of integers, each followed by a space: Number of inversions: 2"
run_test_args "" "1 1 0 0" "Enter sequence of integers, each followed by a space: Number of inversions: 4"
run_test_args "" "3 1 0 1 2 9" "Enter sequence of integers, each followed by a space: Number of inversions: 5"
run_test_args "" "1" "Enter sequence of integers, each followed by a space: Number of inversions: 0"
# END fast tests

echo -e "\nTotal tests run: $total"
echo -e "Number correct : $num_right"
echo -n "Percent correct: "
echo "scale=2; 100 * $num_right / $total" | bc

if [ "$language" = "java" ]; then
    echo -e -n "\nRemoving class files..."
    rm -f *.class
    echo "done"
elif [ "$language" = "c" ]; then
    echo -e -n "\nCleaning project..."
    make clean > /dev/null 2>&1
    echo "done"
fi
