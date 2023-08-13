/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:41:42 by rmerzak           #+#    #+#             */
/*   Updated: 2023/08/09 13:52:44 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
int RPN::evaluate(const char* expression) {
        std::istringstream iss(expression);
        std::string token;
        std::cout << "Expression: " << iss.str() << std::endl;

        while (iss >> token) {
            if (std::strchr("+-*/", token[0])) {
                if (stack.size() < 2) {
                    std::cout << "Error: Not enough operands for operator " << token << std::endl;
                    return -1;
                }
                int b = stack.top();
                stack.pop();
                int a = stack.top();
                stack.pop();
                stack.push(perform_operation(a, b, token[0]));
            } else if (std::isdigit(token[0]) || (token[0] == '-' && std::isdigit(token[1]))) {
                int num = std::atoi(token.c_str());
                if (num < 0 || num > 10) {
                    std::cout << "Error: Number must be between 0 and 10" << std::endl;
                    return -1;
                }
                stack.push(num);
            } else {
                std::cout << "Error: Invalid token " << token << std::endl;
                return -1;
            }
        }

        if (stack.size() != 1) {
            std::cout << "Error: Invalid expression" << std::endl;
            return -1;
        }

        return stack.top();
        iss.clear();
    }
int RPN::perform_operation(int a, int b, const char op) {
        if (op == '+') return a + b;
        if (op == '-') return a - b;
        if (op == '*') return a * b;
        if (op == '/') return a / b;
        return 0;
}