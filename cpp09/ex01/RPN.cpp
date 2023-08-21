/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:41:42 by rmerzak           #+#    #+#             */
/*   Updated: 2023/08/20 20:59:38 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
RPN::RPN() {
}
RPN::~RPN() {
}
RPN::RPN(const RPN &src) {
    *this = src;
}
RPN &RPN::operator=(const RPN &rhs) {
    if (this == &rhs) {
        return *this;
    }
    stack = rhs.stack;
    return *this;
}
int RPN::evaluate(const char* expression) {
        int i = 0;
        while (expression[i] != '\0') {
            if (std::strchr("+-*/", expression[i])) {
                if (stack.size() < 2) {
                    std::cout << "Error" << std::endl;
                    return -1;
                }
                int b = stack.top();
                stack.pop();
            //     if (expression[i] == '/' && b == 0) {
            //     std::cout << "Error" << std::endl;
            //     return -1;
            // }
                int a = stack.top();
                stack.pop();
                stack.push(perform_operation(a, b, expression[i]));
            } else if (std::isdigit(expression[i])) {
                std::string a(1, expression[i]);
                int num = std::atoi(a.c_str());
                if (num < 0 || num > 10) {
                    std::cout << "Error" << std::endl;
                    return -1;
                }
                    stack.push(num);
            }
            else if (std::isspace(expression[i])) {
                i++;
                continue;
            } else {
                std::cout << "Error" << expression[i] << std::endl;
                return -1;
            }
            i++;
        }

        if (stack.size() != 1) {
            std::cout << "Error" << std::endl;
            return -1;
        }

        return stack.top();
    }

int RPN::perform_operation(int a, int b, const char op) {
        if (op == '+') return a + b;
        if (op == '-') return a - b;
        if (op == '*') return a * b;
        if (op == '/') return a / b;
        return 0;
}