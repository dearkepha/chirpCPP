#include<iostream>
#include<fstream>

using namespace std;

int main() {
    char chunk_id [5] = {0};
    
    ifstream file("test.wav");
    file.read(reinterpret_cast<char*>(chunk_id), 4);

        cout << chunk_id << endl;

    return 0;
}
