#include <vector>
#include <map>
#include <stack>
#include <exception>
#include <utility>
#include <set>
#include "vector/utils.hpp"
#include "set/set.hpp"
#include "stack.hpp"
#define NEXTD std::cout << "<---------- ---------- ---------- ---------- ---------- ----------|---------- ---------- ---------- ---------- ---------- ----------|" << std::endl

#ifndef PH
#define PH ft
#endif

bool fncomp (int lhs, int rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs<rhs;}
};

int main()
{
	{
		PH::set<int> first;                           // empty set of ints

        int myints[]= {10,20,30,40,50};
        PH::set<int> second (myints,myints+5);        // range

        PH::set<int> third (second);                  // a copy of second

        PH::set<int> fourth (second.begin(), second.end());  // iterator ctor.

        PH::set<int,classcomp> fifth;                 // class as Compare

        bool(*fn_pt)(int,int) = fncomp;
        PH::set<int,bool(*)(int,int)> sixth (fn_pt);  // function pointer as Compare

	}
	{
        int myints[]={ 12,82,37,64,15 };
        PH::set<int> first (myints,myints+5);   // set with 5 ints
        PH::set<int> second;                    // empty set

        second = first;                          // now second contains the 5 ints
        // first = PH::set<int>();                 // and first is empty

        std::cout << "Size of first: " << int (first.size()) << '\n';
        std::cout << "Size of second: " << int (second.size()) << '\n';
	}
	NEXTD;
	{
        int myints[] = {75,23,65,42,13};
        PH::set<int> myset (myints,myints+5);

        std::cout << "myset contains:";
        for (PH::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
        std::cout << ' ' << *it;

        std::cout << '\n';
	}
	NEXTD;
	{
        PH::set<int> myset;

        myset.insert(20);
        myset.insert(30);
        myset.insert(10);

        std::cout << "myset contains:";
        while (!myset.empty())
        {
            std::cout << ' ' << *myset.begin();
            myset.erase(myset.begin());
        }
        std::cout << '\n';
	}
	NEXTD;
	{
        PH::set<int> myset;
        PH::set<int>::iterator it;
        PH::pair<PH::set<int>::iterator,bool> ret;

        // set some initial values:
        for (int i=1; i<=5; ++i) myset.insert(i*10);    // set: 10 20 30 40 50

        ret = myset.insert(20);               // no new element inserted

        if (ret.second==false) it=ret.first;  // "it" now points to element 20

        myset.insert (it,25);                 // max efficiency inserting
        myset.insert (it,24);                 // max efficiency inserting
        myset.insert (it,26);                 // no max efficiency inserting

        int myints[]= {5,10,15};              // 10 already in set, not inserted
        myset.insert (myints,myints+3);

        std::cout << "myset contains:";
        for (it=myset.begin(); it!=myset.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
	}
	NEXTD;
	{
        PH::set<int> myset;
        PH::set<int>::iterator it;

        // set some initial values:
        for (int i=1; i<=5; i++) myset.insert(i*10);    // set: 10 20 30 40 50

        it=myset.find(20);
        myset.erase (it);
        myset.erase (myset.find(40));

        std::cout << "myset contains:";
        for (it=myset.begin(); it!=myset.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
	}
	NEXTD;
	{
        PH::set<int> myset;

        // set some initial values:
        for (int i=1; i<5; ++i) myset.insert(i*3);    // set: 3 6 9 12

        for (int i=0; i<10; ++i)
        {
            std::cout << i;
            if (myset.count(i)!=0)
            std::cout << " is an element of myset.\n";
            else
            std::cout << " is not an element of myset.\n";
        }
	}
	NEXTD;
	{
        int myints[]={12,75,10,32,20,25};
        PH::set<int> first (myints,myints+3);     // 10,12,75
        PH::set<int> second (myints+3,myints+6);  // 20,25,32

        first.swap(second);

        std::cout << "first contains:";
        for (PH::set<int>::iterator it=first.begin(); it!=first.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';

        std::cout << "second contains:";
        for (PH::set<int>::iterator it=second.begin(); it!=second.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
	}
	NEXTD;
	{
        PH::set<int> myset;

        myset.insert (100);
        myset.insert (200);
        myset.insert (300);

        std::cout << "myset contains:";
        for (PH::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';

        myset.clear();
        myset.insert (1101);
        myset.insert (2202);

        std::cout << "myset contains:";
        for (PH::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
	}
	NEXTD;
	{
        PH::set<int> myset;
        PH::set<int>::iterator itlow,itup;

        for (int i=1; i<10; i++) myset.insert(i*10); // 10 20 30 40 50 60 70 80 90

        itlow=myset.lower_bound (30);                //       ^
        itup=myset.upper_bound (60);                 //                   ^

        myset.erase(itlow,itup);                     // 10 20 70 80 90

        std::cout << "myset contains:";
        for (PH::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
	}
	NEXTD;
	{
        PH::set<int> myset;

        for (int i=1; i<=5; i++) myset.insert(i*10);   // myset: 10 20 30 40 50

        PH::pair<PH::set<int>::const_iterator,PH::set<int>::const_iterator> ret;
        ret = myset.equal_range(30);

        std::cout << "the lower bound points to: " << *ret.first << '\n';
        std::cout << "the upper bound points to: " << *ret.second << '\n';
	}
	NEXTD;
	{
        PH::set<int> myset;
        int * p;
        unsigned int i;

        // allocate an array of 5 elements using myset's allocator:
        p=myset.get_allocator().allocate(5);

        // assign some values to array
        for (i=0; i<5; i++) p[i]=(i+1)*10;

        std::cout << "The allocated array contains:";
        for (i=0; i<5; i++) std::cout << ' ' << p[i];
        std::cout << '\n';

        myset.get_allocator().deallocate(p,5);
	}
}