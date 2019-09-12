#include <iostream>
#include <time.h>
#include "ForwardList.h"
#include "DoubleList.h"
#include "CircularList.h"
#include "DoubleCircularList.h"
using namespace std;

void llenar_int(List<int>* lista,int max,int n){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        int data = rand()%(max+1);
        lista->push_front(data);
    }
}

int main() {
    cout << "ForwardList: \n\n";

    ForwardList<int> forwardlist;// = new ForwardList<int>();
    llenar_int(&forwardlist,50,15);
    cout << forwardlist;
    ForwardList<int> forwardlista1;
    forwardlista1.push_back(10);
    forwardlista1.push_back(20);
    forwardlista1.push_back(30);
    cout << forwardlista1;
    ForwardList<int> forwardlista2(forwardlista1);// = new ForwardList<int>(forwardlista1);
    cout << forwardlista2;
    int f_array[4]= {10,20,30,40};
    ForwardList<int> forwardlista3(f_array,4);// = new ForwardList<int>(f_array,4);
    cout << forwardlista3;
    ForwardList<int> forwardlista4(forwardlist.pop_back());// = new ForwardList<int>(forwardlist->pop_back());
    cout << forwardlista4;
    ForwardList<int> forwardlista5(5);// = new ForwardList<int>(5);
    cout << forwardlista5;
    cout << forwardlist.pop_back()->data << '\n';
    cout << forwardlist.pop_front()->data << '\n';
    cout << forwardlist.empty() << '\n';
    cout << forwardlist.size() << '\n';
    cout << forwardlista1[0] << '\n';

    forwardlist.clear();
    cout << forwardlist;


    cout << "DoubleList: \n\n";

    DoubleList<int> doublelist;// = new DoubleList<int>();

    llenar_int(&doublelist,50,15);
    cout << doublelist;
    DoubleList<int> doublelist1;
    doublelist1.push_back(10);
    doublelist1.push_back(20);
    doublelist1.push_back(30);
    cout << doublelist1;
    DoubleList<int> doublelist2;// = new DoubleList<int>(doublelist1);
    cout << doublelist2;
    int d_array[4] = {10,20,30,40};
    DoubleList<int> doublelist3(d_array,4);// = new DoubleList<int>(d_array,4);
    cout << doublelist3;
    DoubleList<int> doublelist4(doublelist.pop_back());// = new DoubleList<int>(doublelist->pop_back());
    cout << doublelist4;
    DoubleList<int> doublelist5(5);// = new DoubleList<int>(5);
    cout << doublelist5;
    cout << doublelist.pop_back()->data << '\n';
    cout << doublelist.pop_front()->data << '\n';
    cout << doublelist.empty() << '\n';
    cout << doublelist.size() << '\n';
    cout << doublelist1[0] << '\n';

    doublelist.clear();
    cout << doublelist;

    cout << "CircularList: \n\n";

    CircularList<int> circularlist;// = new CircularList<int>();

    llenar_int(&circularlist,50,15);
    cout << circularlist;
    CircularList<int> circularlist1;
    circularlist1.push_back(10);
    circularlist1.push_back(20);
    circularlist1.push_back(30);
    cout << circularlist1;
    CircularList<int> circularlist2;// = new CircularList<int>(circularlist1);
    cout << circularlist2;
    int c_array[4] = {10,20,30,40};
    CircularList<int> circularlist3(c_array,4);// = new CircularList<int>(c_array,4);
    cout << circularlist3;
    CircularList<int> circularlist4(circularlist.pop_back());// = new CircularList<int>(circularlist->pop_back());
    cout << circularlist4;
    CircularList<int> circularlist5(5);// = new CircularList<int>(5);
    cout << circularlist5;
    cout << circularlist.pop_back()->data << '\n';
    cout << circularlist.pop_front()->data << '\n';
    cout << circularlist.empty() << '\n';
    cout << circularlist.size() << '\n';
    cout << circularlist1[0] << '\n';

    circularlist.clear();
    cout << circularlist;

    cout << "DoubleCircularList: \n\n";

    DoubleCircularList<int> doublecircularlist;// = new DoubleCircularList<int>();

    llenar_int(&doublecircularlist,50,15);
    cout << doublecircularlist;
    DoubleCircularList<int> doublecircularlist1;
    doublecircularlist1.push_back(10);
    doublecircularlist1.push_back(20);
    doublecircularlist1.push_back(30);
    cout << doublecircularlist1;
    DoubleCircularList<int> doublecircularlist2(doublecircularlist1);// = new DoubleCircularList<int>(doublecircularlist1);
    cout << doublecircularlist2;
    int dc_array[4] = {10,20,30,40};
    DoubleCircularList<int> doublecircularlist3(dc_array,4);// = new DoubleCircularList<int>(dc_array,4);
    cout << doublecircularlist3;
    DoubleCircularList<int> doublecircularlist4(doublecircularlist.pop_back());// = new DoubleCircularList<int>(doublecircularlist->pop_back());
    cout << doublecircularlist4;
    DoubleCircularList<int> doublecircularlist5(5);// = new DoubleCircularList<int>(5);
    cout << doublecircularlist5;
    cout << doublecircularlist.pop_back()->data << '\n';
    cout << doublecircularlist.pop_front()->data << '\n';
    cout << doublecircularlist.empty() << '\n';
    cout << doublecircularlist.size() << '\n';
    cout << doublecircularlist1[0] << '\n';

    doublecircularlist.clear();
    cout << doublecircularlist;


    return 0;
}