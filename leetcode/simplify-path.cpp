class Solution {
public:
    string simplifyPath(string path) {
        stack<string> pathStack;
        int i(0),j(0),len(path.length());
        //get the essential element first by ignoring '/'and then join different segments.
        while(i<len){
            while(path[i]=='/'&&i<len)
                i++;
            if(i==len)
                break;
            j=i;
            while(path[j]!='/'&&j<len)
                j++;
            string seg = path.substr(i,j-i);
            if(seg==".")
                continue;
            if(seg==".."){
                if(!pathStack.empty())
                    pathStack.pop();
                continue;
            }
            pathStack.push(seg);
            i=j;
        }
        
        if(pathStack.empty())
            return "/";
        string res;
        while(!pathStack.empty()){
            res="/"+pathStack.top()+res;
            pathStack.pop();
        }
        return res;
    }
};