#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN &RPN::operator=(const RPN &copy)
{
    if(this != &copy)
        *this = copy;
    return(*this);
}

RPN::RPN(const RPN &copy)
{
    *this = copy;
}

void RPN::set_arguments(std::string argument)
{
    bool val = 0;
    size_t invalidPos = argument.find_first_not_of("0123456789/*+- ");

    if (invalidPos != std::string::npos) {
        std::cerr << "Error: argument contains character out of normal: '"
                << argument[invalidPos] << "'" << std::endl;
        return;
    }
    for (int i = static_cast<int>(argument.size() - 1); i >= 0; i--)
    {
        if(argument[i] != ' ')
        {
            if (val == 1)
            {
                std::cerr << "Error: argument contains charecter out of normal" << std::endl;
                return ;
            }
            val = 1;
            stack.push(argument[i] - '0');
        }
        else
            val = 0;
    }
    reverse_PN();
}

void RPN::reverse_PN()
{
    void (RPN::*functionptrs[])(int, int) = {&RPN::plus, &RPN::minus, &RPN::multiply, &RPN::divide};
    int types[] = {'+', '-', '*', '/'};
    int first = 0;
    int second = 0;

    while(stack.size() >= 3)
    {
        first = stack.top();
        for (int i = 0; i < 4; i++)
        {
            if (static_cast<char>(first + '0') == types[i])
            {
                std::cerr << "Error: suposed number is an operator" << std::endl;
                return ;
            }
        }
        stack.pop();
        if(!stack.empty())
            second = stack.top();
        for (int i = 0; i < 4; i++)
        {
            if (static_cast<char>(second + '0') == types[i])
            {
                std::cerr << "Error: suposed number is an operator" << std::endl;
                return ;
            }
        }
        if (!stack.empty())
            stack.pop();
        for (int i = 0; i < 4; i++)
        {
            if (!stack.empty() && static_cast<char>(stack.top() + '0') == types[i])
            {
                if (!stack.empty())
                    stack.pop();
                (this->*functionptrs[i])(first, second);
                break;
            }
        }
    }
    std::cout << (stack.top()) << std::endl;
    stack.pop();
}

void RPN::plus(int first, int second)
{
    stack.push(first + second);
}

void RPN::minus(int first, int second)
{
    stack.push(first - second);
}

void RPN::multiply(int first, int second)
{
    stack.push(first * second);
}

void RPN::divide(int first, int second)
{
    stack.push(first / second);
}
