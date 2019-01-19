#include "ArrayList.cpp"
#include "HashSet.cpp"
#include "LinkedList.cpp"
#include <string>
using namespace COLLECTION;
int main(){
    /*LinkedList<int,list<int>>sample;
    sample.add(10);
    sample.add(10);
    sample.add(20);
    sample.add(30);
    sample.add(40);
    sample.add(80);
    sample.printAll();
    cout<<endl;

    LinkedList<int,list<int>>sample2;
    sample2.add(10);
    sample2.add(80);
    sample2.add(110);
    sample2.add(120);
    sample2.printAll();

    cout<<endl;
    //sample.addAll(sample2);
    //sample.clear();
    //sample.add(10);
    //cout<<sample.contains(1)<<' '<<sample.contains(10)<<endl;
    //cout<<sample.containsAll(sample2)<<endl;
    //sample.removeAll(sample2);
    sample.retainAll(sample2);
    sample.printAll();*/

    cout<<"\n\n****TESTING 'HashSet' FOR INT****"<<endl;
    HashSet<int> sample7;
    sample7.add(3);
    sample7.add(5);
    sample7.add(7);
    sample7.add(2);
    sample7.add(20);

    HashSet<int> sample8;
    sample8.add(5);
    sample8.add(2);
    sample8.add(10);
    sample8.add(35);

    cout<<"sample7:"<<endl;
    sample7.printAll();
    cout<<"\nsample8:"<<endl;
    sample8.printAll();
    cout<<"\nAfter the addAll():"<<endl;
    sample7.addAll(sample8);
    sample7.printAll();
    cout<<"\nafter the removeAll() added sample7 and sample8:"<<endl;
    sample7.removeAll(sample8);
    sample7.printAll();
    cout<<"\nremove() '3' to sample7 and contains() for '3' and size():"<<endl;
    sample7.remove(3);
    sample7.printAll();
    cout<<"\nContains() '3'?:"<<sample7.contains(3)<<endl;
    cout<<"sample7 size:"<<sample7.size()<<endl;
    cout<<"ContainsAll() for itself:"<<sample7.containsAll(sample7)<<endl;
    cout<<"RetainAll() sample7 and sample8:"<<endl;
    sample7.retainAll(sample8);
    sample7.add(0);
    sample7.printAll();
    cout<<"\nClear the sample7 and isEmpty():";
    sample7.clear();
    cout<<sample7.isEmpty();






    return 0;
}
