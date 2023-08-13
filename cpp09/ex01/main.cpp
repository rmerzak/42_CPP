/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:52:44 by rmerzak           #+#    #+#             */
/*   Updated: 2023/08/09 13:34:55 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool is_valid_expression(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;
    int operandCount = 0;
    int operatorCount = 0;

    while (iss >> token) {
        if (std::strchr("+-*/", token[0])) {
            operatorCount++;
        } else if (std::isdigit(token[0]) || (token[0] == '-' && std::isdigit(token[1]))) {
            operandCount++;
        } else {
            return false;
        }
    }

    return (operandCount > operatorCount);
}


int main(int argc, char* argv[]) {
   if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " \"expression\"" << std::endl;
        return 1;
    } else {
        std::string expression = argv[1];
        if (!is_valid_expression(expression)) {
            std::cout << "Error: Invalid inverted Polish mathematical expression" << std::endl;
            return 1;
        }
        RPN rpn;
        int result = rpn.evaluate(expression.c_str());
        if (result != -1) {
            std::cout << result << std::endl;
        }
        return 0;
    }
}