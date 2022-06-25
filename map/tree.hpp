#ifndef TREE_HPP
# define TREE_HPP

# include "iterator.hpp"
# include <memory>

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

    template <class T, class Compare, class Allocator = std::allocator<T> >
    class Tree
    {
        public: //typedef all template parameters 
            typedef T           value_type;
            typedef Compare     key_compare;
            typedef Allocator   allocator_type;
        
        private: //typedef member Types of Nodes
            typedef typename allocator_type::template rebind<Node<T> >::other   allocator_node;
            typedef typename allocator_node::reference				                    node_reference;
			typedef typename allocator_node::const_reference			                    node_const_reference;
			typedef typename allocator_node::pointer					                    node_pointer;
			typedef typename allocator_node::const_pointer			                    node_const_pointer;
			typedef typename allocator_node::difference_type			                    node_difference_type;
			typedef typename allocator_node::size_type				                    node_size_type;
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
        
        private: //Declare all attributes needed in Tree
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
            iterator begin()                { return(iterator(Min())); };
            const_iterator begin() const    { return(const_iterator(Min())); };
            iterator end()					{ return (iterator(this->_end)); };
			const_iterator end() const		{ return (const_iterator(this->_end)); };
			reverse_iterator rbegin()		{ return (reverse_iterator(end())); };
			const_reverse_iterator rbegin() const	{ return (const_reverse_iterator(end())); };
			reverse_iterator rend()			{ return (reverse_iterator(begin())); };
			const_reverse_iterator rend() const		{ return (const_reverse_iterator(begin())); };

        public: //Capacity
            bool empty() const { return (this->_size == 0); };
            size_type size() const { return (this->_size); };
            size_type max_size() const
            {
                return (std::min<size_type>(std::numeric_limits<size_type>::max() / sizeof(Node_type), std::numeric_limits<difference_type>::max()));
            }

        private:
            void    _destroy(Node_ptr node)
            {
                if (node != nullptr)
                {
                    _destroy(node->left);
                    _destroy(node->right);
                    this->_alloc.destroy(node);
                    this->_alloc.deallocate(node, 1);
                }
            };
            Node_ptr _makeNode(value_type key)
            {
                Node_ptr newnode = this->_alloc.allocate(1);
                this->_alloc.construct(newnode, key);
                newnode->height = 1;
                newnode->parent = nullptr;
                newnode->left = nullptr;
                newnode->right = nullptr;
                return (newnode);
            };
            void    _deleteNode(Node_ptr* node)
            {
                this->_alloc.destroy(*node);
                this->_alloc.deallocate(*node, 1);
                *node = nullptr;
            };
            int     _Height(Node_ptr temp)
            {
                if (temp = nullptr)
                    return (0);
                return (temp->height);
            };
            int     _getBalanceFactor(Node_ptr N)
            {
                if (N == NULL)
                    return (0);
                return (_Height(N->left) - _Height(N->right));
            };
            Node_ptr    _leftRotate(Node_ptr x)
            {
                Node_ptr y = x->right;
                Node_ptr T2 = y->left;
                Node_ptr p = x->parent;
                y->left = x;
                x->right = T2;
                if (p != this->_end)
                {
                    if (p->left == x)
                        p->left = y;
                    else
                        p->right = y;
                }
                y->parent = x->parent;
                x->parent = y;
                if (T2 != nullptr)
                    T2->parent = x;
                x->height = std::max(_Height(x->left), _Height(x->right)) + 1;
                y->height = std::max(_Height(y->left), _Height(y->right)) + 1;
                return y;
            };
            Node_ptr    _rightRotate(Node_ptr parent)
            {
                Node_ptr child = parent->left;
                Node_ptr T2 = child->right;
                Node_ptr p = parent->parent;
                child->left = T2;
                if (p != this->_end)
                {
                    if (p->right == parent)
                        p->right = child;
                    else
                        p->left = child;
                }
                child->parent = parent->parent;
                parent->parent = child;
                if (T2 != nullptr)
                    T2->parent = parent;
                parent->height = std::max(_Height(parent->left), _Height(parent->right)) + 1;
                child->height = std::max(_Height(child->left), _Height(child->right)) + 1;
                return child;
            };
            Node_ptr _RightLeftRotate(Node_ptr node)
            {
                node->right = _rightRotate(node->right);
                return (_leftRotate(node));
            };
            Node_ptr _LeftRightRotate(Node_ptr node)
            {
                node->left = _leftRotate(node->left);
                return (_rightRotate(node));
            };
            Node_ptr    _reBalance(Node_ptr node)
            {
                int balancefactor = _getBalanceFactor(node);
                if (balancefactor > 1)
                {
                    if (_getBalanceFactor(node->left) >= 0)
                        return (_rightRotate(node));
                    else
                        return (_LeftRightRotate(node));
                }
                else if (balancefactor < -1)
                {
                    if (_getBalanceFactor(node->right) <= 0)
                        return (_leftRotate(node))
                    else
                        return (_RightLeftRotate(node));
                }
                return (node);
            };
            Node_ptr    _insert(Node_ptr temp, Node_ptr newNode)
            {
                if (temp == nullptr || temp == this->_end)
                    return (newNode);
                if (!this->_comp(temp->key.first, newNode->key.first))
                {
                    temp->left = _insert(temp->left, newNode);
                    if (temp->left == newNode)
                        newNode->parent = temp;
                }
                else if (this->_comp(temp->key.first, newNode->key.first))
                {
                    temp->right = _insert(temp->right, newNode);
                    if (temp->right == newNode)
                        newNode->parent = temp;
                }
                else
                    return temp;
                _ReSetHeight(temp);
                temp = _reBalance(temp);
                return temp;
            };
            Node_ptr    _remove(Node_ptr root, T key)
            {
                if (root = nullptr) return (nullptr);
                else if (this->_comp(key.first, root->key.first))
                    root->left = _remove(root->left, key);
                else if (this->_comp(root->key.first, key.first))
                    root->right = _remove(root->right, key);
                else
                {
                    if (root->left == nullptr && root->right == nullptr)
                    {
                        this->_alloc.destroy(root);
                        this->_alloc.deallocate(root, 1);
                        root = nullptr;
                        return (root);
                    }
                    else if (root->left == nullptr)
                    {
                        Node_ptr    temp = root;
                        root = root->right;
                        root->parent = temp->parent;
                        this->_alloc.destroy(temp);
                        this->_alloc.deallocate(temp, 1);
                        temp = nullptr;
                        return (root);
                    }
                    else if (root->right == nullptr)
                    {
                        Node_ptr    temp = root;
                        root = root->left;
                        root->parent = temp->parent;
                        this->_alloc.destroy(temp);
                        this->_alloc.deallocate(temp, 1);
                        temp = nullptr;
                        return (root);
                    }
                    else
                    {
                        Node_ptr    temp = _TreeMin(root->right);
                        value_type  p = temp->key;
                        root->right = _remove(root->right, temp->key);
                        this->_alloc.construct(root, p);
                    }
                }
                _ReSetHeight(root);
                root = _reBalance(root);
                return (root);
            };
            Node_ptr    _search(Node_ptr temp, key_type key) const
            {
                if (temp == nullptr)
                    return (this->_end);
                if (temp->key.first == key)
                    return (temp);
                else if (this->_comp(key, temp->key.first))
                    return (_search(temp->left, key));
                else if (this->_comp(temp->key.first, key))
                    return(_search(temp->right, key));
                return (this->_end);
            };
            void    _ReSetHeight(Node_ptr temp)
            {
                if(!temp->left && !temp->right)
                    temp->height = 1;
                else if (temp->left == nullptr)
                    temp->height = 1 + temp->right->height;
                else if (temp->right == nullptr || temp->right == this->_end)
                    temp->height = 1 + temp->left->height;
                else
                    temp->height = 1 + std::max(temp->right->height, temp->left->height);
            };

        public:
            Node_ptr    insert(value_type key)
            {
                Node_ptr newnode = _makeNode(key);
                if (this->_root == this->_end)
                {
                    this->_root = newnode;
                    this->_root->parent = this->_end;
                    this->_end->left = this->_root;
                    ++this->_size;
                }
                else
                {
                    ++this->_size;
                    this->_root = _insert(this->_root, newnode);
                }
                return (newnode);
            };
            Node_ptr	insertInPossition(Node_ptr position, T key)
            {

            };
            
    };
};


#endif