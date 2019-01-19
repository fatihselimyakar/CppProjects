#ifndef HASHSET_H
#define HASHSET_H

#include"Set.h"
namespace COLLECTION{
    template<typename E,typename container=set<E> >
    class HashSet : public Set<E,container>{//defulted std::set
    public:
        HashSet()noexcept;
        virtual Iterator<E,container> iterator()noexcept override;
        virtual bool add(E e)noexcept override;
        virtual bool addAll(Collection<E,container>& c)throw(MyException) override;
        virtual void clear()noexcept override;
        virtual bool contains(E e)noexcept override;
        virtual bool containsAll(Collection<E,container>& c)noexcept override;
        virtual bool isEmpty()const noexcept override;
        virtual bool remove(E e)throw(MyException) override;
        virtual bool removeAll(Collection<E,container>& c)throw(MyException) override;
        virtual bool retainAll(Collection<E,container>& c)throw(MyException) override;
        virtual int size()const noexcept override;

        //My added print function for test and getter
        container getCont()const noexcept;
        void printAll() noexcept;
    private:
        container Container;
    };
}


#endif
