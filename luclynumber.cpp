#include<bits/stdc++.h>
using namespace std;
int main ()
{

        string s;
        getline(cin,s);
        int sum=0;
        for(int i=0; i<s.size(); i++)
        {

            if(s[i]=='4'||s[i]=='7')
            {
                sum=sum+1;


            }

        }
        cout<<sum<<endl;
        if(sum==7||sum==4)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }



    return 0;
}
