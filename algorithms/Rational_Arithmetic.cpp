/******************************************************************************
Rational Arithmetic

https://open.kattis.com/problems/rationalarithmetic

assets/images/rational_arithmetic.png


*******************************************************************************/
#include <iostream>
#include <string>
#include <vector>

void calculate_result(std::vector<std::int16_t> &operands, std::vector<char> &operators)
{
    std::uint16_t x1 = operands[0];
    std::uint16_t y1 = operands[1];
    std::uint16_t x2 = operands[2];
    std::uint16_t y2 = operands[3];

    switch (operators[0])
    {
    case '+':
        std::cout << ((x1 * y2) + (x2 * y1)) << "/" << (y1 * y2);
        break;
    case '-':
        std::cout << ((x1 * y2) - (x2 * y1)) << "/" << (y1 * y2);
        break;
    case '*':
        std::cout << (x1 * x2) << "/" << (y1 * y2);
        break;
    case '/':
        std::cout << (x1 * y2) << "/" << (x2 * y1);
        break;

    default:
        break;
    }
}

int main()
{
    const char possible_operations[] = {'+', '-', '*', '/'};
    // Get received word from user input
    std::uint16_t num_operations;
    std::cin >> num_operations;

    for (int line_ix = 0; line_ix < num_operations; line_ix++)
    {
        std::vector<std::int16_t> operands;
        std::vector<char> operators;
        std::string received_word; // Parsed by ' ' (space)

        for (int operand_ix = 0; operand_ix < 4; operand_ix++) // x1, y1, op x2, y2 (y2 has new line after it)
        {
            std::getline(std::cin, received_word, ' ');

            if (received_word == "+" || received_word == "-" || received_word == "*" || received_word == "/")
            {
                operators.push_back(received_word[0]);
                continue;
            }
            operands.push_back(std::stoi(received_word));
        }
        std::getline(std::cin, received_word, '\n'); // Get the last operand (y2) after the operator
        operands.push_back(std::stoi(received_word));

        calculate_result(operands, operators);
        std::cout << std::endl;
    }

    return 0;
}