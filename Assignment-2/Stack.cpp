//Stack and stack problems
#include <iostream>

using namespace std;

template<class T>
class stack
{
    private:
    T *arr;
    int size;
    int top;
public:
    stack(){
        size = 100;
        top = -1;
        arr = new T[size];
    }
    stack(int s){
        size = s;
        top = -1;
        arr = new T[size];
    }
    void push(T element){
        if(top == size-1){
            cout << "Stack Overflow" << endl;
        }
        else{
            top++;
            arr[top] = element;
        }
    }
    T pop(){
        if(top == -1){
            cout << "Stack Underflow" << endl;
        }
        else{
            T temp = arr[top];
            top--;
            return temp;
        }
    }
    T Top()
    {
        if(top == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            return arr[top];
        }
    }
    bool isEmpty()
    {
        if(top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int Size()
    {
        return top+1;
    }

    void clear()
    {
        top = -1;
    }

    void print()
    {
        for(int i=top; i>=0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
//function to convert infix to postfix
string InfixToPostfix(string expression)
    {

        stack<char> S;
        string postfix = "";
        for(int i = 0;i< expression.length();i++) {


            if(expression[i] == ' ' || expression[i] == ',') continue;


            else if(IsOperator(expression[i]))
            {
                while(!S.isEmpty() && S.Top() != '(' && HasHigherPrecedence(S.Top(),expression[i]))
                {
                    postfix+= S.Top();
                    S.pop();
                }
                S.push(expression[i]);
            }
            else if(IsOperand(expression[i]))
            {
                postfix +=expression[i];
            }

            else if (expression[i] == '(')
            {
                S.push(expression[i]);
            }

            else if(expression[i] == ')')
            {
                while(!S.isEmpty() && S.Top() !=  '(') {
                    postfix += S.Top();
                    S.pop();
                }
                S.pop();
            }
        }

        while(!S.isEmpty()) {
            postfix += S.Top();
            S.pop();
        }

        return postfix;
    }
    bool IsOperand(char C)
    {
        if(C >= '0' && C <= '9') return true;
        if(C >= 'a' && C <= 'z') return true;
        if(C >= 'A' && C <= 'Z') return true;
        return false;
    }
    bool IsOperator(char C)
    {
        if(C == '+' || C == '-' || C == '*' || C == '/' || C== '$' || C== '^' || C== '%' )
            return true;

        return false;
    }
    int IsRightAssociative(char op)
    {
        if(op == '$') return true;
        return false;
    }
    int GetOperatorWeight(char op)
    {
        int weight = -1;
        switch(op)
        {
            case '+':
            case '-':
                weight = 1;
                break;
            case '*':
            case '/':
                weight = 2;
                break;
            case '$':
                weight = 3;
                break;
            case '^':
                weight = 4;
                break;

        }
        return weight;
    }
    bool HasHigherPrecedence(char op1, char op2)
    {
        int op1Weight = GetOperatorWeight(op1);
        int op2Weight = GetOperatorWeight(op2);

        if(op1Weight == op2Weight)
        {
            if(IsRightAssociative(op1)) return false;
            else return true;
        }
        return op1Weight > op2Weight;
    }

    //longest valid parenthesis
    int longestValidParentheses(string s) {
        stack<int> st;
        int n = s.length();
        int ans = 0;
        st.push(-1);
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                if(!st.isEmpty()){
                    st.pop();
                }
                if(!st.isEmpty()){
                    ans = max(ans,i-st.Top());
                }
                else{
                    st.push(i);
                }
            }
        }
        return ans;
    }
};

int main()
{
    //test longest valid parenthesis
    stack<int> s;
    string str;
    cout << "Enter the string: ";
    cin >> str;
    cout << s.longestValidParentheses(str) << endl;

    return 0;
}