#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Forward declaration of the function in top_articles.cpp
vector<string> topArticles(int limit);

int main() {
    int limit = 2;
    cout << "Fetching top " << limit << " articles...\n" << endl;
    
    vector<string> results = topArticles(limit);
    
    for (const string& title : results) {
        cout << title << endl;
    }
    
    return 0;
}