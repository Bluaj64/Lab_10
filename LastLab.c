#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//Trie Struct
struct Trie
{
  int isWord;//0/1
  struct trie* next[26];
};

void insert(struct Trie **ppTrie, char *word);
struct Trie * init();
int numberOfOccurances(struct Trie *pTrie, char *word);
struct Trie *deallocateTrie(struct Trie *pTrie);


void insert(struct Trie **ppTrie, char *word)
{
  int index = 0;
  struct Trie * temp = (*ppTrie);
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

  temp->isWord += 1;
}


int numberOfOccurances(struct Trie *pTrie, char *word)
{
  int index = 0;
  struct Trie * temp = pTrie;
  if (temp == NULL)
  {
    return 0;
  }

  for (int i = 0; i < (strlen(word)); i++)
  {
    index = ((int)word[i] - 97);
    if (temp->next[index] == NULL)
    {
      return 0;
    }
    temp = temp->next[index];
  }

  return 1;
}


struct Trie* init() 
{
  struct Trie* temp = malloc(sizeof(struct Trie));
  temp->isWord = 0;
  
  for (int i = 0; i < 26; i++)
    temp->next[i] = NULL;
  
  return temp;
}


struct Trie *deallocateTrie(struct Trie *pTrie)
{
  for (int i = 0; i < 26; i++)
    if (pTrie->next[i] != NULL)
    {
      deallocateTrie(pTrie->next[i]);
    }
  free(pTrie);
  return NULL;
}


int main(void)
{
      //read the number of the words in the dictionary
      int num;
      char word[100];
      struct Trie * trie = init();
      printf("Input number of words:\n");
      scanf("%d", &num);

      for (int i = 0; i < num; i++)
      {
        printf("Input word number %d :\n", i);
        fgets(word, sizeof(word), stdin);
        insert(&trie, word);
      }
   
      // parse line  by line, and insert each word to the trie data structure
      char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};
      for (int i=0;i<5;i++)
      {
          printf("\t%s : %d\n",pWords[i], numberOfOccurances(&trie, pWords[i]));
     }
    trie = deallocateTrie(&trie);
    if (trie != NULL)
       printf("There is an error in this program\n");
    return 0;
}
