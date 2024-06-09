// Reading and Writing with `ifstream` and `ofstream`
#include <fstream>
using namespace std;

// When dealing with file input and output, use these standard C++ classes.
int main()
{
    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    int a, b;
    infile >> a >> b;
    outfile << a + b << endl;

    infile.close();
    outfile.close();

    return 0;
}
// **Advantages:**
// - Standard and portable.
// - Suitable for file operations.

// **Disadvantages:**
// - Not the fastest method for competitive programming.