class Solution {
public:
    string strip(string s){
        string res;
        int i = 0;
        for(; i < s.size() ; ++i){
            if (s[i] != ' '){
                if(s[i] == '-'){res = s.substr(i+1, s.size()-i) + '-';}
                else if (s[i] == '+'){res = s.substr(i+1, s.size()-i) + '+';}
                else{res = s.substr(i, s.size()-i) + '+';}
                break;
            }
        }
        return res;
    }

    int myAtoi(string s) {
        s = strip(s);
        if ( s == "") return 0;
        long result;
        int i = 0;
        string middle;
        for(; i < s.size() ; ++i){
            if (!isdigit(s[i]) ){
                break;
            }
        }
        i ? middle = s.substr(0, i) : middle = '0';
        try{
            result = stoi(s[s.size() - 1] + middle);
        }
        catch(out_of_range){
            if(s[s.size() - 1] == '-'){
                result = INT_MIN;
            }else{
                result = INT_MAX;
            }
        }
        return result;
    }
};

/*
This is my one got weird between debugging but finally did not a good answer by the way.
Have to improve lot

class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int it=0, sign=1;
        long long int x=0;

        while(it<n && s[it]==' '){
            it++;
        }

        if(it<n && (s[it]=='+' || s[it]=='-')){
            sign = (s[it]=='-') ? -1 : 1;
            it++;
        }

        while(it<n && s[it]>='0' && s[it]<='9'){
            int k=s[it]-'0';

            if(x>(INT_MAX - k)/10){
                return (sign==1) ? INT_MAX : INT_MIN;
            }

            x = x * 10 + k;
            it++;
        }

        return x * sign;
    }
};

this is a good answer */