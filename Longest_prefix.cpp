/**Let the dictionary contains the following words:
{are, area, base, cat, cater, children, basement}

Below are some input/output examples:
--------------------------------------
Input String            Output
--------------------------------------
caterer                 cater
basemexy                base
child                   < Empty >
**/
#include "bits/stdc++.h"
using namespace std;

struct node{
    bool endmark;
    node* next[27];
    node(){
        endmark=false;
        for(int i=0; i<26; i++){
            next[i]=NULL;
        }
    }
};

void _insert(node* root,char* str,int len){
    node* curr=root;
    for(int i=0; i<len; i++){
        int id=str[i]-'a';
        if(curr->next[id]==NULL){
            curr->next[id]=new node();
        }
        curr=curr->next[id];
    }
    curr->endmark=true;
}

string longest_prefix_matching(node* root,char* str){
    node* curr=root;
    string ans="",temp="";
    int len=strlen(str);
    for(int i=0; i<len; i++){
        int id=str[i]-'a';
        if(curr->next[id]==NULL){
            return ans;
        }
        else{
            temp=temp+str[i];
            curr=curr->next[id];
            if(curr->endmark){
                ans=temp;
            }
        }
    }
    return ans;
}

void del(node* curr){
    for(int i=0; i<26; i++){
        if(curr->next[i]){
            del(curr->next[i]);
        }
    }
    delete(curr);
}

int main(){
    node *root=new node();
    char keys[][8] = {"the", "a", "there","thhor", "answer", "any","by", "bye", "their", "hi"};
    for(int i=0; i<10; i++){
        _insert(root,keys[i],strlen(keys[i]));
    }
    cout<<longest_prefix_matching(root,"thhhor")<<endl;
    cout<<longest_prefix_matching(root,"all")<<endl;
    cout<<longest_prefix_matching(root,"th")<<endl;
    cout<<longest_prefix_matching(root,"the")<<endl;
    del(root);
    return 0;
}
