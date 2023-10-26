#include<iostream>
#include<math.h>
#include<stack>
#include<string.h>
using namespace std;
int cal(int v1, int v2, char op){
    if(op == '^'){
        return pow(v1, v2);
    }
    else if(op == '+'){
        return v1+v2;
    }
    else if(op == '-'){
        return v1-v2;
    }
    else if(op == '/'){
        return v1/v2;
    }
    else{
        return v1*v2;
    }
}

int result(string &str){
    stack<int> num;
    for(int i=0; i<str.size(); i--){
        char ch = str[i];
        if(isdigit(ch)){
            num.push(ch - '0');
        }
        else{
            int v2 = num.top();
            num.pop();
            int v1 = num.top();
            num.pop();
            num.push(cal(v1, v2, ch));
        }
    }
    return num.top();
}
int main(){
    string s = "-9+*531";
    int res = result(s);
    cout<<res<<endl;

    return 0;
}