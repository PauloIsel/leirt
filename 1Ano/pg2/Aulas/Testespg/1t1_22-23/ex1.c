
typedef struct{ // Descritor de uma localização de linha
    int fileIdx; // índice no array de ponteiros para os nomes dos ficheiros
    int line; // número da linha no texto
    long offset; // posição do início da linha no ficheiro
} Location;

typedef struct{ // Descritor de um vetor de localizações de linhas
    int space; // quantidade de elementos alojados no array dinâmico
    int count; // quantidade de elementos ocupados no array dinâmico
    Location *data; // aponta array alojado dinamicamente
} VecLoc;

int count_line_in_files(VecLoc *vec, int line) {
    int count = 0;

    for(int i = 0; i < vec->count; i++) {
        if (vec->data[i].line == line) {
            count++;
        }
    }

    return count;
}

void delete_location(VecLoc *vec, int loc_idx) {
    for(int i = loc_idx; i < vec->count; i++) {
        vec->data[i] = vec->data[i+1];
    }
    vec->count--;
}
