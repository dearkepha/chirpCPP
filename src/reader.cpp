#include<iostream>
#include<fstream>
#include<cstdint>

using namespace std;

struct wav_header {
    char chunk_id[4];
    uint32_t chunk_size;
    char format[4];
    char subchunk1_id[4];
    uint32_t sunchunk1_size;

};

void read_as_bytes(string fname) {
    ifstream wavfile("test.wav", ios::binary);

    wav_header wav;
    wavfile.read(reinterpret_cast<char*>(&wav), sizeof(wav_header));

    cout << "File name: " << fname << endl;
    cout << "Chunk ID: " << string(wav.chunk_id, 4) << endl;
    cout << "File size: " << wav.chunk_size+8 << endl; 
    cout << "File format: " << string(wav.format, 4) << endl;
}

int main() {
    read_as_bytes("test.wav");
    return 0;
}
