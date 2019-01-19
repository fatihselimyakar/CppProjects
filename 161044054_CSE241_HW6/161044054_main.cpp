#include "ArrayList.cpp"
#include "HashSet.cpp"
#include "LinkedList.cpp"
#include <string>
using namespace COLLECTION;
int main(){
    try{
        //Note:iterator() and Iterator<E,container>'s' functions are almost all function implement's in it,Because of this I don't test these in main.
        cout<<"****TESTING 'ArrayList' FOR STRING[container:std::vector(defaulted)]****"<<endl;
        //ARRAYLIST FUNCTIONS TEST
        ArrayList<string> sample;//add() function test
        sample.add("one");
        sample.add("one");
        sample.add("two");
        sample.add("three");
        sample.add("for");
        sample.add("eight");

        ArrayList<string> sample2;
        sample2.add("three");
        sample2.add("for");
        sample2.add("seven");
        sample2.add("eight");

        cout<<"Sample1:"<<endl;
        sample.printAll();
        cout<<"\nSample2:"<<endl;
        sample2.printAll();
        cout<<"\nAfter the addAll():"<<endl;
        sample.addAll(sample2);
        sample.printAll();
        cout<<"\nafter the removeAll() added sample and sample2:"<<endl;
        sample.removeAll(sample2);
        sample.printAll();
        cout<<"\nremove() 'two' to sample1 and contains() for 'two' and size():"<<endl;
        sample.remove("two");
        sample.printAll();
        cout<<"\nContains() 'one'?:"<<sample.contains("one")<<endl;
        cout<<"Sample1 size:"<<sample.size()<<endl;
        cout<<"ContainsAll() for itself:"<<sample.containsAll(sample)<<endl;
        cout<<"RetainAll() sample1 and sample2:"<<endl;
        sample.retainAll(sample2);//All element in sample have sample2 because of this the resılt is same "sample"
        sample.printAll();
        cout<<"\nClear the sample1 and isEmpty():";
        sample.clear();
        cout<<sample.isEmpty();

        cout<<"\n\n****TESTING 'ArrayList' FOR INT[container:std::vector(defaulted)]****"<<endl;
        ArrayList<int> sample3;//add() function test
        sample3.add(1);
        sample3.add(2);
        sample3.add(3);
        sample3.add(4);

        ArrayList<int> sample4;
        sample4.add(3);
        sample4.add(4);
        sample4.add(5);
        sample4.add(6);
        sample4.add(7);

        cout<<"sample3:"<<endl;
        sample3.printAll();
        cout<<"\nsample4:"<<endl;
        sample4.printAll();
        cout<<"\nAfter the addAll():"<<endl;
        sample3.addAll(sample4);
        sample3.printAll();
        cout<<"\nafter the removeAll() added sample3 and sample4:"<<endl;
        sample3.removeAll(sample4);
        sample3.printAll();
        cout<<"\nremove() '1' to sample3 and contains() for '1' and size():"<<endl;
        sample3.remove(1);
        sample3.printAll();
        cout<<"\nContains() '1'?:"<<sample3.contains(1)<<endl;
        cout<<"sample3 size:"<<sample3.size()<<endl;
        cout<<"ContainsAll() for itself:"<<sample3.containsAll(sample3)<<endl;
        cout<<"RetainAll() sample3 and sample4:"<<endl;
        sample3.retainAll(sample4);
        sample3.printAll();
        cout<<"\nClear the sample3 and isEmpty():";
        sample3.clear();
        cout<<sample3.isEmpty();

        cout<<"\n\n****TESTING 'ArrayList' FOR STRING(container:std::list)****"<<endl;
        ArrayList<string,list<string>> sample5;//add() function test
        sample5.add("one");
        sample5.add("one");
        sample5.add("two");
        sample5.add("three");
        sample5.add("for");
        sample5.add("eight");

        ArrayList<string,list<string>> sample6;
        sample6.add("three");
        sample6.add("for");
        sample6.add("seven");
        sample6.add("eight");

        cout<<"Sample5:"<<endl;
        sample5.printAll();
        cout<<"\nSample6:"<<endl;
        sample6.printAll();
        cout<<"\nAfter the addAll():"<<endl;
        sample5.addAll(sample6);
        sample5.printAll();
        cout<<"\nafter the removeAll() added sample5 and sample6:"<<endl;
        sample5.removeAll(sample6);
        sample5.printAll();
        cout<<"\nremove() 'two' to sample5 and contains() for 'two' and size():"<<endl;
        sample5.remove("two");
        sample5.printAll();
        cout<<"\nContains() 'one'?:"<<sample5.contains("one")<<endl;
        cout<<"Sample5 size:"<<sample5.size()<<endl;
        cout<<"ContainsAll() for itself:"<<sample5.containsAll(sample5)<<endl;
        cout<<"RetainAll() sample5 and sample6:"<<endl;
        sample5.retainAll(sample6);//All element in sample have sample2 because of this the resılt is same "sample"
        sample5.printAll();
        cout<<"\nClear the sample5 and isEmpty():";
        sample5.clear();
        cout<<sample5.isEmpty();

        cout<<"\n\n****TESTING 'ArrayList' FOR INT(container:std::list)****"<<endl;
        ArrayList<int,list<int>> sample7;//add() function test
        sample7.add(1);
        sample7.add(2);
        sample7.add(3);
        sample7.add(4);

        ArrayList<int,list<int>> sample8;
        sample8.add(3);
        sample8.add(4);
        sample8.add(5);
        sample8.add(6);
        sample8.add(7);

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
        cout<<"\nremove() '1' to sample7 and contains() for '1' and size():"<<endl;
        sample7.remove(1);
        sample7.printAll();
        cout<<"\nContains() '1'?:"<<sample7.contains(1)<<endl;
        cout<<"sample7 size:"<<sample7.size()<<endl;
        cout<<"ContainsAll() for itself:"<<sample7.containsAll(sample7)<<endl;
        cout<<"RetainAll() sample7 and sample8:"<<endl;
        sample7.retainAll(sample8);
        sample7.printAll();
        cout<<"\nClear the sample7 and isEmpty():";
        sample7.clear();
        cout<<sample7.isEmpty();


        cout<<"\n\n****TESTING 'ArrayList' FOR STRING(container:std::list)****"<<endl;
        ArrayList<string,list<string>> sample9;//add() function test
        sample9.add("one");
        sample9.add("one");
        sample9.add("two");
        sample9.add("three");
        sample9.add("for");
        sample9.add("eight");

        ArrayList<string,list<string>> sample10;
        sample10.add("three");
        sample10.add("for");
        sample10.add("seven");
        sample10.add("eight");

        cout<<"Sample9:"<<endl;
        sample9.printAll();
        cout<<"\nsample10:"<<endl;
        sample10.printAll();
        cout<<"\nAfter the addAll():"<<endl;
        sample9.addAll(sample10);
        sample9.printAll();
        cout<<"\nafter the removeAll() added sample and sample10:"<<endl;
        sample9.removeAll(sample10);
        sample9.printAll();
        cout<<"\nremove() 'two' to sample9 and contains() for 'two' and size():"<<endl;
        sample9.remove("two");
        sample9.printAll();
        cout<<"\nContains() 'one'?:"<<sample9.contains("one")<<endl;
        cout<<"Sample9 size:"<<sample9.size()<<endl;
        cout<<"ContainsAll() for itself:"<<sample9.containsAll(sample9)<<endl;
        cout<<"RetainAll() sample9 and sample10:"<<endl;
        sample9.retainAll(sample10);//All element in sample have sample10 because of this the resılt is same "sample"
        sample9.printAll();
        cout<<"\nClear the sample9 and isEmpty():";
        sample9.clear();
        cout<<sample9.isEmpty();

        cout<<"\n\n****TESTING 'ArrayList' FOR INT(container:std::list)****"<<endl;
        ArrayList<int,list<int>> sample11;//add() function test
        sample11.add(1);
        sample11.add(2);
        sample11.add(3);
        sample11.add(4);

        ArrayList<int,list<int>> sample12;
        sample12.add(3);
        sample12.add(4);
        sample12.add(5);
        sample12.add(6);
        sample12.add(7);

        cout<<"sample11:"<<endl;
        sample11.printAll();
        cout<<"\nsample12:"<<endl;
        sample12.printAll();
        cout<<"\nAfter the addAll():"<<endl;
        sample11.addAll(sample12);
        sample11.printAll();
        cout<<"\nafter the removeAll() added sample11 and sample12:"<<endl;
        sample11.removeAll(sample12);
        sample11.printAll();
        cout<<"\nremove() '1' to sample11 and contains() for '1' and size():"<<endl;
        sample11.remove(1);
        sample11.printAll();
        cout<<"\nContains() '1'?:"<<sample11.contains(1)<<endl;
        cout<<"sample11 size:"<<sample11.size()<<endl;
        cout<<"ContainsAll() for itself:"<<sample11.containsAll(sample11)<<endl;
        cout<<"RetainAll() sample11 and sample12:"<<endl;
        sample11.retainAll(sample12);
        sample11.printAll();
        cout<<"\nClear the sample11 and isEmpty():";
        sample11.clear();
        cout<<sample11.isEmpty();

        cout<<"\n\n****TESTING 'ArrayList' FOR STRING(container:std::set)****"<<endl;
        ArrayList<string,set<string>> sample13;//add() function test
        sample13.add("one");
        sample13.add("one");
        sample13.add("two");
        sample13.add("three");
        sample13.add("for");
        sample13.add("eight");

        ArrayList<string,set<string>> sample14;
        sample14.add("three");
        sample14.add("for");
        sample14.add("seven");
        sample14.add("eight");

        cout<<"Sample13:"<<endl;
        sample13.printAll();
        cout<<"\nsample14:"<<endl;
        sample14.printAll();
        cout<<"\nAfter the addAll():"<<endl;
        sample13.addAll(sample14);
        sample13.printAll();
        cout<<"\nafter the removeAll() added sample and sample14:"<<endl;
        sample13.removeAll(sample14);
        sample13.printAll();
        cout<<"\nremove() 'two' to sample13 and contains() for 'two' and size():"<<endl;
        sample13.remove("two");
        sample13.printAll();
        cout<<"\nContains() 'one'?:"<<sample13.contains("one")<<endl;
        cout<<"Sample13 size:"<<sample13.size()<<endl;
        cout<<"ContainsAll() for itself:"<<sample13.containsAll(sample13)<<endl;
        cout<<"RetainAll() sample13 and sample14:"<<endl;
        sample13.retainAll(sample14);//All element in sample have sample14 because of this the resılt is same "sample"
        sample13.printAll();
        cout<<"\nClear the sample13 and isEmpty():";
        sample13.clear();
        cout<<sample13.isEmpty();

        cout<<"\n\n****TESTING 'ArrayList' FOR INT(container:std::set)****"<<endl;
        ArrayList<int,set<int>> sample15;//add() function test
        sample15.add(1);
        sample15.add(2);
        sample15.add(3);
        sample15.add(4);

        ArrayList<int,set<int>> sample16;
        sample16.add(3);
        sample16.add(4);
        sample16.add(5);
        sample16.add(6);
        sample16.add(7);

        cout<<"sample15:"<<endl;
        sample15.printAll();
        cout<<"\nsample16:"<<endl;
        sample16.printAll();
        cout<<"\nAfter the addAll():"<<endl;
        sample15.addAll(sample16);
        sample15.printAll();
        cout<<"\nafter the removeAll() added sample15 and sample16:"<<endl;
        sample15.removeAll(sample16);
        sample15.printAll();
        cout<<"\nremove() '1' to sample15 and contains() for '1' and size():"<<endl;
        sample15.remove(1);
        sample15.printAll();
        cout<<"\nContains() '1'?:"<<sample15.contains(1)<<endl;
        cout<<"sample15 size:"<<sample15.size()<<endl;
        cout<<"ContainsAll() for itself:"<<sample15.containsAll(sample15)<<endl;
        cout<<"RetainAll() sample15 and sample16:"<<endl;
        sample15.retainAll(sample16);
        sample15.printAll();
        cout<<"\nClear the sample15 and isEmpty():";
        sample15.clear();
        cout<<sample15.isEmpty();


        cout<<"\n\n****TESTING 'HashSet' FOR STRING[container std::set(defaulted)]****"<<endl;
        HashSet<string> sample17;
        sample17.add("one");
        sample17.add("two");
        sample17.add("three");

        HashSet<string> sample18;
        sample18.add("three");
        sample18.add("for");
        sample18.add("five");

        cout<<"sample17:"<<endl;
        sample17.printAll();
        cout<<"\nsample18:"<<endl;
        sample18.printAll();
        cout<<"\nAfter the addAll():"<<endl;
        sample17.addAll(sample18);
        sample17.printAll();
        cout<<"\nafter the removeAll() added sample17 and sample18:"<<endl;
        sample17.removeAll(sample18);
        sample17.printAll();
        cout<<"\nremove() 'one' to sample17 and contains() for 'one' and size():"<<endl;
        sample17.remove("one");
        sample17.printAll();
        cout<<"\nContains() 'one'?:"<<sample17.contains("one")<<endl;
        cout<<"sample17 size:"<<sample17.size()<<endl;
        cout<<"ContainsAll() for itself:"<<sample17.containsAll(sample17)<<endl;
        cout<<"RetainAll() sample17 and sample18:"<<endl;
        //sample17.retainAll(sample18);
        sample17.printAll();
        cout<<"\nClear the sample17 and isEmpty():";
        sample17.clear();
        cout<<sample17.isEmpty();

        cout<<"\n\n****TESTING 'HashSet' FOR INT[container std::set(defaulted)]****"<<endl;
        HashSet<int> sample19;
        sample19.add(3);
        sample19.add(5);
        sample19.add(7);
        sample19.add(2);
        sample19.add(20);

        HashSet<int> sample20;
        sample20.add(5);
        sample20.add(2);

        cout<<"sample19:"<<endl;
        sample19.printAll();
        cout<<"\nsample20:"<<endl;
        sample20.printAll();
        cout<<"\nAfter the addAll():"<<endl;
        sample19.addAll(sample20);
        sample19.printAll();
        cout<<"\nafter the removeAll() added sample19 and sample20:"<<endl;
        sample19.removeAll(sample20);
        sample19.printAll();
        cout<<"\nremove() '3' to sample19 and contains() for '3' and size():"<<endl;
        sample19.remove(3);
        sample19.printAll();
        cout<<"\nContains() '3'?:"<<sample19.contains(3)<<endl;
        cout<<"sample19 size:"<<sample19.size()<<endl;
        cout<<"ContainsAll() for itself:"<<sample19.containsAll(sample19)<<endl;
        cout<<"RetainAll() sample19 and sample20:"<<endl;
        sample19.retainAll(sample20);
        sample19.printAll();
        cout<<"\nClear the sample19 and isEmpty():";
        sample19.clear();
        cout<<sample19.isEmpty();

        cout<<"\n\n****TESTING 'HashSet' FOR STRING(container std::vector)****"<<endl;
        HashSet<string,vector<string>> sample21;
        sample21.add("one");
        sample21.add("two");
        sample21.add("three");

        HashSet<string,vector<string>> sample22;
        sample22.add("three");
        sample22.add("for");
        sample22.add("five");

        cout<<"sample21:"<<endl;
        sample21.printAll();
        cout<<"\nsample22:"<<endl;
        sample22.printAll();
        cout<<"\nAfter the addAll():"<<endl;
        sample21.addAll(sample22);
        sample21.printAll();
        cout<<"\nafter the removeAll() added sample21 and sample22:"<<endl;
        sample21.removeAll(sample22);
        sample21.printAll();
        cout<<"\nremove() 'one' to sample21 and contains() for 'one' and size():"<<endl;
        sample21.remove("one");
        sample21.printAll();
        cout<<"\nContains() 'one'?:"<<sample21.contains("one")<<endl;
        cout<<"sample21 size:"<<sample21.size()<<endl;
        cout<<"ContainsAll() for itself:"<<sample21.containsAll(sample21)<<endl;
        cout<<"RetainAll() sample21 and sample22:"<<endl;
        //sample21.retainAll(sample22);
        sample21.printAll();
        cout<<"\nClear the sample21 and isEmpty():";
        sample21.clear();
        cout<<sample21.isEmpty();

        cout<<"\n\n****TESTING 'HashSet' FOR INT(container std::vector)****"<<endl;
        HashSet<int,vector<int>> sample23;
        sample23.add(3);
        sample23.add(5);
        sample23.add(7);
        sample23.add(2);
        sample23.add(20);

        HashSet<int,vector<int>> sample24;
        sample24.add(5);
        sample24.add(2);

        cout<<"sample23:"<<endl;
        sample23.printAll();
        cout<<"\nsample24:"<<endl;
        sample24.printAll();
        cout<<"\nAfter the addAll():"<<endl;
        sample23.addAll(sample24);
        sample23.printAll();
        cout<<"\nafter the removeAll() added sample23 and sample24:"<<endl;
        sample23.removeAll(sample24);
        sample23.printAll();
        cout<<"\nremove() '3' to sample23 and contains() for '3' and size():"<<endl;
        sample23.remove(3);
        sample23.printAll();
        cout<<"\nContains() '3'?:"<<sample23.contains(3)<<endl;
        cout<<"sample23 size:"<<sample23.size()<<endl;
        cout<<"ContainsAll() for itself:"<<sample23.containsAll(sample23)<<endl;
        cout<<"RetainAll() sample23 and sample24:"<<endl;
        sample23.retainAll(sample24);
        sample23.printAll();
        cout<<"\nClear the sample23 and isEmpty():";
        sample23.clear();
        cout<<sample23.isEmpty();

        cout<<"\n\n****TESTING 'HashSet' FOR STRING(container std::list)****"<<endl;
        HashSet<string,list<string>> sample25;
        sample25.add("one");
        sample25.add("two");
        sample25.add("three");

        HashSet<string,list<string>> sample26;
        sample26.add("three");
        sample26.add("for");
        sample26.add("five");

        cout<<"sample25:"<<endl;
        sample25.printAll();
        cout<<"\nsample26:"<<endl;
        sample26.printAll();
        cout<<"\nAfter the addAll():"<<endl;
        sample25.addAll(sample26);
        sample25.printAll();
        cout<<"\nafter the removeAll() added sample25 and sample26:"<<endl;
        sample25.removeAll(sample26);
        sample25.printAll();
        cout<<"\nremove() 'one' to sample25 and contains() for 'one' and size():"<<endl;
        sample25.remove("one");
        sample25.printAll();
        cout<<"\nContains() 'one'?:"<<sample25.contains("one")<<endl;
        cout<<"sample25 size:"<<sample25.size()<<endl;
        cout<<"ContainsAll() for itself:"<<sample25.containsAll(sample25)<<endl;
        cout<<"RetainAll() sample25 and sample26:"<<endl;
        //sample25.retainAll(sample26);
        sample25.printAll();
        cout<<"\nClear the sample25 and isEmpty():";
        sample25.clear();
        cout<<sample25.isEmpty();

        cout<<"\n\n****TESTING 'HashSet' FOR INT(container std::list)****"<<endl;
        HashSet<int,list<int>> sample27;
        sample27.add(3);
        sample27.add(5);
        sample27.add(7);
        sample27.add(2);
        sample27.add(20);

        HashSet<int,list<int>> sample28;
        sample28.add(5);
        sample28.add(2);

        cout<<"sample27:"<<endl;
        sample27.printAll();
        cout<<"\nsample28:"<<endl;
        sample28.printAll();
        cout<<"\nAfter the addAll():"<<endl;
        sample27.addAll(sample28);
        sample27.printAll();
        cout<<"\nafter the removeAll() added sample27 and sample28:"<<endl;
        sample27.removeAll(sample28);
        sample27.printAll();
        cout<<"\nremove() '3' to sample27 and contains() for '3' and size():"<<endl;
        sample27.remove(3);
        sample27.printAll();
        cout<<"\nContains() '3'?:"<<sample27.contains(3)<<endl;
        cout<<"sample27 size:"<<sample27.size()<<endl;
        cout<<"ContainsAll() for itself:"<<sample27.containsAll(sample27)<<endl;
        cout<<"RetainAll() sample27 and sample28:"<<endl;
        sample27.retainAll(sample28);
        sample27.printAll();
        cout<<"\nClear the sample27 and isEmpty():";
        sample27.clear();
        cout<<sample27.isEmpty();


        cout<<"\n\n****TESTING 'LinkedList' FOR STRING[container std::list[defaulted]]****"<<endl;
        LinkedList<string> sample29;
        sample29.add("one");
        sample29.add("two");
        sample29.add("three");

        LinkedList<string> sample30;
        sample30.add("three");
        sample30.offer("for");
        sample30.add("five");

        cout<<"sample29:"<<endl;
        sample29.printAll();
        cout<<"\nsample30:"<<endl;
        sample30.printAll();
        cout<<"\nAfter the addAll():"<<endl;
        sample29.addAll(sample30);
        sample29.printAll();
        cout<<"\nafter the removeAll() added sample29 and sample30:"<<endl;
        sample29.removeAll(sample30);
        sample29.printAll();
        cout<<"\nremove() 'one' to sample29 and contains() for 'one' and size():"<<endl;
        sample29.remove("one");
        sample29.printAll();
        cout<<"\nContains() 'one'?:"<<sample29.contains("one")<<endl;
        cout<<"sample29 size:"<<sample29.size()<<endl;
        cout<<"ContainsAll() for itself:"<<sample29.containsAll(sample29)<<endl;
        cout<<"RetainAll() sample29 and sample30:"<<endl;
        sample29.retainAll(sample30);
        sample29.printAll();
        cout<<"\nClear the sample29 and isEmpty():";
        sample29.clear();
        cout<<sample29.isEmpty();


        cout<<"\n\n****TESTING 'LinkedList' FOR INT[container std::list[defaulted]]****"<<endl;
        LinkedList<int> sample31;
        sample31.add(-1);
        sample31.add(1);
        sample31.add(2);
        sample31.add(3);
        sample31.offer(4);
        sample31.offer(5);

        LinkedList<int> sample32;
        sample32.add(4);
        sample32.add(5);
        sample32.add(6);
        sample32.add(7);

        cout<<"sample31:"<<endl;
        sample31.printAll();
        cout<<"\nsample32:"<<endl;
        sample32.printAll();
        cout<<"\nelement() function for sample31:"<<sample31.element()<<endl;
        cout<<"poll() function for sample31:"<<sample31.poll()<<endl;
        cout<<"After the poll function"<<endl;
        sample31.printAll();
        cout<<"\nAfter the addAll():"<<endl;
        sample31.addAll(sample32);
        sample31.printAll();
        cout<<"\nafter the removeAll() added sample31 and sample32:"<<endl;
        sample31.removeAll(sample32);
        sample31.printAll();
        cout<<"\nremove() '3' to sample31 and contains() for '3' and size():"<<endl;
        sample31.remove(3);
        sample31.printAll();
        cout<<"\nContains() '3'?:"<<sample31.contains(3)<<endl;
        cout<<"sample31 size:"<<sample31.size()<<endl;
        cout<<"ContainsAll() for itself:"<<sample31.containsAll(sample31)<<endl;
        cout<<"RetainAll() sample31 and sample32:"<<endl;
        sample31.retainAll(sample32);
        sample31.printAll();
        cout<<"\nClear the sample31 and isEmpty():";
        sample31.clear();
        cout<<sample31.isEmpty();

        cout<<"\n\n****TESTING 'LinkedList' FOR STRING(container std::vector)****"<<endl;
        LinkedList<string,vector<string>> sample33;
        sample33.add("one");
        sample33.add("two");
        sample33.add("three");

        LinkedList<string,vector<string>> sample34;
        sample34.add("three");
        sample34.offer("for");
        sample34.add("five");

        cout<<"sample33:"<<endl;
        sample33.printAll();
        cout<<"\nsample34:"<<endl;
        sample34.printAll();
        cout<<"\nAfter the addAll():"<<endl;
        sample33.addAll(sample34);
        sample33.printAll();
        cout<<"\nafter the removeAll() added sample33 and sample34:"<<endl;
        sample33.removeAll(sample34);
        sample33.printAll();
        cout<<"\nremove() 'one' to sample33 and contains() for 'one' and size():"<<endl;
        sample33.remove("one");
        sample33.printAll();
        cout<<"\nContains() 'one'?:"<<sample33.contains("one")<<endl;
        cout<<"sample33 size:"<<sample33.size()<<endl;
        cout<<"ContainsAll() for itself:"<<sample33.containsAll(sample33)<<endl;
        cout<<"RetainAll() sample33 and sample34:"<<endl;
        sample33.retainAll(sample34);
        sample33.printAll();
        cout<<"\nClear the sample33 and isEmpty():";
        sample33.clear();
        cout<<sample33.isEmpty();


        cout<<"\n\n****TESTING 'LinkedList' FOR INT(container std::vector)****"<<endl;
        LinkedList<int,vector<int>> sample35;
        sample35.add(-1);
        sample35.add(1);
        sample35.add(2);
        sample35.add(3);
        sample35.offer(4);
        sample35.offer(5);

        LinkedList<int,vector<int>> sample36;
        sample36.add(4);
        sample36.add(5);
        sample36.add(6);
        sample36.add(7);

        cout<<"sample35:"<<endl;
        sample35.printAll();
        cout<<"\nsample36:"<<endl;
        sample36.printAll();
        cout<<"\nelement() function for sample35:"<<sample35.element()<<endl;
        cout<<"poll() function for sample35:"<<sample35.poll()<<endl;
        cout<<"After the poll function"<<endl;
        sample35.printAll();
        cout<<"\nAfter the addAll():"<<endl;
        sample35.addAll(sample36);
        sample35.printAll();
        cout<<"\nafter the removeAll() added sample35 and sample36:"<<endl;
        sample35.removeAll(sample36);
        sample35.printAll();
        cout<<"\nremove() '3' to sample35 and contains() for '3' and size():"<<endl;
        sample35.remove(3);
        sample35.printAll();
        cout<<"\nContains() '3'?:"<<sample35.contains(3)<<endl;
        cout<<"sample35 size:"<<sample35.size()<<endl;
        cout<<"ContainsAll() for itself:"<<sample35.containsAll(sample35)<<endl;
        cout<<"RetainAll() sample35 and sample36:"<<endl;
        sample35.retainAll(sample36);
        sample35.printAll();
        cout<<"\nClear the sample35 and isEmpty():";
        sample35.clear();
        cout<<sample35.isEmpty();

        cout<<"\n\n****TESTING 'LinkedList' FOR STRING(container std::set)****"<<endl;
        LinkedList<string,set<string>> sample37;
        sample37.add("one");
        sample37.add("two");
        sample37.add("three");

        LinkedList<string,set<string>> sample38;
        sample38.add("three");
        sample38.offer("for");
        sample38.add("five");

        cout<<"sample37:"<<endl;
        sample37.printAll();
        cout<<"\nsample38:"<<endl;
        sample38.printAll();
        cout<<"\nAfter the addAll():"<<endl;
        sample37.addAll(sample38);
        sample37.printAll();
        cout<<"\nafter the removeAll() added sample37 and sample38:"<<endl;
        sample37.removeAll(sample38);
        sample37.printAll();
        cout<<"\nremove() 'one' to sample37 and contains() for 'one' and size():"<<endl;
        sample37.remove("one");
        sample37.printAll();
        cout<<"\nContains() 'one'?:"<<sample37.contains("one")<<endl;
        cout<<"sample37 size:"<<sample37.size()<<endl;
        cout<<"ContainsAll() for itself:"<<sample37.containsAll(sample37)<<endl;
        cout<<"RetainAll() sample37 and sample38:"<<endl;
        sample37.retainAll(sample38);
        sample37.printAll();
        cout<<"\nClear the sample37 and isEmpty():";
        sample37.clear();
        cout<<sample37.isEmpty();


        cout<<"\n\n****TESTING 'LinkedList' FOR INT(container std::set)****"<<endl;
        LinkedList<int,set<int>> sample39;
        sample39.add(-1);
        sample39.add(1);
        sample39.add(2);
        sample39.add(3);
        sample39.offer(4);
        sample39.offer(5);

        LinkedList<int,set<int>> sample40;
        sample40.add(4);
        sample40.add(5);
        sample40.add(6);
        sample40.add(7);

        cout<<"sample39:"<<endl;
        sample39.printAll();
        cout<<"\nsample40:"<<endl;
        sample40.printAll();
        cout<<"\nelement() function for sample39:"<<sample39.element()<<endl;
        cout<<"poll() function for sample39:"<<sample39.poll()<<endl;
        cout<<"After the poll function"<<endl;
        sample39.printAll();
        cout<<"\nAfter the addAll():"<<endl;
        sample39.addAll(sample40);
        sample39.printAll();
        cout<<"\nafter the removeAll() added sample39 and sample40:"<<endl;
        sample39.removeAll(sample40);
        sample39.printAll();
        cout<<"\nremove() '3' to sample39 and contains() for '3' and size():"<<endl;
        sample39.remove(3);
        sample39.printAll();
        cout<<"\nContains() '3'?:"<<sample39.contains(3)<<endl;
        cout<<"sample39 size:"<<sample39.size()<<endl;
        cout<<"ContainsAll() for itself:"<<sample39.containsAll(sample39)<<endl;
        cout<<"RetainAll() sample39 and sample40:"<<endl;
        sample39.retainAll(sample40);
        sample39.printAll();
        cout<<"\nClear the sample39 and isEmpty():";
        sample39.clear();
        cout<<sample39.isEmpty();


    }
    catch(MyException e){
        cout<<e.what()<<endl;
        exit(1);
    }

}
