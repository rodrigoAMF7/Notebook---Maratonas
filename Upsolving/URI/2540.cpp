#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define DINF (double)1e+30

#define forn(i, n) for ( int i = 0; i < (n); ++i )
#define forxn(i, x, n) for ( int i = (x); i < (n); ++i )
#define forr(i, a, b) for ( int i = (a); i <= (b); ++i )
#define ford(i, a, b) for ( int i = (a); i >= (b); −−i )

using namespace std;

int main(){
	int n;

	while(true){
		int resultado = 0;

		cin >> n;
		if(!cin) break;

		forn(i, n){
			int aux;
			cin >> aux;
			if(aux == 1)
				resultado++;
		}
		if(resultado >= ((2.0*n)/3.0)){
			cout << "impeachment" << endl;
		}else{
			cout << "acusacao arquivada" << endl;
		}
	}
	
    return 0;
}