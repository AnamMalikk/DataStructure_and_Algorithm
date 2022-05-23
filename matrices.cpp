#include<iostream>
using namespace std;

template<class t>
class diagonal{
    t*a;
    int size;
    public:
        diagonal(int s1){
            size = s1;
            a = new t[size];
        }
        void store(int i, int j, t x);
        t retrieve(int i, int j);

};

template <class t>
void diagonal<t>::store(int i, int j, t x){
    if((i<1)||(j<1)||(i>size)||(j>size)){
        cout << "Invalid index!!\n";
        return;
    }
    else if (i==j)
        a[i-1] = x;
    else if (x!=0){
        cout << "x must be zero!!\n";
        return;
    }
}

template <class t>
t diagonal<t>::retrieve(int i, int j){
    if((i<1)||(j<1)||(i>size)||(j>size)){
        cout << "Invalid index!!\n";
        exit(1);
    }
    else if (i==j)
        return a[i-1];
    else
        return 0;
}

template <class t>
class low_tri{
    t*a;
    int size;
    public:
        low_tri(int s1){
            size = s1*(s1+1)/2;
            a = new t[size];
        }
        void store(int i, int j, t x);
        t retrieve(int i, int j);

};

template <class t>
void low_tri<t>::store(int i, int j, t x){
    if((i<1)||(j<1)||(i>size)||(j>size)){
        cout << "Invalid index!!\n";
        return;
    }
    else if (i>=j)
        a[(i*(i-1)/2)+(j-1)] = x;
    else if (x!=0){
        cout << "x must be zero!!\n";
        return;
    }
}

template <class t>
t low_tri<t>::retrieve(int i, int j){
    if((i<1)||(j<1)||(i>size)||(j>size)){
        cout << "Invalid index!!\n";
        exit(1);
    }
    else if (i>=j)
        return a[(i*(i-1)/2)+(j-1)];
    else
        return 0;
}

template <class t>
class upper_tri{
    t*a;
    int size;
    public:
        upper_tri(int s1){
            size = s1*(s1+1)/2;
            a = new t[size];
        }
        void store(int i, int j, t x);
        t retrieve(int i, int j);

};

template <class t>
void upper_tri<t>::store(int i, int j, t x){
    if((i<1)||(j<1)||(i>size)||(j>size)){
        cout << "Invalid index!!\n";
        return;
    }
    else if (j>=i)
        a[(j*(j-1)/2)+(i-1)] = x;
    else if (x!=0){
        cout << "x must be zero!!\n";
        return;
    }
}

template <class t>
t upper_tri<t>::retrieve(int i, int j){
    if((i<1)||(j<1)||(i>size)||(j>size)){
        cout << "Invalid index!!\n";
        exit(1);
    }
    else if (j>=i)
        return a[(j*(j-1)/2)+(i-1)];
    else
        return 0;
}

template <class t>
class symmetric{
    t*a;
    int size;
    public:
        symmetric(int s1){
            size = s1*(s1+1)/2;
            a = new t[size];
        }
        void store(int i, int j, t x);
        t retrieve(int i, int j);

};

template <class t>
void symmetric<t>::store(int i, int j, t x){
    if((i<1)||(j<1)||(i>size)||(j>size)){
        cout << "Invalid index!!\n";
        return;
    }
    else{
        a[(i*(i-1)/2)+(j-1)] = x;
        return;
    }
}

template <class t>
t symmetric<t>::retrieve(int i, int j){
    if((i<1)||(j<1)||(i>size)||(j>size)){
        cout << "Invalid index!!\n";
        exit(1);
    }
    else if (i>=j)
        return a[(i*(i-1)/2)+(j-1)];
    else
        return a[(j*(j-1)/2)+(i-1)];
}

int main()
{
    int x, i, j, size, choice;
    char ch;
    cout << "\nEnter the size of the matrix : ";
    cin >> size;
    diagonal<int> d(size);
    low_tri<int> l(size);
    upper_tri<int> u(size);
    symmetric<int> s(size);
    do{
        cout << "\n----------------Main Menu------------------\n";
        cout << "1.Diagonal\n";
        cout << "2.LowerTriangular\n";
        cout << "3.UpperTriangular\n";
        cout << "4.Symmetric\n";
        cout << "\n";
        cout << "\nEnter your choice : ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "\nEnter the elements : \n";
                for(i=1; i<=size; i++)
                    for(j=1; j<=size; j++){
                        cin >> x;
                        d.store(i, j, x);
                    }
                cout << "\nThe matrix is : \n";
                for(i=1; i<=size; i++){
                    for(j=1; j<=size; j++){
                        cout << d.retrieve(i, j) << "\t";
                    }
                    cout << "\n";
                }
                break;
            case 2:
                cout << "\nEnter the elements : \n";
                for(i=1; i<=size; i++)
                    for(j=1; j<=size; j++){
                        cin >> x;
                        l.store(i, j, x);
                    }
                cout << "\nThe matrix is : \n";
                for(i=1; i<=size; i++){
                    for(j=1; j<=size; j++){
                        cout << l.retrieve(i, j) << "\t";
                    }
                    cout << "\n";
                }
                break;
            case 3:
                cout << "\nEnter the elements : \n";
                for(i=1; i<=size; i++)
                    for(j=1; j<=size; j++){
                        cin >> x;
                        u.store(i, j, x);
                    }
                cout << "\nThe matrix is : \n";
                for(i=1; i<=size; i++){
                    for(j=1; j<=size; j++){
                        cout << u.retrieve(i, j) << "\t";
                    }
                    cout << "\n";
                }
                break;
            case 4:
                cout << "\nEnter the elements : \n";
                for(i=1; i<=size; i++)
                    for(j=1; j<=size; j++){
                        cin >> x;
                        s.store(i, j, x);
                    }
                cout << "\nThe matrix is : \n";
                for(i=1; i<=size; i++){
                    for(j=1; j<=size; j++){
                        cout << s.retrieve(i, j) << "\t";
                    }
                    cout << "\n";
                }
                break;
            default:
                cout << "\nWrong Choice!";
        }
        cout << "\nDo you want to continue? (y/n) \n";
        cin >> ch;
    } while (ch == 'y'|| ch == 'Y');
}

