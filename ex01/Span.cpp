/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:37:08 by luifer            #+#    #+#             */
/*   Updated: 2025/08/19 14:11:26 by luifer           ###   ########.fr       */
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

