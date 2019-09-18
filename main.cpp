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
        *lista << data;
    }
}

int main() {

    cout << "ForwardList: \n\n";

    ForwardList<int> forwardlist;
    llenar_int(&forwardlist,50,15);
    cout << forwardlist;
    ForwardList<int> forwardlista1;
    forwardlista1 << 20 << 30 >> 10;
    cout << forwardlista1;
    ForwardList<int> forwardlista2(forwardlista1);
    cout << forwardlista2;
    int f_array[4]= {10,20,30,40};
    ForwardList<int> forwardlista3(f_array,4);
    cout << forwardlista3;
    ForwardList<int> forwardlista4(forwardlist.pop_back());
    cout << forwardlista4;
    ForwardList<int> forwardlista5(5);
    cout << forwardlista5;
    cout << forwardlist.back() << '\n';
    cout << **forwardlist.pop_back() << '\n';
    cout << forwardlist.front() << '\n';
    cout << **forwardlist.pop_front() << '\n';
    cout << forwardlist.empty() << '\n';
    cout << forwardlist.size() << '\n';
    cout << forwardlist[0] << '\n';


    ForwardList<int>::ForwardIterator it_forward = forwardlist.begin();
    cout << *it_forward << '\n' << *(++it_forward) << '\n';

    forwardlist.clear();
    cout << forwardlist;
/*

    cout << "DoubleList: \n\n";

    DoubleList<int> doublelist;

    llenar_int(&doublelist,50,15);
    cout << doublelist;
    DoubleList<int> doublelist1;
    doublelist1 << 20 << 30 >> 10;
    cout << doublelist1;
    DoubleList<int> doublelist2(doublelist1);
    cout << doublelist2;
    int d_array[4] = {10,20,30,40};
    DoubleList<int> doublelist3(d_array,4);
    cout << doublelist3;
    DoubleList<int> doublelist4(doublelist.pop_back());
    cout << doublelist4;
    DoubleList<int> doublelist5(5);
    cout << doublelist5;
    cout << **doublelist.pop_back() << '\n';
    cout << **doublelist.pop_front() << '\n';
    cout << doublelist.empty() << '\n';
    cout << doublelist.size() << '\n';
    cout << doublelist[0] << '\n';

    DoubleList<int>::DoubleIterator it_double = doublelist.begin();
    cout << *it_double << '\n' << *(++it_double) << '\n';

    doublelist.clear();
    cout << doublelist;

    cout << "CircularList: \n\n";

    CircularList<int> circularlist;

    llenar_int(&circularlist,50,15);
    cout << circularlist;
    CircularList<int> circularlist1;
    circularlist1 << 20 << 30 >> 10;
    cout << circularlist1;
    CircularList<int> circularlist2(circularlist1);
    cout << circularlist2;
    int c_array[4] = {10,20,30,40};
    CircularList<int> circularlist3(c_array,4);
    cout << circularlist3;
    CircularList<int> circularlist4(circularlist.pop_back());
    cout << circularlist4;
    CircularList<int> circularlist5(5);
    cout << circularlist5;
    cout << **circularlist.pop_back() << '\n';
    cout << **circularlist.pop_front() << '\n';
    cout << circularlist.empty() << '\n';
    cout << circularlist.size() << '\n';
    cout << circularlist[0] << '\n';

    CircularList<int>::CircularIterator it_circle = circularlist.begin();
    cout << *it_circle << '\n' << *(++it_circle) << '\n';

    circularlist.clear();
    cout << circularlist;

    cout << "DoubleCircularList: \n\n";

    DoubleCircularList<int> doublecircularlist;

    llenar_int(&doublecircularlist,50,15);
    cout << doublecircularlist;
    DoubleCircularList<int> doublecircularlist1;
    doublecircularlist1 << 20 << 30 >> 10;
    cout << doublecircularlist1;
    DoubleCircularList<int> doublecircularlist2(doublecircularlist1);
    cout << doublecircularlist2;
    int dc_array[4] = {10,20,30,40};
    DoubleCircularList<int> doublecircularlist3(dc_array,4);
    cout << doublecircularlist3;
    DoubleCircularList<int> doublecircularlist4(doublecircularlist.pop_back());
    cout << doublecircularlist4;
    DoubleCircularList<int> doublecircularlist5(5);
    cout << doublecircularlist5;
    cout << **doublecircularlist.pop_back() << '\n';
    cout << **doublecircularlist.pop_front() << '\n';
    cout << doublecircularlist.empty() << '\n';
    cout << doublecircularlist.size() << '\n';
    cout << doublecircularlist[0] << '\n';

    DoubleCircularList<int>::DoubleCircularIterator it_doublecircle = doublecircularlist.begin();
    cout << *it_doublecircle << '\n' << *(++it_doublecircle) << '\n';


    doublecircularlist.clear();
    cout << doublecircularlist;

    DoubleCircularList<int>::DoubleCircularIterator it_doublecircle2 = doublecircularlist2.begin();
    cout << *it_doublecircle2;

    bool n0 = it_doublecircle == it_doublecircle2;
    bool n1 = it_doublecircle != it_doublecircle2;
    bool n2 = it_doublecircle <= it_doublecircle2;
    bool n3 = it_doublecircle >= it_doublecircle2;
    bool n4 = it_doublecircle < it_doublecircle2;
    bool n5 = it_doublecircle > it_doublecircle2;
    cout << '\n' << n0 << '\n' << n1 << '\n' << n2 << '\n' << n3 << '\n' << n4 << '\n' << n5 << '\n';
*/
    return 0;
}