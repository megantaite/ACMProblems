/* Worked on as a team of 3 in preparation for ACM competition
 * 1062: Containers
 * Status: Accepted!
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
        string input;
        int casenumb = 0;
        while((cin>>input) && (input!= "end"))
        {
                char top[input.length()];
                casenumb++;
                int strct = 0;
                int stkct = 0;
                bool newstack = false;

                for(int l = 0;l<input.length();l++)
                {
                        top[l] = '@';
                }

                while(input.length() != strct)
                {
                        newstack = false;
                        if(stkct == 0)
                        {
                                stkct++;
                                top[0] = input[0];
                        }
                        else
                        {

                                for(int i=0;i<input.length();i++)
                                {
                                        if((input[strct] <= top[i]) && (top[i] != '@'))
                                        {
                                                top[i] = input[strct];
                                                newstack = true;
                                                break;
                                        }
                                }
                                if(newstack==false)
                                {
                                        top[stkct] = input[strct];
                                        stkct++;
                                }
                        }

                        strct++;
                }

                cout<<"Case "<<casenumb<<": "<<stkct<<endl;
        }

        return 0;
}
