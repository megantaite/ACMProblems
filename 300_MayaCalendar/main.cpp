/* Name: Megan Taite
 * Problem #: Problem 300 - ACM Maya Calendar
 * Last Updated: September 11, 2017
 * Current Status: Accepted!
 */

#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	//get number of dates
	int dateCount;
	cin >> dateCount;
	cout << dateCount << endl;

	string dayStrInput, monthInput;
	int yearInput, dayIntInput, totDaysPassed;

	//Haab months 0-19
	string haabMonths[20] = {"pop","no","zip","zotz","tzec","xul","yoxkin","mol",
		"chen","yax","zac","ceh", "mac", "kankin","muan","pax","koyab","cumhu", "uayet"};

	//Tzolkin 20 day names
	string tzolkinDay[20] = {"imix","ik","akbal","kan","chicchan","cimi","manik","lamat",
			"muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};

	for(int i = 0; i < dateCount; i++) 
  {
		cin >> dayStrInput >> monthInput >> yearInput;

		//Remove . at end of day

		int strCount = 0;
		int strLength = dayStrInput.length();

		while(strCount < strLength) 
    {
			char c = dayStrInput[strCount];
			if(c == '.') 
      {
				dayStrInput.erase(strCount, 1);
				strLength--;
		  }
		  else 
      {
				strCount++;
		  }
		}

		//convert the string to an int
		dayIntInput = stoi(dayStrInput);

		//OKAY HERE WE GO WITH THE MATH
		//CONVERT HAAB TO TZOLKIN

		//Step 1: Get the total amount of days passed for all time
		//which = (years * 365) + (months that have PASSED * 20) + days into current month

		//what is the corresponding number for input month?
		int corrMoNum;
		//convert month input to lowercase just in case
		transform(monthInput.begin(), monthInput.end(), monthInput.begin(), ::tolower);

		for(corrMoNum=0; corrMoNum < 20; corrMoNum++)
    {
			if(monthInput == haabMonths[corrMoNum]) 
      {
				break;
			}
		}

		totDaysPassed = (yearInput*365) + (corrMoNum*20) + (dayIntInput); 

		//Step 2: Divide tot. # of days by 260 & truncate (260 because that is the # of days
		//			in the Tzolkin calendar

		int tzolkinYear = totDaysPassed/260;

		//Step 4: To get the current day # in Tzolkin....
		//	Take # of 13 day cycles passed and subtract from curr. years passed

		int outputDayNum = totDaysPassed%13;

		//Step 5: To get specific word associated with the day...
		//		Take # of 20 day cycles passed and subtract all these days from tot. days

		int daysIntoCurrentPeriod = totDaysPassed%20;

		string outputDayName = tzolkinDay[daysIntoCurrentPeriod];	//minus one because array starts at 0 but days
																	//start at 1

		cout << (outputDayNum+1) << " " << outputDayName << " " << tzolkinYear << endl;

	}

	return 0;
  
}
