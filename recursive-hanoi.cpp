#include <iostream>
using namespace std;

void move(char from, char to, char extra, int n){
	static int call=0;
	//cout << call++ << " ";
	if(n==1){
		cout << call++ << ": ";
		cout << "Move ring from " << from << " to " << to << endl;
		return;
	}
	move(from, extra, to, n-1);
	cout << call++ << ": ";
	cout << "Move ring from " << from << " to " << extra << endl;
	move(extra, to, from, n-1);
	return;
}

int main(){
	char replay = 'Y';
	while(replay=='Y' || replay=='y')
	{
		cout << "Enter the number of rings to move: " ;
		int n;
		cin >> n;
		move('A', 'B', 'C', n);
		cout << "--------------------------\nReplay? (y/n): ";
		cin >> replay;
	}
	return 0;
}
