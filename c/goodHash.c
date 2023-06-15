unsigned fnv_hash_1a_32 ( void *key, int len ) {
    unsigned char *p = key;
    unsigned h = 0x811c9dc5;
    int i;

    for ( i = 0; i < len; i++ )
      h = ( h ^ p[i] ) * 0x01000193;

    return h;
}

unsigned long long fnv_hash_1a_64 ( void *key, int len ) {
    unsigned char *p = key;
    unsigned long long h = 0xcbf29ce484222325ULL;
    int i;

    for ( i = 0; i < len; i++ )
      h = ( h ^ p[i] ) * 0x100000001b3ULL;

   return h;
}
