class Solution {
public:
bool isValid(string word) {
    if(word.size() < 3) return 0;
    int vowel = 0, consonant = 0;
    for(auto &it: word){
        if(!isalpha(it) && !isdigit(it)) return 0;
        if(it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u' ||
           it == 'A' || it == 'E' || it == 'I' || it == 'O' || it == 'U')
            vowel = 1;
        else if (isalpha(it)) consonant = 1;
    }
    return (vowel && consonant) ? 1 : 0;
}
};
