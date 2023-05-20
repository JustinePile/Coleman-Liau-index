#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string input = get_string("Text: ");

    int letter_count = count_letters(input);

    int word_count = count_words(input);

    int sentence_count = count_sentences(input);

    float letter_avg = ((float)letter_count / word_count) * 100;
    float sentence_avg = ((float)sentence_count / word_count) * 100;
    int score = round((0.0588 * letter_avg - 0.296 * sentence_avg) - 15.8);

    if (score < 1)
    {
        printf("Before Grade 1\n");
    }
    else if ((score >= 1) && (score < 16))
    {
        printf("Grade %i\n", score);
    }
    else if (score >= 16)
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string text)
{
    int length = strlen(text);
    int count = 0;

    for (int i = 0; i < length; i++)
    {
        char c = text[i];
        if (isalpha(c))
        {
            count++;
        }
    }

    return (count);
}

int count_words(string text)
{
    int length = strlen(text);
    int count = 1; // Start with 1 to account for the last word

    for (int i = 0; i < length; i++)
    {
        char c = text[i];

        if (isspace(c))
        {
            count++;
        }
    }

    return count;
}

int count_sentences(string text)
{
    int length = strlen(text);
    int count = 0;

    for (int i = 0; i < length; i++)
    {
        char c = text[i];

        if (c == '.' || c == '!' || c == '?')
        {
            count++;
        }
    }

    return (count);
}