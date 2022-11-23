#include <stack>
#include <vector>
#include <string>

bool is_operand(std::string operand)
{
    if (operand == "+" || operand == "-" || operand == "*" || operand == "/")
    {
        return true;
    }
    else
    {
        return false;
    }
}

int onp(std::vector<std::string> vector)
{
    std::stack<int> S;
    for (auto x : vector)
    {
        if (!is_operand(x))
        {

            S.push(stoi(x));
        }
        else
        {
            int a = S.top();
            S.pop();
            int b = S.top();
            S.pop();
            if (x == "+")
            {
                S.push(b + a);
            }
            else if (x == "-")
            {
                S.push(b - a);
            }
            else if (x == "*")
            {
                S.push(b * a);
            }
            else
            {
                S.push(b / a);
            }
        }
    }
    return S.top();
}
