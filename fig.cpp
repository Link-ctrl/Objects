#include <iostream>
#include <cmath>

using namespace std;
class figure{
    protected:
    double x, y;
    public:
    figure(){
        x = 0;
        y = 0;
    }
    figure(double nx, double ny){
        x = nx;
        y = ny;
    }
    void virtual print() = 0;
    double virtual area() = 0;
    double virtual lenth() = 0;
};
 class circle : public figure {
    protected:
    double r;
    public:
    circle(double nx, double ny, double nr){
        x = nx;
        y = ny;
        r = nr;
    }
    double area(){
        return 4 * atan(1) * r * r;
    }
    double lenth(){
        return 2 * 4 * atan(1) * r;
    }
    void print(){
        cout << "("<< x << ", " << y << ") "<< "r = " << r << endl;
    }
 };
 class square : public figure {
    protected:
    double reb;
    public:
    square(double nx, double ny, double nreb){
        x = nx;
        y = ny;
        reb = nreb;
    }
    double area(){
        return reb * reb;
    }
    double lenth(){
        return 4 * reb;
    }
    void print(){
        cout << "(" << x << ", " << y << ")(" << x + reb << ", " << y << ")(" << x + reb << ", " << y - reb << ")(" << x << ", " << y - reb << ")" << endl;
    }

 };
 class triangle : figure {
    protected:
    double x2, y2, x3, y3, x1, y1;
    public:
    triangle(double nx1, double ny1, double nx2, double ny2, double nx3, double ny3){
        x1 = nx1;
        y1 = ny1;
        x2 = nx2;
        y2 = ny2;
        x3 = nx3;
        y3 = ny3;
    }
    void print(){
    cout << "(" << x1 << ", " << y1 << ")(" << x2 << ", " << y2 << ")(" << x3 << ", " << y3 << ")" << endl;    
    }
    double area(){
        double a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        double b = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
        double c = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
        double halfP = (a + b + c) / 2;
    }
 };

 int main(){
    figure *p, *p2, *p3;
    circle *c;
    //p = new figure(2, 3);
    //p -> print();
    p2 = new circle(5, 6, 8);
    c = new circle(2, 3, 4);
    c->print();
    cout << c->area() <<"\n"<< c->lenth()<< endl;
    p2->print();
    cout << p2->area() <<"\n"<< p2->lenth()<< endl;
    p3 = new square(2, 2, 2);
    p3->print();
    cout << p3->lenth() << endl;
    cout << p3->area() << endl;
    delete p2, c, p3;
    return 0;
 }//квадрат коорд лев верхугол + длин ребра, area, lenth, коорд 4 вершин.