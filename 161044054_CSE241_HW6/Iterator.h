#ifndef ITERATOR_H
#define ITERATOR_H
#include<iostream>
#include <vector>
#include <list>
#include <set>
using namespace std;


namespace COLLECTION{
    //My generated exception class derived from 'exception' class
    class MyException:public exception{
    public:
        MyException():str("ERROR OCCURED"){/*empty*/}
        MyException(string a):str(a){/*empty*/}
        virtual const char* what()const noexcept override final{
            return str.c_str();
        }
    private:
        string str;
    };

    //Iterator class defaulted vector
    template<typename E,typename container=vector<E> >
    class Iterator{
    public:
        Iterator()noexcept{}
        Iterator(container &c)noexcept;
        bool hasNext() noexcept;
        E next()throw(MyException);
        E back()noexcept;
        void remove()noexcept;
        typename container::iterator getIterator()noexcept;
        typename container::iterator getIteratorEnd()noexcept;

    private:
        typename container::iterator it;//I keep the normal iterator in Iterator class
        typename container::iterator itEnd;//I keep the end iterator in Iterator class
        container cont;//for hashnext's finding


    };
}
#endif
