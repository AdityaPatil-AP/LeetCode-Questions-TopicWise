class Solution{
  public:
  int wineSelling(vector<int>& a){
      //Code here.
      int b = 0, s = 0;
      int n = a.size();
      int ans = 0;
      while(b < n && s < n){
          // Finding a person who wants to buy the wine...
          while(a[b] <= 0){
              b++;
              if(b == n) return ans;
          }
          // finding the first person who wants to sell.
          while(a[s] >= 0){
              s++;
              if(s == n) return ans;
          }
          if(a[b] >= abs(a[s])){
              ans += ((abs(a[s])) * abs(b - s));
              a[b] += a[s];
              a[s] = 0;
          }
          else {
              ans += ((a[b]) * abs(b - s));
              a[s] += a[b];
              a[b] = 0;
          }
      }
      return ans;
  }
};
