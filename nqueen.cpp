#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp> 
#include<ext/pb_ds/tree_policy.hpp> 
#include<ext/pb_ds/trie_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define      ull                                                                            unsigned long long int
#define      lint                                                                                        long long
#define      ll                                                                                      long long int
#define      lf                                                                                        long double
#define      intmax                                                                                     1000000007
#define      endl                                                                                             "\n"
#define      loop(a,n)                                                               for(int i = a ; i <= n ; i++)
#define      rep(n)                                                                  for(int r = 0 ; r < n ; r ++)
#define      lambda(x)                                                                               void(auto &x)
#define      test_cases                                                                 int t;cin>>t;for(;t>0;t--)
#define      max_precise                         std::setprecision(std::numeric_limits<long double>::digits10 + 1)
#define      precise(n)                                                                       std::setprecision(n)
#define      pi                                                                           3.1415926535897932384626

typedef tree<lint, null_type, std::less<lint>, rb_tree_tag, tree_order_statistics_node_update>       ordered_set ;
typedef trie<std::string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update>trie_t;

void file_i_o(){

    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(0); 
    std::cout.tie(0);
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/
    return ;
}

lint power(lint a, lint b) // cal a ^ b
{
    lint res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

lint binpow(lint a, lint b, lint m) // (a^b)%m
{
    a %= m;
    lint res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

bool IsSafe(vector<string>&board , int &row , int &col){

    if(board[row][col] == '*'){
        return false;
    }
    for(int i = 0 ; i <= col ; i ++){
        if(board[row][i] == 'Q'){
            return false;
        }
    }

    for(int i = 0 ; i <= row ; i ++){
        if(board[i][col] == 'Q'){
            return false;
        }
    }

    int i = row;
    int j = col;
    while(i>=0 && j>=0){
        if(board[i][j] == 'Q'){
            return false;
        }
        i--;
        j--;
    }
    i = row;
    j = col;
    while(i>=0 && j<8){
        if(board[i][j] == 'Q'){
            return false;
        }
        i--;
        j++;
    }

    return true;
}

void NQueen(vector<vector<string>>&sol , vector<string>&board , int row){

    if(row == 8){
        sol.emplace_back(board);
        return ;
    }

    for(int i = 0 ; i < 8 ; i ++){

        if(IsSafe(board,row , i)){

            board[row][i] = 'Q';
            NQueen(sol,board,row+1);
            board[row][i] = '.';
        }
    }

    return ;
}

int32_t main(int argv , const char *argc[]){

    file_i_o;
    
    vector<vector<string>>sol;
    vector<string>board;
    board.reserve(8);
    for(int i = 0 ; i < 8 ; i ++){
        string temp;
        cin>>temp;
        board.emplace_back(temp);
    }
    // board set
    NQueen(sol,board,0);
    cout<<sol.size()<<endl;
    return 0;
}
