#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include "List.h"

namespace COLLECTION{
    template<typename E,typename container=vector<E> >
    class ArrayList : public List<E,container>{
    public:
        ArrayList()noexcept;
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

        //for the testing main addded function printAll and getter
        container getCont()const noexcept;
        void printAll()noexcept;
    private:
        container Container;
    };

}

#endif
