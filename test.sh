#!/bin/bash

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Test counters
TOTAL_TESTS=0
PASSED_TESTS=0

# Function to run a test
run_test() {
    local test_name="$1"
    local input="$2"
    local expected_result="$3"  # "success" or "error"
    
    echo -e "${BLUE}Testing: $test_name${NC}"
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    
    # Run the program and capture output
    output=$(./rush-01 "$input" 2>&1)
    exit_code=$?
    
    if [ "$expected_result" = "success" ]; then
        if [ $exit_code -eq 0 ] && [[ ! "$output" =~ "Error" ]]; then
            echo -e "${GREEN}✓ PASS${NC}"
            echo "$output"
            PASSED_TESTS=$((PASSED_TESTS + 1))
        else
            echo -e "${RED}✗ FAIL${NC} (Expected success but got error)"
            echo "Output: $output"
        fi
    else
        if [ $exit_code -ne 0 ] || [[ "$output" =~ "Error" ]]; then
            echo -e "${GREEN}✓ PASS${NC} (Correctly detected error)"
            PASSED_TESTS=$((PASSED_TESTS + 1))
        else
            echo -e "${RED}✗ FAIL${NC} (Expected error but got success)"
            echo "Output: $output"
        fi
    fi
    echo
}

echo -e "${YELLOW}=== Skyscraper Puzzle Solver - Comprehensive Test Suite ===${NC}"
echo

# Test valid grids for each size
echo -e "${BLUE}=== VALID GRID TESTS ===${NC}"

# 4x4 Grid Test
run_test "4x4 Grid" "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" "success"

# 5x5 Grid Test
run_test "5x5 Grid" "5 4 3 2 1 1 2 2 2 2 5 4 3 2 1 1 2 2 2 2" "success"

# 6x6 Grid Test
run_test "6x6 Grid" "6 5 4 3 2 1 1 2 2 2 2 2 6 5 4 3 2 1 1 2 2 2 2 2" "success"

# 7x7 Grid Test (identity Latin square pattern)
run_test "7x7 Grid" "7 6 5 4 3 2 1 1 2 2 2 2 2 2 7 6 5 4 3 2 1 1 2 2 2 2 2 2" "success"

# 8x8 Grid Test (identity Latin square pattern)
run_test "8x8 Grid" "8 7 6 5 4 3 2 1 1 2 2 2 2 2 2 2 8 7 6 5 4 3 2 1 1 2 2 2 2 2 2 2" "success"

# 9x9 Grid Test (identity Latin square pattern)
run_test "9x9 Grid" "9 8 7 6 5 4 3 2 1 1 2 2 2 2 2 2 2 2 9 8 7 6 5 4 3 2 1 1 2 2 2 2 2 2 2 2" "success"

echo -e "${BLUE}=== ERROR HANDLING TESTS ===${NC}"

# Test wrong number of arguments
echo -e "${BLUE}Testing: No arguments${NC}"
TOTAL_TESTS=$((TOTAL_TESTS + 1))
output=$(./rush-01 2>&1)
if [[ "$output" =~ "Error" ]]; then
    echo -e "${GREEN}✓ PASS${NC} (Correctly detected missing argument)"
    PASSED_TESTS=$((PASSED_TESTS + 1))
else
    echo -e "${RED}✗ FAIL${NC}"
fi
echo

echo -e "${BLUE}Testing: Too many arguments${NC}"
TOTAL_TESTS=$((TOTAL_TESTS + 1))
output=$(./rush-01 "1 2 3 4" "extra" 2>&1)
if [[ "$output" =~ "Error" ]]; then
    echo -e "${GREEN}✓ PASS${NC} (Correctly detected too many arguments)"
    PASSED_TESTS=$((PASSED_TESTS + 1))
else
    echo -e "${RED}✗ FAIL${NC}"
fi
echo

# Test invalid input formats
run_test "Invalid characters in input" "a b c d e f g h i j k l m n o p" "error"

run_test "Mixed valid/invalid characters" "1 2 a 4 1 2 2 2 4 3 2 1 1 2 2 2" "error"

run_test "Numbers with spaces only (no numbers)" "     " "error"

# Test wrong number of constraints
run_test "Too few constraints (3x3 attempt)" "1 2 3 4 5 6 7 8 9 10 11 12" "error"

run_test "Too many constraints for any valid grid" "1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 1 2 3 4 5" "error"

run_test "Wrong count for 4x4 (15 instead of 16)" "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2" "error"

run_test "Wrong count for 4x4 (17 instead of 16)" "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2 1" "error"

# Test invalid constraint values for grid sizes
run_test "4x4 with constraint value 5 (too high)" "5 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" "error"

run_test "4x4 with constraint value 0 (too low)" "0 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" "error"

run_test "5x5 with constraint value 6 (too high)" "6 4 3 2 1 1 2 2 2 2 5 4 3 2 1 1 2 2 2 2" "error"

run_test "9x9 with constraint value 10 (too high)" "10 8 7 6 5 4 3 2 1 1 2 2 2 2 2 2 2 2 9 8 7 6 5 4 3 2 1 1 2 2 2 2 2 2 2 2" "error"

# Test impossible constraints
run_test "Impossible 4x4 (all constraints = 1)" "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1" "error"

run_test "Impossible 5x5 (all constraints = 1)" "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1" "error"

run_test "Impossible 4x4 (all constraints = 4)" "4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4" "error"

# Edge case tests
run_test "Single number input" "5" "error"

run_test "Empty string" "" "error"

# Summary
echo -e "${YELLOW}=== TEST SUMMARY ===${NC}"
echo -e "Total tests: $TOTAL_TESTS"
echo -e "Passed: ${GREEN}$PASSED_TESTS${NC}"
echo -e "Failed: ${RED}$((TOTAL_TESTS - PASSED_TESTS))${NC}"

if [ $PASSED_TESTS -eq $TOTAL_TESTS ]; then
    echo -e "${GREEN}🎉 ALL TESTS PASSED! 🎉${NC}"
    exit 0
else
    echo -e "${RED}❌ SOME TESTS FAILED ❌${NC}"
    exit 1
fi
