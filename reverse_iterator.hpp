#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include <iostream>
# include <string>
# include <iterator>
# include "iterator_traits.hpp"

namespace ft
{
    template <class T>
    class reverse_iterator : public std::iterator<std::random_access_iterator_tag, T>
    {
        public:
            
    }
};

#endif