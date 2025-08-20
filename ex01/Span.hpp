/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:22:20 by luifer            #+#    #+#             */
/*   Updated: 2025/08/20 11:37:16 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <limits.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

class Span{
    private:
        Span(); //No instantiation allowed without params
        unsigned int _size;
        std::vector<int> _setOfNums;

    public:
        //Canonical form
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();
        
        // methods
        void addNumber(int number);

        void addBatch(int size);
        //find the minimun diff possible between all the numbers
        int shortestSpan() const;
        //find the maximun diff possible between all the numbers
        int longestSpan() const;

        // Getters
        unsigned int getSize();
        
        //Classes for exceptions 
        class NoSpanFoundException : public std::exception {
            public:
                const char* what() const throw() {
                    return "Not enough elements to find a Span";
                }
        };

        class SpanFullException : public std::exception {
            public:
                const char* what() const throw() {
                    return "Span is full, no space available";
                }
        };
};

#endif

