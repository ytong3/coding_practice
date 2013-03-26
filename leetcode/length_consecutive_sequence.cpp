class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<int, int> check_table;
        check_table.clear();
        int to_return=0;
        
        for(int i=0;i<num.size();i++){
            if(check_table.count(num[i])) continue;
            if(!check_table.count(num[i])){
                check_table.insert(make_pair(num[i],1));//bug here
                int new_length=1;
            
            if(check_table.count(num[i]-1)) new_length+=check_table[num[i]-1];
            if(check_table.count(num[i]+1)) new_length+=check_table[num[i]+1];
            
            //update the lengths(values) at the head and tail of the sequence
            /*
            int temp_key=num[i];
            while(check_table.count(temp_key)){
                temp_key--;
            }
            */
            check_table[num[i]] = new_length;
            if(check_table.count(num[i]-1)) 
                check_table[num[i]-check_table[num[i]-1]]=new_length;
            if(check_table.count(num[i]+1))
                check_table[num[i]+check_table[num[i]+1]]=new_length;
            to_return = max(to_return,new_length);
            }
        }
        return to_return;
    }
};
