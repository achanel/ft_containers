#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template <class T1, class T2>
	struct pair
	{
		typedef T1	first_type;
		typedef T2	second_type;

		first_type	first;
		second_type	second;

		explicit pair(): first(), second() {};
		template<class U, class V>
		pair (const pair<U, V>& pr): first(pr.first), second(pr.second) {};
		pair (const first_type& a, const second_type& b): first(a), second(b) {};

		template<class U, class V>
		pair<U, V>& operator= (const pair<U, V>& pr)
		{
			if (this != &pr)
			{
				this->first = pr.first;
				this->second = pr.second;
			}
			return (*this);
		};
	};
	
	template< class T1, class T2 >
	bool operator==( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}
	template< class T1, class T2 >
	bool operator!=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{
		return !(lhs == rhs);
	}
	template< class T1, class T2 >
	bool operator<( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{
		return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second<rhs.second);
	}
	template< class T1, class T2 >
	bool operator<=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{
		return !(rhs<lhs);
	}
	template< class T1, class T2 >
	bool operator>( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{
		return rhs<lhs;
	}
	template< class T1, class T2 >
	bool operator>=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
	{
		return !(lhs<rhs);
	}

	template <class T1, class T2>
	ft::pair<T1,T2> make_pair (T1 x, T2 y)
	{
		return (ft::pair<T1, T2>(x,y));
	}
};

#endif