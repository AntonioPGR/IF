/* ------------------------------- */
-- I
create database Biblioteca;
use Biblioteca;
create table Editora (codigo int, nome varchar(30), contato varchar(20), primary key (codigo));
insert into Editora values (1, "Nova", "Ana"), (2,"Atual", Null), (3,"Moderna",null);
create table autores (codigo int, nome varchar(30), nacionalidade varchar(30), primary key (codigo));
insert into autores values (1, "Luiz", null), (2,"Antonio", null), (3, "Laura", null);
create table Livros (codigo int, titulo varchar(40), edicao int, genero varchar(30), anoPublicacao int, codigoEditora int, primary key (codigo), foreign key (codigoEditora) references Editora (codigo));
insert into Livros values (1, "A Terra", 1, "Romance", 2020, 1), (2, "A Lua", 1, "Terror", 2020, 1), (3, "O Mar", 1, null, 2020, 3);
create table Funcionarios ( cpf char(7), nome varchar(30), funcao  varchar(20), salario double, primary key(cpf));
insert into Funcionarios values ("345.678", "Beatriz", "Recepcionista", 2000.00), ("044.033","Sílvia","DBA", 1000.00), ("098.890", "Maria", "TI", 1500.00); 
create table retiraFuncionario ( cpfFuncionario char(7), codigoLivro int, primary key (cpfFuncionario, codigoLivro), foreign key (cpfFuncionario) references Funcionarios (cpf), foreign key (codigoLivro) references Livros (codigo));
insert into retiraFuncionario values ( "044.033", 1), ("345.678", 1), ("345.678", 3);
create table Usuarios (cpf char(7), nome varchar(30), endereco varchar(30), telefone varchar(12), codigoLivro int, primary key (cpf), foreign key (codigoLivro) references Livros (codigo));
insert into Usuarios values ("123.456", "Ana", "Rua A, 10", "3712-1010", 1), ("789.999", "Maria", "Rua WJ,30", "3722-2020", 1), ("876.985", "José", "Rua Dois, 33","3713-9090", 2);
create table Retirar (cpf char(7), codigoLivro int, primary key(cpf, codigoLivro), foreign key (cpf) references Usuarios (cpf), foreign key (codigoLivro) references Livros (codigo));
insert into Retirar values ("123.456", 1),("789.999", 1), ("789.999",3);
create table escreve (codigoLivro int, codigoAutor int, primary key(codigoLivro, codigoAutor), foreign key(codigoLivro) references Livros (codigo), foreign key (codigoAutor) references Autores (codigo));
insert into escreve values (1, 12), (1, 10),(3, 10);

-- 1. Mostrar os nomes dos funcionários e os títulos dos livros retirados por ele.
CREATE VIEW FuncionariosRetiraLivros AS
SELECT Funcionarios.nome, Livros.titulo FROM retiraFuncionario
JOIN Funcionarios ON retiraFuncionario.cpfFuncionario = Funcionarios.cpf
JOIN Livros ON retiraFuncionario.codigoLivro = Livros.codigo;

-- 2. Apresentar uma listagem de funcionários com seus salários acrescidos de 30%.
CREATE VIEW FuncionariosAumentaSalario AS
SELECT *, (salario * 1.3) FROM Funcionarios;

-- 3. Apresentar a soma do salário dos funcionários de Campinas. ( cidade? )
/*CREATE VIEW SomaSalarioCampinas AS
SELECT SUM(salario) FROM Funcionarios
WHERE cidade = "Campinas"*/

-- 4. Selecionar os 5 menores salários e suas respectivas cidades.

/* ------------------------------- */
-- II
USE Exercicios;
CREATE TABLE Curso (Codigo VARCHAR(10) PRIMARY KEY, Nome VARCHAR(100), Creditos INT, Valor DECIMAL(10,2));
INSERT INTO Curso (Codigo, Nome, Creditos, Valor) VALUES
('10-A', 'Sistemas Operacionais', 6, 200.00),
('20-B', 'Redes', 12, 350.00),
('10-C', 'Java', 10, 200.00),
('30-A', 'Banco de Dados', 10, 300.00),
('40-B', 'Computação Gráfica', 6, 250.00),
('20-C', 'Orientação a Objeto', 6, 200.00),
('11-A', 'Inteligência Artificial', 12, 300.00),
('35-C', 'Projeto de Software', 8, 350.00),
('56-E', 'Qualidade de Software', 12, 400.00);


-- 1. Selecione os nomes dos cursos, créditos e valores e mostre com os respectivos nomes: Nome_Curso, Créditos e Preço.
CREATE VIEW A AS
SELECT Nome AS Nome_Curso, Creditos AS "Créditos", Valor AS "Preço" FROM Curso;

-- 2. Mostre os créditos dos cursos sem valores repetidos.
CREATE VIEW B AS
SELECT DISTINCT Creditos FROM Curso;

-- 3. Mostre os valores dos cursos, sem repetição.
CREATE VIEW C AS
SELECT DISTINCT Valor FROM Curso;

-- 4. Selecione os códigos e nomes de cursos com valores entre 330,00 e 400 .
CREATE VIEW D AS
SELECT Codigo, Nome FROM Curso
WHERE Valor >= 330 AND Valor <= 400;

-- 5. Mostre os nomes e valores dos cursos com um acréscimo de 20%.
CREATE VIEW E AS
SELECT Nome, (Valor * 1.2) AS "Valor + 20%" FROM Curso;

-- 6. Selecione o nome dos cursos com 12 ou 10 créditos.
CREATE VIEW F AS
SELECT Nome FROM Curso
WHERE Creditos = 10 OR Creditos = 12;

-- 7. Selecione o nome dos cursos com 6, 8 e 10 créditos.
CREATE VIEW G AS
SELECT Nome FROM Curso
WHERE Creditos = 6 OR Creditos = 8 OR Creditos = 10;

-- 8. Selecione os cursos que tenham Software no seu nome.
CREATE VIEW H AS
SELECT * FROM Curso
WHERE nome LIKE '%Software%';

-- 9. Selecione o código e nome dos cursos que tenham a letra A em seu nome.
CREATE VIEW I AS
SELECT Codigo, Nome FROM Curso
WHERE nome LIKE '%a%';

-- 10. Selecione o nome e valor dos cursos com valores abaixo de 300,00 (inclusive).
CREATE VIEW J AS
SELECT Nome, Valor FROM Curso
WHERE valor <= 300;

-- 11. Selecione o nome e créditos dos cursos e acrescente 6 créditos.
CREATE VIEW K AS
SELECT Nome, Creditos, (Creditos + 6 ) FROM Curso;

-- 12. Selecione os cursos de 6 créditos e valores acima de 200,00.
CREATE VIEW L AS
SELECT * FROM Curso
WHERE Creditos = 6 AND Valor > 200;

/* ------------------------------- */
-- III
create database Transportadora;
use Transportadora;
create table Cliente (idCliente int, nomeCliente varchar(30),endereco varchar(30), cidade varchar(20), estado char(2), obs varchar(50), primary key (idCliente));
insert into Cliente values (1, "ANTON", "R. TOON 23", "Campinas", "SP", null), (2, "Vicky", "AV. 2 – 342", "Campinas", "SP", null),(3, "Kinnard", "AV 5 - BL9", "RIO DE JANEIRO", "RJ", null),(4, "Steven", "ASA NORTE - BL8 - 56", "Brasília", "DF", null),(5, "BROWN", "R. 156 – 90", "São Paulo", "SP", null),(6, "SAM", "R. 32 – 23", "São Paulo", "SP", null),(7, "BERGS", "AV. NORTE SUL 456", "Campinas", "SP", null),(8, "AROUT", "R. BERKAZEL 90", "Porto Alegre", "RS", null), (9, "LARRY", "AV. UM 908", "Campinas", "SP", null),(10, "HARRISON", "R. 23 -98", "Belo Horizonte", "MG", null);
create table Transportadora (idTransp int, nomeTransportadora varchar(30), endereco varchar(30), cidade varchar(20), estado char(2), atividade varchar(30), primary key (idTransp));
insert into Transportadora values (1, "TRANSCAR S.A", "R. 13 DE MAIO 213", "Campinas", "SP", null), (2, "CITY CAR", "AV. 2 – 342", "Campinas", "SP", null), (3, "TRANSPORTE JUND", "AV 5 - BL9", "Rio de Janeiro", "RJ", null), (4, "SPEED S.A.", "ASA NORTE - BL8 - 56", "Brasília", "DF", null), (5, "ALIENS TRANSPORTES", "R. 156 – 90", "São Paulo", "SP", null);
create table Produto (idProduto int, nomeProduto varchar(30), descricao varchar(40), preco float, quantidade int, primary key (idProduto));
insert into Produto values (1, "MK22.", "MAQUINA SERIE 23", 560.00, 200),(2, "SPMW34", "ROLAMENTO SERIE3", 210.00, 50), (3, "FVG1", "BLOCO 5 MAQUINA SP", 780.00, 10), (4,"SPEG234.", "SUPORTE MAQUINA R5", 300.00, 15), (5, "MKS34", "MAQUINA SERIE 21A", 1250.00, 8), (6, "MKP22.", "MAQUINA SERIE 23C", 656.00, 20),(7, "SPMW34", "ROLDANA SERIE 13", 910.00, 10),(8, "FVG1", "BLOCO 4 MAQUINA SP3", 880.00, 10);
create table Pedido (idPedido int, idCliente int, idTransportadora int, dataPedido date, obs varchar(30), primary key (idPedido), foreign key (idCliente) references Cliente (idCliente), foreign key (idTransportadora) references Transportadora (idTransp));
insert into Pedido values (1, 5, 1, "2004-10-25", null), (2, 8, 3, "2004-10-02", null), (3, 5, 1, "2004-04-25", null), (4, 4, 1, "2004-10-02", null), (5, 10, 2, "2004-04-02", null), (6, 10, 5, "2004-04-08", null), (7, 10, 1, "2004-10-08", null), (8, 10, 2, "2004-10-25", null), (9, 1, 1, "2004-10-25", null), (10, 2, 3, "2004-05-03", null), (11, 1, 1, "2004-04-26", null), (12, 2, 1, "2004-08-02", null), (13, 2, 5, "2004-04-15", null), (14, 4, 5, "2004-08-08", null),(15, 2, 1, "2004-05-08", null),(16, 8, 2, "2004-05-25", null);
create table OrdemPedido (idOrdemPedido int, idProduto int, idPedido int, quantidade int, primary key(idOrdemPedido), foreign key(idProduto) references Produto (idProduto), foreign key (idPedido) references Pedido (idPedido));
insert into OrdemPedido values (1, 5, 1, 15), (2, 8, 1, 2),(3, 5, 2, 25), (4, 4, 3, 204), (5, 1, 4, 424), (6, 1, 5, 84), (7, 8, 5, 80), (8, 4, 6, 25), (9, 1, 6, 21), (10, 2, 7, 35), (11, 1, 8, 26),(12, 2, 9, 82),(13, 2, 10, 42), (14, 4, 11, 8), (15, 6, 11, 14), (16, 5, 12, 54), (17, 4, 13, 12), (18, 7, 14, 42), (19, 7, 15, 44), (20, 2, 15, 14), (21, 1, 16, 20), (22, 2, 16, 54), (23, 3, 7, 32), (24, 1, 8, 26), (25, 2, 9, 80), (26, 2, 10, 15), (27, 4, 11, 20);

-- 1. Nome dos clientes que já fizeram alguma compra.
CREATE VIEW M AS
SELECT DISTINCT Cliente.nomeCliente FROM Pedido
JOIN Cliente ON Cliente.idCliente = Pedido.idCliente;

-- 2. Quantidade total de itens pedido pelos clientes do Distrito Federal.
CREATE VIEW N AS
SELECT COUNT(idPedido) FROM Pedido
JOIN Cliente ON Cliente.idCliente = Pedido.idCliente AND Cliente.estado = "DF";

-- 3. Número de transportadoras do estado de SP.
CREATE VIEW O AS
SELECT COUNT(idTransp) FROM Transportadora
WHERE estado = "SP";

-- 4. Nome dos produtos que começam com a letra M e tem mais que 20 unidades em estoque.
CREATE VIEW P AS
SELECT nomeProduto FROM Produto
WHERE quantidade > 20 AND nomeProduto LIKE "M%";