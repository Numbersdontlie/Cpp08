/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 00:37:53 by luifer            #+#    #+#             */
/*   Updated: 2025/08/19 00:41:20 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EasyFind.hpp"

int main(){
    std::vector<int> vec = {2, 5, 9, 7, 3, 15, 20, 42};
    try {
        int value = easyFind(vec, 2);
        std::cout << "Found value: " << &value << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    return(0);
}
