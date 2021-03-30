// Writer note: initially I use stack<string>
// guess what: it was worse because on every loop we need to process strings before doing the arithmetic operations
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                s.push(atoi(tokens[i].c_str()));
            } else {
                int num2 = s.top();
                s.pop();
                int num1 = s.top();
                s.pop();
                
                if (tokens[i] == "+") {
                    s.push(num1+num2);
                } else if (tokens[i] == "-") {
                    s.push(num1-num2);
                } else if (tokens[i] == "*") {
                    s.push(num1*num2);
                } else if (tokens[i] == "/") {
                    s.push(num1/num2);
                }
            }
        }
        
        return s.top();
    }
};