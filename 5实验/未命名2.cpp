#include<iostream>
#include<string>
using namespace std;

template<typename T>  // template<typename T, int N>
void Input(T *a,const int n){
	for(int i=0;i<n;i++)
		cin>>a[i];	
}
template<typename T>
void Sort(T *a,const int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				T tep;
				tep=a[j];
				a[j]=a[j+1];
				a[j+1]=tep;
			}
		}
	}
	
}
template<typename T>
void Output(T *a,const int n){
	for(int i=0;i<n-1;i++){
		cout<<a[i]<<", ";
	}
  cout<<a[n-1]<<endl;
}
int main()
{
    const int LEN = 5;
    int type;
    while (std::cin >> type)
    {
        switch (type) 
        {
            case 0: 
            {
                int a1[LEN];
                Input<int>(a1, LEN); Sort<int>(a1, LEN); Output<int>(a1, LEN);
                break;
            }
            case 1: 
            {
                char a2[LEN];
                Input(a2, LEN); Sort(a2, LEN); Output(a2, LEN); 
                break; 
            }
            case 2: 
            {
                double a3[LEN];
                Input(a3, LEN); Sort(a3, LEN); Output(a3, LEN);
                break;
            }
        }
    }

    return 0;
}
