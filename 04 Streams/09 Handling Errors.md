## Handling Errors
When using `std::cin` in C++, it's common to encounter errors when the user provides input of an unexpected type. For example, if the program expects an integer but the user enters a string, this can cause the input stream to enter a "fail" state. In such cases, the program needs to detect this error, clear the stream's error state, and potentially discard the incorrect input before prompting the user again.

Here’s how you can handle such situations:

### Basic Approach

1. **Check the Stream State**: After reading input, check if `std::cin` is in a fail state using `std::cin.fail()`.

2. **Clear the Stream State**: If an error is detected, clear the error state using `std::cin.clear()`.

3. **Discard Invalid Input**: To remove the incorrect input from the stream, use `std::cin.ignore()`.

4. **Prompt the User Again**: After handling the error, prompt the user to enter the correct type.

### Example Code

```cpp
#include <iostream>
#include <limits>

int main() {
    int number;

    while (true) {
        std::cout << "Enter an integer: ";
        std::cin >> number;

        if (std::cin.fail()) {
            // If the input is not of the correct type
            std::cin.clear();  // Clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard invalid input
            std::cout << "Invalid input. Please enter an integer." << std::endl;
        } else {
            // If the input is correct
            break;  // Exit the loop
        }
    }

    std::cout << "You entered: " << number << std::endl;

    return 0;
}
```

### Explanation

1. **`std::cin >> number;`**: The program attempts to read an integer from the user. If the user enters something that cannot be interpreted as an integer (e.g., a string like "abc"), `std::cin` will enter a fail state.

2. **Error Check**: After the input attempt, `std::cin.fail()` is checked. If it returns `true`, it means the input was not valid.

3. **Clearing the Error State**: `std::cin.clear();` resets the error flags on the stream, allowing further input operations to be attempted.

4. **Discarding Invalid Input**: `std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');` discards everything in the input buffer up to the next newline (`'\n'`). This is necessary because, without it, the invalid input would still be in the stream, causing subsequent input attempts to fail immediately.

5. **Looping**: The loop continues to prompt the user until valid input is provided.

### Handling Multiple Types of Input

If you expect multiple types of input, you can combine type checks or use different methods (e.g., `std::getline()` for strings and `std::stringstream` for parsing).

### Example with Multiple Inputs

```cpp
#include <iostream>
#include <limits>
#include <string>
#include <sstream>

int main() {
    std::string input;
    int number;

    while (true) {
        std::cout << "Enter an integer: ";
        std::getline(std::cin, input);

        std::stringstream ss(input);
        if (ss >> number) {
            // Check if the stream is in a good state and if there is any remaining input
            char remaining;
            if (ss >> remaining) {
                std::cout << "Invalid input. Please enter a valid integer." << std::endl;
            } else {
                break;  // Exit loop if input is correct
            }
        } else {
            std::cout << "Invalid input. Please enter a valid integer." << std::endl;
        }
    }

    std::cout << "You entered: " << number << std::endl;

    return 0;
}
```

### Explanation

- **`std::getline(std::cin, input);`**: Reads the entire line of input, allowing for more flexible input processing.
- **`std::stringstream ss(input);`**: Converts the input string into a `stringstream` for easier type checking.
- **`ss >> number`**: Attempts to parse an integer from the input. If this fails, an error message is printed.
- **Check for Extra Characters**: After reading the integer, the program checks if there are any extra characters left in the stream, which would indicate that the input wasn't purely numeric (e.g., "123abc").

This approach is more robust and can handle various types of input errors, making it more suitable for applications where the user might provide unexpected input.