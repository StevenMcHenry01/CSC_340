#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <array>

using namespace std;

map<string, vector<string>> createHash(const vector<string>&);
string queryDictionary(const map<string, vector<string>>&, const string&, const string&,
                       const string&);
vector<string> getFullDef(const map<string, vector<string>>&, const string&);
vector<string> distinctDefs(const vector<string>&, const string&);
vector<string> partOfSpeechIsolate(const vector<string>&, string);
string formatDef(string&);
string createResponse(const vector<string>&, string);
string formatWord(string);
void looper();

int main() {
    looper();
    cout << "\n-----THANK YOU-----" << endl;
}

void looper() {
    fstream ioFile;
    vector<string> fileReadVector;
    map<string, vector<string>> dictionaryMap;
    string token, response, input, lineToken;

    // place each line into vector
    ioFile.open("Data.CS.SFSU.txt", ios::in);
    cout << "!Opening data file... ./Data.CS.SFSU.txt\n";
    // continue getting each line of file until the end
    cout << "!Loading data...\n";
    while (!ioFile.eof()) {
        getline(ioFile, lineToken);
        // add each line to vector
        fileReadVector.push_back(lineToken);
    }
    cout << "!Loading completed...\n";
    cout << "!Closing data file... ./Data.CS.SFSU.txt\n\n";
    ioFile.close();
    cout << "----- DICTIONARY 340 C++ -----\n\n";
    dictionaryMap = createHash(fileReadVector);

    while (true) {
        string inputs[3];
        cout << "Search: ";
        // store entire line in string
        getline(cin, input);

        // allow input to be streamed
        stringstream stream(input);
        // limit inputs to 3
        for(string & input : inputs) {
            stream >> input;
        }

        // give user search dialogue again if nothing was entered
        if(inputs[0].empty()) {
            continue;
        }
        // check only one input was given. so we will the other spots with empty strings
        if (inputs[1].empty()) {
            inputs[1] = "";
            inputs[2] = "";
        }
        // check only two inputs given
        if (inputs[2].empty()) {
            inputs[2] = "";
        }

        // convert all strings to lowercase
        for (string & input : inputs) {
            transform(input.begin(), input.end(), input.begin(),
                      ::tolower);
        }

        // check for quit sequence
        if (inputs[0] == "!q") {
            break;
        }

        // send tokens into dictionary controls
        response = queryDictionary(dictionaryMap, inputs[0], inputs[1], inputs[2]);

        cout << response << endl;
    }
};

string queryDictionary(const map<string, vector<string>>& dictionaryMap, const string& word,
                       const string& secondEntry, const string& thirdEntry) {
    vector<string> responseVec;
    string response;

    // put all defs of the inputted word into a vector
    responseVec = getFullDef(dictionaryMap, word);

    // check if only the word was entered
    if (secondEntry.empty() && thirdEntry.empty()) {
        response = createResponse(responseVec, word);
        return response;
    }
    // check for if two entries were given
    if (thirdEntry.empty()) {
        // check if second entry is "distinct"
        if (secondEntry == "distinct") {
            responseVec = distinctDefs(responseVec, secondEntry);
            response = createResponse(responseVec, word);
            return response;
        } else {
            responseVec = partOfSpeechIsolate(responseVec, secondEntry);
            response = createResponse(responseVec, word);
            return response;
        }
    }

    // all entries filled
    responseVec = distinctDefs(responseVec, thirdEntry);
    responseVec = partOfSpeechIsolate(responseVec, secondEntry);
    response = createResponse(responseVec, word);

    return response;
};

string createResponse(const vector<string>& responseVec, string word) {
    string tempResponse;
    word = formatWord(word);

    // check for invalid inputs
    if (responseVec[0] == "<2nd argument must be a part of speech or \"distinct\">" ||
        responseVec[0] == "<Not found>") {
        return responseVec[0];
    }
    // format
    tempResponse = "|\n";
    for(const auto & i : responseVec) {
        tempResponse += " " + word + " " + i + "\n";
    }
    tempResponse += "|";
    return tempResponse;
}

// send in vector of strings and return a new one with no copies
vector<string> distinctDefs(const vector<string>& defs, const string& distinct) {
    vector<string> tempDefs;
    // make sure entry is distinct
    if(distinct != "distinct") {
        return defs;
    }
    // iterate over vector
    for(const string & def : defs) {
        // if current def is not found in temp, add to temp
        if (!(count(tempDefs.begin(), tempDefs.end(), def))) {
            tempDefs.push_back(def);
        }
    }
    return tempDefs;
}

vector<string> partOfSpeechIsolate(const vector<string>& defs, string partSpeech) {
    vector<string> tempDefs;
    bool accept;
    string parts[8] = {"adjective", "adverb", "noun", "conjunction",
                       "interjection", "verb", "preposition", "pronoun"};
    // make sure partSpeech is acceptable
    for(auto & i : parts) {
        if(i == partSpeech) {
            accept = true;
        }
    }
    if (!accept) {
        tempDefs.push_back("<2nd argument must be a part of speech or \"distinct\">");
        return tempDefs;
    }

    // add brackets to part of speech to ensure that full word is being found
    partSpeech = "[" + partSpeech + "]";
    // iterate over vector
    for(const string & def : defs) {
        if(def.find(partSpeech) != string::npos) {
            tempDefs.push_back(def);
        }
    }
    // no defs with that part of speech found
    if (tempDefs.empty()) {
        tempDefs.push_back("<Not found>");
    }
    return tempDefs;
}

// send in map with the word you are looking for. Return a vector<string> of all the definitions
vector<string> getFullDef(const map<string, vector<string>>& dictionaryMap, const string& word) {
    vector<string> defs;
    // get location of key and values
    auto pos = dictionaryMap.find(word);
    // make sure it exists
    if (pos == dictionaryMap.end()) {
        defs.push_back("<Not found>");
    } else {
        // run through all defs and add to vector
        for (int i = 0; i < pos->second.size(); i++) {
            defs.push_back(pos->second[i]);
        }
    }
    return defs;
}

map<string, vector<string>> createHash(const vector<string>& dataVector) {
    string token, word;
    vector<string> definitionsTemp;
    map<string, vector<string>> tempHashMap;

    // iterate over each vector node
    for (const string& currentValue : dataVector) {
        // erase temp vector of defs
        definitionsTemp.clear();
        // add each value into temp vector, designated by delimeter
        stringstream tokenStream(currentValue);
        // get the word from current value and store in variable
        getline(tokenStream, token, '|');
        // token = formatWord(token);
        word = token;
        // add the rest of the string (definitions) to vector
        while (getline(tokenStream, token, '|')) {
            token = formatDef(token);
            definitionsTemp.push_back(token);
        }
//        // add each pair to map
        tempHashMap.insert(pair<string, vector<string>>(word, definitionsTemp));
    }
    return tempHashMap;
};

string formatWord(string word) {
    //check for special case of class name
    if(any_of(word.begin(), word.end(), ::isdigit)) {
        // indicate location of first digit
        size_t wordEnd = (int)word.find_first_of("0123456789");
        // convert all characters until digit location to uppercase
        for(int i = 0; i < wordEnd; i++) {
            word[i] = toupper(word[i]);
        }
        return word;
    }

    // convert first char to uppercase
    word[0] = toupper(word[0]);
    return word;
}

string formatDef(string& def) {
    string arrow = "-=>>";

    // add brackets to part of speech
    def = "[" + def;
    def = def.insert (def.find(' '), "]");

    // replace arrows with colons
    def.replace(def.find(arrow),arrow.length(),":");

    return def;
}