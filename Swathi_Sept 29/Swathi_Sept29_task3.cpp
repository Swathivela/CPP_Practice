a) Function header for exchange

Takes two double* parameters and returns nothing:

void exchange(double* x, double* y)

b) Function prototype for exchange
void exchange(double* x, double* y);

c) Function header for evaluate

Returns an int.

Takes:

int x

int (*poly)(int) → pointer to a function that takes an int and returns an int.

int evaluate(int x, int (*poly)(int))

d) Function prototype for evaluate
int evaluate(int x, int (*poly)(int));

e) Two statements to initialize character array vowel with "AEIOU"

Array initializer:

char vowel[] = "AEIOU";


Using strcpy (assuming <cstring> is included):

char vowel[6];  
strcpy(vowel, "AEIOU");