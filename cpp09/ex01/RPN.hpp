/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:41:34 by rmerzak           #+#    #+#             */
/*   Updated: 2023/08/08 16:41:35 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <functional>

class RPN {
private:
    std::stack<int> stack;
    int perform_operation(int a, int b, const char op);
public:
    int evaluate(const char* expression);
};