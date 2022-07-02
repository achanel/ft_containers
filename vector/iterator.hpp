#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iostream>
# include <string>
# include <iterator>
# include "../reverse_iterator.hpp"

namespace ft
{
	template <class T>
	class VecIter : public std::iterator<std::random_access_iterator_tag, T>
	{
        public:
            typedef T                                               iterator_type;
            typedef std::random_access_iterator_tag					iterator_category;
            typedef typename iterator_traits<T>::value_type         value_type;
            typedef typename iterator_traits<T>::difference_type    difference_type;
            typedef typename iterator_traits<T>::pointer            pointer;
            typedef typename iterator_traits<T>::reference          reference;

		private:
			iterator_type	_it;

		public:
            VecIter(): _it(nullptr) {};
            explicit VecIter( iterator_type x ): _it(x) {};
            template <class Iter>
            VecIter( const VecIter<Iter>& vec_it ): _it(vec_it.base()) {};

            iterator_type	base() const            { return (this->_it); };
            reference operator*() const             { return (*this->_it); };
            VecIter& operator++()					{ ++this->_it; return (*this); };
            VecIter  operator++(int)  { VecIter temp(*this); ++(*this); return (temp); };
            VecIter& operator--()					{ --this->_it; return (*this); };
            VecIter  operator--(int)  { VecIter temp(*this); ++(*this); return (temp); };
            pointer operator->() const  { return(&(operator*())); };
            reference operator[] (difference_type n) const { return(*(this->_it + n)); };
    };

	template <class Iterator1, class Iterator2>
    bool operator== (const VecIter<Iterator1>& lhs, const VecIter<Iterator2>& rhs)
    {
        return (lhs.base() == rhs.base());
    }
    template <class Iterator1, class Iterator2>
    bool operator!= (const VecIter<Iterator1>& lhs, const VecIter<Iterator2>& rhs)
    {
        return (lhs.base() != rhs.base());
    }
    template <class Iterator1, class Iterator2>
    bool operator<  (const VecIter<Iterator1>& lhs, const VecIter<Iterator2>& rhs)
    {
        return (lhs.base() < rhs.base());
    }
    template <class Iterator1, class Iterator2>
    bool operator<= (const VecIter<Iterator1>& lhs, const VecIter<Iterator2>& rhs)
    {
        return (lhs.base() <= rhs.base());
    }
    template <class Iterator1, class Iterator2>
    bool operator>  (const VecIter<Iterator1>& lhs, const VecIter<Iterator2>& rhs)
    {
        return (lhs.base() > rhs.base());
    }
    template <class Iterator1, class Iterator2>
    bool operator>= (const VecIter<Iterator1>& lhs, const VecIter<Iterator2>& rhs)
    {
        return (lhs.base() >= rhs.base());
    }

	template <class Iterator>
	VecIter<Iterator> operator+ (typename VecIter<Iterator>::difference_type n, const VecIter<Iterator>& vec_it)
	{ return (VecIter<Iterator>( vec_it + n)); };
	template <class Iterator>
	typename VecIter<Iterator>::difference_type operator- (const VecIter<Iterator>& lhs, const VecIter<Iterator>& rhs)
	{ return (lhs.base() - rhs.base()); };
};

#endif