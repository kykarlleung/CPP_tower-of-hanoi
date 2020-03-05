#include <iostream>
#include <vector>
using namespace std;

int main() {
	bool flag = true;
	string replay;
	while (flag == true)
	{
		vector<int> t[3];
		int n;
		cout << "Please enter the number of rings to move: ";
		cin >> n;
		cout << endl;
		// close is the number of spots to move to the right to find the "closest" tower.
		// If n is odd, close = 1 and far = 2.  If n is even, the reverse.
		int close, far;
		int from = 0, to, candidate = 1, move = 0;
		
		if ((n%2)!=0)     	// When Odd
		{
			close = 1;
			far = 2;
		}
		else				// When Even
		{
			close = 2;
			far = 1;
		}
		to = close;
			
		// Initialize the towers
		for(int i = n + 1; i >= 1; --i)
			t[0].push_back(i);
		t[1].push_back(n+1);
		t[2].push_back(n+1);
	
		while (t[1].size() < n+1) // while t[1] does not contain all of the rings
		{ 
			cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from+'A') << " to tower " << char(to+'A') << "\n";
		     
		    // Move the ring from "from" to "to" (first copy it, then delete it from "from")
			t[to].push_back(candidate);
	        t[from].pop_back();
		    
		    // from = the tower with the smallest ring that has not just been moved: (to+1)%3 or (to+2)%3
			if ((n%2)!=0)
			{
				if(t[(to+1)%3].back() < t[(to+2)%3].back())
					from=(to+1)%3;
	        	else
	            	from=(to+2)%3;
	            	
				if(t[(from)].back() < t[(from+close)%3].back())
	        	    to=(from+close)%3;
	        	else
	            	to=(from+far)%3;
		    // candidate = the ring on top of the from tower
				candidate = (t[from].back());
			}
		}
		cout << "Replay? Y/N: ";
		cin >> replay;
		cout << "----------------------------------" << endl ; 
		if (!(replay == "Y" || replay == "y"))
			flag = false;

	}
	return 0;
}
