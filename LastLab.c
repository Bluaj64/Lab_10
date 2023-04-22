#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//Trie Struct
struct trie
{
  int isWord;//0/1
  struct trie* next[26];
};

void insert(struct Trie **ppTrie, char *word);
struct trie * init();
int numberOfOccurances(struct Trie *pTrie, char *word);
struct Trie *deallocateTrie(struct Trie *pTrie);


void insert(struct Trie **ppTrie, char *word)
{
  int index = 0;
  struct trie * temp = (*ppTrie);
  if (temp == NULL)
  {
    return;
  }

  for (int i = 0; i < (strlen(word)); i++)
  {
    index = ((int)word[i] - 97);
    if (temp->next[index] == NULL)
    {
      temp->next[index] = init();
    }
  }

  temp->count += 1;
}

struct trie* init() 
{
  struct trie* temp = malloc(sizeof(struct trie));
  temp->isWord = 0;
  
  for (int i = 0; i < 26; i++)
    temp->next[i] = NULL;
  
  return temp;
}

int main(void)
{
      //read the number of the words in the dictionary
      // parse line  by line, and insert each word to the trie data structure
      char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};
      for (int i=0;i<5;i++)
      {
          printf("\t%s : %d\n",pWords[i], numberOfOccurances(&trie, pWords[i]));
     }
    trie = deallocateTree(&trie);
    if (trie != NULL)
       printf("There is an error in this program\n");
    return 0;
}
