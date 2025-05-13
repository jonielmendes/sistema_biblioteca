# 📚 Sistema de Biblioteca em C

Este é um sistema simples de biblioteca desenvolvido em linguagem C. O programa permite o gerenciamento de livros e usuários, com funcionalidades específicas para diferentes tipos de sócios da biblioteca.

## 👥 Tipos de Sócios Aceitos
Ao iniciar o sistema, o usuário deve informar seu tipo de vínculo com a biblioteca. Os tipos aceitos são:

- Professores
- Alunos
- Funcionários
- Comunidade Externa

**⚠️ Observação:** Algumas funcionalidades são exclusivas para funcionários da biblioteca.

---

## 🧩 Funcionalidades do Sistema

### 📘 Livros
1. **Cadastrar Livro** – Adiciona um novo livro ao acervo. *(Acesso exclusivo de funcionários)*
2. **Listar Livros** – Mostra todos os livros cadastrados no sistema.
3. **Pesquisar Livro por ID** – Permite localizar um livro específico utilizando seu ID.
4. **Excluir Livro** – Remove um livro do sistema. *(Acesso exclusivo de funcionários)*
5. **Atualizar Livro** – Permite editar informações de um livro. *(Acesso exclusivo de funcionários)*

### 👤 Usuários
6. **Cadastrar Usuário** – Adiciona um novo sócio ao sistema. *(Acesso exclusivo de funcionários)*
7. **Listar Usuários** – Exibe a lista de todos os sócios cadastrados.
8. **Pesquisar Usuário por ID** – Permite localizar um sócio específico utilizando seu ID.
9. **Excluir Usuário** – Remove um sócio do sistema. *(Acesso exclusivo de funcionários)*

### 📖 Empréstimos
10. **Realizar Empréstimo** – Permite que um sócio realize o empréstimo de um livro disponível.

---

## 🚀 Tecnologias Utilizadas
- Linguagem C
- Terminal/Console

---

## 🛠️ Como Executar
1. Compile o código com um compilador C, como `gcc`.
2. Execute o programa no terminal.
3. Siga as instruções interativas.

---

## 📌 Observações
- O sistema utiliza controle de permissões com base no tipo de usuário.
- O foco é demonstrar conceitos básicos de programação em C com estruturas como `struct`, arrays e funções.

---

## 📄 Licença
Este projeto é livre para fins educacionais.




