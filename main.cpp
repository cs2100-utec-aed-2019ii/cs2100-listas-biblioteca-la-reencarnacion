#include <iostream>
#include <time.h>
#include "ForwardList.h"
#include "DoubleList.H"
#include "CircularList.h"
using namespace std;

void llenar_int(List<int>* lista,int max,int n){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        int data = rand()%(max+1);
        lista->push_front(data);
    }
}


int main() {
/*    cout << "ForwardList: \n";

    List<int>* forwardlist = new ForwardList<int>();
    llenar_int(forwardlist,50,15);
    forwardlist->print();
    ForwardList<int> forwardlista1;
    forwardlista1.push_back(10);
    forwardlista1.push_back(20);
    forwardlista1.push_back(30);
    forwardlista1.print();
    List<int>* forwardlista2 = new ForwardList<int>(forwardlista1);
    forwardlista2->print();
    int f_array[4]= {10,20,30,40};
    List<int>* forwardlista3 = new ForwardList<int>(f_array,4);
    forwardlista3->print();
    List<int>* forwardlista4 = new ForwardList<int>(forwardlist->pop_back());
    forwardlista4->print();
    List<int>* forwardlista5 = new ForwardList<int>(5);
    forwardlista5->print();
    cout << forwardlist->pop_back()->data << '\n';
    cout << forwardlist->pop_front()->data << '\n';
    cout << forwardlist->empty() << '\n';
    cout << forwardlist->size() << '\n';
    cout << forwardlista1[0] << '\n';

    forwardlist->clear();
    forwardlist->print();


    cout << "DoubleList: \n";

    List<int>* doublelist = new DoubleList<int>();

    llenar_int(doublelist,50,15);
    doublelist->print();
    DoubleList<int> doublelist1;
    doublelist1.push_back(10);
    doublelist1.push_back(20);
    doublelist1.push_back(30);
    doublelist1.print();
    List<int>* doublelist2 = new DoubleList<int>(doublelist1);
    doublelist2->print();
    int d_array[4] = {10,20,30,40};
    List<int>* doublelist3 = new DoubleList<int>(d_array,4);
    doublelist3->print();
    List<int>* doublelist4 = new DoubleList<int>(doublelist->pop_back());
    doublelist4->print();
    List<int>* doublelist5 = new DoubleList<int>(5);
    doublelist5->print();
    cout << doublelist->pop_back()->data << '\n';
    cout << doublelist->pop_front()->data << '\n';
    cout << doublelist->empty() << '\n';
    cout << doublelist->size() << '\n';
    cout << doublelist1[0] << '\n';

    doublelist->clear();
    doublelist->print();*/

    cout << "CircularList: \n\n";

    List<int>* circularlist = new CircularList<int>();

    llenar_int(circularlist,50,15);
    circularlist->print();
    CircularList<int> circularlist1;
    circularlist1.push_back(10);
    circularlist1.push_back(20);
    circularlist1.push_back(30);
    circularlist1.print();
    List<int>* circularlist2 = new CircularList<int>(circularlist1);
    circularlist2->print();
    int c_array[4] = {10,20,30,40};
    List<int>* circularlist3 = new CircularList<int>(c_array,4);
    circularlist3->print();
    List<int>* circularlist4 = new CircularList<int>(circularlist->pop_back());
    circularlist4->print();
    List<int>* circularlist5 = new CircularList<int>(5);
    circularlist5->print();
    cout << circularlist->pop_back()->data << '\n';
    cout << circularlist->pop_front()->data << '\n';
    cout << circularlist->empty() << '\n';
    cout << circularlist->size() << '\n';
    cout << circularlist1[0] << '\n';

    circularlist->clear();
    circularlist->print();

    cout << "DoubleCircularList: \n";

    List<int>* doublecircularlist = new CircularList<int>();

    llenar_int(circularlist,50,15);
    doublecircularlist->print();
    CircularList<int> doublecircularlist1;
    doublecircularlist1.push_back(10);
    doublecircularlist1.push_back(20);
    doublecircularlist1.push_back(30);
    doublecircularlist1.print();
    List<int>* doublecircularlist2 = new CircularList<int>(circularlist1);
    doublecircularlist2->print();
    int dc_array[4] = {10,20,30,40};
    List<int>* doublecircularlist3 = new CircularList<int>(dc_array,4);
    doublecircularlist3->print();
    List<int>* doublecircularlist4 = new CircularList<int>(circularlist->pop_back());
    doublecircularlist4->print();
    List<int>* doublecircularlist5 = new CircularList<int>(5);
    doublecircularlist5->print();
    cout << doublecircularlist->pop_back()->data << '\n';
    cout << doublecircularlist->pop_front()->data << '\n';
    cout << doublecircularlist->empty() << '\n';
    cout << doublecircularlist->size() << '\n';
    cout << doublecircularlist1[0] << '\n';

    doublecircularlist->clear();
    doublecircularlist->print();


    return 0;
}
