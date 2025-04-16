#include "validate_dna.h"

bool isValidDNA(const std::string& input) {
    for (char c : input) {
        if (c != 'A' && c != 'T' && c != 'C' && c != 'G') {
            return false;
        }
    }
    return true;
}