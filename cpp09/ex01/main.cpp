/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:52:44 by rmerzak           #+#    #+#             */
/*   Updated: 2023/08/19 15:54:02 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool is_valid_expression(const char* expression) {
    int operandCount = 0;
    int operatorCount = 0;
    int i = 0;

    while (expression[i] != '\0') {
        if (std::strchr("+-*/", expression[i])) {
            operatorCount++;
        } else if (std::isdigit(expression[i])) {
            operandCount++;
        } else if (std::isspace(expression[i])) {
            i++;
            continue;
        }
        else {
            return false;
        }
        i++;
    }

    return (operandCount > operatorCount);
}


int main(int argc, char* argv[]) {
   if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " \"expression\"" << std::endl;
        return 1;
    } else {
        if (!is_valid_expression(argv[1])) {
            std::cout << "Error" << std::endl;
            return 1;
        }
        RPN rpn;
        int result = rpn.evaluate(argv[1]);
        if (result != -1) {
            std::cout << result << std::endl;
        }
        return 0;
    }
}