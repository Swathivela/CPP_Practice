int mystery2( const char *s ) {
    int x;
    for ( x = 0; *s != '\0'; s++ )
        x++;
    return x;
}
