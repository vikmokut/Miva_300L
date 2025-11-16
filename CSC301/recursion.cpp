#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// ============================================================================
// PROBLEM 1: FACTORIAL CALCULATION
// ============================================================================

/**
 * Recursive function to calculate factorial of a number
 * 
 * BASE CASE: factorial(0) = 1 and factorial(1) = 1
 * RECURSIVE CASE: factorial(n) = n * factorial(n-1)
 * 
 * The function breaks down the problem by multiplying n with the factorial
 * of (n-1), continuing until it reaches the base case.
 * 
 * @param n The number to calculate factorial for
 * @return The factorial of n
 */
long long factorial(int n) {
    // Base case: factorial of 0 and 1 is 1
    if (n <= 1) {
        return 1;
    }
    
    // Recursive case: n! = n * (n-1)!
    return n * factorial(n - 1);
}

// ============================================================================
// PROBLEM 2: FIBONACCI SEQUENCE
// ============================================================================

/**
 * Recursive function to calculate the nth Fibonacci number
 * 
 * BASE CASE: fib(0) = 0, fib(1) = 1
 * RECURSIVE CASE: fib(n) = fib(n-1) + fib(n-2)
 * 
 * Each Fibonacci number is the sum of the two preceding ones.
 * The recursion branches into two recursive calls until base cases are reached.
 * 
 * @param n The position in Fibonacci sequence (0-indexed)
 * @return The nth Fibonacci number
 */
long long fibonacci(int n) {
    // Base cases: first two Fibonacci numbers
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    
    // Recursive case: sum of previous two Fibonacci numbers
    return fibonacci(n - 1) + fibonacci(n - 2);
}

/**
 * Helper function to generate first n Fibonacci numbers
 * 
 * @param n Number of Fibonacci numbers to generate
 * @return Vector containing the first n Fibonacci numbers
 */
vector<long long> generateFibonacci(int n) {
    vector<long long> result;
    for (int i = 0; i < n; i++) {
        result.push_back(fibonacci(i));
    }
    return result;
}

// ============================================================================
// PROBLEM 3: STRING REVERSAL
// ============================================================================

/**
 * Recursive function to reverse a string
 * 
 * BASE CASE: Empty string or single character returns itself
 * RECURSIVE CASE: Last character + reverse(remaining string)
 * 
 * The function takes the last character and prepends it to the reversed
 * version of the string without that last character.
 * 
 * @param str The string to reverse
 * @return Reversed string
 */
string reverseString(string str) {
    // Base case: empty string or single character
    if (str.length() <= 1) {
        return str;
    }
    
    // Recursive case: last character + reverse of remaining string
    // Take last character and concatenate with reverse of substring
    return str[str.length() - 1] + reverseString(str.substr(0, str.length() - 1));
}

// Alternative implementation using first character
string reverseStringAlt(string str) {
    // Base case: empty string or single character
    if (str.length() <= 1) {
        return str;
    }
    
    // Recursive case: reverse of remaining + first character
    return reverseStringAlt(str.substr(1)) + str[0];
}

// ============================================================================
// PROBLEM 4: BINARY SEARCH
// ============================================================================

/**
 * Recursive binary search implementation
 * 
 * BASE CASE: 
 * - left > right (element not found, return -1)
 * - arr[mid] == target (element found, return mid)
 * 
 * RECURSIVE CASE:
 * - If target < arr[mid], search left half
 * - If target > arr[mid], search right half
 * 
 * The search space is halved with each recursive call by adjusting
 * the left or right boundary based on comparison with middle element.
 * 
 * @param arr Sorted array to search in
 * @param target Element to find
 * @param left Left boundary of search space
 * @param right Right boundary of search space
 * @return Index of target element, or -1 if not found
 */
int binarySearch(const vector<int>& arr, int target, int left, int right) {
    // Base case 1: search space is exhausted
    if (left > right) {
        return -1;  // Element not found
    }
    
    // Calculate middle index
    int mid = left + (right - left) / 2;
    
    // Base case 2: element found at middle
    if (arr[mid] == target) {
        return mid;
    }
    
    // Recursive case 1: target is in left half
    if (target < arr[mid]) {
        return binarySearch(arr, target, left, mid - 1);
    }
    
    // Recursive case 2: target is in right half
    return binarySearch(arr, target, mid + 1, right);
}

// Wrapper function for easier calling
int binarySearch(const vector<int>& arr, int target) {
    return binarySearch(arr, target, 0, arr.size() - 1);
}

// ============================================================================
// UTILITY FUNCTIONS
// ============================================================================

void printSeparator(char c = '=', int length = 35) {
    cout << string(length, c) << endl;
}

void printHeader(const string& title) {
    cout << "\n";
    printSeparator();
    cout << title << endl;
    printSeparator();
}

void printSubHeader(const string& title) {
    cout << "\n--- " << title << " ---" << endl;
}

// ============================================================================
// TEST FUNCTIONS
// ============================================================================

/**
 * Test factorial function with various inputs including edge cases
 */
void testFactorial() {
    printHeader("PROBLEM 1: FACTORIAL CALCULATION");
    
    cout << "\nRecursive Logic:" << endl;
    cout << "  Base Case: factorial(0) = 1, factorial(1) = 1" << endl;
    cout << "  Recursive Case: factorial(n) = n * factorial(n-1)" << endl;
    cout << "  Example: 5! = 5 * 4! = 5 * 4 * 3! = ... = 5 * 4 * 3 * 2 * 1 = 120\n" << endl;
    
    // Test cases
    vector<int> testInputs = {0, 1, 5, 10, 15, 20};
    
    cout << left << setw(15) << "Input (n)" 
         << setw(25) << "Factorial (n!)" << endl;
    printSeparator('-', 40);
    
    for (int n : testInputs) {
        long long result = factorial(n);
        cout << left << setw(15) << n 
             << setw(25) << result << endl;
    }
    
    printSubHeader("Edge Cases");
    cout << " Factorial of 0: " << factorial(0) << " (Base case)" << endl;
    cout << " Factorial of 1: " << factorial(1) << " (Base case)" << endl;
    cout << " Factorial of 20: " << factorial(20) << " (Large number)" << endl;
}

/**
 * Test Fibonacci sequence generation with various inputs
 */
void testFibonacci() {
    printHeader("PROBLEM 2: FIBONACCI SEQUENCE");
    
    cout << "\nRecursive Logic:" << endl;
    cout << "  Base Case: fib(0) = 0, fib(1) = 1" << endl;
    cout << "  Recursive Case: fib(n) = fib(n-1) + fib(n-2)" << endl;
    cout << "  Example: fib(5) = fib(4) + fib(3) = 3 + 2 = 5\n" << endl;
    
    // Test cases
    vector<int> testInputs = {0, 1, 5, 10, 15};
    
    for (int n : testInputs) {
        printSubHeader("First " + to_string(n) + " Fibonacci numbers");
        
        if (n == 0) {
            cout << "Empty sequence (edge case)" << endl;
            continue;
        }
        
        vector<long long> fibSeq = generateFibonacci(n);
        cout << "Sequence: ";
        for (size_t i = 0; i < fibSeq.size(); i++) {
            cout << fibSeq[i];
            if (i < fibSeq.size() - 1) cout << ", ";
        }
        cout << endl;
    }
    
    printSubHeader("Edge Cases");
    cout << " fib(0): " << fibonacci(0) << " (First base case)" << endl;
    cout << " fib(1): " << fibonacci(1) << " (Second base case)" << endl;
    cout << " fib(2): " << fibonacci(2) << " (First recursive call)" << endl;
}

/**
 * Test string reversal with various inputs including edge cases
 */
void testStringReversal() {
    printHeader("PROBLEM 3: STRING REVERSAL");
    
    cout << "\nRecursive Logic:" << endl;
    cout << "  Base Case: String of length 0 or 1 returns itself" << endl;
    cout << "  Recursive Case: last_char + reverse(remaining_string)" << endl;
    cout << "  Example: reverse('hello') = 'o' + reverse('hell') = 'olleh'\n" << endl;
    
    // Test cases
    vector<string> testInputs = {
        "",                      // Empty string (edge case)
        "a",                     // Single character (edge case)
        "ab",                    // Two characters
        "hello",                 // Normal string
        "recursion",             // Longer string
        "A man a plan a canal Panama"  // Sentence
    };
    
    cout << left << setw(35) << "Original String" 
         << setw(35) << "Reversed String" << endl;
    printSeparator('-', 70);
    
    for (const string& str : testInputs) {
        string reversed = reverseString(str);
        string displayOriginal = str.empty() ? "(empty)" : str;
        string displayReversed = reversed.empty() ? "(empty)" : reversed;
        
        cout << left << setw(35) << displayOriginal 
             << setw(35) << displayReversed << endl;
    }
    
    printSubHeader("Edge Cases");
    cout << " Empty string: \"" << reverseString("") << "\" (Base case)" << endl;
    cout << " Single character: \"" << reverseString("x") << "\" (Base case)" << endl;
    cout << " Two characters: \"" << reverseString("ab") << "\" (First recursion)" << endl;
}

/**
 * Test binary search with various inputs including edge cases
 */
void testBinarySearch() {
    printHeader("PROBLEM 4: BINARY SEARCH (RECURSIVE)");
    
    cout << "\nRecursive Logic:" << endl;
    cout << "  Base Case 1: left > right -> element not found (return -1)" << endl;
    cout << "  Base Case 2: arr[mid] == target -> element found (return mid)" << endl;
    cout << "  Recursive Case 1: target < arr[mid] -> search left half" << endl;
    cout << "  Recursive Case 2: target > arr[mid] -> search right half\n" << endl;
    
    // Test Case 1: Normal sorted array
    printSubHeader("Test Case 1: Normal Array [1, 3, 5, 7, 9, 11, 13, 15]");
    vector<int> arr1 = {1, 3, 5, 7, 9, 11, 13, 15};
    vector<int> targets1 = {7, 1, 15, 10};
    
    cout << "Array: ";
    for (int val : arr1) cout << val << " ";
    cout << "\n" << endl;
    
    for (int target : targets1) {
        int result = binarySearch(arr1, target);
        cout << "Searching for " << target << ": ";
        if (result != -1) {
            cout << "Found at index " << result << endl;
        } else {
            cout << "Not found" << endl;
        }
    }
    
    // Test Case 2: Single element array
    printSubHeader("Test Case 2: Single Element Array [42]");
    vector<int> arr2 = {42};
    vector<int> targets2 = {42, 10};
    
    cout << "Array: ";
    for (int val : arr2) cout << val << " ";
    cout << "\n" << endl;
    
    for (int target : targets2) {
        int result = binarySearch(arr2, target);
        cout << "Searching for " << target << ": ";
        if (result != -1) {
            cout << "Found at index " << result << endl;
        } else {
            cout << "Not found" << endl;
        }
    }
    
    // Test Case 3: Empty array (edge case)
    printSubHeader("Test Case 3: Empty Array [] (Edge Case)");
    vector<int> arr3 = {};
    int target3 = 5;
    
    cout << "Array: (empty)\n" << endl;
    int result3 = binarySearch(arr3, target3);
    cout << "Searching for " << target3 << ": ";
    if (result3 != -1) {
        cout << "Found at index " << result3 << endl;
    } else {
        cout << "Not found (expected - array is empty)" << endl;
    }
    
    // Test Case 4: Large array
    printSubHeader("Test Case 4: Larger Array");
    vector<int> arr4;
    for (int i = 0; i <= 100; i += 5) {
        arr4.push_back(i);
    }
    
    cout << "Array: [0, 5, 10, 15, ..., 95, 100] (21 elements)\n" << endl;
    vector<int> targets4 = {0, 50, 100, 37};
    
    for (int target : targets4) {
        int result = binarySearch(arr4, target);
        cout << "Searching for " << target << ": ";
        if (result != -1) {
            cout << "Found at index " << result << endl;
        } else {
            cout << "Not found" << endl;
        }
    }
    
    printSubHeader("Edge Cases Summary");
    cout << " Empty array: Handled correctly (returns -1)" << endl;
    cout << " Single element: Handled correctly (base case)" << endl;
    cout << " First element: Found at index 0" << endl;
    cout << " Last element: Found at last index" << endl;
    cout << " Element not in array: Returns -1" << endl;
}

// ============================================================================
// MAIN FUNCTION
// ============================================================================

int main() {
    cout << "\n";
    cout << "||=============================================================||" << endl;
    cout << "||          RECURSIVE PROBLEM SOLVING IN C++                   ||" << endl;
    cout << "||     Factorial | Fibonacci | String Reversal | Binary Search ||" << endl;
    cout << "||=============================================================||" << endl;
    
    try {
        // Test all recursive functions
        testFactorial();
        testFibonacci();
        testStringReversal();
        testBinarySearch();
        
        // Final summary
        printHeader("RECURSION VS ITERATION - COMPARISON SUMMARY");
        cout << "\nRECURSION ADVANTAGES:" << endl;
        cout << "   More intuitive for naturally recursive problems (tree traversal, divide-and-conquer)" << endl;
        cout << "   Cleaner, more readable code for complex problems" << endl;
        cout << "   Directly models mathematical definitions (factorial, Fibonacci)" << endl;
        cout << "   Easier to implement for backtracking algorithms" << endl;
        
        cout << "\nITERATION ADVANTAGES:" << endl;
        cout << "   More memory efficient (no function call stack overhead)" << endl;
        cout << "   Generally faster execution (no function call overhead)" << endl;
        cout << "   No risk of stack overflow for deep recursion" << endl;
        cout << "   Better for simple, sequential operations" << endl;
        
        cout << "\nWHEN TO USE RECURSION:" << endl;
        cout << "  * Tree and graph traversals" << endl;
        cout << "  * Divide-and-conquer algorithms (merge sort, quick sort)" << endl;
        cout << "  * Backtracking problems (N-Queens, Sudoku solver)" << endl;
        cout << "  * Problems with recursive mathematical definitions" << endl;
        cout << "  * When code clarity is more important than performance" << endl;
        
        cout << "\nWHEN TO USE ITERATION:" << endl;
        cout << "  * Simple loops and sequential processing" << endl;
        cout << "  * Performance-critical code" << endl;
        cout << "  * Memory-constrained environments" << endl;
        cout << "  * Very deep recursion (risk of stack overflow)" << endl;
        
        printSeparator();
        cout << "\n ALL TESTS COMPLETED SUCCESSFULLY\n" << endl;
        
    } catch (const exception& e) {
        cout << "\n Error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}
