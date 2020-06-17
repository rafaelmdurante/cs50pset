// readability (https://cs50.harvard.edu/x/2020/psets/2/readability/)
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
void calc_readability(int letters, int words, int sentences);

int main(void)
{
  string text = get_string("Type your text: ");
  calc_readability(count_letters(text), count_words(text), count_sentences(text));
  printf("\n");
}

int count_letters(string text)
{
  int letters = 0;
  int i = 0;

  while (text[i] != '\0')
  {
    if (isalpha(text[i])) 
    {
      letters++;
    }
    i++;
  }
  return letters;
}

int count_words(string text)
{
  int words = 1;
  for (int i = 0; i < strlen(text); i++)
  {
    if (text[i] == ' ')
    {
      words++;
    }
  }
  return words;
}

int count_sentences(string text)
{
  int sentences = 0;
  bool last_is_whitespace = true;

  for (int i = 0; i < strlen(text); i++)
  {
    if (isupper(text[i]) && last_is_whitespace)
    {
      sentences++;
      last_is_whitespace = false;
    }

    if ((text[i-1] == '.' || text[i-1] == '!' || text[i-1] == '?') && text[i] == ' ')
    {
      last_is_whitespace = true;
    }
  }
  return sentences;
}

void calc_readability(int letters, int words, int sentences)
{
  float L = (float) letters * 100 / (float) words;
  float S = (float) sentences * 100 / (float) words;
  float index = 0.0588 * L - 0.296 * S - 15.8;

  if (index > 16)
  {
    printf("Grade 16+");
  }
  else if (index < 1)
  {
    printf("Before Grade 1");
  }
  else
  {
    printf("Grade %.f", round(index));
  }
}