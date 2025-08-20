/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:44:45 by luifer            #+#    #+#             */
/*   Updated: 2025/08/20 14:42:48 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp example
#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

int main() {
    std::cout << "=== MutantStack with default container (deque) ===" << std::endl;
    
    // Create a MutantStack (uses deque by default)
    MutantStack<int> mstack;
    
    // Use it like a normal stack
    mstack.push(4);
    mstack.push(42);
    mstack.push(420);
    mstack.push(4200);
    mstack.push(420000);
    mstack.push(4300000);
    
    std::cout << "Stack size: " << mstack.size() << std::endl;
    std::cout << "Top element: " << mstack.top() << std::endl;
    
    // Now the magic: iterate through the stack!
    std::cout << "\nIterating bottom to top (normal iterator): 🫥 🫥 🫥" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
    
    // Iterate top to bottom (reverse iterator - stack-like order)
    std::cout << "\nIterating top to bottom (reverse iterator): 🫥 🫥 🫥" << std::endl;
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
        std::cout << *rit << ", ";
    }
    std::cout << std::endl;
    
    // Pop an element and iterate again
    mstack.pop();
    std::cout << "\nAfter pop, iterating bottom to top:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
    
    // Using another container types
    std::cout << "\n=== MutantStack with vector container ===" << std::endl;
    MutantStack<int, std::vector<int> > vectorStack;
    vectorStack.push(10);
    vectorStack.push(20);
    vectorStack.push(30);
    
    for (MutantStack<int, std::vector<int> >::iterator it = vectorStack.begin(); it != vectorStack.end(); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
    
    std::cout << "\n=== MutantStack with list container ===" << std::endl;
    MutantStack<int, std::list<int> > listStack;
    listStack.push(100);
    listStack.push(200);
    listStack.push(300);
    
    for (MutantStack<int, std::list<int> >::iterator it = listStack.begin(); it != listStack.end(); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
    
    return 0;
}