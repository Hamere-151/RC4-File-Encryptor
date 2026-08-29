#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
void rc4(vector<unsigned char>& data, string key)
{
    vector<unsigned char> S(256);


    // Initialize S array
    for (int i = 0; i < 256; i++)
    {
        S[i] = i;
    }


    // Key Scheduling Algorithm (KSA)
    int j = 0;

    for (int i = 0; i < 256; i++)
    {
        j = (j + S[i] + key[i % key.length()]) % 256;

        swap(S[i], S[j]);
    }


    // Pseudo Random Generation Algorithm (PRGA)

    int i = 0;
    j = 0;


    for (int k = 0; k < data.size(); k++)
    {
        i = (i + 1) % 256;

        j = (j + S[i]) % 256;

        swap(S[i], S[j]);


        int t = (S[i] + S[j]) % 256;

        unsigned char keystream = S[t];


        // XOR
        data[k] = data[k] ^ keystream;
    }
}
int main()
{
    string key = "INSA2026";


    // Open encrypted file
    ifstream input("encrypted_file.bin", ios::binary);


    if (!input)
    {
        cout << "Cannot open encrypted_file.bin" << endl;
        return 1;
    }


    // Read encrypted data
    vector<unsigned char> data(
        (istreambuf_iterator<char>(input)),
        istreambuf_iterator<char>()
    );


    input.close();


    cout << "Encrypted file loaded successfully!" << endl;



    // Decrypt using RC4
    rc4(data, key);


    cout << "Decryption completed!" << endl;



    // Save decrypted file
    ofstream output("decrypted_file.txt", ios::binary);


    if (!output)
    {
        cout << "Cannot create decrypted_file.txt" << endl;
        return 1;
    }


    output.write(
        reinterpret_cast<char*>(data.data()),
        data.size()
    );


    output.close();


    cout << "Saved as decrypted_file.txt" << endl;


    return 0;
}
