#ifndef TREE_HPP
# define TREE_HPP

# include "iterator.hpp"

namespace ft
{
    template <class T>
    struct Node
    {
        public:
            typedef T   value_type;
        public:
            T       key;
            Node*   parent;
            Node*   left;
            Node*   right;
            int     height;
        public:
            Node(): key() {};
            Node(T, key): key(key){};
    };

    template <class T, class Compare, class Allocator>
    class Tree
    {
        public: //typedef all template parameters 
            typedef T;
            typedef Compare;
            typedef Allocator;
        
        public: //typedef member Types of Nodes
            typedef typename allocator_type::template rebind<Node<T> >::other   allocator_node;
            typedef allocator_type::reference				                    node_reference;
			typedef allocator_type::const_reference			                    node_const_reference;
			typedef allocator_type::pointer					                    node_pointer;
			typedef allocator_type::const_pointer			                    node_const_pointer;
			typedef allocator_type::difference_type			                    node_difference_type;
			typedef allocator_type::size_type				                    node_size_type;
            typedef Node<value_type>                                            Node_type;
            typedef Node_type*                                                  Node_ptr;

        public: //typedef member Types of Tree iterator
            typedef typename allocator_type::reference				            reference;
			typedef typename allocator_type::const_reference			        const_reference;
			typedef typename allocator_type::pointer					        pointer;
			typedef typename allocator_type::const_pointer			            const_pointer;
			typedef typename allocator_type::difference_type			        difference_type;
			typedef typename allocator_type::size_type				            size_type;
            typedef typename value_type::first_type                             key_type;
            typedef typename value_type::second_type                            mapped_type;
            typedef ft::TreeIter<pointer, Node_ptr>                             iterator;
            typedef ft::TreeIter<const_pointer, Node_ptr>                       const_iterator;
            typedef ft::reverse_iterator<iterator>                              reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>                        const_reverse_iterator;
        
        public: //Declare all attributes needed in Tree
            allocator_node  _alloc;
            key_compare     _comp;
            Node_ptr        _root;
            Node_ptr        _end;
            int             _size

        public: //Tree constructor and distructor
            Tree(const key_compare &compare - key_compare(), const allocator_type& alloc = allocator_type()): _size(0), _comp(compare)
            {
                this->_alloc = alloc;
                this->_end = this->_makeNode(value_type());
                this->_root = this->_end;
            };
            ~Tree() {};

        public: //Iterators

        public: //Capacity

    };
};


#endif