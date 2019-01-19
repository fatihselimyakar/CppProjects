#ifndef COLLECTION_H
#define COLLECTION_H
#include "Iterator.cpp"

namespace COLLECTION{

    template<typename E,typename container=vector<E> >//defulted vector but based on concrete class'es entered template container
    class Collection{
    public:
        Collection()noexcept{}
        virtual Iterator<E,container> iterator()noexcept =0;
        virtual bool add(E e)noexcept=0;
        virtual bool addAll(Collection<E,container>& c)throw(MyException)=0;
        virtual void clear()noexcept=0;//for the abstract base class
        virtual bool contains(E e)noexcept=0;
        virtual bool containsAll(Collection<E,container>& c)noexcept=0;
        virtual bool isEmpty()const noexcept=0;
        virtual bool remove(E e)throw(MyException)=0;
        virtual bool removeAll(Collection<E,container>& c)throw(MyException)=0;
        virtual bool retainAll(Collection<E,container>& c)throw(MyException)=0;
        virtual int size()const noexcept=0;

        //for the abstract base class
        virtual ~Collection(){}
    };

}


#endif
