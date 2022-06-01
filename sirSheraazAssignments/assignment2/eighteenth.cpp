//Question no 18
//xviii.	Write a Program which should read two files and should display the paragraphs which are having in common at least 3-sequence of consecutive characters having sum of characters more than 300 and difference should not be less than 30% of their sum. 

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;

vector<string> getParagraphs(ifstream& file, vector<string>Paragraph){    
    string paragraph;
    while(!file.eof()){
        getline(file, paragraph);
        Paragraph.push_back(paragraph);
    }
    file.clear();
    file.seekg(0, ios::beg);
    return Paragraph;
}
vector<int> fillCountOfWords(ifstream& file, vector<int> wordsInParagraph){
    while(!file.eof()){
        string paragraph;
        stringstream words;
        string word;
        int noOfWords = 0;
        getline(file, paragraph);
        words.clear();
        words.str(paragraph);
        while(words.good()){
            words >> word;
            ++noOfWords;
        }
        wordsInParagraph.push_back(noOfWords);
    }
    file.clear();
    file.seekg(0 , ios::beg);
    return wordsInParagraph;
}
int main(){
    ifstream firstFile("question18.txt");
    ifstream secondFile("question18part2.txt");
    //printParagraph(secondFile);
    vector<string> paragraphInFirstFile;
    paragraphInFirstFile = getParagraphs(firstFile, paragraphInFirstFile);
    vector<string> paragraphInSecondFile;
    paragraphInSecondFile = getParagraphs(secondFile, paragraphInSecondFile);
    cout << endl <<"Number of Paragraph in first File = " << paragraphInFirstFile.size() << endl;
    for(int i = 0; i < paragraphInFirstFile.size(); ++i){
        cout << endl << "Number of characters in " << i  <<" para of First file = " << paragraphInFirstFile[i].length() << endl;
    }

    bool consecutive = false; int sum = 0; int difference;
    for(int i = 0; i < paragraphInFirstFile.size(); ++i){ 
        for(int j = 0; j < paragraphInSecondFile.size(); ++j){
            for(int k = 0; k < paragraphInFirstFile[i].length(); ++k){           
                for(int l = 0; l < paragraphInSecondFile[j].length(); ++l){
                    bool firstCharacter = paragraphInFirstFile[i][k] == paragraphInSecondFile[j][l];
                    bool secondCharacter = paragraphInFirstFile[i][k+1] == paragraphInSecondFile[j][l+1];
                    bool thirdCharacter = paragraphInFirstFile[i][k+2] == paragraphInSecondFile[j][l+2];
                    if(firstCharacter == true && secondCharacter == true && thirdCharacter == true){
                        consecutive = true;
                    }
                    if(consecutive == true){
                        sum = paragraphInFirstFile[i].size() + paragraphInSecondFile[j].size();
                        difference = paragraphInFirstFile[i].size() - paragraphInSecondFile.size();
                        bool sumCondition = sum > 300;
                        bool differenceCondition = difference >= 0.3*sum;
                        if(sumCondition == true && differenceCondition == true){
                            cout << endl<< "Sum " << sum << " is greater than " << 300 << " and difference " << difference << " is not less than 0.3 of sum " << 0.3 * sum << endl;
                            cout << endl << "\t" << paragraphInFirstFile[i] << endl;
                            cout << endl << " IS SIMILAR TO " << endl;
                            cout << endl << "\t" << paragraphInSecondFile[j] << endl;
                            break;
                        }
                        
                    }
                }
                if(sum > 300 && difference >= 0.3*sum){
                    break;
                }           
            }
            if(sum > 300 && difference >= 0.3*sum){
                break;
            }  
        }
    }
    
    // for(int i = 0; i < paragraphInSecondFile.size(); ++i){
    //     cout << "\t" << paragraphInSecondFile[i] << endl;
    // }

    return 0;
}