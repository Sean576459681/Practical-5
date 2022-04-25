//// ConsoleApplication4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
////
//
#include <iostream>
#include<vector>
using namespace std;
class MapGeneric {
private:
    vector<int> inter_varild;
    virtual int f(int) = 0;
public:
    vector<int> map(vector<int>);
};
vector<int> MapGeneric::map(vector<int>a) {
    vector<int>::iterator it;
    for (it=a.begin(); it!=a.end(); it++) {
        this->inter_varild.push_back(f(*it));
    }
    return this->inter_varild;
}
class MapSquare :public MapGeneric {
private:
    int f(int a) { return a * a; }
};
class MapAbsoluteValue :public MapGeneric {
private:
    int f(int a) { if (a >= 0) return  a; else return -a; }
};
class MapTriple :public MapGeneric {
private:
    int f(int a) { return 3 * a; }
};
//int main()
//{
//    MapGeneric* a,*b,*c;
//    a = new MapTriple();
//    c = new MapSquare();
//    b = new MapAbsoluteValue();
//    vector<int> d;
//    for (int i = 0; i < 3; i++) {
//        int k;
//        cin >> k;
//        d.push_back(k);
//    }
//    vector<int>f = b->map(d);
//    vector<int>g = a->map(d);
//    vector<int>e=c->map(d);
//
//    for (int i = 0; i < 3; i++) {
//        cout << e[i] << "\t";
//       
//    }
//    cout << "\n";
//    for (int i = 0; i < 3; i++) {
//        cout << f[i] << "\t";
//
//    }
//    cout << "\n";
//    for (int i = 0; i < 3; i++) {
//        cout << g[i] << "\t";
//
//    }
//    return 0;
//}
//#include<iostream>
//#include<vector>
//#include<map>
//using namespace std;
class ReduceGeneric {
private:
    //vector<int>inter_varild;
    int v;
	virtual int binaryOperator(int, int) = 0;
public:
	int reduce(vector<int>);
};
int ReduceGeneric::reduce(vector<int>a) {
    vector<int>::iterator it;
    for (it=a.begin(); ; ) {
        if(*it>*(it+1))
         *(it+1)=(binaryOperator(*it,*(it+1)));
        else
            *(it + 1)=(binaryOperator(*(it+1), *it));
        if (it + 2 == a.end())
        {
            v = *(it + 1);
            break;
        }
        it++;
    }
    return v;
}
class ReduceMinimum :public ReduceGeneric {
    int binaryOperator(int a, int b) { if (a < b)return a; else return b; }
};
class ReduceGCD :public ReduceGeneric {
    int binaryOperator(int a, int b) { if (a % b == 0)return b; else return binaryOperator(b, a % b); }
};
//int main()
//{
//    ReduceGeneric* a, * b;
//    a = new ReduceMinimum();
//    b = new ReduceGCD();
//    vector<int> d;
//    for (int i = 0; i < 4; i++) {
//        int k;
//        cin >> k;
//        d.push_back(k);
//    }
//    int f = b->reduce(d);
//    int g = a->reduce(d);
//    cout << f << endl << g << endl;
//    return 0;
//}
//#include<iostream>
//#include<vector>
//#include<map>
//using namespace std;
//
class FilterGeneric {
private:
	vector<int> inter_varild;
	virtual bool g(int) = 0;
public:
	vector<int> filter(vector<int>);
};
vector<int> FilterGeneric::filter(vector<int>a) {
	vector<int>::iterator it;
	for (it=a.begin(); it!=a.end(); it++) {
		if(g(*it))
			this->inter_varild.push_back(*it);
	   }
	return this->inter_varild;
}
class FilterOdd :public FilterGeneric {
	bool g(int a) { if (a % 2 == 0)return false; else return true; }
};
class FilterNonPositive :public FilterGeneric {
	bool g(int a) { if (a < 0)return true; else return false; }
};
class FilterTwoDigitPositive :public FilterGeneric {
	bool g(int a) { int tmp = a, tmp1 = 0; while (tmp != 0) { tmp /= 10; tmp1++; }; if (a > 0&&tmp1==2)return true; else return false; }
};
int main()
{
    FilterGeneric* a,*b,*c;
    a = new FilterOdd();
    b = new FilterNonPositive();
    c = new FilterTwoDigitPositive();
    MapGeneric* a1, * b1, * c1;
    a1 = new MapTriple();
    b1 = new MapSquare();
    c1 = new MapAbsoluteValue();
    ReduceGeneric* a2, * b2;
    a2 = new ReduceMinimum();
    b2 = new ReduceGCD();
    vector<int> d;
    for (int i = 0; i < 20; i++) {
        int k;
        cin >> k;
        d.push_back(k);
    }
    d = c1->map(d);
    d = a1->map(d);
    d = a->filter(d);
    d = c->filter(d);
    int temp = a2->reduce(d);
    int temp1 = b2->reduce(d);
    cout << temp << " " << temp1;
    return 0;
}
