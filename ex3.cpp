#include <iostream>
#include <string>
#include <vector>

class Produto {
private:
    std::string nome;
    double preco;
    int codigo;

public:
    Produto(const std::string& nome, double preco, int codigo)
        : nome(nome), preco(preco), codigo(codigo) {}

    std::string getNome() const {
        return nome;
    }

    double getPreco() const {
        return preco;
    }

    int getCodigo() const {
        return codigo;
    }
};

class Estoque {
private:
    std::vector<Produto> produtos;
    std::vector<int> quantidades;

public:
    void adicionarProduto(const Produto& produto, int quantidade) {
        produtos.push_back(produto);
        quantidades.push_back(quantidade);
    }

    void removerProduto(int codigo) {
        for (size_t i = 0; i < produtos.size(); ++i) {
            if (produtos[i].getCodigo() == codigo) {
                produtos.erase(produtos.begin() + i);
                quantidades.erase(quantidades.begin() + i);
                break;
            }
        }
    }

    void exibirEstoque() const {
        std::cout << "Estoque:" << std::endl;
        for (size_t i = 0; i < produtos.size(); ++i) {
            std::cout << "Código: " << produtos[i].getCodigo() << ", Nome: " << produtos[i].getNome()
                      << ", Preço: " << produtos[i].getPreco() << ", Quantidade: " << quantidades[i] << std::endl;
        }
    }
};

class CarrinhoDeCompras {
private:
    std::vector<Produto> produtosNoCarrinho;

public:
    void adicionarProduto(const Produto& produto) {
        produtosNoCarrinho.push_back(produto);
    }

    void removerProduto(int codigo) {
        for (size_t i = 0; i < produtosNoCarrinho.size(); ++i) {
            if (produtosNoCarrinho[i].getCodigo() == codigo) {
                produtosNoCarrinho.erase(produtosNoCarrinho.begin() + i);
                break;
            }
        }
    }

    double calcularValorTotal() const {
        double total = 0.0;
        for (const Produto& produto : produtosNoCarrinho) {
            total += produto.getPreco();
        }
        return total;
    }

    void exibirCarrinho() const {
        std::cout << "Carrinho de Compras:" << std::endl;
        for (const Produto& produto : produtosNoCarrinho) {
            std::cout << "Código: " << produto.getCodigo() << ", Nome: " << produto.getNome()
                      << ", Preço: " << produto.getPreco() << std::endl;
        }
    }
};

int main() {
    Produto p1("Arroz", 5.99, 1);
    Produto p2("Feijão", 4.49, 2);
    Produto p3("Leite", 3.29, 3);

    Estoque estoque;
    estoque.adicionarProduto(p1, 50);
    estoque.adicionarProduto(p2, 30);
    estoque.adicionarProduto(p3, 40);

    CarrinhoDeCompras carrinho;

    carrinho.adicionarProduto(p1);
    carrinho.adicionarProduto(p2);

    std::cout << "Conteúdo do carrinho:" << std::endl;
    carrinho.exibirCarrinho();
    std::cout << "Valor total no carrinho: " << carrinho.calcularValorTotal() << std::endl;

    estoque.exibirEstoque();

    return 0;
}
