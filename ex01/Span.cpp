/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:37:08 by luifer            #+#    #+#             */
/*   Updated: 2025/08/20 11:40:56 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Canonical form
Span::Span(unsigned int N) : _size(N) {}

// Copy constructor
Span::Span(const Span &other) : _size(other._size), _setOfNums(other._setOfNums) {}

// Copy assignment operator
Span &Span::operator=(const Span &other) {
    if (this != &other){
        this->_size = other._size;
        this->_setOfNums = other._setOfNums;
    }
    return *this;
}

//Destructor
Span::~Span() {}

//add a number into  the Span
void Span::addNumber(int n) {
    if(this->_setOfNums.size() >= this->_size){
        throw SpanFullException();
    }
    this->_setOfNums.push_back(n);
}

//sort the vector and find the max element and the previous
//then substract and get the longest span
//previous solution was not optimal
int Span::shortestSpan() const {
    if (this->_setOfNums.size() < 2)
        throw NoSpanFoundException();
    std::vector<int> copy = this->_setOfNums;
    std::sort(copy.begin(), copy.end());
    int min1 = copy[0];
    int min2 = copy[1];
    //int min1 = *std::min_element(_setOfNums.begin(), _setOfNums.begin() + _setOfNums.size() / 2);
    //int min2 = *std::min_element(_setOfNums.begin() + _setOfNums.size() / 2, _setOfNums.end());
    return min2 - min1;
}

//sort the vector and find the max element and the previous
//then substract and get the longest span
int Span::longestSpan() const {
    if (this->_setOfNums.size() < 2)
        throw NoSpanFoundException();
    std::vector<int> copy = this->_setOfNums;
    std::sort(copy.begin(), copy.end());
    int max1 = copy[copy.size() - 1];
    int max2 = copy[copy.size() - 2];
    //int max1 = *std::max_element(_setOfNums.begin(), _setOfNums.begin() + _setOfNums.size() / 2);
    //int max2 = *std::max_element(_setOfNums.begin() + _setOfNums.size() / 2, _setOfNums.end());
    return max1 - max2;
}

//Getter for the size of the vector
unsigned int Span::getSize() {
    return this->_size;
}

//Function to create a random vector with big set of numbers
//it should insert the numbers into the Span
//and handle the case when the Span is full
void Span::addBatch(int size){
    std::srand(std::time(0));
    Span large = Span(10000);
    for (int i = 0; i < size; i++){
        large.addNumber(std::rand() % 100);
    }
    try {
        this->_setOfNums.insert(this->_setOfNums.end(), large._setOfNums.begin(), large._setOfNums.end());
    } catch (const Span::SpanFullException& e) {
        std::cerr << e.what() << std::endl;
    }
}