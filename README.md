# KEYLOGGIN BENCHMARKS

In the Crypto folder you will find "Benchmarktool.zip" in which you will find the .exe file with a text file that you can change the content to increase or decrease the size.
You can use "https://www.lipsum.com/" to generate a text based on size in bytes and fill the txt file with it.

In the terminal input the command :

For AES Algorithm : 
```
execcrypt.exe 1 128
```
For Blowfish Algorithm :
```
execcrypt.exe 2 32
```
Note : The second argument in the command is the keysize for encryption and decryption :
- For AES you can use : 128 | 192 | 256
- For Blowfish you can use : 32 | 64 | 128 | 192 | 256

Documentation on the algorithms :

https://cybernews.com/resources/what-is-aes-encryption/

https://en.wikipedia.org/wiki/Blowfish_(cipher)

https://en.wikipedia.org/wiki/Advanced_Encryption_Standard

https://github.com/openssl/openssl

To download openssl library on windows, follow this guide.

https://thesecmaster.com/procedure-to-install-openssl-on-the-windows-platform/
