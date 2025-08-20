/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:40:01 by luifer            #+#    #+#             */
/*   Updated: 2025/08/20 15:39:53 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iostream>

//Inherit from stack and expose the underlying container
//to iterate it. Reverse iterators for stack-like iteration (top to bottom)
//Container defaults to std::deque same as std::stack default
//forward both template parameters to the base class
//allowing users to choose the underlying container
template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
    public:
        //Iterator type aliasing to create type aliases for iterator types
        //typename is required because we're in template context
        typedef typename Container::iterator iterator;
        typedef typename Container::const_iterator const_iterator;
        typedef typename Container::reverse_iterator reverse_iterator;
        typedef typename Container::const_reverse_iterator const_reverse_iterator;

        //Expose iterators to underlying container from the inherited protected member c
        //this protected member is the actual container storing the data
        iterator begin(){
            //protected member access from the base class. It works because
            //inheritance from std::stack allows access to the protected member c
            return this->c.begin();
        }
        iterator end(){
            return this->c.end();
        }
        const_iterator begin() const {
            return this->c.begin();
        }
        const_iterator end() const {
            return this->c.end();
        }
        // Reverse iterator (stack-iter: top to bottom)
        reverse_iterator rbegin(){
            return this->c.rbegin();
        }
        reverse_iterator rend(){
            return this->c.rend();
        }
        const_reverse_iterator rbegin() const {
            return this->c.rbegin();
        }
        const_reverse_iterator rend() const {
            return this->c.rend();
        }
};

#endif
