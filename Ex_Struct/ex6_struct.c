#include <stdio.h>
#include <stdlib.h>
#define TOTAL_LIVROS 30

typedef struct Livro{
    char titulo[51];
    char autor[51];
    int anoPublicacao;
}Livro;

void exibirLivros(Livro livros[], int ano);

int main(){
    Livro livros[TOTAL_LIVROS] = {
        {"Dom Casmurro", "Machado de Assis", 1899},
        {"1984", "George Orwell", 1949},
        {"O Senhor dos Anéis", "J.R.R. Tolkien", 1954},
        {"A Revolução dos Bichos", "George Orwell", 1945},
        {"O Pequeno Príncipe", "Antoine de Saint-Exupéry", 1943},
        {"Cem Anos de Solidão", "Gabriel García Márquez", 1967},
        {"Harry Potter e a Pedra Filosofal", "J.K. Rowling", 1997},
        {"O Código Da Vinci", "Dan Brown", 2003},
        {"Jogos Vorazes", "Suzanne Collins", 2008},
        {"A Garota no Trem", "Paula Hawkins", 2015},
        {"O Hobbit", "J.R.R. Tolkien", 1937},
        {"Orgulho e Preconceito", "Jane Austen", 1813},
        {"Drácula", "Bram Stoker", 1897},
        {"Frankenstein", "Mary Shelley", 1818},
        {"As Crônicas de Nárnia", "C.S. Lewis", 1950},
        {"O Nome do Vento", "Patrick Rothfuss", 2007},
        {"O Silmarillion", "J.R.R. Tolkien", 1977},
        {"O Alquimista", "Paulo Coelho", 1988},
        {"A Menina que Roubava Livros", "Markus Zusak", 2005},
        {"A Culpa é das Estrelas", "John Green", 2012},
        {"It: A Coisa", "Stephen King", 1986},
        {"Misery", "Stephen King", 1987},
        {"O Iluminado", "Stephen King", 1977},
        {"Admirável Mundo Novo", "Aldous Huxley", 1932},
        {"O Apanhador no Campo de Centeio", "J.D. Salinger", 1951},
        {"Ensaio sobre a Cegueira", "José Saramago", 1995},
        {"O Morro dos Ventos Uivantes", "Emily Brontë", 1847},
        {"Grande Sertão: Veredas", "João Guimarães Rosa", 1956},
        {"Os Miseráveis", "Victor Hugo", 1862},
        {"O Retrato de Dorian Gray", "Oscar Wilde", 1890}
    };

    int anoFiltro;
    printf("\nDigite o ano para filtrar os livros: ");
    scanf("%d", &anoFiltro);
    
    exibirLivros(livros, anoFiltro);

    return 0;
}

void exibirLivros(Livro livros[], int ano){
    printf("\nPublicado a partir após %d:\n\n", ano);
    int encontrados = 0;
    for(int i = 0; i < TOTAL_LIVROS; i++){
        if(livros[i].anoPublicacao > ano){
            printf("Título: %s\n", livros[i].titulo);
            printf("Autor: %s\n", livros[i].autor);
            printf("Ano de Publicação: %d\n\n", livros[i].anoPublicacao);
            encontrados++;
        }
    }
    if(encontrados == 0){
        printf("Nenhum Livro encontrado após %d.\n", ano);
    }
}