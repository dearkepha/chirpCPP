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
    uint16_t audio_format;
    uint16_t num_channels;
    uint32_t sample_rate;
    uint32_t byte_rate;
    uint16_t block_allign;
    uint16_t bits_per_sample;
};

void read_as_bytes(string fname) {
    ifstream wavfile("test.wav", ios::binary);

    wav_header wav;
    wavfile.read(reinterpret_cast<char*>(&wav), sizeof(wav_header));

    cout << "File name: " << fname << endl;
    cout << "File size: " << wav.chunk_size+8 << endl; 
    cout << "Chunk ID: " << string(wav.chunk_id, 4) << endl;
    cout << "File format: " << string(wav.format, 4) << endl;
    cout << "number of channels: " << wav.num_channels << endl;
    cout << "Sample rate: " << wav.sample_rate << endl;
    cout << "Bits per sample: " << wav.bits_per_sample << endl;
}

int main() {
    read_as_bytes("test.wav");
    return 0;
}
