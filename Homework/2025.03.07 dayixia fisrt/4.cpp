#include<iostream>
using namespace std;
int main(){
    char a[200];
    cin>>a;
    int vowels=0,consonants=0;
    for(int i=0;i<200;i++){
        if(a[i]=='\0') break;
        if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u') vowels++;
        else if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')) consonants++;
    }
    cout<<vowels<<endl<<consonants<<endl;
    return 0;
}
