#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class   MyArray {
    private: 
    int n, *ms, *R;
    public:
    MyArray (){
        n=0;
        ms=NULL;
        //cout << "construct";
    }

    void init(int k){
        if(ms==NULL){
            ms = new int[k];
            n=k;
        }
        for (int i=0;i<n;i++){
            ms[i]=0;
            if (i == n - 1){
                R = &ms[i];
            }
        }
    }

    void set(int k, int v){
        ms[k] = v;
    }

    int get(int k){
        return ms[k];
    }

    void insertElm(int index, int elm){
        int *tmp, i, j;
        tmp = new int[n + 1];
        for (i = 0; i <= index; i++){
            if (i == index){
                tmp[i] = elm;
                break;
            }
            tmp[i] = ms[i];

        } 
        for (i = index + 1; i <= n + 1; i++){
            tmp[i] = ms[i - 1];
        }
        delete ms;
        ms = tmp;
        n++;
    }

    void removeElm(int index){
        int i;
        int *tmp = new int[n - 1];
        for (i = 0; i < index; i++){
            tmp[i] = ms[i];
        }
        for (i = index;i <= n - 1; i++){
            tmp[i] = ms[i + 1];
        }
        n--;
        delete ms;
        ms = tmp;
    }

    void bubbleSort(){
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (ms[j] > ms[j + 1]){
                swap(ms[j], ms[j + 1]);
            }
}

void gnomeSort() {
    int *  l = ms;
    int * r = R; 
	int *i = l;
	while (i < r) {
		if (i == l || *(i - 1) <= *i) i++;
		else swap(*(i - 1), *i), i--;
	}
}

    void print(){
        for (int i=0;i<n;i++) cout << ms[i]<<" ";
        cout <<endl;
    }

    ~MyArray(){
        if (ms){
            delete ms;
        }
    }
};



int main()
{

    MyArray m;
    m.init(20);
    for (int i = 0; i < 20; i++){
        m.set(i, 19 - i);
    }
    m.print();
    unsigned int bubleStart = clock();
    m.bubbleSort();
    unsigned int bubleEnd = clock();
    unsigned int bubleTime = bubleStart - bubleEnd;
    m.print();
    MyArray a;
    a.init(20);
    for (int i = 0; i < 20; i++){
        a.set(i, 19 - i);
    }
    a.print();
    unsigned int gnomeStart = clock();
    a.gnomeSort();
    unsigned int gnomeEnd = clock();
    unsigned int gnomeTime = gnomeStart - gnomeEnd;
    a.print();
    cout << gnomeTime << " " << bubleTime;
    //m.insertElm(19, 10);
    //m.removeElm(0);
    //m.print();
    //m.addNewElm(1);
    //m.removeElm(21);



    //MyArray *A = new MyArray; 
    //A->init(10);
    //A->print();
    //delete A;

    return 0;
}