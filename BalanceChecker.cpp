#include<iostream>
#include<stack>
using namespace std;

bool isBalanced(string input)
{
    stack<char> Stack;
    char temp;



    // A for-loop for the length of input
    for (int i = 0; i < input.length(); i++)
    {
    // This if statement makes sure that ONLY the round brackets are accepted, other wise it'll automatically be false
/*        if (input[i] == '[' || input[i] == ']' ||
            input[i] == '{' || input[i] == '}')
            {
                cout << "\nUse only round brackets '( )'!";
                return false;
            }
*/
    // The 'if' statement below makes use of the temp function I created to insert all the opening bracket
    // into a new stack, meaning that any number or letter will NOT influence the programs outcome
        if (input[i] == '(' || input[i] == '[' || input[i] == '{')
            {
            Stack.push(input[i]);
            continue;
            }

    // If the initial input has letters but no brackets then it will output a "Not Balance"
        if (Stack.empty())
            {
            return false;
            }
    // A Switch Statement, while I could've just used 'if' statements I find it much more readable
    // and convenient if I just created cases instead of "if (input[i] == '{')  . . . for every bracket
        switch (input[i])
        {
            case ')':
                temp = Stack.top();
                Stack.pop();
                if (temp =='{' || temp =='[')
                    return false;
                    break;

            case '}':
                temp = Stack.top();
                Stack.pop();
                if (temp =='(' || temp =='[')
                    return false;
                    break;

            case ']':
                temp = Stack.top();
                Stack.pop();
                if (temp =='(' || temp == '{')
                    return false;
                    break;

        }
    }

    // Depending on whether or not the 'for-loop' finishes looping will determine if
    // the bool will return false or true. If it loops successfully it'll return a true
    // if not then it'll be false.
        return (Stack.empty());
}

main()
{
   string input;
   cout << "- Balance Checker -\nYour Input : ";
   cin >> input;

   if (isBalanced(input))
      cout << "\nBalanced\n";
   else
      cout << "\nNot Balanced\n";
}
