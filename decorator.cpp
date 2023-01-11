#include <iostream>
using namespace std;

class coffee
{
protected:
    int price;

public:
    coffee()
    {
        price = 10;
    }
    virtual int getprice()
    {
        return price;
    }
    void setprice(int p)
    {
        price = p;
    }
};
class milkCoffe : public coffee
{
protected:
    coffee* cof;

public:
    milkCoffe(coffee* c){
        cof = c;
        price = 20;
    }
    int getprice(){
        return price + cof->getprice();
    }
};
class sugarCoffee:public coffee{
protected:
    coffee* cof;
public:
    sugarCoffee(coffee* c){
        cof = c;
        price = 30;
    }
    int getprice(){
        return price + cof->getprice();
    }
};
int main(){
    coffee c;
    milkCoffe mc(&c);
    cout << mc.getprice()<<endl;
    sugarCoffee sc(&mc);
    cout << sc.getprice()<< endl;
    c.setprice(20);
    cout << mc.getprice() <<endl;
    cout << sc.getprice()<< endl;
    return 0;
}