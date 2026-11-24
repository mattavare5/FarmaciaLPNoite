# Identificação do Projeto

**Nome completo:** Matheus Amancio Tavares  
**RA:** 1630482523029

## Motivo da escolha do tema

A escolha do tema ocorreu devido à minha pouca familiaridade com o assunto farmácia, encarando o desenvolvimento do projeto como um desafio e uma oportunidade de aprendizado.

## Relato do desenvolvimento

Foi utilizada uma modelagem baseada no material disponibilizado durante as aulas, complementada por pesquisas na internet. Também foram utilizadas ferramentas de apoio para revisão do código e diagnóstico de erros e exceções durante o desenvolvimento do projeto.

# Instruções de compilação e execução

**Requisitos:**
- Compilador C (GCC).
- IDE CLion ou terminal com GCC instalado.
- CMake configurado.

**Arquivos do projeto:**
- `main.c`
- `medicamento.c`
- `medicamento.h`
- `dados.txt`

**Compilação pelo terminal:**

Abra o terminal na pasta do projeto e execute:

```bash
gcc main.c medicamento.c -o medicamentos
```

**Execução no Windows:**

```bash
medicamentos.exe
```

**Execução no Linux:**

```bash
./medicamentos
```

**Execução pelo CLion:**

1. Abra o projeto no CLion.
2. Aguarde a configuração do CMake.
3. Selecione a configuração de execução do projeto.
4. Clique em Run para executar o programa.

**Observação:** O arquivo `dados.txt` deve estar no caminho utilizado pelo programa para carregar e salvar os medicamentos cadastrados.