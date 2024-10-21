#include <iostream>
#include <cstring>
#include <stdexcept>
#include <cctype>
#include <vector>
#include <sstream>

class String {
private:
    char* data;      // Dynamic character array to store the string.
    size_t len;      // Length of the string.
    size_t capacity; // Capacity for optimization (to minimize reallocations).

    // Helper function to reallocate memory for the string.
    void resize(size_t newCapacity) {
        char* newData = new char[newCapacity];
        std::strncpy(newData, data, len);
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    // Constructors
    String() : data(new char[1]{'\0'}), len(0), capacity(1) {}

    String(const char* str) : len(std::strlen(str)), capacity(len + 1) {
        data = new char[capacity];
        std::strcpy(data, str);
    }

    String(const String& other) : len(other.len), capacity(other.capacity) {
        data = new char[capacity];
        std::strcpy(data, other.data);
    }

    // Destructor
    ~String() {
        delete[] data;
    }

    // Copy assignment
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] data;
            len = other.len;
            capacity = other.capacity;
            data = new char[capacity];
            std::strcpy(data, other.data);
        }
        return *this;
    }

    // Concatenation with assignment (operator+=)
    String& operator+=(const String& other) {
        if (len + other.len + 1 > capacity) {
            resize(len + other.len + 1);
        }
        std::strcat(data, other.data);
        len += other.len;
        return *this;
    }

    // Addition (operator+)
    String operator+(const String& other) const {
        String result(*this);
        result += other;
        return result;
    }

    // Comparison operators
    bool operator==(const String& other) const {
        return std::strcmp(data, other.data) == 0;
    }

    bool operator!=(const String& other) const {
        return !(*this == other);
    }

    bool operator<(const String& other) const {
        return std::strcmp(data, other.data) < 0;
    }

    bool operator>(const String& other) const {
        return std::strcmp(data, other.data) > 0;
    }

    // Subscript operator (non-const)
    char& operator[](size_t index) {
        if (index >= len) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Subscript operator (const)
    const char& operator[](size_t index) const {
        if (index >= len) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Stream insertion (operator<<)
    friend std::ostream& operator<<(std::ostream& os, const String& str) {
        os << str.data;
        return os;
    }

    // Stream extraction (operator>>)
    friend std::istream& operator>>(std::istream& is, String& str) {
        char buffer[1000]; // Temp buffer (adjust as necessary).
        is >> buffer;
        str = String(buffer);
        return is;
    }

    // Methods
    size_t length() const {
        return len;
    }

    bool empty() const {
        return len == 0;
    }

    void clear() {
        delete[] data;
        data = new char[1]{'\0'};
        len = 0;
        capacity = 1;
    }

    const char* c_str() const {
        return data;
    }

    // Substring
    String substr(size_t start, size_t count) const {
        if (start >= len) throw std::out_of_range("Index out of range");
        size_t actualCount = std::min(count, len - start);
        char* sub = new char[actualCount + 1];
        std::strncpy(sub, data + start, actualCount);
        sub[actualCount] = '\0';
        String result(sub);
        delete[] sub;
        return result;
    }

    // Case conversion
    String toUpperCase() const {
        String result(*this);
        for (size_t i = 0; i < len; ++i) {
            result.data[i] = std::toupper(result.data[i]);
        }
        return result;
    }

    String toLowerCase() const {
        String result(*this);
        for (size_t i = 0; i < len; ++i) {
            result.data[i] = std::tolower(result.data[i]);
        }
        return result;
    }

    // Find a substring
    size_t find(const String& substr) const {
        const char* pos = std::strstr(data, substr.data);
        if (pos) {
            return pos - data;
        }
        return std::string::npos;
    }

    // Split into a vector of substrings
    std::vector<String> split(const char delimiter) const {
        std::vector<String> result;
        std::stringstream ss(data);
        std::string item;
        while (std::getline(ss, item, delimiter)) {
            result.push_back(String(item.c_str()));
        }
        return result;
    }

    // Join a vector of strings with a delimiter
    static String join(const std::vector<String>& parts, const char* delimiter) {
        String result;
        for (size_t i = 0; i < parts.size(); ++i) {
            result += parts[i];
            if (i != parts.size() - 1) {
                result += delimiter;
            }
        }
        return result;
    }

    // Trim whitespace
    String trim() const {
        size_t start = 0;
        while (start < len && std::isspace(data[start])) ++start;
        
        size_t end = len;
        while (end > start && std::isspace(data[end - 1])) --end;
        
        return this->substr(start, end - start);
    }
};

// Example usage:
int main() {
    String s1("Hello");
    String s2("World");
    
    String s3 = s1 + ", " + s2 + "!";
    std::cout << s3 << std::endl;

    std::vector<String> parts = s3.split(' ');
    String joined = String::join(parts, " ");
    std::cout << "Joined string: " << joined << std::endl;

    std::cout << "Upper case: " << s3.toUpperCase() << std::endl;
    std::cout << "Trimmed string: '" << s3.trim() << "'" << std::endl;

    return 0;
}
