#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <chrono>
#include <openssl/aes.h>
#include <openssl/blowfish.h>

#define BUF_SIZE 256

void benchmark_aes()
{
    const unsigned char key[AES_BLOCK_SIZE] = "0123456789abcde";
    unsigned char iv[AES_BLOCK_SIZE] = "fedcba98765430";
    FILE *myFile;
    myFile = fopen("text.txt", "r");

    if (myFile == NULL)
    {
        printf("Error Reading File\n");
        exit(1);
    }
    unsigned char plaintext[BUF_SIZE];

    for (int i = 0; i < BUF_SIZE; i++)
    {
        fscanf(myFile, "%s", &plaintext[i]);
    }
    fclose(myFile);
    unsigned char ciphertext[BUF_SIZE];
    unsigned char decryptedtext[BUF_SIZE];
    int cipher_len, decrypted_len;

    AES_KEY aes_key;
    AES_set_encrypt_key(key, 128, &aes_key);

    auto startenc = std::chrono::high_resolution_clock::now();
    AES_cbc_encrypt(plaintext, ciphertext, strlen((const char*)plaintext), &aes_key, iv, AES_ENCRYPT);
    auto endenc = std::chrono::high_resolution_clock::now();

    std::cout << "AES encryption time: "<< endenc - startenc << std::endl;
    cipher_len = strlen((const char*)ciphertext);
    AES_set_decrypt_key(key, 128, &aes_key);

    auto startdec = std::chrono::high_resolution_clock::now();
    AES_cbc_encrypt(ciphertext, decryptedtext, cipher_len, &aes_key, iv, AES_DECRYPT);
    auto enddec = std::chrono::high_resolution_clock::now();

    decrypted_len = strlen((const char*)decryptedtext);
    decryptedtext[decrypted_len] = '\0';

    std::cout << "AES encryption time: "<< enddec - startdec << std::endl;
}

void benchmark_blowfish()
{
    const unsigned char key[16] = "0123456789abcde";
    unsigned char iv[BF_BLOCK] = {0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10};
    FILE *myFile;
    myFile = fopen("text.txt", "r");

    if (myFile == NULL)
    {
        printf("Error Reading File\n");
        exit(1);
    }
    unsigned char plaintext[BUF_SIZE];

    for (int i = 0; i < BUF_SIZE; i++)
    {
        fscanf(myFile, "%s", &plaintext[i]);
    }
    fclose(myFile);
    unsigned char ciphertext[BUF_SIZE];
    unsigned char decryptedtext[BUF_SIZE];
    int cipher_len, decrypted_len;

    BF_KEY bf_key;
    BF_set_key(&bf_key, 16, (unsigned char*)key);

    auto startenc = std::chrono::high_resolution_clock::now();
    BF_cbc_encrypt(plaintext, ciphertext, strlen((const char*)plaintext), &bf_key, iv, BF_ENCRYPT);
    auto endenc = std::chrono::high_resolution_clock::now();

    std::cout << "Blowfish encryption time: "<< endenc - startenc << std::endl;
    cipher_len = strlen((const char*)ciphertext);
    BF_set_key(&bf_key, 16, (unsigned char*)key);

    auto startdec = std::chrono::high_resolution_clock::now();
    BF_cbc_encrypt(ciphertext, decryptedtext, cipher_len, &bf_key, iv, BF_DECRYPT);
    auto enddec = std::chrono::high_resolution_clock::now();

    decrypted_len = strlen((const char*)decryptedtext);
    decryptedtext[decrypted_len] = '\0';

    std::cout << "Blowfish decryption time: "<< enddec - startdec << std::endl;
}

void welcome_screen()
{
    std::cout << "*------------------------------------ Algorithm Benchmarking -------------------------------------*"  << std::endl;
    std::cout << "|                                                                                                 |" << std::endl;
    std::cout << "|                                   Project made by :                                             |" << std::endl;
    std::cout << "|                                                                                                 |" << std::endl;
    std::cout << "|                                             Amine Naqi                                          |" << std::endl;
    std::cout << "|                                             Arnas Krutkis                                       |" << std::endl;
    std::cout << "|                                             Peter Kögler                                        |" << std::endl;
    std::cout << "|                                                                                                 |" << std::endl;
    std::cout << "*-------------------------------------------------------------------------------------------------*"  << std::endl;
}

int main(int argc, char* argv[])
{
    welcome_screen();
    int selected_val = atoi(argv[1]);

    if (selected_val == 1 || selected_val == 2)
    {
        switch(selected_val)
        {
            case 1 :
                benchmark_aes();
                break;
            
            case 2 :
                benchmark_blowfish();
                break;
            
            default :
                std::cout << "Please select 1 or 2" <<std::endl;
                break;
        }
    }

    return 0;
}