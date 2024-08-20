#include <editline/readline.h>
#include <iostream>
#include <vector>
#include <string>

// Liste des options pour la complétion
std::vector<std::string> options = {"Toyota", "Honda", "Ford", "Chevrolet", "Nissan"};

// Fonction de complétion
char* completionGenerator(const char* text, int state) {
    static size_t listIndex, len;
    if (!state) {
        listIndex = 0;
        len = strlen(text);
    }

    while (listIndex < options.size()) {
        const std::string& option = options[listIndex];
        listIndex++;
        if (option.compare(0, len, text) == 0) {
            return strdup(option.c_str());
        }
    }
    return nullptr;
}

// Fonction de complétion
char** completer(const char* text, int start, int end) {
    rl_attempted_completion_over = 1;
    return rl_completion_matches(text, completionGenerator);
}

int main() {
    rl_attempted_completion_function = completer;

    while (true) {
        char* input = readline("Enter car brand: ");
        if (input == nullptr) {
            break;
        }
        if (*input) {
            add_history(input);
        }
        std::cout << "You entered: " << input << std::endl;
        free(input);
    }

    return 0;
}