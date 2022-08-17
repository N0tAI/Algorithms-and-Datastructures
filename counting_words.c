#include <string.h>
#include <stddef.h>

int main() {
	char* string = "How are you";

	size_t vowel_count = 0;
	size_t word_count =	 0;
	for (size_t i = 0; string[i] != '\0'; i++) {
		{
			char current_letter = tolower(string[i]);
			if (current_letter == 'a' || current_letter == 'e' || current_letter == 'o' || current_letter == 'u' || current_letter == 'y')
				vowel_count++;
		}
		if (string[word_count] == ' ' && string[word_count + 1] != ' ')
			word_count++;
	}
}