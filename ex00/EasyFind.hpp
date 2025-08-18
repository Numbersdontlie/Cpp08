/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EasyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 00:16:07 by luifer            #+#    #+#             */
/*   Updated: 2025/08/19 00:40:06 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <vector>
#include <stdexcept>
#include <iostream>

template <typename T>
int easyFind(T &container, int value){
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it != container.end())
        return *it;
    throw std::runtime_error("Value not found");
}

#endif