/*	Megan Taite
 * 	524: Prime Ring Problem
 * 	Current Status: Accepted!
 */

#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

int caseCount = 1;

struct availData{
	int num;
	bool valid;
};

void backTrack(stack<int> primeRing, availData availArr[], int size);

bool isPrime(int n);

int main(){

	//create var for uva input
	int size;
	//while uva provides another input
	while (cin >> size){

		//create array to hold available numbers
		availData availArr[size];
		for(int i = 0; i < (size); i++){
			availArr[i].valid = true;
			availArr[i].num = i+1;
		}
		availArr[0].valid = false;

		//create stack that will hold prime ring
		stack<int> primeRing;
		primeRing.push(1);

		if(caseCount!=1){
			cout << endl;
		}

		cout << "Case " << caseCount << ":" << endl;


		if((size != 1) && ((size % 2) != 0)){
			//will not work
			//sum of two odds is not prime
		}
		else{
			//call back track function
			backTrack(primeRing, availArr, size);
		}

		caseCount++;


	}

	return 0;

}

bool isPrime(int num){
	//if the number is divisible by any # other than 1 and itself
	//return false (it is not prime)
    for (int i=2; i<num; i++)
    {
    	//if remained is zero, it divided evenly: NOT PRIME!
    	if((num % i) == 0)
    	return false;
    }
    //else true will be returned: the number is prime
    return true;
}


void backTrack(stack<int> primeRing, availData availArr[], int size){

	//BASE CASE
	//prime ring is now of the correct size
	if(primeRing.size() == size){
		//print the ring
			int printArray[size];
			//reverse, print and return
			if(isPrime(primeRing.top() + 1))
			{
				for(int p = size-1; p > -1; p--){
					printArray[p] = primeRing.top();
					primeRing.pop();
				}
				for(int pN = 0; pN < size; pN++){
					cout << printArray[pN];
					if(pN != size-1){
						cout << " ";
					}
				}
				cout << endl;
			}
	}
	else{
			int currNum;
			//get next available number that sums and is prime
			//with the top value in ring
			for(int i = 0; i < size;i++){
				if(availArr[i].valid == true){
					currNum = availArr[i].num;

				if(isPrime(primeRing.top()+availArr[i].num)){


					availData newAvailArr[size];
					//create new array of available numbers
					for(int j = 0; j < size;j++){
						newAvailArr[j].valid = availArr[j].valid;
						newAvailArr[j].num = availArr[j].num;
					}

					//push current number onto prime ring
					primeRing.push(currNum);
					//set the currNum as not available in NEW avail arr
					newAvailArr[currNum-1].valid = false;
					//recursive call
					backTrack(primeRing,newAvailArr,size);
					//pop from ring upon return
					primeRing.pop();

				}
				}
			}

		}

}


