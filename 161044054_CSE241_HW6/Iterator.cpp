#include "Iterator.h"

namespace COLLECTION{
    //in constructing I get the starting iterator and container
    template<typename E,typename container>
    Iterator<E,container>::Iterator(container &c)noexcept{
        it=c.begin();
        itEnd=c.end();
        cont=c;
    }

    // I bring the iterator end of the element and controlled
    template<typename E,typename container>
    bool Iterator<E,container>::hasNext()noexcept{
        bool result=(++it)!=(itEnd);
        --it;
        return result;
    }

    //if hasnext true then there is a next element
    template<typename E,typename container>
    E Iterator<E,container>::next()throw(MyException){
        if(hasNext()==1)
            ++it;
        else
            throw MyException("ERROR ITERATOR IS UNVALID");
        return *it;
    }

    //My added function for sometimes bring the iterator back
    template<typename E,typename container>//DENEMEE
    E Iterator<E,container>::back()noexcept{
        --it;
        return *it;
    }

    //I used normal stl container's erase function
    template<typename E,typename container >
    void Iterator<E,container>::remove()noexcept{
        cont.erase(it);
    }

    //getter
    template<typename E,typename container>
    typename container::iterator Iterator<E,container>::getIterator()noexcept{
        return it;
    }

    template<typename E,typename container>
    typename container::iterator Iterator<E,container>::getIteratorEnd()noexcept{
        return itEnd;
    }
}
