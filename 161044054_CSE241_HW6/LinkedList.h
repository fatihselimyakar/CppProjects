#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "List.h"
#include "Queue.h"

namespace COLLECTION{
    template<typename E,typename container=list<E> >//defulted std::list
    class LinkedList : public List<E,container>,public Queue<E,container>{//Multiple inherited class
    public:
        LinkedList()noexcept;
        virtual Iterator<E,container> iterator()noexcept override;
        virtual bool addAll(Collection<E,container>& c)throw(MyException) override;
        virtual void clear()noexcept override;
        virtual bool contains(E e)noexcept override;
        virtual bool containsAll(Collection<E,container>& c)noexcept override;
        virtual bool isEmpty()const noexcept override;
        virtual bool remove(E e)throw(MyException) override;
        virtual bool removeAll(Collection<E,container>& c)throw(MyException) override;
        virtual bool retainAll(Collection<E,container>& c)throw(MyException) override;
        virtual int size()const noexcept override;

        //added functions
        virtual bool add(E e)noexcept override;
        virtual E element()noexcept override;
        virtual bool offer(E e)noexcept override;
        virtual E poll()throw(MyException) override;

        container getCont()const noexcept;
        void printAll() noexcept;
    private:
        container Container;
    };
}


#endif
