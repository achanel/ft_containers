#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "iterator.hpp"
# include "utils.hpp"
# include <string>
# include <iostream>
# include <algorithm>
# include <limits>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector // generic template
	{
		public:
			typedef T									value_type;
			typedef Allocator							allocator_type;
			typedef typename allocator_type::size_type	size_type;
			typedef typename allocator_type::difference_type	difference_type;
			typedef typename allocator_type::reference	reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer	pointer;
			typedef typename allocator_type::const_pointer	const_pointer;
			typedef VecIter<pointer>					iterator;
			typedef VecIter<const_pointer>				const_iterator;
			typedef ft::reverse_iterator<pointer>		reverse_iterator;
			typedef ft::reverse_iterator<const_pointer>	const_reverse_iterator;

		private:
			allocator_type		_alloc;
			value_type*			_vec;
			size_type			_size;
			size_type			_capacity;

		public: //construct
			explicit vector (const allocator_type& alloc = allocator_type()):
				_alloc(alloc), _vec(nullptr), _size(0), _capacity(0) {};
			explicit vector (size_type n, const value_type& val = value_type()),
				const allocator_type& alloc = allocator_type()):
				_alloc(alloc), _size(0), _capacity(0), _vec(nullptr)
			{ this->assign(n, val); };
			template <class InputIterator>
			vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type(), typename ft::enable_if<!is_integral<InputIterator>::value, bool>::type = true):
				 _alloc(alloc), _size(0), _capacity(0), _vec(nullptr)
			{ this->assign(first, last); };
			vector (const vector& x): _vec(nullptr), _size(0), _capacity(0) { *this = x; };

		public: //destruct
			~vector()
			{
				if (this->_vec != nullptr)
					clear();
			};

		public: //operator=
			vector& operator= (const vector& x)
			{
				if (this != &x)
				{
					if (this->_capacity != 0)
						this->_alloc.deallocate(this->_vec, this->_capacity);
					this->_alloc = x._alloc;
					this->_size = x._size;
					this->_capacity = x._size;
					this->_vec = this->_alloc.allocate(this->_capacity);
					for (size_t i = 0; i < this->_size; i++)
						this->_alloc.construct(this->_vec + i, x._vec[i]);
				}
				return (*this);
			}

		public: //itgerators
			iterator begin() { return(iterator(this->_vec)); };
			const_iterator begin() const { return(const_iterator(this->_vec)); };
			iterator end()	{ return(iterator(begin() + size())); };
			const_iterator end() const { return(const_iterator(begin() + size())); };
			reverse_iterator rbegin() { return(reverse_iterator((end() - 1).base())); };
			const_reverse_iterator begin() const { return(const_reverse_iterator((end() - 1).base())); };
			reverse_iterator rend() { return(reverse_iterator((begin() - 1).base())); };
			const_reverse_iterator end() const { return(const_reverse_iterator((begin() - 1).base())); };

		public: //capacity
			size_type size()
			size_type max_size() const;
			void resize (size_type n, value_type val = value_type());
			size_type capacity() const;
			bool empty() const;
			void reserve (size_type n);
			void shrink_to_fit();

		public: //element access
			reference operator[] (size_type n);
			const_reference operator[] (size_type n) const;
			reference at (size_type n);
			const_reference at (size_type n) const;
			reference front();
			const_reference front() const;
			reference back();
			const_reference back() const;
			value_type* data() noexcept;
			const value_type* data() const noexcept;

		public: //Modifiers
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last);	
			void assign (size_type n, const value_type& val);

			void push_back (const value_type& val);
			void pop_back();

			iterator insert (iterator position, const value_type& val);	
    		void insert (iterator position, size_type n, const value_type& val);	
			template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last);

			iterator erase (iterator position);
			iterator erase (iterator first, iterator last);

			void swap (vector& x);
			void clear();

			template <class... Args>
			iterator emplace (const_iterator position, Args&&... args);

			template <class... Args
			void emplace_back (Args&&... args);

		public: //allocator
			allocator_type get_allocator() const;
	};	
	template <class T, class Alloc>
  	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>
  	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
};

#endif