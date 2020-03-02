#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

void print(json &element, string pref){
    //pref = pref + "-";
    for (json::iterator it = element.begin(); it != element.end(); ++it) {
        try{
            string key  = it.key();
            cout << pref << key << ": ";
        }
        catch (json::invalid_iterator& e){
            // Object sin Key
        }

        // Es array o object
        if ((*it).is_structured()) {
            cout << endl;
            print(*it, pref + " ");
        }else{
            cout << it.value() << endl;
        }
    }
}

int main(){
    // Leer archivo json
    ifstream i("entrada.json");
    json j;
    i >> j;

    print(j, "");
    return 0;
}