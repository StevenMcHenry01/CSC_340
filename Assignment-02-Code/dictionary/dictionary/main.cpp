#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <array>

using namespace std;

map<string, vector<string>> createHash(vector<string>);
string queryDictionary(const map<string, vector<string>>&, const string&, const string&,
                               const string&);
vector<string> getFullDef(const map<string, vector<string>>&, string);
vector<string> distinctDefs(const vector<string>&);
string formatDef(string);
string formatWord(string);
void looper();

int main(int argc, const char *argv[]) {
  looper();
  cout << "Thank you!" << endl;
}

void looper() {
  fstream ioFile;
  string lineToken;
  vector<string> dataVector;
  map<string, vector<string>> hashMap;
  string token;
  string input;
  string response;
  vector<string> tokens;

  // place each line into vector
  ioFile.open("Data.CS.SFSU.txt", ios::in);
  while (!ioFile.eof()) {
    getline(ioFile, lineToken);
    dataVector.push_back(lineToken);
  }

  hashMap = createHash(dataVector);
  
//  for(auto elem : hashMap)
//  {
//     cout << elem.first << " " << elem.second[0] << endl;
//  }
  

  while (true) {
    tokens.clear();
    cout << "Search: ";
    getline(cin, input);

    // store each input as a token
    stringstream check(input);
    while (getline(check, token, ' ')) {
      tokens.push_back(token);
    }

    // refetch if entered more than three items
    if (tokens.size() > 3 || tokens.size() == 0) {
      cout << "Please only enter correct number of inputs. Between 1 and 3" << endl;
      continue;
    }
    if (tokens.size() == 1) {
      tokens[1] = "EMPTY";
      tokens[2] = "EMPTY";
    }
    if (tokens.size() == 2) {
      tokens[2] = "EMPTY";
    }

    // convert all strings to lowercase
    for (int i = 0; i < tokens.size(); i++) {
      transform(tokens[i].begin(), tokens[i].end(), tokens[i].begin(),
                ::tolower);
    }

    // check for quit sequence
    if (tokens[0] == "!q") {
      break;
    }

    // send tokens into dictionary controls
    response = queryDictionary(hashMap, tokens[0], tokens[1], tokens[2]);

    cout << response << endl;
  }
};

string queryDictionary(const map<string, vector<string>>& hashMap, const string& word,
                               const string& secondEntry, const string& thirdEntry) {
  vector<string> responseVec;
  string response = "";
  string empty = "EMPTY";
  responseVec = getFullDef(hashMap, word);
  // check if only the word was entered
  if (secondEntry == empty && thirdEntry == empty) {
    for(int i = 0; i < responseVec.size(); i++) {
      response = response + word + " " + responseVec[i] + "\n";
    }
    return response;
  }
  // check for if two entries were given
  if (thirdEntry == empty) {
    // check if second entry is "distinct"
    if (secondEntry == "distinct") {
      responseVec = distinctDefs(responseVec);
      for(int i = 0; i < responseVec.size(); i++) {
        response = response + word + " " + responseVec[i] + "\n";
      }
      return response;
    }
  }
  
  return "nope";
};

vector<string> distinctDefs(const vector<string>& defs) {
  vector<string> tempDefs;
  for(int i = 0; i < defs.size(); i++) {
    cout << defs[i] << endl;
    tempDefs.push_back(defs[i]);
  }
  return tempDefs;
}

// send in map with the word you are looking for. Return a vector<string> of all the definitions
vector<string> getFullDef(const map<string, vector<string>>& hashMap, string word) {
  vector<string> defs;
  // get location of key and values
  auto pos = hashMap.find(word);
  // make sure it exists
  if (pos == hashMap.end()) {
    defs.push_back("was not found");
  } else {
    // run through all defs and add to vector
    for (int i = 0; i < pos->second.size(); i++) {
      defs.push_back(pos->second[i]);
    }
  }
  return defs;
}

map<string, vector<string>> createHash(vector<string> dataVector) {
  string token;
  string word;
  vector<string> definitionsTemp;
  map<string, vector<string>> tempHashMap;
  // iterate over each vector node
  for (vector<string>::iterator i = dataVector.begin(); i != dataVector.end();
       ++i) {
    // erase temp vector of defs
    definitionsTemp.clear();
    string currentValue = *i;
    // add each value into temp vector, designated by delimeter
    stringstream tokenStream(currentValue);
    // get the word from current value and store in variable
    getline(tokenStream, token, '|');
//    token = formatWord(token);
    word = token;
    // add the rest of the string (definitions) to vector
    while (getline(tokenStream, token, '|')) {
      token = formatDef(token);
      definitionsTemp.push_back(token);
    }
    // add each pair to map
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

string formatDef(string def) {
  string arrow = "-=>>";
  
  // add brackets to part of speech
  def = "[" + def;
  def = def.insert (def.find(" "), "]");
  
  // replace arrows with colons
  def.replace(def.find(arrow),arrow.length(),":");

  return def;
}
