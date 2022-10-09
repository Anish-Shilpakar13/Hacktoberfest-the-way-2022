// Cpp program to check if two strings are anagram or not.
//Please note : only lowercase alphabets should be taken as input. No special characters,fullstop,comma,numbers are allowed.
//The code is accepted in geekforgeeks.

 #include<iostream>
 using namespace std;

 bool isAnagram(string a, string b){
        
        int lena[26],lenb[26]; // lena and lenb are two hash arrays.lena stores the count of the characters in string 1 and lenb store the count of characters in string 2.
        for(int i = 0; i < 26; i++){  
            lena[i] = 0; // Initially count of all characters is set to zero.
            lenb[i] = 0;
            
        }
        if(a.size() != b.size()){ //if both string are of unequal length, then they are not anagram.
            return 0;
        }
        for(int i = 0; i < a.size(); i++){//we iterate through both the strings and store their character count in lena and lenb.
            lena[a[i]-'a']++; 
            lenb[b[i]-'a']++;
            
        }
         for(int i = 0; i < 25; i++){ // compare both lena and lenb
            if(lena[i] != lenb[i]){ //if both strings are not anagram, return 0
                return 0;
                
            }
            
        }
        return 1;// if both strings are anagram, return 1
       
      
        
}

int main(){
    
    string s1,s2;
    int status;
    cout<<"Enter string 1"<<endl;
    cin>>s1;
    cout<<"Enter string 2"<<endl;
    cin>>s2;
    status = isAnagram(s1,s2);
    if(status == 1){
        cout<<"Anagram"<<endl;
    }
    else{
        cout<<"Not Anagram"<<endl;
    }




}