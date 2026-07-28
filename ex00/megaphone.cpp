#include <iostream>
#include <string>
#include <cctype>

/*
No args - print standard message
More than 1 arg - print all in caps

Then: print nl at the end

Cast - std::toupper returns int
*/

using std::cout;
using std::string;

int main(int argc, char** argv)
{
    if (argc == 1)
    {
        cout << "\033[31m* LOUD AND UNBEARABLE FEEDBACK NOISE *\033[0m";
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            string str(argv[i]);

            cout << "\033[31m";

            for (size_t j = 0; j < str.length(); j++)
            {
                cout << (char)std::toupper(str[j]);
            }

            cout << "\033[0m";
        }
    }

    cout << "\n";
    return 0;
}
