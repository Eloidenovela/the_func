
/*
    Criado por Eloide Novela aos 2024/03/12

    Este programa permite de maneira eficiente de ler um arquivo de texto, extrair 
    strings separadas por vírgulas e armazená-las em um array de strings em memória 
    para posterior processamento ou manipulação.
*/
#include <stdlib.h>
#include <stdio.h>

// esta funcao tem a responsabilidade de concatenar cada caracter do arquivo nas strings do programa.
void str_concaten(char string[], char ch, size_t *l) 
{
    string[*l] = ch;
    (*l)++;
}

// esta funcao permite de maneira eficiente alocar um arry de strings em C ou mesmo uma matriz.
char** mallocStringsArray(size_t line, size_t col)
{
    char **arr = (char**)malloc(line * sizeof(char *));

    if (arr != NULL) 
    {
        for (int i = 0 ; i < line ; i++) 
        {
            arr[i] = (char*)malloc(col * sizeof(char));

            if (arr[i] == NULL) 
            {
                exit(-1);
            }
        }
    } 
    else 
    {
        exit(-1);
    }
    return arr;
}

// A <funcao magica> lol. Ela e o ingrediente principal do programa ela junto com as funcoes anterior fazem a magia.
char** getFileValues(const char* path, size_t line, size_t column) 
{
    FILE* file;
    char **arr = mallocStringsArray(line, column);

    file = fopen(path, "r"); // abertura do arquivo de texto

    if (arr != NULL) 
    {
        if (file != NULL) 
        {
            size_t i = 0, l = 0; // i-> posicao da do elemento da array | l-> e o tamanho do elemento da array, isto e, a capacidade de caracteres. 
            int ch = 0;

            while ((ch = fgetc(file)) != EOF) 
            {
                if (ch != ',') 
                {
                    if (l < column) 
                    {
                        str_concaten(arr[i], (char) ch, &l); // concatenando os caracteres nas strings.
                    }
                } 
                else 
                {
                    arr[i][l] = '\0'; // termindor...
                    i++; // quando e encontrado uma virgulo, (i) muda o elemento da array para preencher-se a proxima posicao do array. 
                    if (i >= line) //
                        break;
                    l = 0; // o l e responsavel por acessar as posicoes de cada elemento no array. Quando encontrado uma virgula ele deve ser zerado.
                }

            }

            fclose(file); // ...
        }

        return arr; // ...
    }

    return NULL;
}

int main() 
{
    size_t size = 4, length = 100;
    char **arr = getFileValues("names.txt", size, length);

    for (size_t i = 0 ; i < size ; i++) {
        printf("%s\n", arr[i]);
    }

    free(arr);

    return 0;
}

// ... e.n
