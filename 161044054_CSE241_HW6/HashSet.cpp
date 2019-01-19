#include "HashSet.h"

namespace COLLECTION{
    //call the parent classes constructor in it and construct the object
    template<typename E,typename container>
    HashSet<E,container>::HashSet()noexcept:Set<E,container>(){ }

    //generate a new Iterator<E,container> and return this
    template<typename E,typename container>
    Iterator<E,container> HashSet<E,container>::iterator()noexcept{ Iterator<E,container>it(Container); return it; }

    //adds the new e int Container via std::'s insert functions
    template<typename E,typename container>
    bool HashSet<E,container>::add(E e)noexcept{
        if(contains(e))//FOR THE NO DUPLİCATE ELEMENTS İN THE SET
            return false;
        Iterator<E,container> it=iterator();
        Container.insert(it.getIterator(),e);
        return true;
    }

    //I provide the all c element adds via add() function and for loop
    template<typename E,typename container>
    bool HashSet<E,container>::addAll(Collection<E,container>& c)throw(MyException){
        if(c.isEmpty()){
            throw MyException("ADALL FUNCTION ERROR");
            return false;
        }//if 'c' is empty return false
        else{
            //with the for loop I add() the new values then return true
            Iterator<E,container>itTemp = c.iterator();
            for(int i=0;i<c.size();i++){
                add(*(itTemp.getIterator()));
                if(i!=c.size()-1)
                    itTemp.next();
            }
            return true;
        }
    }

    //I clear the all of elements via std::'s clear() function
    template<typename E,typename container>
    void HashSet<E,container>::clear()noexcept{ Container.clear(); }//Sıkıntı çıkarabilir

    //I use normal for loop and if equal to each other then I return the true statement
    template<typename E,typename container>
    bool HashSet<E,container>::contains(E e)noexcept{
        Iterator<E,container>itTemp(Container);
        for(int i=0;i<Container.size();i++){
            if(*itTemp.getIterator()==e)
                return true;
            if(i!=Container.size()-1)
                itTemp.next();
        }
        return false;
    }

    //I control the all element with my typed contains function via while loop
    template<typename E,typename container>
    bool HashSet<E,container>::containsAll(Collection<E,container>& c)noexcept{
        Iterator<E,container> it = c.iterator();
        while (it.hasNext())
            if(!contains(it.next()))
                return false;

        return true;

    }

    //I use the std::'s empty function
    template<typename E,typename container>
    bool HashSet<E,container>::isEmpty()const noexcept{ return Container.empty(); }

    //I use the control all element and find with my iterator and remove this with std::'s erase function
    template<typename E,typename container>
    bool HashSet<E,container>::remove(E e)throw(MyException){
        if(contains(e)){
            Iterator<E,container>itTemp(Container);
            for(int i=0;i<Container.size();++i){
                if(*itTemp.getIterator()==e){
                    Container.erase(itTemp.getIterator());
                    return true;
                }
                if(i!=Container.size())
                    itTemp.next();
            }
        }
        throw MyException("REMOVE FUNCTION ERROR");
        return false;
    }

    //I control the the container by all of loop and if controlled elements are the same I remove my typed remove function
    template<typename E,typename container>
    bool HashSet<E,container>::removeAll(Collection<E,container>& c)throw(MyException){
        if(c.isEmpty()){
            throw MyException("REMOVEALL FUNCTION ERROR");
            return false;
        }
        else{
            Iterator<E,container>itTemp=c.iterator();
            for(int i=0;i<c.size();++i){
                if(contains(*itTemp.getIterator()))
                    remove(*(itTemp.getIterator()));
                if(i!=c.size()-1)
                    itTemp.next();
            }
            return true;
        }
    }

    //I control all of elements in member conteiner and if contains then add my temp container and assign the member container
    template<typename E,typename container>
    bool HashSet<E,container>::retainAll(Collection<E,container>& c)throw(MyException){
        if(c.isEmpty()==1){
            throw MyException("RETAINALL FUNCTION ERROR");
        }
        bool result=false;
        container temp;
        Iterator<E,container>itTemp=c.iterator();
        while(itTemp.hasNext()){
            if(contains(*itTemp.getIterator())){
                temp.insert(temp.begin(),*itTemp.getIterator());
                result=true;
            }
            itTemp.next();
        }
        if(contains(*itTemp.getIterator())){
            temp.insert(temp.begin(),*itTemp.getIterator());
            result=true;
        }
        Container=temp;
        return result;

   }

    //I use the std::'s size() function
    template<typename E,typename container>
    int HashSet<E,container>::size()const noexcept{ return Container.size(); }

    template<typename E,typename container >
    container HashSet<E,container>::getCont()const noexcept{ return Container; }

    //MY ADDED FUNCTIONS
    template<typename E,typename container >
    void HashSet<E,container>::printAll() noexcept{
        if(isEmpty())
            cout<<"This container is empty.";
        else{
            Iterator<E,container> it = iterator();
            while (it.hasNext()){
                cout<<*it.getIterator()<<' ';
                it.next();
            }
            cout<<*it.getIterator()<<' ';
        }
    }
}
