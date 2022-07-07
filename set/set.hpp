#pragma once

# include "setTree.hpp"
#include "../vector/utils.hpp"

namespace ft
{
	template < class T, class Compare = std::less<T>, class Alloc = std::allocator<T> > class set
	{
		public:
			typedef T													key_type;
			typedef T													value_type;
			typedef Compare												key_compare;
			typedef Compare												value_compare;
			typedef Alloc													allocator_type;

			typedef typename Alloc::pointer									pointer;
			typedef typename Alloc::const_pointer							const_pointer;
			typedef typename Alloc::reference								reference;
			typedef typename Alloc::const_reference							const_reference;
			typedef typename Alloc::size_type								size_type;
			typedef typename Alloc::difference_type							difference_type;

			typedef setTree<value_type, value_compare, allocator_type>		tree;
			typedef typename tree::iterator								iterator;
			typedef typename tree::const_iterator						const_iterator;
			typedef typename tree::reverse_iterator						reverse_iterator;
			typedef typename tree::const_reverse_iterator				const_reverse_iterator;

		private:
			value_compare	_comp;
			allocator_type	_alloc;
			tree			_tree;

		public: //constr and destr
			explicit set (const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()):
				_comp(comp), _alloc(alloc), _tree(comp, alloc) {}
				
			template <class InputIterator>
			set (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()):
				_comp(comp), _alloc(alloc), _tree(first, last, comp, alloc) {}
				
			set (const set& x): _comp(x._comp), _alloc(x._alloc), _tree(x._tree) {}

			set& operator= (const set& x) {
				if (this != &x)
					_tree = x._tree;
				return *this;
			}

			~set() {}

		public: //iterators
			iterator begin() { return _tree.begin(); };
			const_iterator begin() const { return _tree.begin(); };
			iterator end() { return _tree.end(); };
			const_iterator end() const { return _tree.end(); };
			reverse_iterator rbegin() { return _tree.rbegin(); };
			const_reverse_iterator rbegin() const { return _tree.rbegin(); };
			reverse_iterator rend() { return _tree.rend(); };
			const_reverse_iterator rend() const { return _tree.rend(); };

		public: //capacity
			bool empty() const { return _tree.empty(); };
			size_type size() const { return _tree.size(); };
			size_type max_size() const { return _tree.max_size(); };

		public: //modifiers
			pair<iterator,bool> insert (const value_type& val) {
				return _tree.insert(val);
			};

			iterator insert (iterator position, const value_type& val) {
				return _tree.insert(position, val);
			};

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last) {
				_tree.insert(first, last);
			};

			void erase (iterator position) {
				_tree.erase(position);
			};
			
			size_type erase (const value_type& val) {
				return _tree.erase(val);
			};
			
			void erase (iterator first, iterator last) {
				_tree.erase(first, last);
			};

			void swap (set& x) { _tree.swap(x._tree); };

			void clear() { _tree.clear(); };

		public: //observers
			key_compare key_comp() const { return (this->_comp); };

			value_compare value_comp() const { return (value_compare(_comp)); }

		public: //operations
			iterator find(const value_type& val) {
				return _tree.find(val);
			};
			const_iterator find(const value_type& val) const {
				return _tree.find(val);
			};

			size_type count (const value_type& val) const {
				return _tree.count(val);
			};

			iterator lower_bound (const value_type& val) {
				return (this->_tree.lower_bound(val));
			};

			iterator upper_bound (const value_type& val) {
				return (this->_tree.upper_bound(val));
			};

			ft::pair<iterator, iterator> equal_range(const value_type& val) {
				return _tree.equal_range(val);
			};

		public: //allocator
			allocator_type get_allocator() const {
				return allocator_type();
			};

		public:
			template< class Key, class C, class A >
			friend bool operator==( const set<Key,C,A>& lhs,
				const set<Key,C,A>& rhs );
			template< class Key, class C, class A >
			friend bool operator<( const set<Key,C,A>& lhs,
                const set<Key,C,A>& rhs );
	};

	template< class Key, class Compare, class Alloc >
	bool operator==( const set<Key,Compare,Alloc>& lhs,
		const set<Key,Compare,Alloc>& rhs ) {
			return lhs._tree == rhs._tree;
		};
	template< class Key, class Compare, class Alloc >
	bool operator!=( const set<Key,Compare,Alloc>& lhs,
        const set<Key,Compare,Alloc>& rhs ) {
			return !(lhs == rhs);
		};
	template< class Key, class Compare, class Alloc >
	bool operator<( const set<Key,Compare,Alloc>& lhs,
        const set<Key,Compare,Alloc>& rhs ) {
			return lhs._tree < rhs._tree;
		};
	template< class Key, class Compare, class Alloc >
	bool operator<=( const set<Key,Compare,Alloc>& lhs,
        const set<Key,Compare,Alloc>& rhs ) {
			return !(rhs < lhs);
		};
	template< class Key, class Compare, class Alloc >
	bool operator>( const set<Key,Compare,Alloc>& lhs,
        const set<Key,Compare,Alloc>& rhs ) {
			return rhs < lhs;
		};
	template< class Key, class Compare, class Alloc >
	bool operator>=( const set<Key,Compare,Alloc>& lhs,
        const set<Key,Compare,Alloc>& rhs ) {
			return !(lhs < rhs);
		};

	template< class Key, class Compare, class Alloc >
	void swap( set<Key,Compare,Alloc>& lhs,
		set<Key,Compare,Alloc>& rhs ) { lhs.swap(rhs); };

};
