#include <bits/stdc++.h>
using namespace std;
string doSum(string a, string b){
    if(a.size() < b.size())
        swap(a, b);
 
    for(int i=b.size()-1, j = a.size()-1; i>=0; i--, j--){
        a[j] += (b[i]-'0');

     }
    for(int i=a.size()-1; i>0; i--){
        if(a[i] > '9'){
            int d = a[i]-'0';
            a[i-1] = ((a[i-1]-'0') + d/10) + '0';
            a[i] = (d%10)+'0';
        }
     }
    if(a[0] > '9'){
        string k;
        k += a[0];
        a[0] = ((a[0]-'0')%10)+'0';
        k[0] = ((k[0]-'0')/10)+'0';
        a = k+a;
    }
    return a;
}
int main(){
 	int t, n, f;
 	string a, b, c;
 	scanf("%d", &t);
 	while(t--){
 		cin>>a>>b;
 		reverse(a.begin(), a.end());
 		reverse(b.begin(), b.end());
 		c = doSum(a, b);
 		n = c.size() - 1;
 		f = 0;
 		for(int i = n; i >= 0; i--){
 			if(c[i] > '0' && !f){
 			 	f = 1;
 		 	}
 		 	if(f) printf("%c", c[i]);
 		}
 		printf("\n");
 	}
 	return 0;
}