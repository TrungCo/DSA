#include <iostream>

using namespace std;


class interger_number
{
private:
    int* number;
public:
    int n;
    interger_number(){
        n=0;
        number= new int[n];
    };
    int access(int _n){
        return number[_n]; 
    }
    void add(int x){
        number[n]=x;
        n++;
    };//o[1]
    void add_head(int x){
        n++;
        int a,b;
        a=number[0];
        number[0]=x;
        for (int i=1; i<n; i++){
            b=number[i];
            number[i]=a;
            a=b;
        }

    }//o[n]
    void insert_int(int x, int a){
        n++;
        for (int i=n-1; i>x; i--){
            number[i]=number[i-1];
        }
        number[x]=a;
    }//o[n]
    void delet_head(){
        for (int i=0; i<n-1; i++){
            number[i]=number[i+1];
        }
        n--;
    }//o[n]
    void delet(){
        n--;
    }//o[1]
    void delet_x(int x){
        for (int i=x; i<n-1; i++){
            number[i]=number[i+1];
        }
        n--;
    }//o[n]
    void browse(){
        for (int i=0; i<n;i++){
        cout << number[i];
        cout <<" ";
    }
    }//o[n]
    void browse_in(){
        for (int i=n-1; i>=0;i--){
        cout << number[i];
        cout <<" ";
            
    }
    }//o[n]

};




int main() {
    interger_number a;
    a.add(5);
    a.add(6);
    a.add_head(2);
    a.insert_int(1,36);
    a.delet_x(1);
    a.browse_in();
}