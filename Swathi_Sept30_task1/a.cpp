
void mystery1( char *s1, const char *s2 ) {
    while ( *s1 != '\0' )  // Move pointer s1 to the end of string1
        s1++;
    for ( ; *s1 = *s2; s1++, s2++ )  // Copy characters from s2 to s1
        ; // empty loop body
}
