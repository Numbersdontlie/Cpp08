/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:41:53 by luifer            #+#    #+#             */
/*   Updated: 2025/08/20 12:26:40 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

int main() {
    //seed the random number generator once at the begining of the program
    std::srand(std::time(0));
    Span sp1 = Span(10);
    sp1.addNumber(5);
    sp1.addNumber(1);
    sp1.addNumber(15);
    sp1.addNumber(4);
    sp1.addNumber(8);
    sp1.addNumber(20);
    sp1.addNumber(3);
    sp1.addNumber(90);
    sp1.addNumber(29);
    sp1.addNumber(18);
    std::cout << GRE << "Shortest span is:" << sp1.shortestSpan() << RST << std::endl;
    std::cout << GRE << "Longest span is:" << sp1.longestSpan() << RST << std::endl;

    //Test with big vector 10k
    std::cout << BLU << "Testing with a big vector of 10k elements:" << RST << std::endl;
    Span sp2 = Span(10000);
    sp2.addBatch(10000);
    std::cout << GRE << "Shortest span is:" << sp2.shortestSpan() << RST << std::endl;
    std::cout << GRE << "Longest span is:" << sp2.longestSpan() << RST << std::endl;
    //print for check
    //sp2.printContent();

    //Test with big vector 100k
    std::cout << BLU << "Testing with a big vector of 100k elements:" << RST << std::endl;
    Span sp3 = Span(100000);
    sp3.addBatch(100000);
    std::cout << GRE << "Shortest span is:" << sp3.shortestSpan() << RST << std::endl;
    std::cout << GRE << "Longest span is:" << sp3.longestSpan() << RST << std::endl;

    //Test exceptions
    std::cout << BLU << "Testing exceptions:" << RST << std::endl;
    Span sp4 = Span(5);
    try {
        sp4.addNumber(1);
        sp4.addNumber(2);
        sp4.addNumber(3);
        sp4.addNumber(4);
        sp4.addNumber(5);
        sp4.addNumber(6);
    } catch (const Span::SpanFullException& e) {
        std::cerr << e.what() << std::endl;
    }
    return(0);
}
