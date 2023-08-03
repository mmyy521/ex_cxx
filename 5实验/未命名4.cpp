#include<iostream>
#include<cmath>
using namespace std;
const double D = 1e-6; 

template<typename T>
class Vector
{
private:
    T x, y, z;
	public:
    	Vector<T>(T a,T b,T c){
    		x=a;
    		y=b;
    		z=c;
		}
    	Vector<T>(const Vector<T> & v){
    		x=v.x;
    		y=v.y;
    		z=v.z;
		}
		Vector<T>(){
		}
		friend ostream& operator<<(ostream& os, const Vector<T>& v){
			os <<v.x<<" "<<v.y<<" "<<v.z;
			return os;
		}
		friend istream& operator>>(istream& is, Vector<T>& v){
			is>>v.x>>v.y>>v.z;
			return is;
		}
		friend Vector<T> operator*(T n,  const Vector<T>& v){
			Vector<T> tem;
			tem.x=v.x*n;
			tem.y=v.y*n;
			tem.z=v.z*n;
			return tem;
		}
		friend Vector<T> operator+(const Vector<T>& v1, const Vector<T>& v2){
			Vector<T> tem;
			tem.x=v1.x+v2.x;
			tem.y=v1.y+v2.y;
			tem.z=v1.z+v2.z;
			return tem;
		}
    	friend bool operator==(const Vector<T>& v1, const Vector<T>& v2){
    		if(abs(v1.x-v2.x)<D&&abs(v1.y-v2.y)<D&&abs(v1.z-v2.z)<D)
    		return 1;
    		else
    		return false;
		}
		Vector<T>& operator=(const Vector<T>& v){
		
			x=v.x;
			y=v.y;
			z=v.z;
			return *this;
		}
};


int main()
{
    double a, b, c;
    std::cin >> a >> b >> c;
    Vector<double> v1(a, b, c), v2(v1), v3, v4;
    double d;
    std::cin >> d;
    v4 = d * v1 + v2;

    std::cout << v4 <<std::endl;

    Vector<double>  v;
    std::cin >> v;

    int flag = (v4 == v);
    std::cout << flag << std::endl; 

    return 0;
}
