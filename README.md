# 🛒 Monitor de Preços da Cesta Básica

Este projeto foi desenvolvido em **C** como atividade prática de lógica de programação.  
O objetivo é simular uma ferramenta de análise de preços da cesta básica, identificando aumentos, quedas e possíveis abusos nos preços praticados ao consumidor.  

---

## 📌 Funcionalidades

- Leitura dos dados de **3 produtos** da cesta básica:  
  - Nome do produto  
  - Preço no mês anterior  
  - Preço no mês atual  

- Cálculo da **variação percentual** de cada produto.  
- Classificação automática da situação do preço:
  - **AUMENTO**
  - **QUEDA**
  - **ESTÁVEL**

- Sinalização de casos especiais:
  - **Aumento abusivo** (quando variação > 10%)  
  - **Limite de aumento** (quando variação = 10%)  
  - **Redução de preço** (quando variação < 0)  

---

## 📊 Exemplo de Saída

### Entrada:
```

Produto 1 - nome: Arroz
Preço no mês anterior (R$): 20,00
Preço no mês atual (R$): 22,50

Produto 2 - nome: Feijão
Preço no mês anterior (R$): 8,00
Preço no mês atual (R$): 8,00

Produto 3 - nome: Óleo de soja
Preço no mês anterior (R$): 6,50
Preço no mês atual (R$): 6,00

```

### Saída:
```

==== RESUMO DA ANALISE ====
Produto: Arroz
Preco anterior: R$ 20.00
Preco atual:    R$ 22.50
Variacao: 12.5%
Situacao: AUMENTO - Aumento abusivo
-----------------------------------

Produto: Feijão
Preco anterior: R$ 8.00
Preco atual:    R$ 8.00
Variacao: 0.0%
Situacao: ESTÁVEL
-----------------

Produto: Óleo de soja
Preco anterior: R$ 6.50
Preco atual:    R$ 6.00
Variacao: -7.7%
Situacao: QUEDA - Reducao de preco
----------------------------------

````

---

## ⚙️ Como Compilar e Executar

No terminal (usando GCC):

```bash
gcc variacao-preco-produto.c -o variacao-preco-produto.exe
./variacao-preco-produto.exe
````

---

## 🛠️ Tecnologias Utilizadas

* Linguagem **C**
* Compilador **GCC**
* Ambiente: **Visual Studio Code**

---

## 📚 Aprendizados

* Estruturas de decisão (`if`, `else if`, `else`)
* Manipulação de strings e números decimais
* Estrutura `struct` para organizar dados
* Entrada e saída formatada
