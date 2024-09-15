// Write code to implement a document editor. The code should read character by character from input so as to incorporate the following rule set : 

// 1. If two or more adjacent spaces are found, delete all but one.
// 2. Capitalize the first letter of every sentence. 
// 3. All occurrences of ‘school’ are replaced by the word ‘garden’
// 4. Place _ before and after all the occurrences of articles in the text.


// INPUT FORMAT : The input consists of a single stream of text, which may contain multiple sentences separated by punctuation marks (. ! ?). 
// The text is read character by character from the standard input until the end-of-file (EOF).

// EXAMPLE INPUT : the kids love to go to school every day.   there is a huge   neem tree just at the corner of the north    gate of the school.   
// it is a home to    many birds and    insects. 

// OUTPUT FORMAT : The output consists of a single stream of modified text that adheres to the specified rules.

// EXAMPLE OUTPUT : _The_ kids love to go to garden every day. There is _a_ huge neem tree just at _the_ corner of the north gate of _the_ garden. 
// It is _a_ home to many birds _and_ insects. 


#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Class to handle document editing operations
class DocEditor {
public:
    // Function to process the input and edit the document according to the rules
    void processInput() {
        char ch;
        string word;
        char prevCh = '\0';
        bool capitalize = true;
        bool space = false;
        

        // Read characters until EOF
        while (cin.get(ch)) {
           if (isSpace(ch))
           {
               if (!space)
               {
                   handleWordBoundary(prevCh, word);
                   cout << " ";
                   space = true;
               }
           }
           else if (isPunctuation(ch))
           {
               handleWordBoundary(prevCh, word);
               cout << ch;
               capitalize = true;
               space = false;
           }
           else
           {
               if (capitalize && isalpha(ch))
               {
                   ch = toupper(ch);
                   capitalize = false;
               }
               
               word += ch;
               space = false;
           }
           
           prevCh = ch;
        }
        
        handleWordBoundary(prevCh, word);
    }

private:
    // Function to check if the given word is an article
    bool isArticle(const string &word) {
        return word == "a" || word == "an" || word == "the" || word == "A" || word == "The" ||
            word == "An";
    }

    // Function to print the word, underlining articles with underscores
    void printWord(const string &word) {
       if (word == "school") cout << "garden";
       else if (isArticle(word))
       {
           cout << "_" << word << "_";
       }
       else
       {
           cout << word;
       }
    }

    // Function to check if a character is a space
    bool isSpace(char ch) {
       return ch == ' ';
    }

    // Function to check if a character is a punctuation mark
    bool isPunctuation(char ch) {
        return ch == '.' || ch == '!' || ch == '?';
    }

    // Function to handle word boundaries and manage input characters
    void handleWordBoundary(char ch, string &word) {
        if (!word.empty())
        {
            printWord(word);
            word.clear();
        }
    }
};

int main() {
    DocEditor editor;
    editor.processInput();
    return 0;
}
