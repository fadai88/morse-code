#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// define size 60 - 26 letters, 10 digits and more than 10 punctuation symbols
#define SIZE 60
#define MAX_LENGTH 6

struct dictionary {
   char *value;
   char key;
};

struct dictionary *table[SIZE];

int hashCode(char key);
void insert(char key, char *value);
void display();
void allInsert();

int main() {
    char text[1000];
    printf("Please enter the text you want to translate into Morse code\n");
    fgets(text, sizeof(text), stdin);
    int length = strlen(text);
    char updated_text[1000 * MAX_LENGTH + 1] = "";

    allInsert();

    for (int i = 0; i < length-1; i++) {
        int hash_index = hashCode(text[i]);
        char code[MAX_LENGTH+1];
        strcpy(code, table[hash_index]->value);
        strcat(updated_text, code);
    }
    printf("updated_text is %s\n", updated_text);
    return 0;
}

// create a hash function
int hashCode(char key) {
   key = toupper(key);
   return key % 256;
}

// function for creating and initializing a hash table
void insert(char key, char *value) {
   struct dictionary *item = (struct dictionary*) malloc(sizeof(struct dictionary));
   item->value = value;
   item->key = key;
   //get the hash
   int hashIndex = hashCode(key);
   //move in array until an empty or deleted cell
   while(table[hashIndex] != NULL) {
      //go to next cell
      ++hashIndex;
   }
   table[hashIndex] = item;
}

void allInsert() {
    insert('A', ".-");
    insert('B', "-...");
    insert('C', "-.-.");
    insert('D', "-..");
    insert('E', ".");
    insert('F', "..-.");
    insert('G', "--.");
    insert('H', "....");
    insert('I', "..");
    insert('J', ".---");
    insert('K', "-.-");
    insert('L', ".-..");
    insert('M', "--");
    insert('N', "-.");
    insert('O', "---");
    insert('P', ".--.");
    insert('Q', "--.-");
    insert('R', ".-.");
    insert('S', "...");
    insert('T', "-");
    insert('U', "..-");
    insert('V', "...-");
    insert('W', ".--");
    insert('X', "-..-");
    insert('Y', "-.--");
    insert('Z', "--..");
    insert('1', ".----");
    insert('2', "..---");
    insert('3', "...--");
    insert('4', "....-");
    insert('5', ".....");
    insert('6', "-....");
    insert('7', "--...");
    insert('8', "---..");
    insert('9', "----.");
    insert('0', "-----");
    insert(' ', "/");
    insert('?', "..--..");
    insert(',', "--..--");
    insert(':', "---...");
    insert('-', "-....-");
    insert('+', ".-.-.");
    insert('=', "-...-");
    insert('@', ".--.-.");
    insert('(', "-.--.");
    insert(')', "-.--.-");
    insert('_', "..--.-");  // underscore
    insert(';', "-.-.-.");
    insert('\'', ".----."); // apostrophe
    insert('/', "-..-.");
    insert('.', ".-.-.-");  //full stop or period
}
