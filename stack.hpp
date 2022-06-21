#ifndef STACK_HPP
# define STACK_HPP

#include <vector>

namespace ft
{
	template <class T, class Container = std::vector<T> >
	class stack
	{
		public:
			typedef T			value_type;
			typedef	Container	container_type;
			typedef typename	container_type::size_type	size_type;

		protected:
			container_type	_container;
		
		public:
			bool empty() const	{ return !_container.size();};
			size_type size() const	{ return _container.size();};
			value_type& top()	{return _container.back();};
			const value_type& top() const	{return _container.back();};
			void push (const value_type& val)	{_container.push_back(val);};
			void pop()	{_container.pop_back();};

		protected:
			template <class _T, class _C>
				friend bool operator== (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs);
			template <class _T, class _C>
				friend bool operator!= (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs);
			template <class _T, class _C>
				friend bool operator<  (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs);
			template <class _T, class _C>
				friend bool operator<= (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs);
			template <class _T, class _C>
				friend bool operator>  (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs);
			template <class _T, class _C>
				friend bool operator>= (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs);
	};

	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._container == rhs._container);
	}
	
	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._container != rhs._container);
	}
	
	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._container < rhs._container);
	}
	
	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._container <= rhs._container);
	}
	
	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._container > rhs._container);
	}
	
	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._container >= rhs._container);
	}
}

#endif