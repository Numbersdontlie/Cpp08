/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:37:08 by luifer            #+#    #+#             */
/*   Updated: 2025/08/20 12:23:23 by luifer           ###   ########.fr       */
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

//sort the vector and initialize the min to the diff between 1st and 2nd element
//iterate the vector to compare this diff between numbers and check if there is a minimum
//update when found and return the value
int Span::shortestSpan() const {
    if (this->_setOfNums.size() < 2)
        throw NoSpanFoundException();
    std::vector<int> copy = this->_setOfNums;
    std::sort(copy.begin(), copy.end());
    int shortest = copy[1] - copy[0];
    for(size_t i = 0; i < copy.size() - 1; i++) {
        int diff = copy[i + 1] - copy[i];
        if(diff < shortest){
            shortest = diff;
        }
    }
    //int min1 = *std::min_element(_setOfNums.begin(), _setOfNums.begin() + _setOfNums.size() / 2);
    //int min2 = *std::min_element(_setOfNums.begin() + _setOfNums.size() / 2, _setOfNums.end());
    return shortest;
}

//sort the vector and find the last element aka the maximum
//then substract the 1st element aka minimun and get the longest span
int Span::longestSpan() const {
    if (this->_setOfNums.size() < 2)
        throw NoSpanFoundException();
    std::vector<int> copy = this->_setOfNums;
    std::sort(copy.begin(), copy.end());
    return (copy[copy.size() - 1] - copy[0]);
}

//Getter for the size of the vector
unsigned int Span::getSize() {
    return this->_size;
}

//Function to create a random vector with big set of numbers
//it should insert the numbers into the Span
//and handle the case when the Span is full
void Span::addBatch(int size){
    //check if the batch can fit
    if(this->_setOfNums.size() + size > this->_size){
        throw SpanFullException();
    }

    for (int i = 0; i < size; i++){
        this->_setOfNums.push_back(std::rand() % INT_MAX); //Using a bigger range to avoid duplicates
    }
}

//Function to print the content of the Span
void Span::printContent() const {
    for (size_t i = 0; i < this->_setOfNums.size(); i++){
        std::cout << this->_setOfNums[i] << " ";
    }
    std::cout << std::endl;
}