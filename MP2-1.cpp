/*  Write a syntactic specification using the Backus-Naur Form to describe the
    mini-language with the following description: Simple expressions limited to
    the variable identifiers x, y, or z, that contain the operations of addition (+),
    subtraction (-), and unary negation (~) together with parentheses. 


    Valid strings:
    ~x+~y
    (x+z-y)
    z-(x+y)

    Invalid strings:
    a+b
    xy-xz
    z(x+y) 


    BNF Grammar:
    <string>        ::=     <expression>
    <expression>    ::=     (<expression>) | <operation>
    <operation>     ::=     <expression><sign><expression> | <unary><expression> | <identifier>
    <sign>          ::=     + | -
    <unary>         ::=     ~
    <identifier>    ::=     x | y | z
*/ 


#include <iostream>
using namespace std;

int main()
{
    cout << "Enter string: ";
    string stringInput;
    getline(cin, stringInput);

    string tempString;

    // space removal
    for (char s : stringInput)
    {
        if (s != ' ')
        {
            tempString += s;
        }
    }

    bool checkInGrammar = true;

    int counter = 0;
    for (char s : tempString)
    {
        if (s == '(')
        {
            counter--;
        }
    }

    if (counter != 0)
    {
        cout << "String, " << stringInput << ", is not in the grammar.";
        return 0;
    }

    for (int i = 0; i < tempString.size() - 1; i++)
    {
        char current = tempString[i];
        char next = tempString[i + 1];

        if (current == 'x' || current == 'y' || next == 'z')
        {
            if (next == '+' || next == '-' || next == ')')
            {
                continue;
            }
            else
            {
                checkInGrammar = false;
                break;
            }
        }
        else if (current == '~')
        {
            if (next == 'x' || next == 'y' || next == 'z')
            {
                continue;
            }
            else
            {
                checkInGrammar = false;
                break;
            }
        }

        else if (current == '(')
        {
            if (next == 'x' || next == 'y' || next == 'z' || next == '~')
            {
                continue;
            }
            else
            {
                checkInGrammar = false;
                break;
            }
        }
    }

    if (checkInGrammar)
    {
        cout << "String, " << stringInput << ", is in the grammar.";
    }
    else
    {
        cout << "String, " << stringInput << ", is not in the grammar.";
    }

    return 0;
}