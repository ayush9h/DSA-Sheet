class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
           stack<int> st;
           int n=asteroids.size();
           for(int i=0;i<n;i++){
               bool flag=true;

               while(st.size() && (st.top()>0 && asteroids[i]<0)){
                 if(abs(st.top())<abs(asteroids[i])){
                     st.pop();
                     continue;
                 }
                 else if(abs(st.top())==abs(asteroids[i])){
                     st.pop();
                     flag=false;
                 }
                 
                     flag=false;
                     break; 
               }
             if(flag==true){
                 st.push(asteroids[i]);
             }
           } 

           int l=st.size();
           vector<int>res(l);
           for(int i=l-1;i>=0;i--){
               res[i]=st.top();
               st.pop();
           }

           return res;
           
    }
};
