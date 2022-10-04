#include <ctime>
#include <cstdlib>
#include <iostream>

std::string generateKey(int length){
    //init random seed
    srand(time(NULL));
    //possible characters to use in key
    char characters[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','`','~','!','@','#','$','%','^','&','*','(',')','-','_','=','+','[',']','{','}','|',';',':','"',',','.','/','<','>','?'};

    std::string key = "";

    //select a random character from list and add it to key till key reaches its required length
    for(int i = 0; i < length; i++){
        key += characters[rand() % 92];
    }

    //return final product
    return key;
}

std::string encrypt(std::string plaintext, std::string key){
    std::string ciphertext = "";

    //Loop through ciphertext and key
    for(int i = 0; i < plaintext.length(); i++){

        /*
            convert characters from plaintext and key to ints
            add the 2 values
            convert product to char
            add char to ciphertext
        */
        ciphertext += static_cast<char>((int(plaintext[i] - '0')) + (int(key[i] - '0')));
    }
    //return final product
    return ciphertext;
}

std::string decrypt(std::string ciphertext, std::string key){
    std::string plaintext = "";

    //Loop through ciphertext and key
    for(int i = 0; i < ciphertext.length(); i++){

        /*
            convert characters from cipher text and key to ints
            subtract the 2 values
            convert product to char
            add char to plain text
        */
        plaintext += static_cast<char>((int(ciphertext[i]) - int(key[i] - '0') + '0'));
    }
    //return final product
    return plaintext;
}

int main(){
    std::string plaintext = "";
    //Get Plaintext
    std::cout << "Enter Text to cipher: \n";
    getline(std::cin, plaintext);

    //Return Plaintext to user
    std::cout << "Your Text is: " << plaintext << "\n\n";

    //Genereate Key using the length of the plain text, store it, then return it to the user
    std::cout << "==== GENERATING KEY ====\n";
    std::string key = generateKey(plaintext.length());
    std::cout << "Your key is: " << key << "\n\n";

    //Encrypt Plaintext, store it, then return ciphertext to user
    std::cout << "==== ENCRYPTING PLAINTEXT WITH KEY ====\n";
    std::string ciphertext = encrypt(plaintext,key);
    std::cout << "Your ciphertext is: " << encrypt(plaintext,key) << std::endl << std::endl;//Use of std::endl because it glitches if the output isn't flushed

    //Decrypt ciphertext and return plaintext back to user
    std::cout << "==== DECRPYTING CIPHERTEXT WITH KEY ====\n";
    std::cout << "Decrpyted Text is: " << decrypt(ciphertext, key) << "\n";

    //exit
    return 0;
}
