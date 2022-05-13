
#include "date.h"

class Event {
    char destination[40];
    Date* date1;
    Date* date2;
    unsigned int grade;
    char comment[100];
    char** photos;

public:

    Event(const char* name, unsigned int grade, const char* comment, unsigned int number, char *photos);

}
