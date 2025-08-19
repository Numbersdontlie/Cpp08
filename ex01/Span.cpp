/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:37:08 by luifer            #+#    #+#             */
/*   Updated: 2025/08/19 14:41:27 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Canonical form
Span::Span(unsigned int N) : _size(N) {}

Span::Span(const Span &other) : _size(other._size), _setOfNums(other._setOfNums) {
    if(other._setOfNums.size() > _size) {
        throw SpanFull();
    }
    _setOfNums = other._setOfNums;
}

Span &Span::operator=(const Span &other) {
    if (this != &other){
        _size = other._size;
        _setOfNums = other._setOfNums;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n) {
    if(_setOfNums.size() >= _size){
        throw SpanFull();
    }
    _setOfNums.push_back(n);
}

//Divide the vector in 2, find the min value in 1st half
//find the min value in the 2nd half and calculate the difference
int Span::shortestSpan() const {
    int min1 = *std::min_element(_setOfNums.begin(), _setOfNums.begin() + _setOfNums.size() / 2);
    int min2 = *std::min_element(_setOfNums.begin() + _setOfNums.size() / 2, _setOfNums.end());
    return min2 - min1;
}

//Divide the vector in 2, find the max value in 1st half
//find the max value in the 2nd half and calculate the difference
int Span::longestSpan() const {
    int max1 = *std::max_element(_setOfNums.begin(), _setOfNums.begin() + _setOfNums.size() / 2);
    int max2 = *std::max_element(_setOfNums.begin() + _setOfNums.size() / 2, _setOfNums.end());
    return max2 - max1;
}

