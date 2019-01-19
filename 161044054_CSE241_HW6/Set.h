#ifndef SET_H
#define SET_H
#include "Collection.h"

namespace COLLECTION{
    template<typename E,typename container=vector<E> >
    class Set : public Collection<E,container>{
    public:
        Set()noexcept:Collection<E,container>(){}
        virtual Iterator<E,container> iterator()noexcept=0;
        virtual bool add(E e)noexcept=0;//container tipindede return verebilir.
        virtual bool addAll(Collection<E,container>& c)throw(MyException)=0;
        virtual void clear()noexcept=0;
        virtual bool contains(E e)noexcept=0;
        virtual bool containsAll(Collection<E,container>& c)noexcept=0;
        virtual bool isEmpty()const noexcept=0;
        virtual bool remove(E e)throw(MyException)=0;
        virtual bool removeAll(Collection<E,container>& c)throw(MyException)=0;
        virtual bool retainAll(Collection<E,container>& c)throw(MyException)=0;
        virtual int size()const noexcept=0;
        virtual ~Set(){}//because of the abstract base class
    };
}

#endif
