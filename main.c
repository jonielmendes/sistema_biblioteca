#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char titulo[50];
    char autor[50];
    char editora[50];
    char genero[30];
    int ano_publicacao;
    int disponivel;   
} Livro;

typedef struct {
    int id;
    char nome[50];
    char cpf[20];
    char endereco[100];
} Usuario;

typedef struct {
    int id;
    int id_usuario;
    int id_livro;
    float dias_emprestimo;
    float multa;
} Emprestimo;

Livro lista_livros[100];
Usuario lista_usuarios[100];
Emprestimo lista_emprestimos[100];

int qtd_livros = 0;
int id_livro = 0;
int qtd_usuarios = 0;
int id_usuario = 0;
int qtd_emprestimos = 0;
int id_emprestimo = 0;
int tipo_usuario = 0;

void cadastrar_livro() {
    if (tipo_usuario != 3) {  
        printf("Apenas funcionarios podem adicionar livros.\n");
        return;
    }
    id_livro++;
    char temp;
    lista_livros[qtd_livros].id = id_livro;
    printf("Cadastrar livro\n");
    printf("Titulo: ");
    scanf("%c", &temp);  
    scanf("%[^\n]", lista_livros[qtd_livros].titulo);
    printf("Autor: ");
    scanf("%c", &temp);  
    scanf("%[^\n]", lista_livros[qtd_livros].autor);
    printf("Editora: ");
    scanf("%c", &temp);  
    scanf("%[^\n]", lista_livros[qtd_livros].editora);
    printf("Genero: ");
    scanf("%c", &temp);  
    scanf("%[^\n]", lista_livros[qtd_livros].genero);
    printf("Ano de publicação: ");
    scanf("%d", &lista_livros[qtd_livros].ano_publicacao);
    printf("Quantidade de exemplares disponiveis: ");
    scanf("%d", &lista_livros[qtd_livros].disponivel);
    qtd_livros++;
    printf("\nLivro cadastrado com sucesso!!\nID do livro: %d\n", id_livro);
}

void listar_livros() {
    int i;
    for (i = 0; i < qtd_livros; i++) {
        printf("ID: %d\nTitulo: %s\nAutor: %s\nEditora: %s\nGenero: %s\nAno: %d\nDisponivel: %d exemplares\n",
               lista_livros[i].id, lista_livros[i].titulo, lista_livros[i].autor,
               lista_livros[i].editora, lista_livros[i].genero,
               lista_livros[i].ano_publicacao, lista_livros[i].disponivel);
    }
}

int pesquisar_livro(int id) {
    int i;
    for (i = 0; i < qtd_livros; i++) {
        if (id == lista_livros[i].id) {
            return i;
        }
    }
    return -1;
}

void pesquisar_livro_por_id() {
    int id;
    printf("Digite o ID do livro: ");
    scanf("%d", &id);
    int pos = pesquisar_livro(id);
    if (pos != -1) {
        printf("ID: %d\nTítulo: %s\nAutor: %s\nEditora: %s\nGenero: %s\nAno: %d\nDisponível: %d exemplares\n",
               lista_livros[pos].id, lista_livros[pos].titulo, lista_livros[pos].autor,
               lista_livros[pos].editora, lista_livros[pos].genero,
               lista_livros[pos].ano_publicacao, lista_livros[pos].disponivel);
    } else {
        printf("Livro não encontrado.\n");
    }
}

void excluir_livro() {
    if (tipo_usuario != 3) {  
        printf("Apenas funcionarios podem excluir livros.\n");
        return;
    }
    int id;
    printf("Digite o ID do livro que deseja excluir: ");
    scanf("%d", &id);
    int pos = pesquisar_livro(id);
    if (pos != -1) {
        lista_livros[pos] = lista_livros[qtd_livros - 1];
        qtd_livros--;
        printf("Livro excluido com sucesso.\n");
    } else {
        printf("Livro nao encontrado.\n");
    }
}

void atualizar_livro() {
    if (tipo_usuario != 3) {  
        printf("Apenas funcionarios podem atualizar livros.\n");
        return;
    }
    int id;
    char temp;
    printf("Digite o ID do livro que deseja atualizar os dados: ");
    scanf("%d", &id);
    int pos = pesquisar_livro(id);
    if (pos != -1) {
        printf("Titulo: ");
        scanf("%c", &temp);
        scanf("%[^\n]", lista_livros[pos].titulo);
        printf("Autor: ");
        scanf("%c", &temp);
        scanf("%[^\n]", lista_livros[pos].autor);
        printf("Editora: ");
        scanf("%c", &temp);
        scanf("%[^\n]", lista_livros[pos].editora);
        printf("Genero: ");
        scanf("%c", &temp);
        scanf("%[^\n]", lista_livros[pos].genero);
        printf("Ano de publicação: ");
        scanf("%d", &lista_livros[pos].ano_publicacao);
        printf("Quantidade de exemplares disponiveis: ");
        scanf("%d", &lista_livros[pos].disponivel);
        printf("\nDados do livro atualizados com sucesso!!\n");
    } else {
        printf("Livro nao encontrado.\n");
    }
}

void cadastrar_usuario() {
    id_usuario++;
    char temp;
    lista_usuarios[qtd_usuarios].id = id_usuario;
    printf("Cadastrar usuario\n");
    printf("Nome: ");
    scanf("%c", &temp);
    scanf("%[^\n]", lista_usuarios[qtd_usuarios].nome);
    printf("CPF: ");
    scanf("%c", &temp);
    scanf("%[^\n]", lista_usuarios[qtd_usuarios].cpf);
    printf("Endereco: ");
    scanf("%c", &temp);
    scanf("%[^\n]", lista_usuarios[qtd_usuarios].endereco);
    qtd_usuarios++;
    printf("\nUsuario cadastrado com sucesso!!\nID do usuario: %d\n", id_usuario);
}

void listar_usuarios() {
    int i;
    for (i = 0; i < qtd_usuarios; i++) {
        printf("ID: %d\nNome: %s\nCPF: %s\nEndereco: %s\n",
               lista_usuarios[i].id, lista_usuarios[i].nome, lista_usuarios[i].cpf,
               lista_usuarios[i].endereco);
    }
}

int pesquisar_usuario(int id) {
    int i;
    for (i = 0; i < qtd_usuarios; i++) {
        if (id == lista_usuarios[i].id) {
            return i;
        }
    }
    return -1;
}

void pesquisar_usuario_por_id() {
    int id;
    printf("Digite o ID do usuario: ");
    scanf("%d", &id);
    int pos = pesquisar_usuario(id);
    if (pos != -1) {
        printf("ID: %d\nNome: %s\nCPF: %s\nEndereco: %s\n",
               lista_usuarios[pos].id, lista_usuarios[pos].nome, lista_usuarios[pos].cpf,
               lista_usuarios[pos].endereco);
    } else {
        printf("Usuario nao encontrado.\n");
    }
}

void excluir_usuario() {
    int id;
    printf("Digite o ID do usuario que deseja excluir: ");
    scanf("%d", &id);
    int pos = pesquisar_usuario(id);
    if (pos != -1) {
        lista_usuarios[pos] = lista_usuarios[qtd_usuarios - 1];
        qtd_usuarios--;
        printf("Usuario excluido com sucesso.\n");
    } else {
        printf("Usuario não encontrado.\n");
    }
}

float calcular_multa(float dias) {
    float multa_por_dia = 2.0;
    return dias * multa_por_dia;
}

void realizar_emprestimo() {
    int id_usuario, id_livro;
    printf("Digite o ID do usuario: ");
    scanf("%d", &id_usuario);
    printf("Digite o ID do livro: ");
    scanf("%d", &id_livro);

    int pos_livro = pesquisar_livro(id_livro);
    if (pos_livro != -1 && lista_livros[pos_livro].disponivel > 1) { 
        id_emprestimo++;
        lista_emprestimos[qtd_emprestimos].id = id_emprestimo;
        lista_emprestimos[qtd_emprestimos].id_usuario = id_usuario;
        lista_emprestimos[qtd_emprestimos].id_livro = id_livro;
        printf("Digite o numero de dias de emprestimo: ");
        scanf("%f", &lista_emprestimos[qtd_emprestimos].dias_emprestimo);
        lista_emprestimos[qtd_emprestimos].multa = calcular_multa(lista_emprestimos[qtd_emprestimos].dias_emprestimo - 7);
        lista_livros[pos_livro].disponivel--;  
        qtd_emprestimos++;
        printf("\nEmprestimo realizado com sucesso!\n");
    } else {
        printf("Esse livro nao pode ser emprestado,pois a apenas um exemplar na biblioteca.\n");
    }
}

void menu() {
    printf("Selecione o tipo de usuario:\n");
    printf("1. Aluno(a)\n2. Professor(a)\n3. Funcionario(a)\n4. Pessoa Externa\n");
    printf("Digite sua opcao: ");
    scanf("%d", &tipo_usuario);

    int opcao;
    do {
        printf("\n---- Menu ----\n");
        printf("1. Cadastrar livro\n");
        printf("2. Listar livros\n");
        printf("3. Pesquisar livro por ID\n");
        printf("4. Excluir livro\n");
        printf("5. Atualizar livro\n");
        printf("6. Cadastrar usuario\n");
        printf("7. Listar usuarios\n");
        printf("8. Pesquisar usuario por ID\n");
        printf("9. Excluir usuario\n");
        printf("10. Realizar emprestimo\n");
        printf("11. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar_livro();
                break;
            case 2:
                listar_livros();
                break;
            case 3:
                pesquisar_livro_por_id();
                break;
            case 4:
                excluir_livro();
                break;
            case 5:
                atualizar_livro();
                break;
            case 6:
                cadastrar_usuario();
                break;
            case 7:
                listar_usuarios();
                break;
            case 8:
                pesquisar_usuario_por_id();
                break;
            case 9:
                excluir_usuario();
                break;
            case 10:
                realizar_emprestimo();
                break;
            case 11:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção invalida!\n");
        }
    } while (opcao != 11);
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    
    id_livro++;
    lista_livros[qtd_livros++] = (Livro){id_livro, "O Senhor dos Aneis", "J.R.R. Tolkien", "HarperCollins", "Fantasia", 1954, 2};
    
    id_livro++;
    lista_livros[qtd_livros++] = (Livro){id_livro, "1984", "George Orwell", "Companhia das Letras", "Distopia", 1949, 1};
    
    id_livro++;
    lista_livros[qtd_livros++] = (Livro){id_livro, "Dom Quixote", "Miguel de Cervantes", "Penguin", "Classico", 1605, 3};
    
    id_livro++;
    lista_livros[qtd_livros++] = (Livro){id_livro, "A Revolucao dos Bichos", "George Orwell", "Companhia das Letras", "Distopia", 1945, 1};
    
    id_livro++;
    lista_livros[qtd_livros++] = (Livro){id_livro, "O Pequeno Principe", "Antoine de Saint-Exupe11ry", "HarperCollins", "Infantil", 1943, 4};

    menu();
    return 0;
}

