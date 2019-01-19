#ifndef QUEUE_H
#define QUEUE_H
#include "Collection.h"

namespace COLLECTION{
    template<typename E,typename container=list<E> >
    class Queue : virtual public Collection<E,container>{//Because of the multiple inheritence I put the virtual tag
    public:
        Queue()noexcept:Collection<E,container>(){}
        virtual Iterator<E,container> iterator()noexcept=0;
        virtual bool addAll(Collection<E,container>& c)throw(MyException)=0;
        virtual void clear()noexcept=0;
        virtual bool contains(E e)noexcept=0;
        virtual bool containsAll(Collection<E,container>& c)noexcept=0;
        virtual bool isEmpty()const noexcept=0;
        virtual bool remove(E e)throw(MyException)=0;
        virtual bool removeAll(Collection<E,container>& c)throw(MyException)=0;
        virtual bool retainAll(Collection<E,container>& c)throw(MyException)=0;
        virtual int size()const noexcept=0;

        //added functions
        virtual bool add(E e)noexcept=0;
        virtual E element()noexcept=0;
        virtual bool offer(E e)noexcept=0;
        virtual E poll()throw(MyException)=0;
        virtual ~Queue(){}//because of the abstract base class
    };

}

#endif
