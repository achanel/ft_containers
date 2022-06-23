#ifndef MAP_HPP
# define MAP_HPP

# include "tree.hpp"

namespace ft
{
	template < class Key,                                  // map::key_type
			class T,                                       // map::mapped_type
			class Compare = less<Key>,                     // map::key_compare
			class Alloc = allocator<pair<const Key,T> >    // map::allocator_type
			>
	class map
	{
		public:
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef ft::pair<const key_type, mapped_type>	value_type;
			typedef Compare									key_compare;
			typedef Alloc									allocator_type;
			typedef allocator_type::reference				reference;
			typedef allocator_type::const_reference			const_reference;
			typedef allocator_type::pointer					pointer;
			typedef allocator_type::const_pointer			const_pointer;
			typedef allocator_type::difference_type			difference_type;
			typedef allocator_type::size_type				size_type;
		
		public:
			class value_compare
			{
				friend class map;
				protected:
					Compare _comp;
					value_compare (Compare c) : _comp(c) {}  // constructed with map's comparison object
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return _comp(x.first, y.first);
					};
			};
		
		public: //constructor
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
					_tree(comp, alloc), _alloc(alloc), _comp(comp) {};
			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
					_tree(comp, alloc), _alloc(alloc), _comp(comp) { insert(first, last); };
			map (const map& x) { *this = x; };

		public: //destructor
			~map() { this->_tree.clear(); };

		public: //operator=

		public: //iterators

		public: //capacity

		public: //Element access

		public: //Modifiers

		public: //Observers

		public: //Operations

		public: //Allocator:

		// public: //relational operators:

		// public: //Swap:


	}
	
}

#endif