CREATE DATABASE livraria;
USE livraria;

-- 1
CREATE TABLE Livros(
	id INT UNIQUE NOT NULL AUTO_INCREMENT,
    titulo VARCHAR(50) NOT NULL,
    autor VARCHAR(50) NOT NULL,
    editora VARCHAR(50) NOT NULL,
    ano_publicacao INT NOT NULL,
    preco FLOAT NOT NULL,
    quantidade INT NOT NULL,
    PRIMARY KEY (id)
);

CREATE TABLE Clientes(
	id INT UNIQUE NOT NULL AUTO_INCREMENT,
    nome VARCHAR(50) NOT NULL,
    email VARCHAR(50) NOT NULL,
    data_cadastro DATE NOT NULL,
    telefone VARCHAR(15) NOT NULL,
    PRIMARY KEY (id)
);

CREATE TABLE Vendas(
	id INT UNIQUE NOT NULL AUTO_INCREMENT,
    id_cliente INT NOT NULL,
    data_venda DATE NOT NULL,
    preco FLOAT NOT NULL,
    PRIMARY KEY (id),
    FOREIGN KEY (id_cliente) REFERENCES Clientes(id)
);

CREATE TABLE Items_venda(
	id INT UNIQUE NOT NULL AUTO_INCREMENT,
    id_venda INT NOT NULL,
    id_livro INT NOT NULL,
    quantidade INT NOT NULL,
    preco FLOAT NOT NULL,
    PRIMARY KEY (id),
    FOREIGN KEY (id_venda) REFERENCES Vendas(id),
    FOREIGN KEY (id_livro) REFERENCES Livros(id)
);

-- 2-a)
INSERT INTO Livros (titulo, autor, editora, ano_publicacao, preco, quantidade) VALUES
('Dom Casmurro', 'Machado de Assis', 'Garnier', 1899, 35.90, 15),
('Clean Code', 'Robert Martin', 'Alta Books', 2023, 119.90, 8),
('O Senhor dos Anéis', 'J.R.R. Tolkien', 'Martins Fontes', 1954, 89.90, 12),
('1984', 'George Orwell', 'Companhia das Letras', 1949, 45.50, 12),
('A Revolução dos Bichos', 'George Orwell', 'Companhia das Letras', 1945, 39.90, 20);

INSERT INTO Clientes (nome, email, data_cadastro, telefone) VALUES
('João Silva', 'joao@email.com', '2023-11-15', '119999-8888'),
('Maria Oliveira', 'maria@email.com', '2023-12-05', '119777-6666'),
('Carlos Pereira', 'carlos@email.com', '2023-10-20', '219888-7777'),
('Ana Santos', 'ana@email.com', '2023-12-10', '319555-4444'),
('Pedro Costa', 'pedro@email.com', '2023-09-25', '419333-2222');

INSERT INTO Vendas (id_cliente, data_venda, preco) VALUES
(1, '2023-12-01', 71.80),
(2, '2023-12-03', 239.80),
(3, '2023-12-04', 89.90),
(4, '2023-12-05', 179.80),
(5, '2023-12-06', 45.50);

INSERT INTO Items_venda (id_venda, id_livro, quantidade, preco) VALUES
(1, 1, 2, 35.90),
(2, 2, 2, 119.90),
(3, 3, 1, 89.90),
(4, 3, 2, 89.90),
(5, 4, 1, 45.50);

-- 2-b)
INSERT INTO Vendas (id_cliente, data_venda, preco) VALUES
(3, '2025-04-13', 249.8);

INSERT INTO Items_venda (id_venda, id_livro, quantidade, preco) VALUES
(6, 2, 2, 119.9);

-- 2-c)
UPDATE Livros
SET quantidade = quantidade - 2
WHERE id = 2;

-- 2-d)
UPDATE Livros
SET preco = preco * 1.1
WHERE ano_publicacao < 2000 AND id IS NOT NULL;

-- 2-e)
UPDATE Clientes
SET telefone = "359999-9999"
WHERE id = 1;

-- 2-f)
DELETE FROM Livros l
WHERE NOT EXISTS (
	SELECT 1 FROM items_venda iv WHERE iv.id_livro = l.id
);
