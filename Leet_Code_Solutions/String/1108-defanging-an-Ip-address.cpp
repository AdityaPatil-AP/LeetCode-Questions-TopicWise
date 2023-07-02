class Solution {
public:
    // Using replace : 
    // Replace 7 characters of the str starting from 0th position. with the 7 characters of str1 
    // starting from 0th position
    // str.replace(0, 7, str1, 0, 7);
    // replace_if() replaces each element in the range [first, last) for which the unary predicate i.e. op(elem) yields true with newValue. 
    // string defangIPaddr(string address) {
    //     for(int i = 0;i < address.size();i++){
    //         if(address[i] == '.'){
    //             address.replace(i, 1, "[.]", 0, 3);
    //             i+=2;
    //         }
    //     }
    //     return address;
    // }
    
    // Using insert;
    // string defangIPaddr(string address){
    //     for(int i = 0;i < address.size();i++){
    //         if(address[i] == '.'){
    //             address.insert(i, "[", 0, 1);
    //             address.insert(i + 2, "]", 0, 1);
    //             i+=2;
    //         }
    //     }
    //     return address;
    // }
    
    // Using simple method
    string defangIPaddr(string address){
        string res;
        for(int i = 0;i < address.size();i++){
            if(address[i] == '.'){
                res += "[.]";
            }
            else res += address[i];
        }
        return res;
    }
};